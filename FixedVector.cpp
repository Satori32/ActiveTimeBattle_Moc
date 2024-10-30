#include "FixedVector,h"

template<class T, size_t N>
FixedVector<T, N> ConstructFixedVector<T, N>() {
	FixedVector<T, N> F;
	F.Capacity = N;
	F.use = 0;
	return F;
}
template<class T, size_t N>
bool Free(FixedVector<T, N>& In) {
	In.Use = 0;
	return true;
}

template<class T, size_t N>
T* Index(FixedVector<T, N>& In, size_t P) {
	if (P >= In.Use) { return NULL; }
	return &In.D[P];

}template<class T, size_t N>
bool Push(FixedVector<T, N>& In, const T& I) {
	if (In.Use >= In.Capacity) { return false; }
	In.D[In.Use] = I;

	return true;
}
template<class T, size_t N>
bool Pop(FixedVector<T, N>& In, const T& I) {
	if (In.Use == 0) { return false; }
	In.Use--;
}

template<class T, size_t N>
bool Size(FixedVector<T, N>& In) {
	return In.Use;
}
template<class T, size_t N>
bool Capacity(FixedVector<T, N>& In) {
	return In.Capacity;
}