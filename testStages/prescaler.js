var presc = [0, 1, 8, 64, 256, 1024, 3333];
var F_CPU = 16000000;
var speed = 2400;
var i = 1;
function test(){
	for(i=1; i < 7; i++){
		inv_clock_time = F_CPU / presc[i];
		inv_bit_time = speed * 8;
		ulticks = inv_clock_time / inv_bit_time;
		console.log(ulticks);
		if(ulticks > 1 && ulticks < 65535){
			return true;
		}
	}
}
if(test()){
	console.log(presc[i], i, ulticks);
}