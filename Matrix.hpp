//#include <cstddef>
//#include <iostream>
template <typename T> class Matrix;

template <typename T>
std::ostream & operator<<(std::ostream & left, const Matrix<T> & right);

template <typename T>
Matrix<T> operator*(const Matrix<T> & left, const Matrix<T> &right);

template <typename T>
Matrix<T> operator*(T left, const Matrix<T> & right);

template <typename T>
class Matrix
{
private:	
    size_t rows;
    size_t cols;

    T **data;

public:
    Matrix(size_t rows, size_t cols);

    void WriteMatrix() const;

    void FillMagickNE();

    Matrix();

    ~Matrix();

    Matrix(const Matrix<T> & other);

    Matrix<T> AddMatrix(const Matrix & other) const;

    void ReadMatrix();

    Matrix<T> operator+(const Matrix<T> & right) const;
    Matrix<T> operator-(const Matrix<T> & right) const;

	friend std::ostream & operator<< <T>(std::ostream & left, const Matrix<T> & right);

	friend Matrix<T> operator* <T>(const Matrix<T> & left, const Matrix<T> &right);

	friend Matrix<T> operator* <T>(T left, const Matrix<T> & right);
};

// tar -cJvf cw-[n].txz Matrix.h Matrix.cpp
#include <cstddef>
template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) {
    this->rows = rows;
    this->cols = cols;

    try {
        this->data = new T* [this->rows];

        for (size_t r = 0; r < this->rows; ++r)
            this->data[r] = new T[cols];

        for (size_t r = 0; r < this->rows; ++r) {
            for (size_t c = 0; c < this->cols; ++c)
                this->data[r][c] = 0.0;
        }
    }
    catch (...) {
        std::cerr << "Error C" << std::endl;
        exit(1);
    }
}

template <typename T>
void Matrix<T>::WriteMatrix() const {
    std::cout << this->rows << " " << this->cols << std::endl;
    for (size_t r = 0; r < this->rows; r++) {
        for (size_t c = 0; c < this->cols; c++)
            std::cout << this->data[r][c] << " ";
        std::cout << std::endl;
    }
}

template <typename T>
void Matrix<T>::FillMagickNE() {
    double cou = 1.;
    for (size_t rows = 0; rows < this->rows; ++rows) {
        for (size_t cols = 0; cols < this->cols; ++cols)
            cols > rows ? data[rows][cols] = cou++ : data[rows][cols] = 0.;
    }

}

template <typename T>
Matrix<T>::Matrix() {
    this->rows = 0;
    this->cols = 0;

    this->data = nullptr;
}

template <typename T>
Matrix<T>::~Matrix() {
    if (data != nullptr) {
        for (size_t r = 0; r < this->rows; ++r) delete[] data[r];
        delete[] data;
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) {
    this->rows = other.rows;
    this->cols = other.cols;

    try {
        this->data = new T* [this->rows];
        for (size_t r = 0; r < this->rows; r++)
            data[r] = new T[this->cols];

        for (size_t r = 0; r < this->rows; ++r) {
            for (size_t c = 0; c < this->cols; ++c) data[r][c] = other.data[r][c];
        }
    }
    catch (...) {
        std::cerr << "Error C" << std::endl;
        exit(1);
    }
}

template <typename T>
Matrix<T> Matrix<T>::AddMatrix(const Matrix<T>& other) const {
    if (this->rows == other.rows && this->cols == other.cols) {
        Matrix result(other);
        for (size_t rows = 0; rows < this->rows; ++rows) {
            for (size_t cols = 0; cols < this->cols; ++cols) {
                result.data[rows][cols] = result.data[rows][cols] + this->data[rows][cols];
            }
        }
        return result;
    }
    else exit(1);
    return Matrix<T>();
}


template <typename T>
void Matrix<T>::ReadMatrix() { //method
    if (data != nullptr) {
        for (size_t r = 0; r < this->rows; ++r) delete[] data[r];
        delete[] data;
    }

    if (std::cin >> this->rows >> this->cols) {
        data = new double* [this->rows];

        for (size_t r = 0; r < this->rows; ++r) {
            data[r] = new double[this->cols];
        }

        for (size_t r = 0; r < this->rows; ++r) {
            for (size_t c = 0; c < this->cols; ++c) {
                double i;
                if (std::cin >> i) {
                    this->data[r][c] = i;
                }
            }
        }
    }
}

template <typename T>
Matrix <T> Matrix<T>::operator+(const Matrix<T>& right) const { // overload add
    return this->AddMatrix(right);
}
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& right) const { //overload sub
    if (this->rows == right.rows && this->cols == right.cols) {
        Matrix<T> result(right);
        for (size_t r = 0; r < result.rows; ++r) {
            for (size_t c = 0; c < result.cols; ++c)  result.data[r][c] = result.data[r][c] - this->data[r][c];
        } return result;
    }
    else {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return Matrix<T>();
}
template <typename T>
std::ostream& operator<<(std::ostream& left, const Matrix<T>& right)  //overload of output
{
    left<< right.rows<< " " << right.cols<< '\n';

    for (size_t r = 0; r < right.rows; ++r) {
        for (size_t c = 0; c < right.cols; ++c) left << right.data[r][c]<< " ";
        left << '\n';
    }
    return left;
}
template <typename T>
Matrix<T> operator* (const Matrix<T> & left, const Matrix<T> & right) { // overload of mult Matrix on Matrix
	if (left.cols == right.rows)
	{
		Matrix<T> result(left.rows, right.cols);
		for (size_t ro = 0; ro < left.rows; ++ro) { 
			for (size_t co = 0; co <right.cols;++co){
				for(size_t c =0; c<right.rows;++c) {
					result.data[ro][co] = result.data[ro][co] + left.data[ro][c]*right.data[c][co]; 
				}
			}
		}	
		return result;
	}
	else exit(1);
	return Matrix<T>();
}

template <typename T>
Matrix<T> operator*(T left, const Matrix<T>& right) { // overload of multiolication prvalue const on Matrix
    for (size_t r = 0; r < right.rows; ++r) {
        for (size_t c = 0; c < right.cols; ++c) right.data[r][c] *= left;
    }return right;
}
/*
 Constructor of move
 */
/*

int main()
{

	Matrix test = {3,4};
	Matrix two = {4,5};
	
	test.FillMagickNE();
	std::cout<< test;
	
	two.FillMagickNE();
	std::cout<<two << '\n' << "Ahtung!\n";
	Matrix r = test * two;
	
	std::cout << r << "All good\n";
	
	Matrix qw = {5,5};
	Matrix we = {5,5};
	qw.FillMagickNE();
	we.FillMagickNE();
	std::cout << "qw Matrix:\n"<< qw << "we Matrix:\n" << we<< "operator +\n" << qw+we << "AddMatrix\n";
	std::cout <<we.AddMatrix(qw);
	qw.WriteMatrix();
//	qw.DelMatrix(we);
	//std::cout << we;
}
*/
