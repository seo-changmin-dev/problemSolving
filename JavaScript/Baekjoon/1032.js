const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const n = parseInt(input[0]);
const sLen = (input[1].trim()).length;

let ret = '';
for(let i = 0; i < sLen; i++) {
  let isCommon = true;
  for(let j = 2; j <= n; j++) {
    if(input[j-1][i] != input[j][i]) {
      isCommon = false;
      break;
    }
  }

  ret += isCommon ? input[1][i] : '?';
}

console.log(ret);
