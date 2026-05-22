// ============================================================================
// B10 Удаление элемента по значению: BREMOVE value
// ============================================================================
// Сложность: O(n)
template <typename T>
void DoublyLinkedList<T>::removeByValue(const T& value) {
  DoublyNode<T>* toRemove = searchByValue(value);
  if (toRemove == nullptr) {
    throw std::runtime_error(
        "Cannot remove by value: target value not found: " + value);
  }
  if (toRemove == head_) {
    removeFromHead();
  } else if (toRemove == tail_) {
    removeFromTail();
  } else {
    toRemove->prev_->next_ = toRemove->next_;
    toRemove->next_->prev_ = toRemove->prev_;
    delete toRemove;  // Удаляем узел
    size_--;          // Уменьшаем размер списка
  }
  return;  // удаляем только первое вхождение
}