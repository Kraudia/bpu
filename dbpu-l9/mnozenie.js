var defaultSize = parseInt(process.argv[2]) || 500;
var matrixA = new Array(defaultSize),
	matrixB = new Array(defaultSize),
	matrixC = new Array(defaultSize);

for(var i = 0; i < defaultSize; i++) {
	matrixA[i] = new Array();
	matrixB[i] = new Array();
	matrixC[i] = new Array();
}

function getRandomNumber(min, max){
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function fillMatrices () {
	for(var i = 0; i < defaultSize; i++) {
		for(var j = 0; j < defaultSize; j++) {
			matrixA[i][j] = getRandomNumber(0, 50); 
			matrixB[i][j] = getRandomNumber(0, 50);
			matrixC[i][j] = 0;
		}
	}
}

function multiplyMatrices () {
	for(var i = 0; i < defaultSize; i++) {
		for(var j = 0; j < defaultSize; j++) {
			for(var k = 0; k < defaultSize; k++) {
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}

var startTime = new Date().getTime();

fillMatrices();
multiplyMatrices();

var endTime = new Date().getTime();
var executionTime = endTime - startTime;
console.log('Execution time: ', executionTime/1000, 'seconds');

// To print results
//console.table ? console.table(matrixC) : console.log(matrixC);
