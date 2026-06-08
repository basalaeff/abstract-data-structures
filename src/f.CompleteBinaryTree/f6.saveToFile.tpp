// ============================================================================
// F6 СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================
template <typename T>
void CBTree<T>::saveToFile(const std::string& file) const {
  if (root_ == nullptr) {
    throw std::runtime_error("Tree is empty.");
  }

  std::ofstream save(file);
  if (!save.is_open()) {
    throw std::runtime_error("Failed to open file for saving");
  }

  Queue<TreeNode<T>*> Q;
  Q.push(root_);
  while (!Q.isEmpty()) {
    TreeNode<T>* current = Q.front();
    Q.pop();
    save << current->data_ << std::endl;
    if (current->left_) {
      Q.push(current->left_);
    }
    if (current->right_) {
      Q.push(current->right_);
    }
  }
  save.close();
}