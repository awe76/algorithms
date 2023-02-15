const a = [];

a[0] = 2;
a["0"] = 3;

a["foo"] = 5;

const s = a.join('-');

console.log(a[0]);
console.log(s);
