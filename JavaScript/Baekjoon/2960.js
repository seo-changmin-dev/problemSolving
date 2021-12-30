let fs = require("fs");
let input = fs.readFileSync('dev/stdin').toString().split(' ');

const [N, K] = input.map(e => parseInt(e));

let nums = [];
let sieved = [];
for(i = 0; i <= N; i++) {
  nums.push(i);
  sieved.push(false);
}

let cnt = 0;
for(i = 2; i <= N; i++) {
  if(sieved[i]) continue;

  for(j = 1; i*j <= N; j++) {
    if(sieved[i*j]) continue;

    sieved[i*j] = true;
    cnt++;

    if(cnt === K) {
      console.log(i*j);
      return;
    }
  }
}