#pragma once

// ============================================================================
// УЗЕЛ БИНАРНОГО ДЕРЕВА
// ============================================================================
// Класс TreeNode - узел бинарного дерева. Он содержит целочисленное значение,
// указатель на левый дочерний узел и указатель на правый дочерний узел.
template <typename T>
class TreeNode {           
 public:
  T data_;
  TreeNode* left_;
  TreeNode* right_;

  TreeNode(T value, TreeNode* leftNode = nullptr,
           TreeNode* rightNode = nullptr)
      : data_(value), left_(leftNode), right_(rightNode) {}
};
