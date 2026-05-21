// ============================================================================
// B5 Вставка элемента перед указанным значением: BINSERTBEFORE targetValue
// newValue
// ============================================================================
// Сложность: O(n) - линейный поиск

template <typename T>
void SinglyLinkedList<T>::insertBefore(const T& targetValue,
                                       const T& newValue) {
  if (head_ == nullptr) {
    throw std::runtime_error("Cannot insert before: list is empty");
  }
  // targetValue в голове, вставляем новую голову
  if (head_->data_ == targetValue) {
    addToHead(newValue);
    return;
  }
  // ищем узел ДО целевого
  Node<T>* current = head_;
  while (current->next_ != nullptr && current->next_->data_ != targetValue) {
    current = current->next_;
  }
  // Если нашли узел перед целью — вставляем после него (то есть ДО цели)
  if (current->next_ != nullptr) {
    Node<T>* newNode = new Node(newValue);
    newNode->next_ = current->next_;
    current->next_ = newNode;
    size_++;
  } else {
    throw std::runtime_error("Target value not found: " + targetValue);
  }
}