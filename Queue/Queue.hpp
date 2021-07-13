#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "../DeQue/Deque.hpp"

namespace ft
{
	template <class T, class Container = deque<T, std:: allocator<T> > >
		class queue
		{
			public:
				typedef T			value_type;
				typedef Container	container_type;
				typedef size_t		size_type;

				explicit queue( const container_type & ctnr = container_type())	{
					container = ctnr;
				}

				bool empty() const {
					return (container.empty());
				}

				size_type size() const {
					return (container.size());
				}

				value_type & front() {
					return (container.front());
				}

				value_type & back() {
					return (container.back());
				}

				const value_type & front() const {
					return (container.front());
				}

				const value_type & back() const {
					return (container.back());
				}

				void push(const value_type & val) {
					container.push_back(val);
				}

				void pop() {
					container.pop_front();
				}

			private:
				container_type container;

				friend bool operator== (const queue<T, Container> & lhs, const queue<T, Container> & rhs) {
					return (operator==(lhs.container, rhs.container));
				}
				friend bool operator<  (const queue<T, Container> & lhs, const queue<T, Container> & rhs) {
					return (operator<(lhs.container, rhs.container));
				}
		};

	//non member relationnal operators
		template <class T, class Container>
	bool operator!= (const queue<T, Container> & lhs, const queue<T, Container> & rhs) {
		return (!operator==(lhs, rhs));
	}
	template <class T, class Container>
		bool operator<= (const queue<T, Container> & lhs, const queue<T, Container> & rhs) {
			return (operator==(lhs, rhs) || operator<(lhs, rhs));
		}
	template <class T, class Container>
		bool operator>  (const queue<T, Container> & lhs, const queue<T, Container> & rhs) {
			return (!operator==(lhs, rhs) && !operator<(lhs, rhs));
		}
	template <class T, class Container>
		bool operator>= (const queue<T, Container> & lhs, const queue<T, Container> & rhs) {
			return (operator==(lhs, rhs) || operator>(lhs, rhs));
		}

}
#endif
