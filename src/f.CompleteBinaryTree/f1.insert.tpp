// ============================================================================
// F1 ДОБАВЛЕНИЕ ЭЛЕМЕНТА
// ============================================================================
// Добавление элемента в полное бинарное дерево (обход в ширину)
// Алгоритм:
// 1) Создаем новый узел
// 2) Если дерево пустое, новый узел - root_
// 3) Иначе используем очередь для обхода в ширину
// 4) Находим первый узел, у которого есть свободное место
// 5) Добавляем новый узел в левое или правое поддерево
// Сложность: O(n), где n - количество узлов в дереве

template <typename T>
void CBTree<T>::insert(T value) {
  TreeNode<T>* new_node = new TreeNode<T>(value);
  if (root_ == nullptr) {
    root_ = new_node;
    return;
  }
  Queue<TreeNode<T>*> Q;
  Q.push(root_);
  while (!Q.isEmpty()) {
    TreeNode<T>* current = Q.front();
    Q.pop();
    if (current->left_ == nullptr) {
      current->left_ = new_node;
      return;
    } else {
      Q.push(current->left_);
    }
    if (current->right_ == nullptr) {
      current->right_ = new_node;
      return;
    } else {
      Q.push(current->right_);
    }
  }
}