#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T, class Y>
	class pair
	{
		public:
				T first;
				Y second;

				pair() {
					first = T();
					second = Y();
				}

				pair(const T & a, const Y & b) : first(a), second(b) {
				}

				pair(const pair & src) : first(src.first), second(src.second){
				}

				virtual	~pair() {}

				pair &	operator=(const pair & rhs) {
					first = rhs.first;
					second = rhs.second;
					return *this;
				}
		private:
	};
}
#endif
