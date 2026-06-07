// ============================================================================
// СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================

template <typename T>
void Queue<T>::saveToFile(const std::string& filename) const {
  std::ofstream outFile(filename);
  if (!outFile.is_open()) {
    throw std::out_of_range("Cannot open file for writing: " + filename);
  }
  Node<T>* temp = front_;
  while (temp != nullptr) {
    outFile << temp->data_ << std::endl;
    temp = temp->next_;
  }
  outFile.close();
}