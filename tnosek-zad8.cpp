#include <iostream>

using namespace std;

class Entry
{
public:
    Entry(string entry_name, string entry_phone): 
        name(entry_name), phone(entry_phone){}
    
    Entry() = default;

    const string& getName() const{
        return this->name;
    }
    void print(){
        cout << "Name: " << this->name <<endl;
        cout << "Phone: " << this->phone <<endl;
    }

private:
    string name,phone;
};

class Directiory
{
public:
    Directiory(int max_size):
        max_size(max_size), current_size(0), entry_list(new Entry[max_size]){
    }

    Directiory(const Directiory &directory):
        max_size(directory.max_size), current_size(directory.max_size){
        this->entry_list = new Entry[this->max_size];
            
        for(int i = 0; i < directory.current_size; i++){
            this->entry_list[i]= directory.entry_list[i];
        }
    }
    ~Directiory(){
        delete[] this->entry_list;
    }

    void insert(const Entry &entry){
        if(this->current_size + 1 >= this->max_size){
            this->grow();
        }
        this->entry_list[this->current_size++] = entry;
    }

    void lookup(const string &name) const{
        this->entry_list[this->find_name(name)].print();
    }

    void remove(const string &name){
        int index = this->find_name(name);
        for(int i = index; i < this->current_size - 1; i++){
            this->entry_list[i] = this->entry_list[i+1];
        }
    }
    void display() const{
        for(int i = 0; i < this->current_size; i++){
            this->entry_list[i].print();
        }
    }

private:
    void grow(){
        Directiory temp = Directiory(this->max_size * 2);

        for(int i = 0; i < this->current_size; i++){
            temp.entry_list[i] = this->entry_list[i];
        }
        std::swap(this->entry_list, temp.entry_list);
    }

    int find_name(const string &name) const{
        for(int i = 0; i < this->current_size; i++){
            if (this->entry_list[i].getName() == name){
                return i;
            }
        }
        throw std::runtime_error("Failed to find a name!");
    }

    int max_size;
    int current_size;
    Entry *entry_list;
};



int main(){
    Entry e1("Tomasz", "274938123");
    Entry e2("Kamil", "728413232");
    Directiory book1(1);

    book1.insert(e1);
    cout<<"1. book1 after adding Tomasz to list\n";
    book1.display();
    book1.insert(e2);
    cout<<"2. book1 after adding Kamil to list\n";
    book1.display();
    book1.remove("Tomasz");
    cout << "3. book1 without Tomasz\n";
    book1.display();
    cout<<"4. Searching for Kamil\n";
    book1.lookup("Kamil");



}