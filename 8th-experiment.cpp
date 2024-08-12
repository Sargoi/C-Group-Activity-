#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
class Vector {
private:
    std::vector<T> data;

public:
    Vector() {}
    Vector(int size) : data(size) {}

    void push_back(const T& element) {
        data.push_back(element);
    }

    T smallest() {
        return *std::min_element(data.begin(), data.end());
    }

    bool search(const T& element) {
        return std::find(data.begin(), data.end(), element) != data.end();
    }

    T average() {
        if (data.empty()) {
            throw std::runtime_error("Vector is empty");
        }
        return std::accumulate(data.begin(), data.end(), T(0)) / data.size();
    }

    void print() {
        for (const auto& element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector<int> intVector;
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);
    intVector.push_back(40);
    intVector.push_back(50);

    std::cout << "Vector: ";
    intVector.print();

    std::cout << "Smallest element: " << intVector.smallest() << std::endl;

    int searchElement = 30;
    if (intVector.search(searchElement)) {
        std::cout << "Element " << searchElement << " found in the vector" << std::endl;
    } else {
        std::cout << "Element " << searchElement << " not found in the vector" << std::endl;
    }

    std::cout << "Average of elements: " << intVector.average() << std::endl;

    return 0;
}