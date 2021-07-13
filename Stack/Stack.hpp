#ifndef STACK_HPP
# define STACK_HPP

#include "../DeQue/Deque.hpp"

namespace ft
{
	template <class T, class Container = deque<T, std:: allocator<T> > >
		class stack
		{
			public:
				typedef T			value_type;
				typedef Container	container_type;
				typedef size_t		size_type;

				explicit stack( const container_type & ctnr = container_type())	{
					container = ctnr;
				}

				bool empty() const {
					return (container.empty());
				}

				size_type size() const {
					return (container.size());
				}

				value_type & top() {
					return (container.back());
				}

				const value_type & top() const {
					return (container.back());
				}

				void push(const value_type & val) {
					container.push_back(val);
				}

				void pop() {
					container.pop_back();
				}

			private:
				container_type container;

				friend bool operator== (const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
					return (operator==(lhs.container, rhs.container));
				}
				friend bool operator<  (const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
					return (operator<(lhs.container, rhs.container));
				}
		};

	//non member relationnal operators
		template <class T, class Container>
	bool operator!= (const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
		return (!operator==(lhs, rhs));
	}
	template <class T, class Container>
		bool operator<= (const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return (operator==(lhs, rhs) || operator<(lhs, rhs));
		}
	template <class T, class Container>
		bool operator>  (const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return (!operator==(lhs, rhs) && !operator<(lhs, rhs));
		}
	template <class T, class Container>
		bool operator>= (const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return (operator==(lhs, rhs) || operator>(lhs, rhs));
		}

}
#endif
