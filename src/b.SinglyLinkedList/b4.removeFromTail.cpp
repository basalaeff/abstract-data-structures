#include "b.SinglyLinkedList.hpp"

// ============================================================================
// B4 Удаление элемента (из хвоста): BDELTAIL
// ============================================================================
// 1) Если список пуст — выбрасывается исключение.
// 2) Если в списке один элемент — голова становится nullptr.
// 3) Если элементов больше одного — выполняется обход до предпоследнего
// элемента
// 4) Память последнего элемента очищается
// 5) указатель предпоследнего устанавливается в nullptr.
// 6) Уменьшаем размер списка.
// Сложность: O(n) - требуется пройти почти весь список для нахождения
// предпоследнего элемента.

void SinglyLinkedList::removeFromTail() {
  if (head_ == nullptr) {
    throw std::runtime_error("Cannot remove tail: list is empty");
  }
  if (head_->next_ == nullptr) {
    delete head_;
    head_ = nullptr;
  } else {
    Node* current = head_;
    while (current->next_->next_ != nullptr) {
      current = current->next_;
    }
    delete current->next_;
    current->next_ = nullptr;
  }
  size_--;
}