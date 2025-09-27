#include "s21_array.h"

namespace s21 {

template <typename T, size_t N> array<T, N>::array() : arr_{}, size_(N) {}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : size_(N) {
  size_type i = 0;
  for (const auto &item : items) {
    if (i >= N)
      break;
    arr_[i++] = item;
  }
}

template <typename T, size_t N>
array<T, N>::array(const array &other) : size_(other.size_) {
  for (size_type i = 0; i < N; ++i) {
    arr_[i] = other.arr_[i];
  }
}

template <typename T, size_t N>
array<T, N>::array(array &&other) : size_(other.size_) {
  for (size_type i = 0; i < N; ++i) {
    arr_[i] = std::move(other.arr_[i]);
    other.arr_[i] = value_type();
  }
  other.size_ = 0;
}

template <typename T, size_t N> array<T, N>::~array() {}

template <typename T, size_t N>
s21::array<T, N> &s21::array<T, N>::operator=(const s21::array<T, N> &a) {
  if (this != &a) {
    size_ = a.size_;
    for (size_type i = 0; i < N; ++i) {
      arr_[i] = a.arr_[i];
    }
  }
  return *this;
}

template <typename T, size_t N>
s21::array<T, N> &s21::array<T, N>::operator=(s21::array<T, N> &&a) {
  if (this != &a) {
    size_ = a.size_;
    for (size_type i = 0; i < N; ++i) {
      arr_[i] = std::move(a.arr_[i]);
      a.arr_[i] = value_type();
    }
    a.size_ = 0;
  }
  return *this;
}

template <typename T, size_t N>
typename s21::array<T, N>::reference s21::array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return arr_[pos];
}

template <typename T, size_t N>
typename s21::array<T, N>::reference
s21::array<T, N>::operator[](size_type pos) {
  return arr_[pos];
}

template <typename T, size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::front() {
  return arr_[0];
}

template <typename T, size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::back() {
  return arr_[N - 1];
}

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::data() {
  return arr_;
}

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::begin() {
  return arr_;
}

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::end() {
  return arr_ + N;
}

template <typename T, size_t N> bool s21::array<T, N>::empty() {
  return size_ == 0;
}

template <typename T, size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::size() {
  return size_;
}

template <typename T, size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::max_size() {
  return N;
}

template <typename T, size_t N> void s21::array<T, N>::swap(array &other) {
  if (this != &other) {
    for (size_type i = 0; i < N; ++i) {
      T tmp = arr_[i];
      arr_[i] = other.arr_[i];
      other.arr_[i] = tmp;
    }
    size_type tmp_size = size_;
    size_ = other.size_;
    other.size_ = tmp_size;
  }
}

template <typename T, size_t N>
void s21::array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < N; ++i) {
    arr_[i] = value;
  }
}

} // namespace s21