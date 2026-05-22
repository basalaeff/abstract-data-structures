// ============================================================================
// B11 Вывод списка: PRINT
// ============================================================================
// Сложность: O(n)
template<typename T>
void DoublyLinkedList<T>::print() const {
  DoublyNode<T>* current = head_;
  while (current != nullptr) {
    std::cout << current->data_ << " ";
    current = current->next_;
  }
}