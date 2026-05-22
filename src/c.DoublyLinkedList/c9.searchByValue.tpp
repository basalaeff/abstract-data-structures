// ============================================================================
// B9 Поиск элемента по значению: BSEARCH value
// ============================================================================
// Сложность: O(n)

template <typename T>
DoublyNode<T>* DoublyLinkedList<T>::searchByValue(const T& value) const {
  DoublyNode<T>* current = head_;
  while (current != nullptr) {
    if (current->data_ == value) {
      return current;
    }
    current = current->next_;
  }
  return nullptr;
}