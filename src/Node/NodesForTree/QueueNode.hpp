#include "TreeNode.hpp"
// ============================================================================
// УЗЕЛ ОЧЕРЕДИ ДЛЯ ОБХОДА ДЕРЕВА
// ============================================================================
// Класс QueueNode - вспомогательный узел очереди. Он хранит указатель на узел
// дерева и указатель на следующий элемент очереди.
class QueueNode {
 public:
  TreeNode* tree_;
  QueueNode* next_;

  QueueNode(TreeNode* treeNode = nullptr, QueueNode* nextNode = nullptr)
      : tree_(treeNode), next_(nextNode) {}
};

