#pragma once
#include <string>

// ============================================================================
// УЗЕЛ ДВУСВЯЗНОГО СПИСКА
// ============================================================================
// Класс DoublyNode - узел. Он содержит строковое значение, указатель на
// следующий узел и указатель на предыдущий узел.

struct DoublyNode {
  std::string data_;
  DoublyNode* next_;
  DoublyNode* prev_;

  DoublyNode(const std::string& value, DoublyNode* nextNode = nullptr,
             DoublyNode* prevNode = nullptr)
      : data_(value), next_(nextNode), prev_(prevNode) {}
};