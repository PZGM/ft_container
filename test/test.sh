#!/bin/bash


san=""
if [ ${@: -1} = "san" ]
then
	san="-fsanitize=address"
fi

if [ $# = 0 ] || [ $1 = "1" ] || [[ $# = 1  &&  $1 = "san" ]]
then

	rm -f a.out ft.bin std.bin
	c++ tester1.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester1.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 01 Set test 1 vvvvvvvv"
	diff ft std

fi

if [ $# =  0 ] || [ $1 = "2" ] || [[ $# = 1  &&  $1 = "san" ]]

then
	rm -f a.out ft.bin std.bin
	c++ tester2.cpp -D DEK -D INT $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester2.cpp -D DEK -D INT $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
			cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi


	echo "vvvvvvvv DIFFF 02 Set test 2 vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "3" ] || [[ $# = 1  &&  $1 = "san" ]]

then

	rm -f a.out ft.bin std.bin
	c++ tester3.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester3.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 03 Set test 3  vvvvvvvv"
	diff ft std

fi

if [ $# = 0 ] || [ $1 = "4" ] || [[ $# = 1  &&  $1 = "san" ]]

then
	rm -f a.out ft.bin std.bin
	c++ tester4.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester4.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester5.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester5.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester6.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester6.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester7.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester7.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester8.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester8.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester9.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester9.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester10.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester10.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester11.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester11.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester12.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester12.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester13.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester13.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester14.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester14.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester15.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester15.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester16.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester16.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester17.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester17.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester18.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester18.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester19.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester19.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester20.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester20.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester21.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester21.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester22.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester22.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester23.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester23.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester24.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester24.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester25.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester25.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

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
	c++ tester26.cpp $san -g3 -O0 -D FT -o ft.bin ; ./ft.bin > ft
	c++ tester26.cpp $san -g3 -O0 -D STD -o std.bin; ./std.bin > std

	if [[ $2 = "ft" || $2 = "all" ]];then
		cat ft
	fi
	if [[ $2 = "std" || $2 = "all" ]];then
		cat std
	fi

	echo "vvvvvvvv DIFFF 26 DeQue test 5 vvvvvvvv"
	diff ft std

fi
