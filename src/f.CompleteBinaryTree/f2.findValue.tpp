// ============================================================================
// F2 ПОИСК ЭЛЕМЕНТА
// ============================================================================

// Поиск элемента по значению (рекурсивный вспомогательный метод)
// Алгоритм:
// - Рекурсивно ищем в левом и правом поддеревьях
// - Сложность: O(n)
template <typename T>
bool CBTree<T>::find_value(TreeNode<T>* current, T value) const {
  if (current == nullptr) {
    return false;
  }
  if (current->data_ == value) {
    return true;
  }
  return find_value(current->left_, value) ||
         find_value(current->right_, value);
}

// Поиск элемента по значению (публичный метод)
// Алгоритм:
// - Вызываем рекурсивный метод
// - Сложность: O(n)
template <typename T>
bool CBTree<T>::get_value(T value) const {
  if (root_ == nullptr) {
    return false;
  }
  return find_value(root_, value);
}

// Поиск по индексу (обход в ширину)
// Алгоритм:
// - Используем очередь для обхода в ширину
// - Сложность: O(n)
template <typename T>
void CBTree<T>::find_index(int index) const {
  if (index < 0 || root_ == nullptr) {
    throw std::out_of_range("Invalid index.");
  }

  Queue<TreeNode<T>*> Q;
  Q.push(root_);
  int currentIndex = 0;

  while (!Q.isEmpty()) {
    TreeNode<T>* current = Q.front();
    Q.pop();
    if (currentIndex == index) {
      std::cout << current->data_ << std::endl;
      return;
    }
    currentIndex++;
    if (current->left_) {
      Q.push(current->left_);
    }
    if (current->right_) {
      Q.push(current->right_);
    }
  }
}