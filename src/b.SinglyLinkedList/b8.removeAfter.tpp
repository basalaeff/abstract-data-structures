// ============================================================================
// B8 Удаление элемента после указанного значения: BDELAFTER targetValue
// ============================================================================
// Сложность: O(n) - линейное время
// Алгоритм: линейный поиск + удаление
template <typename T>
void SinglyLinkedList<T>::removeAfter(const T& targetValue) {
  if (head_ == nullptr) {
    throw std::runtime_error("Cannot remove after: list is empty");
  }
  // Ищем целевой узел
  Node<T>* current = head_;
  while (current != nullptr && current->data_ != targetValue) {
    current = current->next_;
  }
  if (current == nullptr) {
    throw std::runtime_error("Target value not found: " + targetValue);
  }
  if (current->next_ == nullptr) {
    throw std::runtime_error("No element after target value");
  }
  // Удаляем следующий узел
  Node<T>* temp = current->next_;
  current->next_ = temp->next_;
  delete temp;
  size_--;
}