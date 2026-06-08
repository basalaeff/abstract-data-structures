// ============================================================================
// E7 СОХРАНЕНИЕ В БИНАРНЫЙ ФАЙЛ
// ============================================================================
template <typename T>
void Queue<T>::saveToBinaryFile(const std::string& filename) const {
  std::ofstream outFile(filename, std::ios::binary);
  if (!outFile) {
    std::cout << "Cannot open file for binary writing: " << filename
              << std::endl;
    return;
  }
  Node<T>* temp = front_;
  while (temp) {
    size_t len = temp->data_.size();
    outFile.write(reinterpret_cast<const char*>(&len), sizeof(len));
    outFile.write(temp->data_.c_str(), len);
    temp = temp->next_;
  }
  outFile.close();
}
