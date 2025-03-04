#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

template <typename T>
void plus(Stack<T>& stack) {
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();

    stack.push(a+b);
}

template <typename T>
void minus(Stack<T>& stack) {
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();

    stack.push(a-b);
}

template <typename T>
void multiplies(Stack<T>& stack) {
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();

    stack.push(a*b);
}

template <typename T>
void divides(Stack<T>& stack) {
    T a = stack.top();
    stack.pop();
    T b = stack.top();
    stack.pop();

    stack.push(a/b);
}

template <typename T>
void negate(Stack<T>& stack) {
    // What is negate ??
}

template <typename T>
Stack<T> &operator<<(Stack<T>& stack, T value) {
    stack.push(value);
    return stack;
}

template <typename T>
Stack<T> &operator<<(Stack<T>& stack, void (*func)(Stack<T>&)) {
    func(stack);
    return stack;
}

#endif // __stack_rpn__