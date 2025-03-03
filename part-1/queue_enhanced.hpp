#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        assert(!this->_storage.empty());
        return this->_storage[this->_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        assert(!this->_storage.empty());
        return this->_storage[this->_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        this->_size++;
        this->_storage[this->_head()] = value;
    }

    // Remove the element at the back of the queue
    // TODO: Something wrong here
    void dequeue_back()
    {
        this->_size--;
        if (this->_position == this->_storage.size()) {
            this->_position = 0;
        }
        else {
            this->_position++;
        }
    }

    // Remove all elements from the queue
    void clear() { 
        while (!this->empty()) {
            this->dequeue();
        }
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        assert(this->_size >= 1);
        auto index = this->_storage.size() - 1;//
        if (index >= this->_storage.size()) { index -= this->_storage.size(); }
        return index;
    }
};

#endif // __queue_enhanced__