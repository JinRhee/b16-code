#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    for(std::size_t i = index; i != A.size(); ++i) {
	    A[i] = A[i+1];
    }
    A.resize(A.size() - 1);
}

#endif // __array_delete__