#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
using namespace std;

class Record {
public:
	int data;
};

template <class T>
class Array {
private:
	T* ar;
	int arraySize;
	int startArraySize = 1;
	int numberOfRecords;
	int resizeCoefficent = 2;

public:
	Array();
	void resize(const Array&);
	~Array();
	const Array operator=(const Array&);
};
template <class T>
Array<T>::Array() {
	arraySize = startArraySize;
	ar = new T[arraySize];
	ar->data = 0;
}

template <class T>
void Array<T>::resize(const Array& obj) {
	arraySize = obj.arraySize * resizeCoefficent;
	*ar = new T[arraySize];
	for (int i = 0; i < arraySize; i++) {
		if (i < obj.arraySize) {
			ar[i].data = obj.ar[i].data;
		}
		else
		{
			ar[i].data = 0;
		}
	}
}

template <class T>
const Array<T> Array<T>::operator=(const Array& right) {
	if (this != right) {
		delete[] ar;
		arraySize = right.arraySize;
		ar = new T[arraySize];
		for (int i = 0; i < arraySize; i++) {
			(ar->data + i) = (right.ar->data = i);
		}
		return *this;
	}
};
#endif // !DYNAMICARRAY_H
