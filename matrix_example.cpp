#include <exception>

template <typename T>
class Matrix {
private:
    class Matrix_row {
    private:
        T* p_begin;
        int column;
        void construct(int col);
    public:
        Matrix_row() : p_begin(nullptr), column(0) {}
        T& operator[](int index);
        const T& operator[](int index) const;
        ~Matrix_row();
        friend class Matrix;
    };
    int row;
    Matrix_row* p_begin;
private:
    Matrix_row* safe_create(const Matrix& other) const;
    Matrix_row* safe_copy(const Matrix& other) const;
public:
    Matrix() = delete;
    Matrix(int row, int col);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    T& operator[](int index);
    ~Matrix();
};

template <typename T>
void Matrix<T>::Matrix_row::construct(int col) {
    p_begin = new T[col];
    column = col;
    return;
}

template <typename T>
T& Matrix<T>::Matrix_row::operator[](int index) {
    if (index < 0 || index >= column) throw std::out_of_range("Invalid index");
    return *(p_begin + index);
}

template <typename T>
Matrix<T>::Matrix_row::~Matrix_row() {delete[] p_begin;}

template <typename T>
Matrix<T>::Matrix_row* Matrix<T>::safe_create(const Matrix<T>& other) const {
    Matrix_row* p_temp = new Matrix_row[other.row];
    try {
        for (size_t i = 0; i < row; ++i)
            p_temp[i].construct(other.p_begin->column);
        }
        catch(...) {
            delete[] p_temp;
            throw;
        }
    return p_temp;
}

template <typename T>
Matrix<T>::Matrix_row* Matrix<T>::safe_copy(const Matrix<T>& other) const {
    T** p_temp = safe_create(other);
    try {        
        for (size_t i = 0; i < other.row; ++i)
            for (size_t j = 0; j < other.column; ++j)
                p_temp[i][j] = other.p_begin[i][j];
    }
    catch(...) {
        for (size_t i = 0; i < other.row; ++i)
            delete[] p_temp[i];
        delete[] p_temp;
        throw;
    }
    return p_temp;
}

template <typename T>
Matrix<T>::Matrix(int row, int col) : row(row) {
        p_begin = new Matrix_row[row];
        try {
            for (size_t i = 0; i < row; ++i)
                p_begin[i].construct(col);
        }
        catch(...) {
            delete[] p_begin;
            throw;
        }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) {
        p_begin = safe_copy(other);
        row = other.row;
        column = other.column;
}
template <typename T>
Matrix<T>::Matrix(Matrix&& other) {
    p_begin = std::move(other.p_begin);
    row = other.row;
    column = other.column;
    other.row = 0;
    other.column = 0;
    other.p_begin = nullptr;
}

template <typename T>
Matrix<T>::~Matrix() {
    for (size_t i = 0; i < row; ++i)
        delete[] p_begin[i];
    delete[] p_begin;
}


int main() {
    Matrix<int> m(2, 2);
    m[0][0] = 1;
    return 0;
}