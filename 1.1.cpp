#include <iostream>
#include <typeinfo>
#include <string>
#include <array>

template<typename T>
decltype(auto) f1(T &param) {
    return param; 
}

template<typename T>
decltype(auto) f2(const T &param) {
    return param; 
}

template<typename T>
decltype(auto) f3(T *param) {
    return param; 
}

template<typename T>
auto f4(T &&param) {
    return param; 
}

template<typename T>
decltype(auto) f5(T param) {
    return param; 
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept {
    return N;
}

int main() {
    int x = 27; // x - int
    const int cx = x; // cx - const int
    const int &rx = x; // rx - ссылка на x как на const int
    const int *px = &x; // px - указатель на x

    decltype(auto) f11 = f1(x); // x - int
    decltype(auto) f12 = f1(cx); // T - const int, param - const int&
    decltype(auto) f13 = f1(rx); // T - const int, param - const int&

    decltype(auto) f21 = f2(x); // T - int, param - const int&
    decltype(auto) f22 = f2(cx); // T - int, param - const int&
    decltype(auto) f23 = f2(rx); // T - int, param - const int&

    decltype(auto) f31 = f3(&x); // T - int, param - int*
    decltype(auto) f32 = f3(px); // T - int, param - const int*

    auto f41 = f4(x); // x - lvalue, T - int&, param - int&
    auto f42 = f4(cx); // cx - lvalue, T - const int&, param - const int&
    auto f43 = f4(rx); // rx - lvalue, T - const int&, param - const int&
    auto f44 = f4(27); // 27 - rvalue, T - int, param - int&&

    decltype(auto) f51 = f5(x); // T, param - int
    decltype(auto) f52 = f5(cx); // T, param - int
    decltype(auto) f53 = f5(rx); // T, param - int

    const char *const ptr = "Pointer";
    decltype(auto) f33 = f3(ptr);

    const char name[] = "Briggs";
    const char *ptrToName = name;
    decltype(auto) f54 = f5(name); // name - массив, но Т - const char*
    decltype(auto) f55 = f1(name); // T - const char[7], param - const char(&)[7]

    int keyVals[] = {1, 3, 7, 9, 11, 22, 35};
    int mappedVals[arraySize(keyVals)];
    std::array<int, arraySize(keyVals)> mappedVals2;

    return 0;
}