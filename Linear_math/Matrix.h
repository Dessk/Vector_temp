#ifndef MATRIX_H
#define MATRIX_H
namespace linear_math {
	template<typename T, int m, int n>
	class Matrix {
	protected:
		std::array<std::array<int, n>, m>;
	public:
		Matrix();
	};
}
#endif // !1
