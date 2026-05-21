#pragma once
#include <string>

// ============================================================================
// УЗЕЛ ДВУСВЯЗНОГО СПИСКА
// ============================================================================
// Класс DoublyNode - узел. Он содержит значение, указатель на
// следующий узел и указатель на предыдущий узел.

template <typename T>
struct DoublyNode {
  T data_;
  DoublyNode* next_;
  DoublyNode* prev_;

  DoublyNode(const T& value, DoublyNode* nextNode = nullptr,
             DoublyNode* prevNode = nullptr)
      : data_(value), next_(nextNode), prev_(prevNode) {}
};