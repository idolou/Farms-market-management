//
// Created by ise on 12/25/21.
//

#ifndef FARMERSMARKET_EXCEPTION_H
#define FARMERSMARKET_EXCEPTION_H
#include <iostream>
#include <exception>
#include <string>

//class CowException : public exception{
//public:
//    const char* what () const noexcept override{
//        return "Insert valid number of cow farms";
//
//    }
//};
//
//class SheepException : public exception{
//public:
//    const char* what() const noexcept override{
//        return "Insert valid number of sheep farms";
//    }
//};
//
//class ChickenException : public exception{
//public:
//    const char* what() const noexcept override{
//        return "Insert valid number of chicken farms";
//    }
//};



class myException : public exception{
public:
    const char* what () const noexcept override{
        return "Insert valid number of cow farms";

    }
};


class CowException : public myException {
public:
    const char* what () const noexcept override{
        return "Insert valid number of cow farms";

    }
};

class SheepException : public myException {
public:
    const char* what() const noexcept override{
        return "Insert valid number of sheep farms";
    }
};

class ChickenException : public myException {
public:
    const char* what() const noexcept override{
        return "Insert valid number of chicken farms";
    }
};








#endif //FARMERSMARKET_EXCEPTION_H
