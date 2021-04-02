#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

template <typename T>
class ReverseIterator : public T
{
	public:
		ReverseIterator(void) : T() {}
		ReverseIterator(typename T::node_pointer & node) : T(node) {}
		ReverseIterator(ReverseIterator const & rhs) : T(rhs) {}
		~ReverseIterator() {}

		ReverseIterator &operator=(const ReverseIterator & rhs) {
			this->node = rhs.node;
			return (*this);
		}

		typename T::value_type operator*() {
			return (node->getValue());
		}

		T &operator++() {
			return (T::operator--());
		}

		T &operator++(int) {
			return (T::operator--());
		}

		T &operator--() {
			return (T::operator++());
		}

		T &operator--(int) {
			return (T::operator++());
		}

	private:
		int *node = 0;
};

#endif
