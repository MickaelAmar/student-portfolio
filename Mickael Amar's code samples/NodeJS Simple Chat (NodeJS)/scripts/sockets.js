module.exports = function (io) {
    var users = [];

    io.on('connection', function (socket) {
        io.set('heartbeat timeout', 60 * 60 * 24); // 24h time out

        // retrieving logged users for a new client
        for (i = 0; i < users.length; i++) {
            socket.emit('join-chat', users[i]);
        }

        socket.on('join-chat', function (username) {
            socket.username = username;
            if (users.indexOf(socket.username) <= -1) {
                users.push(username);
                socket.emit('join-chat', username);
                socket.broadcast.emit('join-chat', username);
                var notification = {
                    text: 'Welcome ' + username + '!',
                    type: 'login'
                };
                var bnotification = {
                    text: 'User "' + username + '" logged in',
                    type: 'login'
                };
                socket.emit('notification', notification);
                socket.broadcast.emit('notification', bnotification);
            }
        });

        socket.on('disconnect', function (username) {
            if (socket.username !== undefined) {
                var notification = {
                    text: 'User "' + username + '" left the chatroom',
                    type: 'logout'
                };
                socket.broadcast.emit('notification', notification);
                var i = users.indexOf(username);
                if (i !== -1) {
                    users.splice(i, 1);
                }
                socket.emit('quit-chat', username);
            }
        });

        socket.on('message', function (message, username) {
            username = socket.username;
            // message = ent.encode.message;
            io.emit('message', message, username);
        });
    });
};