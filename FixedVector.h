#pragma once
#include <stdio.h>
#include <stdint.h>

template<class T, size_t N>
struct FixedVector {
	T D[N] = { 0, };
	size_t Capacity = N;
	size_t Use = 0;
};

template<class T, size_t N> FixedVector<T, N> ConstructFixedVector<T, N>();
template<class T, size_t N> bool Free(FixedVector<T, N>& In);
template<class T, size_t N> T* Index(FixedVector<T, N>& In, size_t P);
template<class T, size_t N> bool Push(FixedVector<T, N>& In, const T& I);
template<class T, size_t N> bool Pop(FixedVector<T, N>& In, const T& I);
template<class T, size_t N> bool Size(FixedVector<T, N>& In);
template<class T, size_t N> bool Capacity(FixedVector<T, N>& In);
