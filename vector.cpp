// Vector class implementation.

/*
 * Constructor.
 * Allocates memory for a vector of the given size and zeros out memory (zero vector).
 */
template <class T>
vector<T>::vector(unsigned size)
	: size_(size), components_(0)
{
	size_ = size;
	if (size_) {
		alloc_components();
		for (int i = 0; i < size_; ++i) {
			(*this)(i) = 0;
		}
	}
}


/*
 * Copy constructor.
 */
template <class T>
vector<T>::vector(const vector<T> &v)
{
	deep_copy(v);
} 


/*
 * Destructor.
 */
template <class T>
vector<T>::~vector()
{
	free_components();
}


/*
 * Assignment operator.
 */
template <class T>
vector<T>& vector<T>::operator=(const vector<T> &v)
{
	deep_copy(v);
	return *this;
}


/*
 * Copies another vectors components into this one. Used in the copy constructor and assignment
 * operator overload.
 */
template <class T>
void vector<T>::deep_copy(const vector<T> &v)
{
	this->size_ = v.size_;
	if (v.components_) {
	 	alloc_components();
		for (int i = 0; i < size_; ++i) {
			(*this)(i) = v(i);
		}
	}
}
