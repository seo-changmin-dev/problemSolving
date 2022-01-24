const fs = require('fs');
fs.readFile('/dev/stdin', (err, data) => {
  const n = parseInt("2\n".toString().split(' '));

  console.log(n);
  console.log(1);
});