#ifndef __S21_STACK_H__
#define __S21_STACK_H__

#include <iostream>

namespace s21 {

template <typename T> class stack {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

private:
  typedef struct Node_ {
    value_type value_;
    Node_ *ptr_next_;

    explicit Node_(value_type value) : value_(value), ptr_next_(nullptr) {}
  } Node_;

  Node_ *top_;
  size_type size_;
  void Clear_();
  value_type operator[](int) const;

public:
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &q);
  stack(stack &&q) noexcept;
  ~stack();
  stack operator=(stack &q) noexcept;
  stack operator=(stack &&q) noexcept;
  bool operator!=(const stack q) const noexcept;

  const_reference top();
  bool empty();
  size_type size();
  void push(const_reference value);
  void pop();
  void swap(stack &other);
  template <typename... Args> void insert_many_back(Args &&...args) {
    for (auto val : {std::forward<Args>(args)...})
      push(val);
  }
};

} // namespace s21

#include "s21_stack.tpp"

#endif