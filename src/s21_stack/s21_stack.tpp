#include "s21_stack.h"

namespace s21 {
template <typename T> stack<T>::stack() : top_(nullptr), size_(0) {}

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const &items)
    : top_(nullptr), size_(0) {
  for (value_type i : items) {
    push(i);
  }
}

template <typename T>
stack<T>::stack(const stack<T> &q) : top_(nullptr), size_(0) {
  if (this != &q) {
    int i = q.size_ - 1;
    while (this->size_ < q.size_) {
      this->push(q[i--]);
    }
  }
}

template <typename T>
stack<T>::stack(stack<T> &&q) noexcept : top_(nullptr), size_(0) {
  if (this != &q) {
    long long i = q.size_ - 1;
    while (i >= 0) {
      this->push(q[i]);
      i--;
    }
    q.Clear_();
  }
}

template <typename T> stack<T>::~stack() { Clear_(); }

template <typename T> stack<T> stack<T>::operator=(stack<T> &q) noexcept {
  if (*this != q) {
    Clear_();

    for (int i = q.size_ - 1; i >= 0; i++)
      push(q[i]);
  }
  return *this;
}

template <typename T> stack<T> stack<T>::operator=(stack<T> &&q) noexcept {
  if (*this != q) {
    Clear_();
    top_ = q.top_;
    size_ = q.size_;
    q.top_ = nullptr;
    q.size_ = 0;
  }
  return *this;
}

template <typename T>
bool stack<T>::operator!=(const stack<T> q) const noexcept {
  if (size_ != q.size_)
    return true;
  for (int i = 0; i < (int)size_; i++) {
    if ((*this)[i] != q[i])
      return true;
  }
  return false;
}

template <typename T> stack<T>::const_reference stack<T>::top() {
  return top_->value_;
}

template <typename T> void stack<T>::push(const_reference value) {
  Node_ *new_node = new Node_(value);
  if (empty()) {
    top_ = new_node;
  } else {
    new_node->ptr_next_ = top_;
    top_ = new_node;
  }
  size_++;
}

template <typename T> void stack<T>::pop() {
  Node_ *second_node = top_->ptr_next_;
  delete top_;
  top_ = second_node;
  size_--;
}

template <typename T> void stack<T>::swap(stack<T> &other) {
  Node_ *tmp_top = top_;
  size_type tmp_size = other.size_;
  if (top_ && other.top_) {
    top_ = other.top_;
    other.top_ = tmp_top;
  }
  other.size_ = size_;
  size_ = tmp_size;
}

template <typename T> bool stack<T>::empty() { return size_ == 0; }

template <typename T> stack<T>::size_type stack<T>::size() { return size_; }

template <typename T> void stack<T>::Clear_() {
  while (top_) {
    pop();
  }
}

template <typename T> stack<T>::value_type stack<T>::operator[](int ind) const {
  if (ind < 0 || ind > (int)size_)
    throw std::out_of_range("Index out of range");
  Node_ *tmp_node = top_;
  for (int i = 0; i < ind; i++) {
    tmp_node = tmp_node->ptr_next_;
  }
  return tmp_node->value_;
}
} // namespace s21