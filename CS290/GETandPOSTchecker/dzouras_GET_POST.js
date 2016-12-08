/*************************
Darlene Zouras
CS 290 Fall 2016
GET and POST Checker assignment
*************************/

var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 5432);

// GET CHECKER
app.get('/', function(req, res) {
  var params = [];
  for (var p in req.query){
    params.push({'name':p,'value':req.query[p]})
  }
  var context = {};
  context.dataList = params;
  context.reqType = "GET";
  res.render('checkData', context);
});

// POST CHECKER
app.post('/', function(req,res) {
  var params = [];
  for (var p in req.body) {
    params.push({'name': p, 'value': req.body[p]})
  }
  console.log(params);
  console.log(req.body);
  var context = {};
  context.dataList = params;
  context.reqType = "POST";
  res.render('checkData', context);
})

app.listen(app.get('port'), function() {
  console.log('Express started on port ' + app.get('port') + '; press ctrl-c to terminate.');
});
