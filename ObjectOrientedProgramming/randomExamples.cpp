#include <stdio.h>
#include <functional>
#include <string>
#include <typeinfo>
#include <iostream>
#include <algorithm>
// #include <concepts>

template<class T>
    T mempty;

template<class T>
    T mappend(T, T) = delete;

// template<class T>
//     concept bool Monoind = requires(T t){
//         { mempty<T> } -> T;
//         { mappend(t,t) } -> T;
//     };


template<>
std::string mempty <std::string> = {""};
std::string mappend(std::string s1, std::string s2)
{
    return s1 + s2;
}

template<class T>
class randomClass
{
 public:
    T returnGiven(T someStuff) {
        return someStuff;
    }
};

// template<class T,  class Z>
// std::function<std::function(std::function, std::function)> compositionFunction(std::function<T(T)> f1, std::function<T(T)> f2)
// {
//     return [f1, f2] (Z x) -> Z
//     {
//         return f1(f2(x));
//     };
//        
// }

// template<class T>
// T addNumber(T a)
// {
//     return a+1;
// }
//
// template<class T>
// T addNumber2(T a)
// {
//     return a+2;
// }

// template<class T>
// T addOne(T t)
// {
//     return t+1;
// }
//
// template<class T>
// T addTwo(T t)
// {
//     return t+2;
// }
//
// template<class T>
// std::function<T (T)> compositionFunction(std::function<T (T)> addOne, std::function<T (T)> addTwo)
// {
//     return [addOne, addTwo](T x){addOne(addTwo(x));};
// }

template<class T>
T addOne(T a)
{
    return a+1;
}

template<class T>
T addTwo(T a)
{
    return a+2;
}

template<class T>
std::function<T (T)> compositionFunction(std::function<T (T)> addOne, std::function<T (T)> addTwo){
    std::function<T (T)> lambda = [addOne, addTwo](T x){return addOne(addTwo(x));};

    return lambda;
}

template<class T>
T identity(T x) {
    return x;
}


std::function<int (int)> retFun() {
    return [](int x) { return x; };
}
int main()
{
    randomClass<double> rand;
    // std::cout << retFun()(4);
    std::cout << compositionFunction<int>(addOne<int>, addTwo<int>)(2) << std::endl;
    std::cout << compositionFunction<int>(addOne<int>, identity<int>)(2)<< std::endl;
    std::cout << compositionFunction<int>(identity<int>, addOne<int>)(2)<< std::endl;

    return 0;
}
