#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
using namespace std;

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
	Array(const Array&);
	//const Array operator=(const Array&);
	T& operator[](const T&);
	void resize();
};
template <class T>
Array<T>::Array() {
	arraySize = startArraySize;
	ar = new T[arraySize];
	*ar = 0;
}

template <class T>
 Array<T>::Array(const Array& obj) {
	arraySize = obj.arraySize;
	numberOfRecords = obj.numberOfRecords;
	ar = new T[arraySize];
	for (int i = 0; i < arraySize; i++) {
		*(ar + i) = *(obj.ar + i);
	}
}

/*template <class T>
const Array<T> Array<T>::operator=(const Array& right) {
	if (this != right) {
		delete[] ar;
		arraySize = right.arraySize;
		ar = new T[arraySize];
		for (int i = 0; i < arraySize; i++) {
			*(ar + i) = *(right.ar = i);
		}
		return *this;
	}
};*/

template <class T>
T& Array<T>::operator[](const T& sub) {
	if (sub < 0) {
		cout << "Error! Can't be < 0" << endl;
	}
	else if (sub >= arraySize) {
		resize();
		return ar[sub];
	}
	else {
		return ar[sub];
	}
};

template <class T>
void Array<T>::resize() {
	Array* copyArray = new Array(*this);
	arraySize = copyArray->arraySize * resizeCoefficent;
	numberOfRecords = copyArray->numberOfRecords;
	delete ar;
	ar = new T[arraySize];
	for (int i = 0; i < arraySize; i++) {
		if (i < copyArray->arraySize) {
			*(ar + i) = *(copyArray->ar + i);
		}
		else
		{
			*(ar + i) = 0;
		}
	}
	delete copyArray;
}
#endif // !DYNAMICARRAY_H
