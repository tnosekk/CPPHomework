#include <iostream>

using namespace std;

class Animal{
    private:
        string name;
        int age;
    public:
        Animal(string name, int age): name{name}, age{age}{}

        ostream &print(ostream &os) const{
            return os << "Animal Name: " << name << "\nAge: " << age <<endl;
        }
};

class Horse: public Animal {
    private:
        string breed;
        int height;

    public:
        Horse(string breed, int height, string name, int age):
            Animal(std::move(name),std::move(age)), breed{breed}, height{height}{}

        ostream &print(ostream &os) const{
            Animal::print(os);
            return os << "Breed: " << breed << "\nHeight: " << height << "\n" << endl;
        }

};



class Dog: public Animal {
    private:
        string breed;
        double weight;
    
    public:
        Dog(string name, int age, string breed, double weight):
            Animal(std::move(name), std::move(age)), breed{breed}, weight{weight}{}

        ostream &print(ostream &os) const{
            Animal::print(os);
            return os << "Breed: " << breed << "\nWeight: " << weight << endl;
        }

};


int main(){

    Horse h{"Horse", 2, "Adrian", 10};
    Dog d{"Dog", 4, "German Shepard", 15.3};

    h.print(cout);
    d.print(cout);
}