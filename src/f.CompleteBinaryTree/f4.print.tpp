// ============================================================================
// F4 Вывод дерева
// ============================================================================
// Вывод дерева (вертикальный обход)
// Параметры:
//   current - текущий узел
//   level - уровень вложенности
// Алгоритм:
//   1. Рекурсивно обходим правое поддерево
//   2. Выводим текущий узел с отступом level
//   3. Рекурсивно обходим левое поддерево
// Сложность: O(n)

template <typename T>
void CBTree<T>::print_CBT(TreeNode<T>* current, int level) const {
  if (current) {
    print_CBT(current->right_, level + 1);
    for (int i = 0; i < level; i++) {
      std::cout << "\t";
    }
    std::cout << current->data_ << std::endl;
    print_CBT(current->left_, level + 1);
  }
}
// Вывод в консоль
// Сложность: O(n)
template <typename T>
void CBTree<T>::print() const {
  if (root_ == nullptr) {
    throw std::out_of_range("Tree is empty.");
  }
  print_CBT(root_, 0);
}