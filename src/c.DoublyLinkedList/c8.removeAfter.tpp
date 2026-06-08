// ============================================================================
// C8 Удаление элемента после указанного значения: CDELAFTER targetValue
// ============================================================================
// Сложность: O(n) - линейное время
// Алгоритм: линейный поиск + удаление
template <typename T>
void DoublyLinkedList<T>::removeAfter(const T& targetValue) {
  DoublyNode<T>* target = searchByValue(targetValue);
  if (target == nullptr) {
    throw std::runtime_error("Cannot remove after: target value not found: " +
                             targetValue);
  }
  if (target == tail_) {
    throw std::runtime_error("Cannot remove after: no element after tail");
  }
  DoublyNode<T>* toRemove = target->next_;
  if (toRemove == tail_) {
    removeFromTail();  // удаляем хвост
  } else {
    toRemove->next_->prev_ = target;
    target->next_ = toRemove->next_;
    delete toRemove;
    size_--;
  }
}