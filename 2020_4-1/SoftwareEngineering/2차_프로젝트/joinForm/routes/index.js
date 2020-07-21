var express = require('express');
var router = express.Router();

var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit: 5,
  host: 'localhost',
  user: 'root',
  database: 'test',
  password: '123456'
});

/* GET home page. */
router.get('/', function(req, res, next) {
  pool.getConnection(function(err, connection){
    connection.query('SELECT * FROM board', function(err, rows){
      if(err) console.log(err);
      console.log('rows : ' + JSON.stringify(rows));

      res.render('index', {title: 'test', rows: rows});
      connection.release();


    });
  });
});

module.exports = router;
