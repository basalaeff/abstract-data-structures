// ============================================================================
// C6 Вставка элемента после указанного значения: CINSERTAFTER targetValue
// newValue
// ============================================================================
// Сложность: O(n) - линейное время
// Алгоритм: линейный поиск + вставка
template <typename T>
void DoublyLinkedList<T>::insertAfter(const T& targetValue, const T& newValue) {
  if (head_ == nullptr) {
    throw std::runtime_error("Cannot insert after: list is empty");
  }
  // Ищем целевой узел
  DoublyNode<T>* current = searchByValue(targetValue);
  if (current == nullptr) {
    throw std::runtime_error("Target value not found: " + targetValue);
  }
  // Вставляем после найденного узла
  DoublyNode<T>* newNode = new DoublyNode<T>(newValue);
  newNode->next_ = current->next_;
  newNode->prev_ = current;
  current->next_->prev_ = newNode;
  current->next_ = newNode;
  size_++;
}