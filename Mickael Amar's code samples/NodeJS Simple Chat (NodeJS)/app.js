var express = require('express');
var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var bodyParser = require('body-parser');
var mongoose = require('mongoose');
var sessions = require('client-sessions');
var csrf = require('csurf'); // CSRF security
var ent = require('ent');

/**
 *
 *
 * CONFIGURATION
 *
 *
 */

// Database connection
mongoose.connect('mongodb://localhost:27017/proof-chat');
var engines = require('consolidate');

// Project organization
app.set('views', __dirname + '/views');
app.engine('html', engines.mustache);
app.set('view engine', 'html');
app.use(express.static(__dirname + '/public'));

// body-parser to parse form data into json req.body
app.use(bodyParser.urlencoded({extended: true}));

// Client session save session using cookie in browser
app.use(sessions({
    cookieName: 'session',
    secret: 'hF3rgY0Ozki73Z1LgjmtiCUFQugB8rbI9tRCRyEl',
    duration: 30 * 60 * 1000,
    activeDuration: 5 * 60 * 1000
}));

// Import auth controller
var auth = require('./scripts/auth.js');

// Generation csrf token
app.use(csrf());

/**
 *
 *
 * MIDDLEWARES
 *
 *
 */

// Verify logged user in session
app.use(function (req, res, next) {
    if (req.session && req.session.user) {
        var user = auth.getUser(req.session.user.email, function (err, user) {
            if (user != null) {
                req.user = user;
                delete req.user.password;
                req.session.user = req.user;
                res.locals.user = req.user;
                next();
            } else {
                next();
            }
        });
    } else {
        next();
    }
});

// Require login middleware can apply on routes in which we need required login
function requireLogin(req, res, next) {
    if (!req.user) {
        // http code is necessary to update url
        res.redirect(301, '/login');
    } else {
        next();
    }
}


/**
 *
 *
 * ROUTES
 *
 *
 */

app.get('/', function (req, res) {
    res.render('home.html');
});

app.get('/', function (req, res) {
    if (req.session.message) {
        var x = req.session.message;
        delete req.session.message;
        res.render('home.html', {message: x});
    } else if (req.session.error) {
        var x = req.session.error;
        delete req.session.error;
        res.render('home.html', {error: x});
    } else {
        res.render('home.html');
    }
});

app.get('/register', function (req, res) {
    if (req.session.message) {
        var x = req.session.message;
        delete req.session.message;
        res.render('register.html', {message: x, csrfToken: req.csrfToken()});
    } else if (req.session.error) {
        var x = req.session.error;
        delete req.session.error;
        res.render('register.html', {error: x, csrfToken: req.csrfToken()});
    } else {
        res.render('register.html', {csrfToken: req.csrfToken()});
    }
});

// on post managing function using call back functions
app.post('/register', function (req, res) {
    auth.register(req, function (err, registered) {
        if (registered == true) {
            var message = "User registered successfully";
            req.session.message = message;
            res.redirect('/');
        } else {
            req.session.error = err;
            res.redirect('/register');
        }
    });
});

app.get('/login', function (req, res) {
    if (req.session && req.session.user) {
        res.locals.user = req.session.user;
        res.redirect('/chat');
    } else {
        res.render('login.html', {csrfToken: req.csrfToken()});
    }
});

app.post('/login', auth.login);

app.get('/logout', function (req, res) {
    req.session.reset();
    res.send('Session Logged out.<br> <a href="/login">Login Again</a>');
});

app.get('/chat', requireLogin, function (req, res) {
        res.render('chat.html');
});

/**
 *
 *
 * SOCKET.IO
 *
 *
 */

require('./scripts/sockets.js')(io);

http.listen(8080, function () {
    console.log('Server is listening on :8080');
});
