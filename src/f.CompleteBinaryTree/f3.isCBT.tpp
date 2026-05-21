// ============================================================================
// F3 Проверка дерева на завершенность (Complete Binary Tree)
// ============================================================================
// Алгоритм:
// - Используем очередь для уровня обхода
// - После первого узла с неполным поддеревом, все последующие узлы должны быть
// листьями
// - Если встречаем узел с неполным поддеревом после этого, дерево не
// завершенное

template <typename T>
bool CBTree<T>::isCBT() const {
  if (root_ == nullptr) {
    return false;
  }

  Queue<TreeNode<T>*> Q;
  Q.push(root_);
  // флажОК
  bool non_child_node = false;
  while (!Q.isEmpty()) {
    // делим на две операции: достаем, затем удаляем
    TreeNode<T>* current = Q.front();
    Q.pop();

    if (current->left_) {
      if (non_child_node) {
        return false;
      }
      Q.push(current->left_);
    } else {
      non_child_node = true;
    }

    if (current->right_) {
      if (non_child_node) {
        return false;
      }
      Q.push(current->right_);
    } else {
      non_child_node = true;
    }
  }
  return true;
}