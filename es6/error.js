function foo(x) {
    if (!x) {
        const err = new Error('Falsy value is not expected');
        console.log('%o', err);
        console.log(err.stack);
        console.log(err.message);
        console.log(err.toString());
        throw err;
    }
}

foo(0);