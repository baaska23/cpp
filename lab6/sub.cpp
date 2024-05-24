#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    int m, n;
    float **values;

public:
    //constructor
    Matrix(int m = 1, int n = 1) : m(m), n(n) {
        values = new float*[m];
        for (int i = 0; i < m; ++i) {
            values[i] = new float[n];
            for (int j = 0; j < n; ++j) {
                values[i][j] = 0.0f; 
            }
        }
    }

    //deconstructor
    ~Matrix() {
        for (int i = 0; i < m; ++i) {
            delete[] values[i];
        }
        delete[] values;
    }

    //setter
    void setValues(int i, int j, float value) {
        values[i][j] = value;
    }

    //dahin todorhoilogdson operatoruud
    Matrix operator+(const Matrix& other) const {
        
        Matrix m2(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                m2.values[i][j] = values[i][j] + other.values[i][j];
            }
        }
        return m2;
    }

    Matrix operator+(float scalar) const {
        Matrix m2(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                m2.values[i][j] = values[i][j] + scalar;
            }
        }
        return m2;
    }
    Matrix operator-(const Matrix& other) const {
        
        Matrix m2(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                m2.values[i][j] = values[i][j] - other.values[i][j];
            }
        }
        return m2;
    }

    Matrix operator*(const Matrix& other) const {
    Matrix m2(m, other.n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < other.n; ++j) {
            m2.values[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                m2.values[i][j] += values[i][k] * other.values[k][j];
            }
        }
    }
    return m2;
}

    Matrix operator++() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ++values[i][j];
            }
        }
        return *this;
    }

    Matrix operator--() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                --values[i][j];
            }
        }
        return *this;
    }

    Matrix operator+=(const Matrix& other) {

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                values[i][j] += other.values[i][j];
            }
        }
        return *this;
    }

    Matrix operator-=(const Matrix& other) {

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                values[i][j] -= other.values[i][j];
            }
        }
        return *this;
    }

    Matrix operator*=(const Matrix& other) {
    Matrix m2(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < other.n; ++j) {
            float sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += values[i][k] * other.values[k][j];
            }
            m2.values[i][j] = sum;
        }
    }
    *this = m2;
    return *this;
    }

    Matrix operator=(const Matrix& other) const {
        
        Matrix m2(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                m2.values[i][j] = other.values[i][j];
            }
        }
        return m2;
    }


    void display() const {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << values[i][j] << " ";
            }
            cout << endl;
        }
    }
};



int main() {
    Matrix m1(2, 2);
    m1.setValues(0, 0, 1.0);
    m1.setValues(0, 1, 2.0);
    m1.setValues(1, 0, 3.0);
    m1.setValues(1, 1, 4.0);

    Matrix m2(2, 2);
    m2.setValues(0, 0, 5.0);
    m2.setValues(0, 1, 6.0);
    m2.setValues(1, 0, 7.0);
    m2.setValues(1, 1, 8.0);

    cout << "Matrix 1:" << endl;
    m1.display();

    cout << "Matrix 2:" << endl;
    m2.display();

    cout << "nemeh" << endl;
    (m1 + m2).display();

    cout << "float nemeh" << endl;
    (m1 + 12.5f).display();

    cout << "ylgavar:" << endl;
    (m1-m2).display();

    cout << "urjver" << endl;
    (m1*m2).display();

    cout << "negeer nemegduuleh" << endl;
    (++m1).display();

    cout << "negeer horogduulah" << endl;
    (--m2).display();

    cout<< "+= : "<<endl;
    m1*=m2;
    m1.display();

    cout<< "-= : "<<endl;
    m1-=m2;
    m1.display();

    cout<< "+= : "<<endl;
    m1+=m2;
    m1.display();

    cout<< "= : "<<endl;
    m1=m2;
    m1.display();


    return 0;
}


// nemeh hasah operator dr 2lang ni nemej hasaj bolhu gdgiin shalgana
// matritsd a mur nemeh hasah, b bagana nemj hasaj uurchildug function bich