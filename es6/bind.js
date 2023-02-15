Function.prototype.myBind = function(that) {
    const f = this;

    return function(...args) {
        return f.call(that, ...args);
    };
}

function add(val) {
    return this + val;
}

const plus7 = add.myBind(7);
const res = plus7(45); // 52

console.log(res);