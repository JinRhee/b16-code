#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    T temp = A[index+1];
    for (std::size_t i = index; i != A.size() - 1; ++i) {
        A[i] = A[i+1];
    }
}

#endif // __array_delete__