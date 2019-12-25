#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>


template <typename T, int dim>
class Vector {
	template<typename T, int dim>
	friend std::ostream& operator<<(std::ostream& stream, Vector<T, dim>& vector);
	static_assert(std::is_same<T, float>::value || std::is_same<T, int>::value || std::is_same<T, double>::value, "Wrong vertex data type. Change data to: int/double/float.");
private:
	std::array<T, dim> cords;
public:
	template<typename ...Args>
	Vector(Args...args) : cords{ (args)... } {}
	Vector() { cords.fill(0); }

	Vector(const Vector& copy) : cords{ copy.cords } {}

	Vector(Vector&& move) noexcept {
		cords.swap(move.cords);
	}


	Vector& operator*=(int&& scalar) {
		for (int i = 0; i < dim; i++) {
			cords[i] *= scalar;
		}
		return *this;
	}
	Vector operator*(int&& scalar) {
		Vector<T, dim>scalar_multi{ *this };
		for (int& ele : scalar_multi.cords) ele *= scalar;
		return scalar_multi;
	}

	T operator*(const Vector& vx) {
		assert(vx.get_dim() == dim);
		T dot_product{ 0 };
		for (int i = 0; i < dim; i++) {
			dot_product += cords[i] * vx.cords[i];
		}
		return dot_product;
	}

	Vector& operator=(const Vector& vx) {
		assert(vx.get_dim() == dim);
		if (&vx == this) {
			return *this;
		}
		Vector<T, dim> swap_v{ vx };
		cords.swap(swap_v.cords);
		return *this;
	}
	Vector& operator=(Vector&& vx) {
		if (&vx == this) {
			return *this;
		}
		cords.swap(vx.cords);
		return *this;
	}

	Vector operator+(const Vector& vx) {
		assert(vx.get_dim() == dim);
		Vector<T, dim> add_operation{ *this };
		for (int i = 0; i < dim; i++) {
			add_operation.cords[i] += vx.cords[i];
		}
		return add_operation;
	}



	Vector& operator+=(const Vector& vx) {
		assert(vx.get_dim() == dim);
		for (int i = 0; i < dim; i++) {
			cords[i] += vx.cords[i];
		}
		return *this;
	}

	Vector operator-(const Vector& vx) {
		assert(vx.get_dim() == dim);
		Vector<T, dim> sub_operation{ *this };
		for (int i = 0; i < dim; i++) {
			sub_operation.cords[i] -= vx.cords[i];
		}
		return sub_operation;
	}

	T& operator[](const int index) {
		return cords[index];
	}


	T* carray_values() {
		return cords.data();
	}

	T get_dim() const {
		return dim;
	}

	Vector cross_product(const Vector& vx) {
		return Vector<T, 3>{cords[1] * vx.cords[2] - cords[2] * vx.cords[1], cords[2] * vx.cords[0] - cords[0] * vx.cords[2], cords[0] * vx.cords[1] - cords[1] * vx.cords[0]};
	}

	~Vector() {}

};

template<typename T, int dim>
std::ostream& operator<<(std::ostream& stream, Vector<T, dim>& vec) {
	stream << "[ ";
	for (int i = 0; i < dim; i++) {
		stream << vec.cords[i];
		(i != dim - 1) ? stream << ", " : stream << " ";
	}
	stream << "]";
	return stream;
}


#endif // !VECTOR_H

