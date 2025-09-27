#include "s21_list.h"

namespace s21 {

template <typename T>
list<T>::list() : head(nullptr), tail(nullptr), size_(0) {}

template <typename T> list<T>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items) : list() {
  for (const auto &item : items) {
    push_back(item);
  }
}

template <typename T> list<T>::list(const list &l) : list() {
  for (Node *current = l.head; current != nullptr; current = current->next) {
    push_back(current->data);
  }
}

template <typename T>
list<T>::list(list &&l) : head(l.head), tail(l.tail), size_(l.size_) {
  l.head = nullptr;
  l.tail = nullptr;
  l.size_ = 0;
}

template <typename T> list<T>::~list() { clear(); }

template <typename T> list<T> &list<T>::operator=(list &&l) {
  if (this != &l) {
    clear();
    head = l.head;
    tail = l.tail;
    size_ = l.size_;
    l.head = nullptr;
    l.tail = nullptr;
    l.size_ = 0;
  }
  return *this;
}

template <typename T> typename list<T>::const_reference list<T>::front() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  return head->data;
}

template <typename T> typename list<T>::const_reference list<T>::back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  return tail->data;
}

template <typename T> typename list<T>::iterator list<T>::begin() {
  return iterator(head);
}

template <typename T> typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(head);
}

template <typename T> typename list<T>::iterator list<T>::end() {
  return iterator(nullptr);
}

template <typename T> typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(nullptr);
}

template <typename T> bool list<T>::empty() { return size_ == 0; }

template <typename T> typename list<T>::size_type list<T>::size() {
  return size_;
}

template <typename T> typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(Node);
}

template <typename T> void list<T>::clear() {
  while (head) {
    pop_front();
  }
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node *new_node = new Node(value);
  Node *cur_node = pos.node_;

  if (!cur_node) {
    new_node->prev = tail;
    if (tail) {
      tail->next = new_node;
    } else {
      head = new_node;
    }
    tail = new_node;
  } else {
    new_node->next = cur_node;
    new_node->prev = cur_node->prev;
    if (cur_node->prev) {
      cur_node->prev->next = new_node;
    } else {
      head = new_node;
    }
    cur_node->prev = new_node;
  }
  ++size_;

  return iterator(new_node);
}

template <class T> void list<T>::erase(iterator pos) {
  Node *node = pos.node_;
  if (node) {
    if (node->prev) {
      node->prev->next = node->next;
    } else {
      head = node->next;
    }

    if (node->next) {
      node->next->prev = node->prev;
    } else {
      tail = node->prev;
    }

    delete node;
    --size_;
  }
}

template <typename T> void list<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <typename T> void list<T>::pop_back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  erase(iterator(tail));
}

template <typename T> void list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T> void list<T>::pop_front() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  erase(begin());
}

template <typename T> void list<T>::swap(list &other) {
  Node *tmp_head = head;
  head = other.head;
  other.head = tmp_head;

  Node *tmp_tail = tail;
  tail = other.tail;
  other.tail = tmp_tail;

  size_type tmp_size = size_;
  size_ = other.size_;
  other.size_ = tmp_size;
}

template <typename T> void list<T>::merge(list &other) {
  if (this != &other) {
    iterator it1 = begin();
    iterator it2 = other.begin();

    while (it1 != end() && it2 != other.end()) {
      if (*it2 < *it1) {
        iterator next = it2;
        ++next;

        insert(it1, *it2);
        other.erase(it2);
        it2 = next;
      } else {
        ++it1;
      }
    }

    while (it2 != other.end()) {
      iterator next = it2;
      ++next;
      insert(end(), *it2);
      other.erase(it2);
      it2 = next;
    }
  }
}

template <typename T> void list<T>::splice(const_iterator pos, list &other) {
  if (this != &other && !other.empty()) {
    Node *insert_pos = const_cast<Node *>(pos.node_);
    if (insert_pos) {
      Node *before = insert_pos->prev;
      other.head->prev = before;
      other.tail->next = insert_pos;
      if (before) {
        before->next = other.head;
      } else {
        head = other.head;
      }
      insert_pos->prev = other.tail;

    } else {
      if (tail) {
        tail->next = other.head;
        other.head->prev = tail;
      } else {
        head = other.head;
      }
      tail = other.tail;
    }
    size_ += other.size_;
    other.head = other.tail = nullptr;
    other.size_ = 0;
  }
}

template <typename T> void list<T>::reverse() {
  if (size_ > 1) {
    Node *cur_node = head;
    Node *tmp = nullptr;

    while (cur_node) {
      tmp = cur_node->prev;
      cur_node->prev = cur_node->next;
      cur_node->next = tmp;

      cur_node = cur_node->prev;
    }
    tmp = head;
    head = tail;
    tail = tmp;
  }
}

template <typename T> void list<T>::unique() {
  if (size_ > 1) {
    Node *cur_node = head;

    while (cur_node && cur_node->next) {
      if (cur_node->data == cur_node->next->data) {
        Node *tmp = cur_node->next;
        cur_node->next = tmp->next;

        if (tmp->next) {
          cur_node->next->prev = cur_node;
        } else {
          tail = cur_node;
        }
        delete tmp;
        size_--;

      } else {
        cur_node = cur_node->next;
      }
    }
  }
}

template <typename T> void list<T>::sort() {
  if (size_ >= 2) {
    list<T> sorted;

    while (!empty()) {
      iterator current = begin();
      T value = *current;
      erase(current);

      iterator insert_pos = sorted.begin();

      while (insert_pos != sorted.end() && *insert_pos < value) {
        ++insert_pos;
      }
      sorted.insert(insert_pos, value);
    }
    splice(begin(), sorted);
  }
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator result = iterator(const_cast<Node *>(pos.node_));

  if (sizeof...(args) > 0) {
    list<T> tmp_list;
    (tmp_list.push_back(args), ...);

    iterator it = begin();
    const_iterator cit = cbegin();

    while (cit != pos && cit != end()) {
      ++it;
      ++cit;
    }
    splice(it, tmp_list);
    result = it;
  }
  return result;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  for (auto arg : {args...}) {
    push_back(arg);
  }
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  T arguments[] = {std::forward<Args>(args)...};
  for (int i = static_cast<int>(sizeof...(args)) - 1; i >= 0; --i) {
    push_front(arguments[i]);
  }
}

} // namespace s21