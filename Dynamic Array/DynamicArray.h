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
	T& operator[](const T&);
	void resize();
	void add(T);
	void print(int);
	void edit(int, T);
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

template <class T>
T& Array<T>::operator[](const T& index) {
	if (index < 0) {
		cout << "Error! Can't be < 0" << endl;
	}
	else if (index >= arraySize) {
		resize();
		return ar[index];
	}
	else {
		return ar[index];
	}
};

template <class T>
void Array<T>::resize() {
	Array* copyArray = new Array(*this);
	arraySize = copyArray->arraySize * resizeCoefficent;
	numberOfRecords = copyArray->numberOfRecords;
	delete[] ar;
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
	delete[] copyArray;
}

template <class T>
void Array<T>::add(T record) {
	if (numberOfRecords >= arraySize)
		resize();
	*(ar + numberOfRecords) = record;
	numberOfRecords++;
};

template <class T>
void Array<T>::print(int index) {
	if (index >= arraySize) {
		cout << "Error! Out of range!" << endl;
	}
	else 
		cout <<  *(ar + index) << endl;
}

template <class T>
void Array<T>::edit(int index, T record) {
	if (index >= numberOfRecords)
		cout << "Error! Out of range!" << endl;
	else
		*(ar + index) = record;
}
#endif // !DYNAMICARRAY_H
