#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double>> mat;

public:
    Matrix(int m, int n) : rows(m), cols(n) {
        mat.resize(rows, vector<double>(cols, 0));
    }

    void input() {
        cout<<"Enter the elements of the matrix :";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter value for element (" << i+1 << "," << j+1 << "): ";
                cin >> mat[i][j];
            }
        }
    }

    Matrix operator*(const Matrix& other) const {

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }

        return result;
    }

    void print() const {
        cout << "Matrix " << rows << "x" << cols << ":" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows for matrix A: ";
    cin >> m;
    cout << "Enter number of columns for matrix A : ";
    cin >> n;
    Matrix matA(m, n), matB(n, m), matC(m, m);

    cout << "Input values for matrix A:" << endl;
    matA.input();
    cout << "Input values for matrix B:" << endl;
    matB.input();

    matC = matA * matB;

    cout << "Matrix A:" << endl;
    matA.print();
    cout << endl;

    cout << "Matrix B:" << endl;
    matB.print();
    cout << endl;

    cout << "Matrix C = A * B:" << endl;
    matC.print();

    return 0;
}
