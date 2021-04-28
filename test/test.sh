#!/bin/bash


san=""
if [ ${@: -1} = "san" ]
then
	san="-fsanitize=address"
fi


# test 1 vec 

if [ $# = 0 ] || [ $1 = "1" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	rm -f a.out ft.bin std.bin
	clang++ tester.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 1 Vector test 1 vvvvvvvv"
	diff ft std

fi

# test 2 dek

if [ $# =  0 ] || [ $1 = "2" ] || [[ $# = 1  &&  $1 = "san" ]]

then
	rm -f a.out ft.bin std.bin
	clang++ tester2.cpp -D DEK -D INT $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester2.cpp -D DEK -D INT $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
			cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi


	echo "vvvvvvvv DIFFF 2 Deque test 1 vvvvvvvv"
	diff ft std

fi


#test 3 stack

if [ $# = 0 ] || [ $1 = "3" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester3.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester3.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 3 Stack test 1 vvvvvvvv"
	diff ft std

fi

#test 4 dek 

if [ $# = 0 ] || [ $1 = "4" ] || [[ $# = 1  &&  $1 = "san" ]]

then
	rm -f a.out ft.bin std.bin
	clang++ tester4.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester4.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 4 Deque test 3 vvvvvvvv"
	diff ft std > diff.out

fi

#test 5 stack

if [ $# = 0 ] || [ $1 = "5" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester5.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester5.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 5 Stack test 2 vvvvvvvv"
	diff ft std

fi

#test 6 set

if [ $# = 0 ] || [ $1 = "6" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester6.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester6.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 6 Set test 1 vvvvvvvv"
	diff ft std

fi

#test 7 set

if [ $# = 0 ] || [ $1 = "7" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester7.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester7.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 7 List test 1 vvvvvvvv"
	diff ft std

fi


#test 8 set

if [ $# = 0 ] || [ $1 = "8" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester8.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester8.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 8 List test 1 vvvvvvvv"
	diff ft std

fi

#test 9 set

if [ $# = 0 ] || [ $1 = "9" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester9.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester9.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 9 List test 1 vvvvvvvv"
	diff ft std

fi

#test 10 set

if [ $# = 0 ] || [ $1 = "10" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester10.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester10.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 10 List test 1 vvvvvvvv"
	diff ft std

fi
