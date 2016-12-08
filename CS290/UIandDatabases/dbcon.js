var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit : 10,
  host            : 'mysql.eecs.oregonstate.edu',
  user            : 'cs290_zourasd',
  password        : '4475',
  database        : 'cs290_zourasd'
});

module.exports.pool = pool;
