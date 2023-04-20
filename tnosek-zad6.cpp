#include <iostream>

using namespace std;


class Fraction {
public:
    int num;
    int denum;
    //contructor
    Fraction(int num, int denum){
        if(denum == 0){
            cout<<"Denominator = 0, ERROR" <<endl;
            EXIT_FAILURE;
        } 
        this->num = num;
        this->denum = denum;
    }
    //fraction addicton functin
    Fraction add(Fraction f){
        int new_num = (num * f.denum) + (denum * f.num);
        int new_denum = denum * f.denum;
        return Fraction(new_num, new_denum);
    }
     //fraction multiplicaton function
    Fraction mult(Fraction f){
        int new_num = num * f.num;
        int new_denum = denum * f.denum;
        return Fraction(new_num, new_denum);
    }

    double eu(int a, int b){
        if(b == a)
            return a;
        return eu(b, a % b);
    }
    //fractions reduction function
    void reduce(){
        int rd = eu(num, denum);
        num /= rd;
        denum /= rd;
    }
    //fraction evaluation function
    double evaluate(){
        double fraction = double(num) / double(denum);
        return fraction;
    }

    void print(){
        cout << num << "/" << denum << endl;
    }
};

int main(){
    int num,denum;
    // cin>>num>>denum;
    // Fraction f1(num, denum);
    Fraction f1(3, 4);
    Fraction f2(2,7);

    Fraction f3 = f1.add(f2);
    printf("%d/%d + %d/%d = %d/%d\n",
         f1.num, f1.denum, f2.num, f2.denum, f3.num, f3.denum);

    // f3.reduce();
    f3.print();
    double decimal = f3.evaluate();
    printf("%d/%d + %d/%d = %.2f\n",
         f1.num, f1.denum, f2.num, f2.denum, decimal);
    
    Fraction f4 = f1.mult(f2);
    // f4.reduce();
    f4.print();
     printf("%d/%d * %d/%d = %d/%d\n",
         f1.num, f1.denum, f2.num, f2.denum, f4.num, f4.denum);
        
    double decimal2 = f4.evaluate();
     printf("%d/%d + %d/%d = %.2f\n",
         f1.num, f1.denum, f2.num, f2.denum, decimal2);


    return EXIT_SUCCESS;

}