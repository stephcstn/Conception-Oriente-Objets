#include <cstddef>
#include <ostream>
#pragma once

template <typename T>

class mllist {
private:
    T car;
    mllist<T>* cdr;
    size_t length;

public:
    mllist()  : car(), cdr(nullptr) , length(0) {
    }

    mllist(const T &val) : car(val), cdr(new mllist<T>()) , length(1){
    }

    mllist(const T &val, const mllist<T> &suite)
    : car(val),
      cdr(new mllist<T>(suite)),
      length(suite.length + 1){
    }

    mllist(const mllist<T> &rhs)
        : car(rhs.car),
          cdr(rhs.cdr != nullptr ? new mllist<T>(*rhs.cdr) : nullptr),
          length(rhs.length) {
    }

    ~mllist(){
        delete cdr;
    }

    const T getCar() const{
        return car;
    }

    size_t count() const { return length; }

    mllist<T>& getCdr() { 
        return *cdr; 
    }

    const mllist<T>& getCdr() const{ 
        return *cdr; 
    }

    mllist<T> operator+(const T &rhs) const {
        mllist<T> res(rhs,*(this->cdr));
        res.length = this->length + 1;
        return res;
    }

    // mllist<T> operator-(const T &rhs) const{
    //     mllist<T> res();
    //     return res;
    // }

    // int search(const T el);
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const mllist<T> &list) {
    os << "[";
    const mllist<T>* current = &list;

    while (current->length() > 0){
        if (current->length() != 1){
            os << current->getCar();
            os << " , ";
            current = current->getCdr();
        }
        os << current->getCar();
        current = current->getCdr();
    }
    os << "]";
    return os;
}