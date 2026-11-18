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
    mllist(const T &val) : car(val), cdr(nullptr) , length(1){
    }
    mllist(const T &val, const mllist<T> &suite)
    : car(val),
      cdr(suite.length == 0 ? nullptr : new mllist<T>(suite)),
      length(suite.length + 1){
    }
    T getCar() const{
        return car;
    }
    mllist<T>* getCdr() { 
        return cdr; 
    }

    const mllist<T>* getCdr() const{ 
        return cdr; 
    }
    // mllist(const mllist<T> &rhs) 
    // : car(rhs.car),
    //   cdr(rhs.cdr != nullptr ? new mllist<T>(*rhs.cdr) : nullptr),
    //   length(rhs.length){
    // }
    // ~mllist(){
    //     delete cdr;
    // }
    // mllist<T> operator+(const T &head) const {
    //     mllist<T> res(head,this);
    //     return res;
    // }
    // mllist<T> operator-(const T &rhs) const{
    //     mllist<T> res();
    //     return res;
    // }
    // int search(const T el);
    int count() const{
        return length;
    }
    // mllist<T> operator+(const mllist &rhs) const;
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const mllist<T> &list) {
    os << "[";
    const mllist<T>* current = &list;

    // Si la liste n'est pas vide
    if (current->count() > 0) {
        // On affiche tous les éléments sauf le dernier avec " ; "
        while (current->getCdr() != nullptr && current->getCdr()->count() > 0) {
            os << current->getCar() << " ; ";
            current = current->getCdr();
        }
        // Ici, current n'est PAS nullptr : c'est bien le dernier élément !
        os << current->getCar();
    }

    os << "]";
    return os;
}