// ============================================================================
// F8 СОХРАНЕНИЕ В БИНАРНЫЙ ФАЙЛ
// ============================================================================
template <typename T>
void CBTree<T>::saveToBinaryFile(const std::string& file) const {
  if (root_ == nullptr) {
    throw std::runtime_error("Tree is empty.");
  }

  std::ofstream save(file, std::ios::binary);
  if (!save.is_open()) {
    throw std::runtime_error("Failed to open file for saving");
  }

  Queue<TreeNode<T>*> Q;
  Q.push(root_);

  while (!Q.isEmpty()) {
    TreeNode<T>* current = Q.front();
    Q.pop();

    // 1. Сохраняем размер строки
    size_t len = current->data_.size();
    save.write(reinterpret_cast<const char*>(&len), sizeof(size_t));

    // 2. Сохраняем сами данные
    if (len > 0) {
      save.write(current->data_.c_str(), len);
    }

    if (current->left_) {
      Q.push(current->left_);
    }
    if (current->right_) {
      Q.push(current->right_);
    }
  }

  save.close();
}