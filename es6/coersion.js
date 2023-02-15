console.log({} + []);
console.log([] + {});

function onlyOne(...args) {
    return args.reduce((sum, val) => val ? sum + val : sum, 0) == 1;
}

const a = false;
const b = true;
const c = true;

console.log(onlyOne(a, b, c)); // false

const d = false;

console.log(onlyOne(a, b, d)); // true

console.log(Object.is('' + 0, '0'));
console.log(Object.is(0 + '', '0'));

console.log("" == false);
