// ============================================================================
// B5 Вставка элемента перед указанным значением: BINSERTBEFORE targetValue
// newValue
// ============================================================================
// Сложность: O(n) - линейный поиск

template <typename T>
void DoublyLinkedList<T>::insertBefore(const T& targetValue,
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
  DoublyNode<T>* current = searchByValue(targetValue);

  // Если нашли узел перед целью — вставляем после него (то есть ДО цели)
  if (current->next_ != nullptr) {
    DoublyNode<T>* newNode = new DoublyNode<T>(newValue);
    newNode->prev_ = current->prev_;
    newNode->next_ = current;
    current->prev_->next_ = newNode;
    current->prev_ = newNode;
    size_++;
  } else {
    throw std::runtime_error("Target value not found: " + targetValue);
  }
}