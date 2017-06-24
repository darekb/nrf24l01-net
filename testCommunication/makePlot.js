var fs = require('fs');
var config = require('./config.js');
function makePlot() {
	var m = {
		sensor11: [],
		sensor21: []
	}
	var f = {
		sensor11: [],
		sensor21: [],
		sensor12: []
	}
	fs.readFile(config.filename, 'utf8', function (err, data) {
		if (err) {
			return console.log(err);
		}
		var lines = data.split("\n");
		lines.map(function (line, index) {
			var t1 = line.split('|');
			if (t1.length > 12 && t1[2] * 1 > 1493069919454) {
				var tmp = line.split('(CEST)');
				var e = tmp[1].split(' ')[1].split('~');

				e.map(function (elem) {
					var t = elem.trim().split('|');
					if (t.length > 4) {
						if (!(t[0] == t[1] && t[1] == t[2])) {
							m['sensor' + t[4].trim()].push({
								time: t1[2] * 1,
								t: t[0] / 100,
								h: t[1] / 100,
								p: t[2] / 100 + 1000,
								v: t[3] / 100
							});
						} else {
							f['sensor' + t[4].trim()].push({
								time: t1[2] * 1,
								t: 0,
								h: 0,
								p: 0,
								v: 0
							});
						}
					}
				});


			}
		});
		var out = '';
		out = out + ('<!DOCTYPE html><html><head>    <meta charset="utf-8">    <meta http-equiv="X-UA-Compatible" content="IE=edge">    <title></title>    <link rel="stylesheet" href=""><meta http-equiv="refresh" content="5" /></head><body><h2>Sensor11 (green) Sensor21 (blue) temperature</h2>');
		makeSvg.reset();
		out = out + ('<svg xmlns="http://www.w3.org/2000/svg" version="1.1" viewBox="0 0 600 100"  >');
		makeSvg.calculateXY(m.sensor11, 't');
		makeSvg.calculateXY(m.sensor21, 't');
		out = out + makeSvg.getPointsFail(f.sensor11,'t');
		out = out + makeSvg.getPointsFail(f.sensor21,'t');
		out = out + (makeSvg.xAxis());
		out = out + (makeSvg.yAxis());
		out = out + ('<path d="' + makeSvg.getLines(m.sensor21, 't') + '" style="fill:none; stroke:rgba(0,0,255,0.6); stroke-width:1px;"></path>');
		out = out + ('<path d="' + makeSvg.getLines(m.sensor11, 't') + '" style="fill:none; stroke:rgba(0,255,0,0.6); stroke-width:1px;"></path>');
		out = out + (makeSvg.xAxisDescription());
		out = out + (makeSvg.yAxisDescription());
		out = out + ('</svg>');
		out = out + ('<h2>Sensor11 (green) Sensor21 (blue) humidity</h2>');
		makeSvg.reset();
		out = out + ('<svg xmlns="http://www.w3.org/2000/svg" version="1.1" viewBox="0 0 600 100"  >');
		makeSvg.calculateXY(m.sensor11, 'h');
		makeSvg.calculateXY(m.sensor21, 'h');
		out = out + (makeSvg.xAxis());
		out = out + (makeSvg.yAxis());
		out = out + ('<path d="' + makeSvg.getLines(m.sensor21, 'h') + '" style="fill:none; stroke:rgba(0,0,255,0.6); stroke-width:1px;"></path>');
		out = out + ('<path d="' + makeSvg.getLines(m.sensor11, 'h') + '" style="fill:none; stroke:rgba(0,255,0,0.6); stroke-width:1px;"></path>');
		out = out + (makeSvg.xAxisDescription());
		out = out + (makeSvg.yAxisDescription());
		out = out + ('</svg>');
		makeSvg.reset();
		out = out + ('<h2>Sensor11 (green) Sensor21 (blue) pressure</h2>');
		out = out + ('<svg xmlns="http://www.w3.org/2000/svg" version="1.1" viewBox="0 0 600 100"  >');
		makeSvg.calculateXY(m.sensor11, 'p');
		makeSvg.calculateXY(m.sensor21, 'p');
		out = out + (makeSvg.xAxis());
		out = out + (makeSvg.yAxis());
		out = out + ('<path d="' + makeSvg.getLines(m.sensor21, 'p') + '" style="fill:none; stroke:rgba(0,0,255,0.6); stroke-width:1px;"></path>');
		out = out + ('<path d="' + makeSvg.getLines(m.sensor11, 'p') + '" style="fill:none; stroke:rgba(0,255,0,0.6); stroke-width:1px;"></path>');
		out = out + (makeSvg.xAxisDescription());
		out = out + (makeSvg.yAxisDescription());
		out = out + ('</svg>');
		makeSvg.reset();
		out = out + ('<h2>Sensor11 (green) Sensor21 (blue) voltage</h2>');
		out = out + ('<svg xmlns="http://www.w3.org/2000/svg" version="1.1" viewBox="0 0 600 100"  >');
		makeSvg.calculateXY(m.sensor11, 'v');
		makeSvg.calculateXY(m.sensor21, 'v');
		out = out + (makeSvg.xAxis());
		out = out + (makeSvg.yAxis());
		out = out + ('<path d="' + makeSvg.getLines(m.sensor21, 'v') + '" style="fill:none; stroke:rgba(0,0,255,0.6); stroke-width:1px;"></path>');
		out = out + ('<path d="' + makeSvg.getLines(m.sensor11, 'v') + '" style="fill:none; stroke:rgba(0,255,0,0.6); stroke-width:1px;"></path>');
		out = out + (makeSvg.xAxisDescription());
		out = out + (makeSvg.yAxisDescription());
		out = out + ('</svg>');
		out = out + ('</body></html>');
		var buffer = new Buffer(out);
		fs.open(config.filename.replace(/dat/, 'html'), 'w', function (err, fd) {
			if (err) {
				console.log('error opening file: ' + err);
			}

			fs.write(fd, buffer, 0, buffer.length, null, function (err) {
				if (err) {
					console.log('error writing file: ' + err);
				}
				fs.close(fd, function () {
					console.log('file written');
				})
			});
		});
	});
}
var makeSvg = (function () {
	var yMinMax;
	var xMinMax;
	var plotHeight;
	var plotWidth;
	return {
		getLines: getLinePoints,
		calculateXY: calculateXY,
		reset: reset,
		xAxis: xAxis,
		xAxisDescription: xAxisDescription,
		yAxis: yAxis,
		yAxisDescription: yAxisDescription,
		getPointsFail: getPointsFail
	};
	function getLinePoints(chartData, forWhat) {
		var pointsTxt = ''; //'M0,100 ';
		var i = 0;
		var out = {};
		var pointsArray = chartData.reduce(function (all, elem) {
			all.push(elem[forWhat]);
			return all;
		}, []);
		var timestampArray = chartData.reduce(function (all, elem) {
			all.push(elem.time);
			return all;
		}, []);
		// if(resetScale){
		//   yMinMax = returnMinMax(pointsArray);
		//   xMinMax = returnMinMax(timestampArray);
		// }
		for (var k in pointsArray) {
			//console.log(returnProperX(timestampArray[k]), returnProperY(pointsArray[k]));
			if (!out[returnProperX(timestampArray[k])]) {
				out[returnProperX(timestampArray[k])] = [];
			}
			out[returnProperX(timestampArray[k])].push(plotHeight - returnProperY(pointsArray[k]));
		}
		for (var k in out) {
			var y = 0;
			var v = out[k];
			//console.log(k, v);
			//   if(v.length > 1){
			//     var t = returnMinMax(v, {
			//   min: 1000000000000000000,
			//   delta: 10000000000000,
			//   max: 0
			// });
			//     pointsTxt = pointsTxt + (i > 0 ? ' L' : 'M') + k + ',' + t['min'];
			//     pointsTxt = pointsTxt +  ' L' + k + ',' + t['max'];
			//   } else {
			pointsTxt = pointsTxt + (i > 0 ? ' L' : 'M') + k + ',' + v[0];
			//}
			i = i + 1;
		}
		;
		return pointsTxt;
	}

	function getPointsFail(dataIn, forWhat) {
		var pointsTxt = '';
		var i = 0;
		var pointsArray = [];
		var timestampArray = [];
		dataIn.forEach(function (elem){
			pointsArray.push(elem[forWhat]);
			timestampArray.push(elem['added_timestamp'] / 1000);
		});
		var out = [];
		var minY = yMinMax.min;
		pointsArray.forEach(function (elem, index){
			var x = returnProperX(timestampArray[index], xMinMax);
			out[x] = [];
			out[x].push(plotHeight - returnProperY(minY, yMinMax));
		});
		out.forEach(function (elem, index){
			pointsTxt = pointsTxt + '<circle cx="'+index+'" cy="'+(plotHeight - dataIn[0]['sensor_id'])+'" r="1" fill="red" />';
		});
		return pointsTxt;
	}

	function xAxis() {
		var out = '';
		var steps = 10;
		var step = plotWidth / steps;
		for (i = 0; i < steps + 1; i++) {
			out = out + '<line x1="' + step * i + '"  y1="0" x2="' + step * i + '"   y2="' + plotHeight + '" style="stroke:#ff0000; stroke-width:0.1px"/>';
		}
		return out;
	}

	function yAxis() {
		var out = '';
		var steps = 5;
		var step = plotHeight / steps;
		for (i = 0; i < steps + 1; i++) {
			out = out + '<line y1="' + step * i + '"  x1="0" y2="' + step * i + '"   x2="' + plotWidth + '" style="stroke:#ff0000; stroke-width:0.1px"/>';
		}
		return out;
	}

	function xAxisDescription() {
		var out = '';
		var steps = 10;
		var step = xMinMax.delta / steps;
		var step2 = plotWidth / steps;
		for (i = 0; i < steps + 1; i++) {
			var xVal = new Date(xMinMax.min + (step * i)).toString().split(' ');
			out = out + '<text x="' + step2 * i + '" y="6" style="font-size: 6px;">' + xVal[4] + '</text>';
		}
		return out;
	}

	function yAxis() {
		var out = '';
		var steps = 5;
		var step = plotHeight / steps;
		for (i = 0; i < steps + 1; i++) {
			out = out + '<line y1="' + step * i + '"  x1="0" y2="' + step * i + '"   x2="' + plotWidth + '" style="stroke:#ff0000; stroke-width:0.1px"/>';
		}
		return out;
	}

	function yAxisDescription() {
		var out = '';
		var steps = 5;
		var step = yMinMax.delta / steps;
		var step2 = plotHeight / steps;
		for (i = 0; i < steps + 1; i++) {
			var yVal = yMinMax.min + (step * i);
			out = out + '<text y="' + (plotHeight - step2 * i) + '" x="0" style="font-size: 6px;">' + Math.round(yVal * 100) / 100 + '</text>';
		}
		return out;
	}

	function calculateXY(chartData, forWhat) {
		var pointsArray = chartData.reduce(function (all, elem) {
			all.push(elem[forWhat]);
			return all;
		}, []);
		var timestampArray = chartData.reduce(function (all, elem) {
			all.push(elem.time);
			return all;
		}, []);
		yMinMax = returnMinMax(pointsArray, yMinMax);
		xMinMax = returnMinMax(timestampArray, xMinMax);
		//console.log(yMinMax, xMinMax);
	}

	function reset() {
		yMinMax = {
			min: 1000000000000000000,
			delta: 10000000000000,
			max: 0
		}
		xMinMax = {
			min: 1000000000000000000,
			delta: 10000000000000,
			max: 0
		}
		plotHeight = 100;
		plotWidth = 600;
	}

	function returnMinMax(dataIn, initData) {
		var out = initData;
		dataIn.forEach(function (elem) {
			if (elem > out.max) {
				out.max = elem;
			}
			if (elem < out.min) {
				out.min = elem;
			}
		});
		out.delta = Math.abs(out.max - out.min);
		return out;
	}

	function returnProperY(y) {
		return Math.round(((y - yMinMax.min) * (plotHeight - 20) / yMinMax.delta) + 10);
	}

	function returnProperX(x) {
		return Math.round(((x - xMinMax.min) * plotWidth / xMinMax.delta));
	}
}());
setInterval(makePlot, 10000);
//makePlot();
