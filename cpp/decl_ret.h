typedef int (&x())[10];

typedef auto y() -> int(*)[10];

typedef int intArr[10];
typedef decltype(intArr) *t();

int z[10] = y();

