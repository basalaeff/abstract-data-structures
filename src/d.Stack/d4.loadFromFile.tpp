// ============================================================================
// D4 ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================

template <typename T>
void Stack<T>::loadFromFile(const std::string& filename) {
  // Очищаем текущий стек перед загрузкой
  while (top_ != nullptr) {
    pop();
  }

  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    throw std::out_of_range("Cannot open file for reading: " + filename);
  }

  T value;
  while (inFile >> value) {
    push(value);
  }
  inFile.close();

  // Переворачиваем стек обратно
  if (top_ == nullptr || top_->next_ == nullptr) {
    return;
  }

  Node<T>* prev = nullptr;
  Node<T>* curr = top_;
  Node<T>* next = nullptr;

  while (curr != nullptr) {
    next = curr->next_;
    curr->next_ = prev;
    prev = curr;
    curr = next;
  }

  top_ = prev;  // теперь порядок правильный
}