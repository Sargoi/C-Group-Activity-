#include <iostream>
using namespace std;

// Generic function to find the largest of three numbers
template <typename T>
T findLargest(T a, T b, T c) {
    T largest = a; // Assume the first number is the largest

    if (b > largest) {
        largest = b;
    }
    if (c > largest) {
        largest = c;
    }

    return largest;
}

int main() {
    // Testing the function with different data types

    // For integers
    int a = 10, b = 20, c = 15;
    cout << "Largest of " << a << ", " << b << ", and " << c << " is: " 
         << findLargest(a, b, c) << endl;

    // For floating-point numbers
    float d = 10.5f, e = 20.7f, f = 15.2f;
    cout << "Largest of " << d << ", " << e << ", and " << f << " is: " 
         << findLargest(d, e, f) << endl;

    // For double-precision floating-point numbers
    double g = 12.345, h = 34.567, i = 23.456;
    cout << "Largest of " << g << ", " << h << ", and " << i << " is: " 
         << findLargest(g, h, i) << endl;

    // For characters (lexicographical comparison)
    char x = 'a', y = 'z', z = 'm';
    cout << "Largest of '" << x << "', '" << y << "', and '" << z << "' is: '" 
         << findLargest(x, y, z) << "'" << endl;

    return 0;
}