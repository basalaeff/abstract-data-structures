// ============================================================================
// B7 Удаление элемента перед указанным значением: BDELBEFORE targetValue
// ============================================================================
// Сложность: O(n) - линейное время
// Алгоритм: линейный поиск + удаление

template <typename T>
void SinglyLinkedList<T>::removeBefore(const T& targetValue) {
  if (head_ == nullptr) {
    throw std::runtime_error("Cannot remove before: list is empty");
  }
  // удаляем голову (если targetValue во втором узле)
  if (head_->next_ != nullptr && head_->next_->data_ == targetValue) {
    removeFromHead();
    return;
  }
  // ищем узел ДО целевого (нужен предыдущий узел)
  Node<T>* prev = head_;
  Node<T>* current = head_->next_;
  while (current != nullptr && current->next_ != nullptr &&
         current->next_->data_ != targetValue) {
    prev = current;
    current = current->next_;
  }
  // Проверяем, нашли ли узел ДО цели
  if (current != nullptr && current->next_ != nullptr &&
      current->next_->data_ == targetValue) {
    // current — это узел ДО целевого. удаляем его
    prev->next_ = current->next_;
    delete current;
    size_--;
  } else {
    throw std::runtime_error(
        "Target value not found or no element before it: " + targetValue);
  }
}