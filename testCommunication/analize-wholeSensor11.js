var fs = require('fs');
var config = require('./config.js');

function showStats() {

  var times = {
    'serverMeasure': [],
    'sensor11Measure': [],
    'sensor12Measure': [],
    'sensor21Measure': [],
    'sendToServer': []

  }
  var fails = 0;
  var fails2 = 0;
  var fails3 = 0;
  var lastTime = 0;
  var actTime = 0;
  var actTime2 = 0;
  var actTime3 = 0;
  var lastIndex = 0;
  var lastIndex2 = 0;
  var lastIndex3 = 0;
  fs.readFile(config.filename, 'utf8', function(err, data) {
    if (err) {
      return console.log(err);
    }
    var lines = data.split("\n");
    lines.map(function(line, index) {
      var elems = line.split('|');
      if (elems[2] && ((elems[2] * 1) > 1493906870026)) {
         if (actTime3 > 0 && elems.length > 5 &&  elems[7]*1 == 21) {
            if(elems[6] == 0 &&  elems[5] == 0 && elems[4] == 0 && elems[3] == 0){
              fails3++;
            } else {
              var diff = elems[2] * 1 - actTime3 * 1;
              times.sensor21Measure.push(diff);
              actTime3 = 0;
              lastIndex3 = 0;
            }
           }
         if (elems[3] && lastIndex3 > 0 && elems[3].trim() == 'F21') {
           //if(index - lastIndex == 1){
           fails3++;
           //}
         }
         if (elems[3]) {
           if (elems[3].trim() == 'S21') {
             actTime3 = elems[2] * 1;
             lastIndex3 = index;
           }
         }
        if (actTime > 0 && elems.length > 5 &&  elems[7]*1 == 11) {
          if(elems[6] == 0 &&  elems[5] == 0 && elems[4] == 0 && elems[3] == 0){
            fails++;
          } else {
            var diff = elems[2] * 1 - actTime * 1;
            times.sensor11Measure.push(diff);
            actTime = 0;
            lastIndex = 0;
          }
        }
        if (elems[3] && lastIndex > 0 && elems[3].trim() == 'F11') {
          //if(index - lastIndex == 1){
          fails++;
          //}
        }
        if (elems[3]) {
          if (elems[3].trim() == 'S11') {
            actTime = elems[2] * 1;
            lastIndex = index;
          }
        }
        if (actTime2 > 0 && elems.length > 5 &&  elems[7]*1 == 12) {
          if(elems[6] == 0 &&  elems[5] == 0 && elems[4] == 0 && elems[3] == 0){
            fails2++;
          } else {
            var diff = elems[2] * 1 - actTime2 * 1;
            times.sensor12Measure.push(diff);
            actTime2 = 0;
            lastIndex2 = 0;
          }
        }
        if (elems[3] && lastIndex2 > 0 && elems[3].trim() == 'F12') {
          //if(index - lastIndex == 1){
          fails2++;
          //}
        }
        if (elems[3] && actTime2 == 0) {
          if (elems[3].trim() == 'S12') {
            actTime2 = elems[2] * 1;
            lastIndex2 = index;
          }
        }

      }
    });
    var t = {};
    times.sensor11Measure.map(function(val) {
      var t1 = Math.round((val / 10)) * 10;
      if (t[t1]) {
        t[t1]++
      } else {
        t[t1] = 1;
      }
    });
    console.log("=======================================================");
    console.log('sensor11Measure;');
    sortData(t);
    console.log('Fails: ' + fails + '; ' + Number(Math.round((fails/(times.sensor11Measure.length+fails))*10000)/100).toFixed(2)+'%');
    // t = {};
    var t = {};
    times.sensor12Measure.map(function(val) {
      var t1 = Math.round((val / 10)) * 10;
      if (t[t1]) {
        t[t1]++
      } else {
        t[t1] = 1;
      }
    });
    console.log('sensor12Measure;');
    sortData(t);
    console.log('Fails: ' + fails2 + '; ' + Number(Math.round((fails2/(times.sensor12Measure.length+fails2))*10000)/100).toFixed(2)+'%');
     var t = {};
     times.sensor21Measure.map(function(val) {
       var t1 = Math.round((val / 10)) * 10;
       if (t[t1]) {
         t[t1]++
       } else {
         t[t1] = 1;
       }
     });
     console.log('sensor21Measure;');
     sortData(t);
      console.log('Fails: ' + fails3 + '; ' + Number(Math.round((fails3/(times.sensor21Measure.length+fails3))*10000)/100).toFixed(2)+'%');
  });
}

function sortData(dataIn) {
  var lastElem = 0;
  var t = Object.keys(dataIn).map(function(k) {
    return {
      time: k * 1,
      count: dataIn[k] * 1
    };
  }).sort(function(a, b) {
    return (a.count < b.count?1:-1)
  }).forEach(function (elem){
    if(lastElem != elem.count){
      console.log('time: ' + elem.time + '\tcount: ' + elem.count);
    }
    if(lastElem != elem.count){
      lastElem = elem.count;
    }
  });
}
setInterval(showStats, 1000);
