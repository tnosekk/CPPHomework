#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 19);

    vector<int> container(15);
    generate(container.begin(), container.end(), [&]() { return dis(gen); });

    int divisible = count_if(container.begin(), container.end(), [](int value) { return value % 7 == 0; });
    cout << "Amount of numbers divisible by 7: " << divisible << endl;

    int sum5 = accumulate(container.begin(), container.begin() + 5, 0);
    cout << "Sum of first 5 numbers: " << sum5 << endl;

    int product3 = accumulate(container.begin(), container.begin() + 3, 1, multiplies<int>());
    cout << "Product of the 3 first numbers: " << product3 << endl;

    int min = *min_element(container.begin(), container.end());
    cout << "Min value: " << min << endl;

    replace(container.begin(), container.end(), min, 50);

    vector<int> squaredNumbers(container.size());
    transform(container.begin(), container.end(), squaredNumbers.begin(), [](int value) { return value * value; });

    sort(squaredNumbers.begin(), squaredNumbers.end());

    return 0;
}
