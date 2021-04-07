#!/bin/sh

rm -f a.out
clang++ tester.cpp Vector/Vector.cpp -g3 -O0 -D FT ; ./a.out > ft
cat ft
rm -f a.out
clang++ tester.cpp Vector/Vector.cpp -g3 -O0 -D STD; ./a.out > std
cat std

echo "vvvvvvvv DIFFF vvvvvvvv"
diff ft std

