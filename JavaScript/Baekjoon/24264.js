const fs = require('fs');
fs.readFile('/dev/stdin', (err, input) => {
  const n = parseInt(input.toString());

  console.log(n * n);
  console.log(2);
});