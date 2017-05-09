var fs = require('fs');
var times  = {
  'weakeUpMeasure': []

}
fs.readFile('log-16-03-2017.dat','utf8',function (err,data) {
  if (err) {
    return console.log(err);
  }
  var lines = data.split("\n");
  var lastTime = 0;
  var actTime = 0;
  lines.map(function (line){
    var elems = line.split('|');
    // if(elems[2] && ((elems[2]*1) > 1489077226000) && ((elems[2]*1) < 1489123706052) ){
    //   console.log(line);
      if(actTime > 0  && elems[3] && elems[3].trim() == 'Sensor11SendOk' && elems[2]){
        var diff = elems[2]*1 - actTime;
        times.weakeUpMeasure.push(diff);
        // if(times.weakeUpMeasure[diff]){
        //   times.weakeUpMeasure[diff] = times.weakeUpMeasure[diff] + 1;
        // } else {
        //   times.weakeUpMeasure[diff] = 1;
        // }
        actTime = 0;
      }
      if(elems[3]){
        //console.log(elems[3].trim());
        if(elems[3].trim() == 'Sensor11StartSending'){
          //console.log(elems[2]);
          actTime = elems[2]*1;
        }
      }
    //}
  });
  var min = 10000000000000;
  var max = 0;
  var average = 0;
  var sum = 0;
  var t = {};
  times.weakeUpMeasure.map(function (val){
    if(val < min){
      min = val;
    }
    if(val > max){
      max = val;
    }
    sum = sum + val;
    var t1 = Math.round(val/1000);
    if(t[t1]){
      t[t1]++
    } else {
      t[t1]=1;
    }
  });
  average = sum/times.weakeUpMeasure.length;
  console.log('min: ', min);
  console.log('max: ', max);
  console.log('average: ', average);
  console.log(t);
});