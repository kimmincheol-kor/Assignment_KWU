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

var multer = require('multer');
var storage = multer.diskStorage({
    destination: function (req, file, cb) {
        cb(null, "uploads/")
    },
    filename: function (req, file, cb) {
    cb(null, req.body.creator_id + "-" + file.originalname)
    }
});

var upload = multer({ storage: storage });
var fs = require('fs')

router.get('/', function(req, res, next) {
    res.redirect('/board/list/1');
});

router.get('/list/:page', function(req, res, next) {
  pool.getConnection(function(err, connection){

    var sqlForSelectList = 'SELECT idx, creator_id, title, hit FROM board'
    connection.query(sqlForSelectList, function(err, rows){
      if(err) console.log(err);

      res.render('list', {title: '게시판 전체 글 조회', rows: rows});
      connection.release();
    });
  });
});

router.get('/write', function(req, res, next){
    res.render('write', {title:"게시판 글 쓰기"});
});

router.post('/write', upload.single('image'), function(req, res, next){

    var creator_id = req.body.creator_id;
    var title = req.body.title;
    var content = req.body.content;
    var passwd = req.body.passwd;
    var image = req.file.path;
    var datas = [creator_id, title, content, passwd, image];

    console.log(image);

    pool.getConnection(function(err, connection){
        var sqlForInsertBoard = "insert into board(creator_id, title, content, regdate,\
            hit, passwd, image) values(?,?,?,NOW(),0,?,?)";
        connection.query(sqlForInsertBoard, datas, function(err, rows){
            if(err) console.log(err);

            res.redirect('/board');
            connection.release();
        });
    });
});

router.get('/read/:idx', function(req, res, next) {

    var idx = req.params.idx;

    pool.getConnection(function(err, connection){
  
      var sqlForRead = 'SELECT idx, creator_id, title, content, hit, image FROM board where idx=?'
      connection.query(sqlForRead, idx, function(err, row){
        if(err) console.log(err);

        console.log("1개 글 조회 결과 확인 : ", row);
  
        res.render('read', {title: '글 조회', row: row[0]});
        connection.release();
      });
    });
  });

  router.get('/uploads/:filename', function(req, res, next) {
      console.log(req.params.filename);

      fs.readFile('uploads/'+req.params.filename, function(err, data){
          res.send(data);
      });
  });

  router.get('/update', function(req, res, next) {

    console.log(req.query);
    var idx = req.query.idx;

    pool.getConnection(function(err, connection){

      if(err) console.error("커넥션 객체 얻어오기 에러 : ", err);
  
      var sqlForRead = 'SELECT idx, creator_id, title, content, hit FROM board where idx=?'
      connection.query(sqlForRead, [idx], function(err, rows){
        if(err) console.log(err);

        console.log("Update에서 1개 글 조회 결과 확인 : ", rows);
  
        res.render('update', {title: '글 수정', row: rows[0]});
        connection.release();
  
  
      });
    });
  });

  router.post('/update', function(req, res, next){

    var idx = req.body.idx;
    var creator_id = req.body.creator_id;
    var title = req.body.title;
    var content = req.body.content;
    var passwd = req.body.passwd;
    var datas = [creator_id, title, content, idx, passwd];
    
    pool.getConnection(function(err, connection){
        var sqlForUpdateBoard = "update board set creator_id=?, title=?, content=? where idx=? and passwd=?";
        connection.query(sqlForUpdateBoard, datas, function(err, result){
            if(err) console.log("글 수정 중 에러 발생 err : ", err);

            console.log(result);

            if(result.affectedRows == 0){
                res.send("<script>alert(\"패스워드가 일치하지 않거나, 잘못된 요청으로 인해 값이 변경되지 않았습니다.\");history.back();</script>");
            }
            else {
                res.redirect('/board/read/'+idx);
            }
            
            connection.release();
        });
    });
});

router.get('/delete/:idx', function(req, res, next) {

    var idx = req.params.idx;

    pool.getConnection(function(err, connection){
  
      var sqlForDel = 'DELETE FROM board WHERE idx=?'
      connection.query(sqlForDel, idx, function(err, row){
        if(err) console.log(err);

        console.log("글 삭제 완료.");
  
        res.redirect('/board/list/1');
        connection.release();
  
  
      });
    });
  });

module.exports = router;
