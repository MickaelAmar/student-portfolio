var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var ObjectId = Schema.ObjectId;

//User schema
var User = mongoose.model('User', new Schema({
    id: ObjectId,
    username: String,
    email: {
        type: String,
        unique: true
    },
    password: String
}));

module.exports = User;
