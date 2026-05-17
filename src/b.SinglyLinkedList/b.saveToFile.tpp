// ============================================================================
// СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================
template <typename T>
void SinglyLinkedList<T>::saveToFile(const std::string& filename) const {
  std::ofstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Cannot open file for writing: " + filename);
  }
  Node<T>* current = head_;
  while (current != nullptr) {
    file << current->data_ << std::endl;
    current = current->next_;
  }
  file.close();
}
