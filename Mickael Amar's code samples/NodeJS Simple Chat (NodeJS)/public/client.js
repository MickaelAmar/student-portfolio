var socket = io();
var username = $("#username").val();
var i;

socket.emit('join-chat', username);

socket.on('join-chat', function(username) {
    $('#users').append($('<li class="' + username + ' new">').html(username + '<span class="typing">typing</span>'));
    setTimeout(function () {
        $('#users li.new').removeClass('new');
    }, 1000);
});

socket.on('notification', function(message) {
    $('#messages').append($('<li class="' + message.type + '">').html('<span class="info">information</span> ' + message.text));
    scrollToBottom();
});

socket.on('quit-chat', function (username) {
    var user = '#users li.' + username;
    $(user).remove();
});

$('#chat form').submit(function (e) {
    e.preventDefault();
    var message = $('#m').val();
    if (message.trim().length !== 0) {
        $('#m').val('');
        socket.emit('message', message);
    }
    $('#chat input').focus();
});

socket.on('message', function (message, username) {
    $('#messages').append($('<li>').html('<span class="username">' + username + '</span> ' + message));
    scrollToBottom();
});

function scrollToBottom() {
    if ($(window).scrollTop() + $(window).height() + 2 * $('#messages li').last().outerHeight() >= $(document).height()) {
        $('html, body').animate({ scrollTop: $(document).height() }, 0);
    }
}