// ============================================================================
// B6 Вставка элемента после указанного значения: BINSERTAFTER targetValue
// newValue
// ============================================================================
// Сложность: O(n) - линейное время
// Алгоритм: линейный поиск + вставка
template <typename T>
void SinglyLinkedList<T>::insertAfter(const T& targetValue, const T& newValue) {
  if (head_ == nullptr) {
    throw std::runtime_error("Cannot insert after: list is empty");
  }
  // Ищем целевой узел
  Node<T>* current = head_;
  while (current != nullptr && current->data_ != targetValue) {
    current = current->next_;
  }
  if (current == nullptr) {
    throw std::runtime_error("Target value not found: " + targetValue);
  }
  // Вставляем после найденного узла
  Node<T>* newNode = new Node<T>(newValue);
  newNode->next_ = current->next_;
  current->next_ = newNode;
  size_++;
}