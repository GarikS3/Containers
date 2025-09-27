#include "s21_vector.h"

namespace s21 {

template <typename T>
vector<T>::vector() : data_{nullptr}, size_{0}, capacity_{0} {};

template <typename T>
vector<T>::vector(size_type n) : data_{new T[n]()}, size_{n}, capacity_{n} {}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : data_(new T[items.size()]), size_(items.size()), capacity_(items.size()) {
  size_type i = 0;
  for (const auto &item : items) {
    data_[i++] = item;
  }
}

template <typename T>
vector<T>::vector(const vector &v)
    : data_{v.size_ ? new T[v.capacity_] : nullptr}, size_{v.size_},
      capacity_{v.capacity_} {
  if (data_) {
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = v.data_[i];
    }
  }
}

template <typename T>
vector<T>::vector(vector &&other)
    : data_{other.data_}, size_{other.size_}, capacity_{other.capacity_} {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename T> vector<T>::~vector() {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T> vector<T> &vector<T>::operator=(vector &&v) {
  if (this != &v) {
    delete[] data_;

    data_ = v.data_;
    size_ = v.size_;
    capacity_ = v.capacity_;

    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <class T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return data_[pos];
};

template <typename T> typename vector<T>::const_reference vector<T>::front() {
  return data_[0];
}

template <typename T> typename vector<T>::const_reference vector<T>::back() {
  return data_[size_ - 1];
}

template <typename T> T *vector<T>::data() { return data_; }

template <typename T> typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const {
  return const_iterator(data_);
}

template <typename T> typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const {
  return const_iterator(data_ + size_);
}

template <typename T> bool vector<T>::empty() { return size_ == 0; }

template <typename T> typename vector<T>::size_type vector<T>::size() {
  return size_;
}

template <typename T> typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <typename T> void vector<T>::reserve(size_type new_capacity) {
  if (new_capacity > capacity_) {
    T *new_data = new T[new_capacity];
    for (size_type i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
}

template <typename T> typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T> void vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    T *new_data = new T[size_];

    if (size > 0) {
      for (size_type i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
      capacity_ = size_;

    } else {
      delete[] data_;
      data_ = nullptr;
      capacity_ = 0;
    }
  }
}

template <typename T> void vector<T>::clear() {
  for (size_type i = 0; i < size_; ++i) {
    data_[i].~T();
  }
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  if (pos < begin() || pos > end()) {
    throw std::out_of_range("Insert position is out of range");
  }

  size_type index = pos - begin();
  if (size_ == capacity_)
    reserve(capacity_ ? capacity_ * 2 : 1);

  pos = begin() + index;
  for (iterator it = end() - 1; it >= pos; --it) {
    *(it + 1) = *(it);
  }
  *pos = value;
  ++size_;

  return pos;
}

template <typename T> void vector<T>::erase(iterator pos) {
  if (pos < begin() || pos >= end()) {
    throw std::out_of_range("Erase position is out of range");
  }

  for (iterator it = pos; it + 1 != end(); ++it) {
    *it = *(it + 1);
  }
  --size_;
}

template <typename T> void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  data_[size_] = value;
  ++size_;
}

template <typename T> void vector<T>::pop_back() {
  if (size_ > 0) {
    data_[size_ - 1].~T();
    --size_;
  }
}

template <typename T> void vector<T>::swap(vector &other) {
  T *tmp_data = data_;
  size_t tmp_size = size_;
  size_t tmp_capacity = capacity_;

  data_ = other.data_;
  size_ = other.size_;
  capacity_ = other.capacity_;

  other.data_ = tmp_data;
  other.size_ = tmp_size;
  other.capacity_ = tmp_capacity;
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  size_type offset = pos - cbegin();
  iterator it = begin() + offset;
  ((it = insert(it, args) + 1), ...);

  return begin() + offset;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  (push_back(args), ...);
}

} // namespace s21