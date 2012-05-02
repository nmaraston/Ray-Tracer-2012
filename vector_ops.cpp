
// Implementation of all vector operations.

/*
 * Vector eqaulity.
 */
template <class T>
bool operator==(const vector<T> &v, const vector<T> &w)
{
	if (v.size() != w.size()) {
		return false;
	}

	for (int i = 0; i < v.size(); ++i) {
		if (v(i) != w(i)) {
			return false;
		}
	}	

	return true;
}
		

/*
 * Scalar multiplication.
 */
template <class T>
vector<T> operator*(T s, const vector<T> &v)
{
	vector<T> result(v.size());
	
	for (int i = 0; i < v.size(); ++i) {
		result(i) = s * v(i);
	}
	
	return result;
}

// For commutivity.
template <class T>
vector<T> operator*(const vector<T> &v, T s)
{
	return s * v;
}


/*
 * Scalar division.
 */
template <class T>
vector<T> operator/(const vector<T> &v, T s)
{
	if (s == 0) {
		// TODO: Throw invalid argument exception.
 	}	

	vector<T> result(v.size());
	
	for (int i = 0; i < v.size(); ++i) {
		result(i) = v(i) / s;
	}
	
	return result;
}


/*
 * Vector addition.
 */
template <class T>
vector<T> operator+(const vector<T> &v, const vector<T> &w)
{
	if (v.size() != w.size()) {
		// TODO: Throw invalid argument exception.
	}	

	vector<T> result(v.size());
	
	for (int i = 0; i < v.size(); ++i) {
		result(i) = v(i) + w(i);
	}
	
	return result;
}


/*
 * Vector subtraction.
 */
template <class T>
vector<T> operator-(const vector<T> &v, const vector<T> &w)
{
	if (v.size() != w.size()) {
		// TODO: Throw invalid argument exception.
	}	

	vector<T> result(v.size());
	
	for (int i = 0; i < v.size(); ++i) {
		result(i) = v(i) - w(i);
	}
	
	return result;
}


/*
 * Accumulated vector addition.
 */
template <class T>
vector<T>& operator+=(const vector<T> &v, const vector<T> &w)
{
	if (v.size() != w.size()) {
		// TODO: Throw invalid argument exception.
	}	
	
	for (int i = 0; i < v.size(); ++i) {
		v(i) += w(i);
	}

	return v;
}
	

/*
 * Accumulated vector subtraction.
 */
template <class T>
vector<T>& operator-=(const vector<T> &v, const vector<T> &w)
{
	if (v.size() != w.size()) {
		// TODO: Throw invalid argument exception.
	}	

	for (int i = 0; i < v.size(); ++i) {
		v(i) -= w(i);
	}

	return v;
}


/*
 * Standard dot product.
 */
template <class T>
T dot_product(const vector<T> &v, const vector<T> &w)
{
	if (v.size() != w.size()) {
		// TODO: Throw invalid argument exception.
	}	

	T result = 0;

	for (int i = 0; i < v.size(); ++i) {
		result += v(i) * w(i);
	}
	
	return result;
}

