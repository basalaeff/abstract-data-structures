// ============================================================================
// B11 Вывод списка: PRINT
// ============================================================================
// Сложность: O(n)
template <typename T>
void SinglyLinkedList<T>::print() const {
  if (head_ == nullptr) {
    return;
  }
  Node<T>* current = head_;
  while (current != nullptr) {
    std::cout << current->data_ << " ";
    current = current->next_;
  }
}