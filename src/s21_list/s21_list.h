#ifndef S21_LIST_H_
#define S21_LIST_H_

#include <initializer_list>
#include <limits>
#include <stdexcept>

namespace s21 {

template <typename T> class list {
public:
  class ListIterator;
  class ListConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

private:
  struct Node {
    T data;
    Node *prev;
    Node *next;

    Node(const T &value = T(), Node *p = nullptr, Node *n = nullptr)
        : data(value), prev(p), next(n) {}
  };
  Node *head;
  Node *tail;
  size_type size_;

public:
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);

  const_reference front();
  const_reference back();

  iterator begin();
  const_iterator cbegin() const;
  iterator end();
  const_iterator cend() const;

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <typename... Args> void insert_many_back(Args &&...args);

  template <typename... Args> void insert_many_front(Args &&...args);

  class ListIterator {
  public:
    ListIterator(Node *ptr = nullptr) : node_(ptr) {}
    ListIterator(const ListConstIterator &other)
        : node_(const_cast<Node *>(other.node_)) {}

    reference operator*() { return node_->data; }

    ListIterator &operator++() {
      node_ = node_->next;
      return *this;
    }

    ListIterator operator++(int) {
      ListIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    ListIterator &operator--() {
      node_ = node_->prev;
      return *this;
    }

    ListIterator operator--(int) {
      ListIterator tmp = *this;
      --(*this);
      return tmp;
    }

    bool operator==(const ListIterator &other) const {
      return node_ == other.node_;
    }
    bool operator!=(const ListIterator &other) const {
      return !(*this == other);
    }

  private:
    Node *node_;
    friend class list<T>;
  };

  class ListConstIterator {
  public:
    ListConstIterator(const Node *ptr = nullptr) : node_(ptr) {}
    ListConstIterator(const ListIterator &other) : node_(other.node_) {}

    const_reference operator*() const { return node_->data; }

    ListConstIterator &operator++() {
      node_ = node_->next;
      return *this;
    }

    ListConstIterator operator++(int) {
      ListConstIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    ListConstIterator &operator--() {
      if (node_)
        node_ = node_->prev;
      return *this;
    }

    ListConstIterator operator--(int) {
      ListConstIterator tmp = *this;
      --(*this);
      return tmp;
    }

    bool operator==(const ListConstIterator &other) const {
      return node_ == other.node_;
    }
    bool operator!=(const ListConstIterator &other) const {
      return !(*this == other);
    }

  private:
    const Node *node_;
    friend class list<T>;
  };
};

} // namespace s21

#include "s21_list.tpp"

#endif