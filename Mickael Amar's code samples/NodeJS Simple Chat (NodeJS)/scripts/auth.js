var bcrypt = require('bcryptjs');
var User = require('.././models/User.js');

// Verify if user exist in DB and store it in session
exports.login = function(req, res) {
    User.findOne({
        email: req.body.email
    }, function(error, user) {
        if (!user) {
            res.render('login.html', {
                error: 'Invalid email'
            });
        } else {
            if (bcrypt.compareSync(req.body.password, user.password)) {
                req.session.user = user;
                res.locals.user = user;
                res.redirect('/chat');
            } else {
                res.render('login.html', {
                    error: 'Invalid password'
                });
            }
        }
    });
};

// register inplemented with callback function only
exports.register = function(req, cb) {
    var hash = bcrypt.hashSync(req.body.password, bcrypt.genSaltSync(10));
    var user = new User({
        username: req.body.username,
        email: req.body.email,
        password: hash
    });
    user.save(function(err) {
        if (err) {
            var error = 'something went wrong!';
            if (err.code === 11000) {
                error = 'Email already registered, try another!';
            }
            cb(error, null); //calling callback and return value as per need
        } else {
            cb(null, true);
        }
    });
};

exports.getUser = function(email, cb) {
    User.findOne({
        email: email
    }, function(err, user) {
        if (user) {
            cb(null, user);
        } else {
            cb("User not found", null);
        }
    });
}
