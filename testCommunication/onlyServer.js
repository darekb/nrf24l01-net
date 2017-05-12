var Q = require("q");
var rp = require('request-promise');
var fs = require('fs');
var SerialPort = require("serialport");
var config = require('./config.js');
var _sockedLog = fs.createWriteStream(config.filename, {
			'flags': 'a'
		});
var _sockedErrorLog = fs.createWriteStream('error.dat', {
			'flags': 'a'
		});
//var sensor11 = new SerialPort('/dev/ttyUSB0', {
//				baudrate: 38400,
//				parser: SerialPort.parsers.readline('\n')
//});
//sensor11.on('open', function (error) {
//				if (error) {
//				  _sockedLog.write(new Date() + ' SensorRecivier: SerialPort: Failed to open serial port: /dev/ttyUSB0 ' + error + '\n');
//				} else {
//				_sockedLog.write('index.js [' + new Date() + '] SerialPort: Open serial port: /dev/ttyUSB0\n');
//				}
//			});
//sensor11.on('data', function(dataIn){
//	_sockedLog.write('sensor11|' + new Date() + '|' + new Date().getTime() + '|' + ' ' + dataIn + '\n');
//});
var server = new SerialPort('/dev/ttyUSB0', {
				baudrate: 115200,
				parser: SerialPort.parsers.readline('\n')
});
server.on('open', function (error) {
				if (error) {
				  _sockedLog.write(new Date() + ' SensorRecivier: SerialPort: Failed to open serial port: /dev/ttyUSB1 ' + error + '\n');
				} else {
				_sockedLog.write('index.js [' + new Date() + '] SerialPort: Open serial port: /dev/ttyUSB1\n');
				}
			});
server.on('data', function(dataIn){
	_sockedLog.write('server  |' + new Date() + '|' + new Date().getTime() + '|' + ' ' + dataIn + '\n');
});
