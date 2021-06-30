#!/bin/bash


san=""
if [ ${@: -1} = "san" ]
then
	san="-fsanitize=address"
fi


# test 1 set

if [ $# = 0 ] || [ $1 = "1" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	rm -f a.out ft.bin std.bin
	clang++ tester1.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester1.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 01 Set test 1 vvvvvvvv"
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


	echo "vvvvvvvv DIFFF 02 Deque test 1 vvvvvvvv"
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

	echo "vvvvvvvv DIFFF 03 Stack test 1 vvvvvvvv"
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

	echo "vvvvvvvv DIFFF 04 Deque test 3 vvvvvvvv"
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

	echo "vvvvvvvv DIFFF 05 Stack test 2 vvvvvvvv"
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

	echo "vvvvvvvv DIFFF 06 Set test 1 vvvvvvvv"
	diff ft std

fi

#test 7 set

if [ $# = 0 ] || [ $1 = "7" ] || [ $1 = "list" ] || [[ $# = 1  &&  $1 = "san" ]]

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

	echo "vvvvvvvv DIFFF 07 List test 1 vvvvvvvv"
	diff ft std

fi


#test 8 set

if [ $# = 0 ] || [ $1 = "8" ] || [ $1 = "list" ] || [[ $# = 1  &&  $1 = "san" ]]

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

	echo "vvvvvvvv DIFFF 08 List test 2 vvvvvvvv"
	diff ft std

fi

#test 9 set

if [ $# = 0 ] || [ $1 = "9" ] || [ $1 = "list" ] || [[ $# = 1  &&  $1 = "san" ]]

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

	echo "vvvvvvvv DIFFF 09 List test 3 vvvvvvvv"
	diff ft std

fi

#test 10 set

if [ $# = 0 ] || [ $1 = "10" ] || [ $1 = "list" ] || [[ $# = 1  &&  $1 = "san" ]]

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

	echo "vvvvvvvv DIFFF 10 List test 4 vvvvvvvv"
	diff ft std

fi

#test 11 set

if [ $# = 0 ] || [ $1 = "11" ] || [ $1 = "list" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester11.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester11.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 11 List test 5 vvvvvvvv"
	diff ft std

fi

#test 12 set

if [ $# = 0 ] || [ $1 = "12" ] || [ $1 = "list" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester12.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester12.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 12 List test 6 vvvvvvvv"
	diff ft std

fi

#test 13 set

if [ $# = 0 ] || [ $1 = "13" ] || [ $1 = "list" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester13.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester13.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 13 List test 7 vvvvvvvv"
	diff ft std

fi

#test 14 set

if [ $# = 0 ] || [ $1 = "14" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester14.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester14.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 14 Vector test 1 vvvvvvvv"
	diff ft std

fi

#test 15 set

if [ $# = 0 ] || [ $1 = "15" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester15.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester15.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 15 Vector test 2 vvvvvvvv"
	diff ft std

fi

#test 16 set

if [ $# = 0 ] || [ $1 = "16" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester16.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester16.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 16 Vector test 3 vvvvvvvv"
	diff ft std

fi

#test 17 set

if [ $# = 0 ] || [ $1 = "17" ] || [ $1 = "vector" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester17.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester17.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 17 Vector test 4 vvvvvvvv"
	diff ft std

fi

#test 18 set

if [ $# = 0 ] || [ $1 = "18" ] || [ $1 = "stack" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester18.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester18.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 18 Stack test 1 vvvvvvvv"
	diff ft std

fi

#test 19 set

if [ $# = 0 ] || [ $1 = "19" ] || [ $1 = "stack" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester19.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester19.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 19 Stack test 2 vvvvvvvv"
	diff ft std

fi

#test 20 set

if [ $# = 0 ] || [ $1 = "20" ] || [ $1 = "queue" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester20.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester20.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 20 Queue test 1 vvvvvvvv"
	diff ft std

fi

#test 21 set

if [ $# = 0 ] || [ $1 = "21" ] || [ $1 = "queue" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester21.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester21.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 21 Queue test 2 vvvvvvvv"
	diff ft std

fi

#test 22 set

if [ $# = 0 ] || [ $1 = "22" ] || [ $1 = "deque" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester22.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester22.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 22 DeQue test 1 vvvvvvvv"
	diff ft std

fi

#test 23 set

if [ $# = 0 ] || [ $1 = "23" ] || [ $1 = "deque" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester23.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester23.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 23 DeQue test 2 vvvvvvvv"
	diff ft std

fi

#test 24 set

if [ $# = 0 ] || [ $1 = "24" ] || [ $1 = "deque" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester24.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester24.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 24 DeQue test 3 vvvvvvvv"
	diff ft std

fi

#test 25 set

if [ $# = 0 ] || [ $1 = "25" ] || [ $1 = "deque" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester25.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester25.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 25 DeQue test 4 vvvvvvvv"
	diff ft std

fi

#test 26 set

if [ $# = 0 ] || [ $1 = "26" ] || [ $1 = "deque" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	clang++ tester26.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	clang++ tester26.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 26 DeQue test 5 vvvvvvvv"
	diff ft std

fi
