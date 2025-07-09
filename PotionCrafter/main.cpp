#include <iostream>

using namespace std;

// Template function to print any type
template<typename T>
void print(const T& value) {
    std::cout << "Printing value: " << value << '\n';
}

int main() {
    print(42);           // int
    print(3.14159);      // double
    print("Hello");      // const char*

    return 0;
}
