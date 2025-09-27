#ifndef __S21_ARRAY_H__
#define __S21_ARRAY_H__

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace s21 {

template <typename T, size_t N> class array {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

private:
  value_type arr_[N];
  size_type size_ = N;

public:
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();
  array &operator=(const array &a);
  array &operator=(array &&a);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void swap(array &other);
  void fill(const_reference value);

  class ArrayIterator {
  public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    ArrayIterator(pointer ptr = nullptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() { return ptr_; }

    ArrayIterator &operator++() {
      ++ptr_;
      return *this;
    }

    ArrayIterator operator++(int) {
      ArrayIterator tmp = *this;
      ++ptr_;
      return tmp;
    }

    ArrayIterator &operator--() {
      --ptr_;
      return *this;
    }

    ArrayIterator operator--(int) {
      ArrayIterator tmp = *this;
      --ptr_;
      return tmp;
    }

    ArrayIterator operator+(difference_type n) const {
      return ArrayIterator(ptr_ + n);
    }

    ArrayIterator operator-(difference_type n) const {
      return ArrayIterator(ptr_ - n);
    }

    difference_type operator-(const ArrayIterator &other) const {
      return ptr_ - other.ptr_;
    }

    bool operator==(const ArrayIterator &other) const {
      return ptr_ == other.ptr_;
    }
    bool operator!=(const ArrayIterator &other) const {
      return ptr_ != other.ptr_;
    }
    bool operator<(const ArrayIterator &other) const {
      return ptr_ < other.ptr_;
    }
    bool operator>(const ArrayIterator &other) const {
      return ptr_ > other.ptr_;
    }
    bool operator<=(const ArrayIterator &other) const {
      return ptr_ <= other.ptr_;
    }
    bool operator>=(const ArrayIterator &other) const {
      return ptr_ >= other.ptr_;
    }

  private:
    pointer ptr_;
  };

  class ArrayConstIterator {
  public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = const T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T *;
    using reference = const T &;

    ArrayConstIterator(pointer ptr = nullptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() { return ptr_; }

    ArrayConstIterator &operator++() {
      ++ptr_;
      return *this;
    }

    ArrayConstIterator operator++(int) {
      ArrayConstIterator tmp = *this;
      ++ptr_;
      return tmp;
    }

    ArrayConstIterator &operator--() {
      --ptr_;
      return *this;
    }

    ArrayConstIterator operator--(int) {
      ArrayConstIterator tmp = *this;
      --ptr_;
      return tmp;
    }

    ArrayConstIterator operator+(difference_type n) const {
      return ArrayConstIterator(ptr_ + n);
    }

    ArrayConstIterator operator-(difference_type n) const {
      return ArrayConstIterator(ptr_ - n);
    }

    difference_type operator-(const ArrayConstIterator &other) const {
      return ptr_ - other.ptr_;
    }

    bool operator==(const ArrayConstIterator &other) const {
      return ptr_ == other.ptr_;
    }
    bool operator!=(const ArrayConstIterator &other) const {
      return ptr_ != other.ptr_;
    }
    bool operator<(const ArrayConstIterator &other) const {
      return ptr_ < other.ptr_;
    }
    bool operator>(const ArrayConstIterator &other) const {
      return ptr_ > other.ptr_;
    }
    bool operator<=(const ArrayConstIterator &other) const {
      return ptr_ <= other.ptr_;
    }
    bool operator>=(const ArrayConstIterator &other) const {
      return ptr_ >= other.ptr_;
    }

  private:
    pointer ptr_;
  };
};

} // namespace s21

#include "s21_array.tpp"

#endif