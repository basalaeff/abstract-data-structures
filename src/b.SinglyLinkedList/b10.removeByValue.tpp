// ============================================================================
// B10 Удаление элемента по значению: BREMOVE value
// ============================================================================
// Сложность: O(n)
template <typename T>
void SinglyLinkedList<T>::removeByValue(const T& value) {
  if (head_ == nullptr) {
    throw std::runtime_error("Cannot remove by value: list is empty");
  }
  // Если значение находится в head - удалить head
  if (head_->data_ == value) {
    removeFromHead();
    return;
  }
  Node<T>* current = head_;
  // Ищем узел, чей next содержит значение
  while (current->next_ != nullptr) {
    if (current->next_->data_ == value) {
      Node<T>* temp = current->next_;
      current->next_ = temp->next_;
      delete temp;
      size_--;
      return;
    }
    current = current->next_;
  }
  // Значение не найдено
  throw std::runtime_error("Value not found: " + value);
}