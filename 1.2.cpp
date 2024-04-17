#include <iostream>
#include <vector>

template<typename T>
void func_for_x(T param) {}

template<typename T>
void func_for_cx(const T param) {}

template<typename T>
void func_for_rx(const T &param) {}

void someFunc(int, double) {};

template<typename T>
void f1(T param) {}

template<typename T>
void f2(std::initializer_list<T> initList) {}

// auto createInitList() {
//     return {1, 2, 3};
// }

int main() {
    auto x = 27;
    const auto cx = x;
    const auto &rx = x;

    func_for_x(27);
    func_for_cx(x);
    func_for_rx(x);

    auto x1 = 27;
    const auto cx1 = x;
    const auto &rx1 = x;

    auto &&uref1 = x; // x - int lvalue, uref1 - int&
    auto &&uref2 = cx; // cx - const int lvalue, uref2 - const int&
    auto &&uref3 = 27; // 27 - int rvalue, uref3 - int&&

    const char name[] = "Briggs"; // name - const char[7]
    auto arr1 = name; // arr1 - const char*
    auto &arr2 = name; // arr2 - const char(&)[7]

    auto func1 = someFunc; // func1 - void(*)(int, double)
    auto &func2 = someFunc; // func2 - void(&)(int, double)

    auto x11 = 27;
    auto x2(27);
    auto x3 = {27};
    auto x4{27};
    // auto x5 = {1, 2, 3.0};

    // f1({11, 23, 9});
    f2({11, 23, 9});

    std::vector<int> v;
    auto resetV = [&v](const auto &newValue) { v = newValue};
    // resetV({1, 2, 3});
}