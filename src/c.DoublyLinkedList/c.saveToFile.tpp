// ============================================================================
// СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================
template <typename T>
void DoublyLinkedList<T>::saveToFile(const std::string& filename) const {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return;
  }
  DoublyNode<T>* current = head_;
  while (current != nullptr) {
    file << current->data_ << "\n";
    current = current->next_;
  }
  file.close();
}
