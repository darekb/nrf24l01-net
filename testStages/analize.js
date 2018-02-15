var fs = require('fs');
var path = require('path');
var filePath = path.join(__dirname, 'gtkwave_trace.vcd');
fs.readFile(filePath, {encoding: 'utf-8'}, function(err,data){
    if (!err) {
        var t = data.split("\n");
        t.forEach(function (line){
          if(line == "b00000010 !"){
            console.log('ST_START');
          }
          if(line == "b00000100 !"){
            console.log('ST_GOT_DATA');
          }
          if(line == "b00001000 !"){
            console.log('ST_SENT_DATA');
          }
          if(line == "b00010000 !"){
            console.log('ST_ERROR_SENT_DATA');
          }
          if(line == "b00100000 !"){
            console.log('ST_UNKNOWN_ERROR');
          }
          if(line == "b00000000 !"){
            console.log('ST_WAITING');
          }
        });
    } else {
        console.log(err);
    }
});