function mult(initVal) {
    let result = initVal ?? 1;
    function run(val) {
        result *= val;
        run.result = result;
        return run;
    }

    return run;
}

const y = mult(5)(10)(21).result;
console.log(y);