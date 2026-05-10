#include "ConsoleUI.hpp"

// ============================================================================
// КОНСТРУКТОР
// ============================================================================
// Конструктор принимает ссылки на структуры данных

ConsoleUI::ConsoleUI(Array& a, SinglyLinkedList& sl, DoublyLinkedList& dl)
    : array_(a), singlyList_(sl), doublyList_(dl) {};