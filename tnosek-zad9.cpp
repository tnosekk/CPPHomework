#include <iostream>


class Complex {
    private:
        double real;
        double imaginary;
    
    public:
        Complex(double re, double im):
            real(re), imaginary(im){
            }
        
        Complex& operator +=(const Complex& c){
            real += c.real;
            imaginary += c.imaginary;
            return *this;
        }
        Complex& operator -=(const Complex& c){
            real -= c.real;
            imaginary -= c.imaginary;
            return *this;
        }
        Complex& operator *=(const Complex& c){
            double Realtemp = real * c.real - imaginary * c.imaginary; real = Realtemp;
            double Imagtemp = real * c.imaginary - imaginary * c.real; imaginary = Imagtemp;
            return *this;
        }
        Complex& operator /=(const Complex& c){
            double denum = c.real * c.real + c.imaginary * c.imaginary;
            double Realtemp = (real * c.real + imaginary * c.imaginary) / denum; real = Realtemp;
            double Imagtemp = (imaginary * c.real - real * c.imaginary) / denum; imaginary = Imagtemp;
            return *this;
        }
        
        friend Complex operator+(const Complex& c1,const Complex& c2){
            Complex result(c1.real + c2.real, c1.imaginary + c2.imaginary);
            return result;
        }
        friend Complex operator-(const Complex& c1, const Complex& c2){
            Complex result(c1.real - c2.real, c1.imaginary - c2.imaginary);
            return result;    
        }
        friend Complex operator*(const Complex& c1, const Complex& c2){
            Complex result(c1.real * c2.real - c1.imaginary * c2.imaginary,
                            c1.real * c2.imaginary + c1.imaginary * c2.real);
            return result;
        }
        friend Complex operator/(const Complex& c1, const Complex& c2){
            double denum = c2.real * c2.real + c2.imaginary * c2.imaginary;
            Complex result((c1.real * c2.real + c1.imaginary * c2.imaginary)/denum,
                            (c1.imaginary * c2.real - c1.real * c2.imaginary/denum));
            return result;
        }
        friend std::ostream& operator<<(std::ostream& os, const Complex& c){
            os << c.real << " + " << c.imaginary << "i";
            return os;
        }
        
};




int main() {
    Complex c1(6.0, 8.0);
    Complex c2(3.0, 4.0);

    std::cout << "c1 =  " << c1 << std::endl;
    std::cout << "c2 =  " << c2 << std::endl;

    Complex c3 = c1 + c2;
    std::cout << "c1 + c2 =  " << c3 << std::endl;

    Complex c4 = c1 - c2;
    std::cout << "c1 - c2 =  " << c4 << std::endl;

    Complex c5 = c1 * c2;
    std::cout << "c1 * c2 =  " << c5 << std::endl;

    Complex c6 = c1 / c2;
    std::cout << "c1 / c2 = " << c6 << std::endl;

    return EXIT_SUCCESS;
}