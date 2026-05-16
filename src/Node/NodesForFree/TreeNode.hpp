#pragma once

// ============================================================================
// УЗЕЛ БИНАРНОГО ДЕРЕВА
// ============================================================================
// Класс TreeNode - узел бинарного дерева. Он содержит целочисленное значение,
// указатель на левый дочерний узел и указатель на правый дочерний узел.
class TreeNode {
 public:
  int data_;
  TreeNode* left_;
  TreeNode* right_;

  TreeNode(int value, TreeNode* leftNode = nullptr,
           TreeNode* rightNode = nullptr)
      : data_(value), left_(leftNode), right_(rightNode) {}
};
