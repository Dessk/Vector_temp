#include <iostream>
#include <assert.h>
#include "Vector.h"


template<typename T, int dim>
linear_math::Vector<T, dim>& linear_math::Vector<T, dim>::operator*=(int&& scalar) {
	for (int i = 0; i < dim; i++) {
		cords[i] *= scalar;
	}
	return *this;
}

template<typename T, int dim>
linear_math::Vector<T, dim> linear_math::Vector<T, dim>::operator*(int&& scalar) {
	Vector<T, dim>scalar_multi{ *this };
	for (int& ele : scalar_multi.cords) ele *= scalar;
	return scalar_multi;

}

template<typename T, int dim>
T linear_math::Vector<T, dim>::operator*(const Vector& vx){
	assert(vx.get_dim() == dim);
	T dot_product{ 0 };
	for (int i = 0; i < dim; i++) {
		dot_product += cords[i] * vx.cords[i];
	}
	return dot_product;
}

template<typename T, int dim>
linear_math::Vector<T,dim>& linear_math::Vector<T,dim>::operator=(const Vector& vx){
	assert(vx.get_dim() == dim);
	if (&vx == this) {
		return *this;
	}
	Vector<T, dim> swap_v{ vx };
	cords.swap(swap_v.cords);
	return *this;
}

template<typename T, int dim>
linear_math::Vector<T, dim>& linear_math::Vector<T, dim>::operator=(Vector&& vx) {
	if (&vx == this) {
		return *this;
	}
	cords.swap(vx.cords);
	return *this;
}

template<typename T, int dim>
linear_math::Vector<T, dim> linear_math::Vector<T, dim>::operator+(const Vector& vx) {
	assert(vx.get_dim() == dim);
	Vector<T, dim> add_operation{ *this };
	for (int i = 0; i < dim; i++) {
		add_operation.cords[i] += vx.cords[i];
	}
	return add_operation;
}

template<typename T, int dim>
linear_math::Vector<T, dim> linear_math::Vector<T, dim>::operator-(const Vector& vx) {
	assert(vx.get_dim() == dim);
	Vector<T, dim> sub_operation{ *this };
	for (int i = 0; i < dim; i++) {
		sub_operation.cords[i] -= vx.cords[i];
	}
	return sub_operation;
}

template<typename T, int dim>
T* linear_math::Vector<T, dim>::carray_values() {
	return cords.data();
}

template<typename T, int dim>
T linear_math::Vector<T, dim>::get_dim() const {
	return dim;
}

template<typename T, int dim>
linear_math::Vector<T,dim> linear_math::Vector<T,dim>::cross_product(const Vector& vx) {
	return linear_math::Vector<T, 3>{cords[1] * vx.cords[2] - cords[2] * vx.cords[1], cords[2] * vx.cords[0] - cords[0] * vx.cords[2], cords[0] * vx.cords[1] - cords[1] * vx.cords[0]};
}

