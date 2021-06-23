#ifndef IS_TYPE
#define IS_TYPE

namespace ft
{

	struct __true_type { };
	struct __false_type { };

	// Integer types
	//
	template<typename _Tp>
		struct __is_integer
		{
			enum { __value = 0 };
			typedef __false_type __type;
		};

	// Thirteen specializations (yes there are eleven standard integer
	// types; 'long long' and 'unsigned long long' are supported as
	// extensions)
	template<>
		struct __is_integer<bool>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<char>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<signed char>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<unsigned char>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<wchar_t>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<short>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<unsigned short>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<int>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<unsigned int>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<long>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<unsigned long>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<long long>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};

	template<>
		struct __is_integer<unsigned long long>
		{
			enum { __value = 1 };
			typedef __true_type __type;
		};
}
#endif
