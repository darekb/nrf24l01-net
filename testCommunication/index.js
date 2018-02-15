var Q = require("q");
var rp = require('request-promise');
var fs = require('fs');
var config = require('./config.js');
var SerialPort = require("serialport");
//'log-10-05-2017-test01.dat'
var _sockedLog = fs.createWriteStream(config.filename, {
			'flags': 'a'
		});
var _sockedErrorLog = fs.createWriteStream('error.dat', {
			'flags': 'a'
		});
var sensor21 = new SerialPort('/dev/ttyUSB0', {
				baudrate: 38400,
				parser: SerialPort.parsers.readline('\n')
});
sensor21.on('open', function (error) {
				if (error) {
				  _sockedLog.write(new Date() + ' SensorRecivier: SerialPort: Failed to open serial port: /dev/ttyUSB0 ' + error + '\n');
				} else {
				_sockedLog.write('index.js [' + new Date() + '] SerialPort: Open serial port: /dev/ttyUSB0\n');
				}
			});
sensor21.on('data', function(dataIn){
	_sockedLog.write('sensor21|' + new Date() + '|' + new Date().getTime() + '|' + ' ' + dataIn + '\n');
});
// var server = new SerialPort('/dev/ttyUSB1', {
// 				baudrate: 38400,
// 				parser: SerialPort.parsers.readline('\n')
// });
// server.on('open', function (error) {
// 				if (error) {
// 				  _sockedLog.write(new Date() + ' SensorRecivier: SerialPort: Failed to open serial port: /dev/ttyUSB1 ' + error + '\n');
// 				} else {
// 				_sockedLog.write('index.js [' + new Date() + '] SerialPort: Open serial port: /dev/ttyUSB1\n');
// 				}
// 			});
// server.on('data', function(dataIn){
// 	_sockedLog.write('server  |' + new Date() + '|' + new Date().getTime() + '|' + ' ' + dataIn + '\n');
// });
