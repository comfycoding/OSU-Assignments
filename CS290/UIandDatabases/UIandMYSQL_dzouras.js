var express = require('express');
var mysql = require('./dbcon.js');

var bodyParser = require('body-parser');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 5433);
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get('/',function(req,res,next){
  var context = {};
  mysql.pool.query('SELECT id, name, reps, weight, lbs, date FROM workouts ORDER BY date DESC', function(err, rows, fields){
    if(err){
      next(err);
      return;
    }

    context.results = rows;

    res.render('home', context);
  });
});

app.post('/insert',function(req,res,next){
  mysql.pool.query("INSERT INTO workouts (name, reps, weight, lbs, date) VALUES (?, ?, ?, ?, ?)", [req.body.name, req.body.reps, req.body.weight, req.body.lbs, req.body.date],
  function(err, result){
    if(err){
      next(err);
      return;
    }
    else {
      console.log("Inserted into the workout table: ");
      console.log(req.body);
    }
  });
});

app.post('/delete',function(req,res,next){
  mysql.pool.query("DELETE FROM workouts WHERE id=?", [req.body.id], function(err, result){
    if(err){
      next(err);
      return;
    }
    else {
      console.log(req.body);
    }
  });
});

app.post('/safe-update',function(req,res,next){
  mysql.pool.query("SELECT * FROM workouts WHERE id=?", [req.body.id], function(err, result){
    if(err){
      next(err);
      return;
    }
    if(result.length == 1){
      var curVals = result[0];
      mysql.pool.query("UPDATE workouts SET name=?, reps=?, weight=?, lbs=?, date=? WHERE id=? ",
        [req.body.name || curVals.name, req.body.reps || curVals.reps, req.body.weight || curVals.weight, req.body.lbs, req.body.date || curVals.date, curVals.id],
        function(err, result){
        if(err){
          next(err);
          return;
        }
        console.log(req.body);
      });
    }
  });
});

app.get('/reset-table',function(req,res,next){
  var context = {};
  mysql.pool.query("DROP TABLE IF EXISTS workouts", function(err){
    var createString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
    mysql.pool.query(createString, function(err){
      context.results = "Table reset";
      res.render('reset',context);
    })
  });
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
