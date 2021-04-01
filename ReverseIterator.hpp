#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

template <typename T>
class ReverseIterator : public T
{
	public:
		ReverseIterator(void) : T() {}
		ReverseIterator(T::src_pointer &src) : T(src) {}
		ReverseIterator(ReverseIterator const & rhs) : T(rhs) {}
		~ReverseIterator() {}

	public:
		ReverseIterator &operator=(const ReverseIterator & rhs) {
			this->src = rhs.src;
			return (*this);
		}

		T::value_type operator*() {
			return (src->getValue());
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
};

#endif
