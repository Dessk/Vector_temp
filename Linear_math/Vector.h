namespace linear_math{

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

		Vector(Vector&& move) noexcept {cords.swap(move.cords);}


		Vector& operator*=(int&& scalar);
		Vector operator*(int&& scalar);
		T operator*(const Vector& vx);

		Vector& operator=(const Vector& vx);
		Vector& operator=(Vector&& vx);

		Vector operator+(const Vector& vx);
		Vector operator-(const Vector& vx);


		T* carray_values();
		T get_dim() const;

		Vector cross_product(const Vector& vx);

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



}