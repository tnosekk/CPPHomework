#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

class Polynomial
{
public:
    Polynomial(int _n) {
        n = _n;
        for(int i = 0 ; i < n && i < N; i++) {
            coefficients[i] = rand() % 100;
        }
    }

    void print() {
        for(int i = n - 1; i >= 0; i--) {
            cout << coefficients[i] << "x^" << i;
            if(i != 0) {
                cout << " + ";
            }
        }
        cout << "\n" << endl;
    }

    Polynomial derivative() {
        Polynomial result(n - 1);

        for(int i = 0; i < n; i++) {
            result.coefficients[i] = coefficients[i + 1] * (i + 1);
        }
        return result;
    }

    inline static constexpr int N = 100;
    int n;
    double coefficients[N];
};

Polynomial add(const Polynomial& a, const Polynomial& b) {
    std::size_t length = std::max(a.n, b.n);
    Polynomial result(length);

    for(int i = 0; i < length; i++) {
        result.coefficients[i] = a.coefficients[i] + b.coefficients[i];
    }
    return result;
}

Polynomial multiply(const Polynomial& a, const Polynomial& b) {
    std::size_t length = std::max(a.n, b.n);
    Polynomial result(length);

    for(int i = 0; i < a.n; i++) {
        for(int j = 0; j < b.n; j++) {
            result.coefficients[i + j] = a.coefficients[i] * b.coefficients[j];
        }
    }
    return result;
}

int main(){
    srand(time(0));
    Polynomial p1(4);
    Polynomial p2(5);

    p1.print();
    p2.print();

    p1.derivative().print();
    p2.derivative().print();

    add(p1, p2).print();
    multiply(p1, p2).print();
    
    }