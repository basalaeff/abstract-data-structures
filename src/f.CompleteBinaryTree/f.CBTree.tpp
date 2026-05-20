// Конструктор
template <typename T>
CBTree<T>::CBTree() : root_(nullptr) {}

// Деструктор
template <typename T>
CBTree<T>::~CBTree() { clear(root_); }

// Очистка дерева (рекурсивное удаление)
template <typename T>
void CBTree<T>::clear(TreeNode<T>*& node) {
  if (node) {
    clear(node->left_);
    clear(node->right_);
    delete node;
    node = nullptr;
  }
}
