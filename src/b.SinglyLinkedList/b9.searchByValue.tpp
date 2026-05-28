// ============================================================================
// B9 Поиск элемента по значению: BSEARCH value
// ============================================================================
// Сложность: O(n)

template <typename T>
Node<T>* SinglyLinkedList<T>::searchByValue(const T& value) const {
  Node<T>* current = head_;
  while (current != nullptr) {
    if (current->data_ == value) {
      return current;
    }
    current = current->next_;
  }
  return nullptr;
}