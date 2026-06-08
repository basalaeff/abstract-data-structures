// ============================================================================
// B15 СОХРАНЕНИЕ В БИНАРНЫЙ ФАЙЛ
// ============================================================================
template <typename T>
void SinglyLinkedList<T>::saveToBinaryFile(const std::string& filename) const {
  std::ofstream outFile(filename, std::ios::binary);
  if (!outFile) {
    std::cout << "Cannot open file for binary writing: " << filename
              << std::endl;
    return;
  }
  Node<T>* current = head_;
  while (current) {
    size_t len = current->data_.size();
    outFile.write(reinterpret_cast<const char*>(&len), sizeof(len));
    outFile.write(current->data_.c_str(), len);
    current = current->next_;
  }
  outFile.close();
}