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
