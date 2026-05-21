#pragma once
#include <string>

// ============================================================================
// УЗЕЛ ОДНОСВЯЗНОГО СПИСКА
// ============================================================================
// Класс Node - узел. Он содержит значение и указатель на следующий узел.
template <typename T>
class Node {
 public:
  T data_;
  Node* next_;

  Node(const T& value, Node* nextNode = nullptr)
      : data_(value), next_(nextNode) {}
};
