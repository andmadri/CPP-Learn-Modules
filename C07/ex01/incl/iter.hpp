#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename U, typename F>
void iter(T* array_address, U array_len, F func) {
    for (U i = 0; i < array_len; ++i) {
        func(array_address[i]);
    }
}

#endif