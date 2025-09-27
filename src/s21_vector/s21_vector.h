#ifndef S21_VECTOR_H_
#define S21_VECTOR_H_

#include <cstddef>
#include <initializer_list>
#include <limits>
#include <stdexcept>

namespace s21 {

template <typename T> class vector {
public:
  class VectorIterator;
  class VectorConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = VectorIterator;
  using const_iterator = VectorConstIterator;
  using size_type = size_t;
  using difference_type = std::ptrdiff_t;

private:
  T *data_;
  size_type size_;
  size_type capacity_;

public:
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data();

  iterator begin();
  const_iterator cbegin() const;
  iterator end();
  const_iterator cend() const;

  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <typename... Args> void insert_many_back(Args &&...args);

  class VectorIterator {
  public:
    using pointer = T *;
    using reference = T &;

    VectorIterator(pointer ptr = nullptr) : ptr_(ptr) {}

    reference operator*() { return *ptr_; }

    VectorIterator &operator++() {
      ++ptr_;
      return *this;
    }

    VectorIterator operator++(int) {
      VectorIterator v = *this;
      ++(*this);
      return v;
    }

    VectorIterator &operator--() {
      --ptr_;
      return *this;
    }

    VectorIterator operator--(int) {
      VectorIterator v = *this;
      --(*this);
      return v;
    }

    VectorIterator operator+(size_t n) const {
      return VectorIterator(ptr_ + n);
    }
    VectorIterator operator-(size_t n) const {
      return VectorIterator(ptr_ - n);
    }
    difference_type operator-(const VectorIterator &other) const {
      return ptr_ - other.ptr_;
    }

    bool operator==(const VectorIterator &other) const {
      return ptr_ == other.ptr_;
    }
    bool operator!=(const VectorIterator &other) const {
      return ptr_ != other.ptr_;
    }
    bool operator<(const VectorIterator &other) const {
      return ptr_ < other.ptr_;
    }
    bool operator>(const VectorIterator &other) const {
      return ptr_ > other.ptr_;
    }
    bool operator<=(const VectorIterator &other) const {
      return ptr_ <= other.ptr_;
    }
    bool operator>=(const VectorIterator &other) const {
      return ptr_ >= other.ptr_;
    }

  private:
    pointer ptr_;
    friend class vector<T>;
    friend class VectorConstIterator;
  };

  class VectorConstIterator {
  public:
    using pointer = const T *;
    using reference = const T &;

    VectorConstIterator(pointer ptr = nullptr) : ptr_(ptr) {}
    VectorConstIterator(const VectorIterator &it) : ptr_(it.ptr_) {}

    reference operator*() const { return *ptr_; }

    VectorConstIterator &operator++() {
      ++ptr_;
      return *this;
    }

    VectorConstIterator operator++(int) {
      VectorConstIterator v = *this;
      ++(*this);
      return v;
    }

    VectorConstIterator &operator--() {
      --ptr_;
      return *this;
    }

    VectorConstIterator operator--(int) {
      VectorConstIterator v = *this;
      --(*this);
      return v;
    }

    VectorConstIterator operator+(size_t n) const {
      return VectorConstIterator(ptr_ + n);
    }
    VectorConstIterator operator-(size_t n) const {
      return VectorConstIterator(ptr_ - n);
    }
    difference_type operator-(const VectorConstIterator &other) const {
      return ptr_ - other.ptr_;
    }

    bool operator==(const VectorConstIterator &other) const {
      return ptr_ == other.ptr_;
    }
    bool operator!=(const VectorConstIterator &other) const {
      return ptr_ != other.ptr_;
    }
    bool operator<(const VectorConstIterator &other) const {
      return ptr_ < other.ptr_;
    }
    bool operator>(const VectorConstIterator &other) const {
      return ptr_ > other.ptr_;
    }
    bool operator<=(const VectorConstIterator &other) const {
      return ptr_ <= other.ptr_;
    }
    bool operator>=(const VectorConstIterator &other) const {
      return ptr_ >= other.ptr_;
    }

  private:
    pointer ptr_;
    friend class vector<T>;
  };
};
} // namespace s21

#include "s21_vector.tpp"

#endif