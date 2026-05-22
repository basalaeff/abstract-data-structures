// ============================================================================
// B7 Удаление элемента перед указанным значением: BDELBEFORE targetValue
// ============================================================================
// Сложность: O(n) - линейное время
// Алгоритм: линейный поиск + удаление

template <typename T>
void DoublyLinkedList<T>::removeBefore(const T& targetValue) {
  DoublyNode<T>* target = searchByValue(targetValue);
  if (target == nullptr) {
    throw std::runtime_error("Cannot remove before: target value not found: " +
                             targetValue);
  }
  if (target == head_) {
    throw std::runtime_error("Cannot remove before: no element before head");
  }
  DoublyNode<T>* toRemove = target->prev_;
  if (toRemove == head_) {
    removeFromHead();  // удаляем голову
  } else {
    toRemove->prev_->next_ = target;
    target->prev_ = toRemove->prev_;
    delete toRemove;
    size_--;
  }
}