#include <iostream>
using namespace std;

template <typename T, int CAPACITY = 8>
class CyclicBuffer
{
private:
    T buffer[CAPACITY];
    int p_read;
    int p_write;
    int count;

public:
    CyclicBuffer() : p_read(0), p_write(0), count(0) {}

    bool empty()
    {
        return count == 0;
    }

    bool full()
    {
        return count == CAPACITY;
    }

    T get()
    {
        if (!empty())
        {
            T value = buffer[p_read];
            p_read = (p_read + 1) % CAPACITY;
            count--;
            return value;
        }
        else
        {
            throw runtime_error("Buffer is empty");
        }
    }

    void put(T value)
    {
        if (!full())
        {
            buffer[p_write] = value;
            p_write = (p_write + 1) % CAPACITY;
            count++;
        }
        else
        {
            throw runtime_error("Buffer is full");
        }
    }

    void print() const
    {
        cout << "Buffer: ";
        for (int i = 0; i < count; i++)
        {
            cout << buffer[(p_read + i) % CAPACITY] << " ";
        }
        cout << endl;
    }
};

class Base_Class
{
public:
    int x;
    Base_Class() : x(0) {}
    Base_Class(int x) : x(x) {}
    friend ostream &operator<<(ostream &os, const Base_Class &obj)
    {
        os << obj.x;
        return os;
    }
};

int main()
{
    CyclicBuffer<int> intBuffer;
    for (int i = 1; i <= 10; i++)
    {
        if (!intBuffer.full())
        {
            intBuffer.put(i);
        }
    }
    intBuffer.print();

    while (!intBuffer.empty())
    {
        cout << intBuffer.get() << " ";
    }
    cout << endl;

    CyclicBuffer<Base_Class, 16> Base_ClassBuffer;
    for (int i = 1; i <= 20; i++)
    {
        if (!Base_ClassBuffer.full())
        {
            Base_ClassBuffer.put(Base_Class(i));
        }
    }
    Base_ClassBuffer.print();

    while (!Base_ClassBuffer.empty())
    {
        cout << Base_ClassBuffer.get() << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
