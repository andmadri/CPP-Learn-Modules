#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack: public std::stack<T, Container>{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    //typedef creates a new alias
    //typename tells the compiler that what follows is a type and not a member variable
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    MutantStack() = default;

    MutantStack(const MutantStack& other): std::stack<T, Container>(other) {
        *this = other;
    }

    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            this->c = other.c;
        }
        return *this;
    }

    ~MutantStack() = default;

    typename Container::reference top() {
        return this->c.back();
    }

    typename Container::const_reference top() const{
        return this->c.back();
    }

    bool empty() const{
        return this->c.empty();
    }

    typename Container::size_type size() const {
        return this->c.size();
    }

    void push(const typename Container::value_type& value) {
        this->c.push_back(value);
    }

    void pop() {
        this->c.pop_back();
    }

    typename MutantStack<T>::iterator begin(){
        return this->c.begin();
    }

    typename MutantStack<T>::iterator end(){
        return this->c.end();
    }

    typename MutantStack<T>::const_iterator begin() const{
        return this->c.begin();
    }

    typename MutantStack<T>::const_iterator end() const{
        return this->c.end();
    }

};

#endif
