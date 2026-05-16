#pragma once
#include <string>

#include "../a.Array/a.Array.hpp"
#include "../b.SinglyLinkedList/b.SinglyLinkedList.hpp"
#include "../c.DoublyLinkedList/c.DoublyLinkedList.hpp"
#include "../d.Stack/d.Stack.hpp"
#include "../e.Queue/e.Queue.hpp"

class ConsoleUI {
 private:
  Array& array_;
  SinglyLinkedList& singlyList_;
  DoublyLinkedList& doublyList_;
  Stack& stack_;
  Queue& queue_;

 public:
  // Конструктор принимает ссылки на структуру данных
  ConsoleUI(Array& a, SinglyLinkedList& sl, DoublyLinkedList& dl, Stack& s, Queue& q)
      : array_(a), singlyList_(sl), doublyList_(dl), stack_(s), queue_(q) {};

  // Основной метод обработки запроса
  void processQuery(const std::string& query);

  // Загрузка данных из файла
  void loadData(const std::string& filename, const std::string& query);

  // Сохранение данных в файл
  void saveData(const std::string& filename, const std::string& query);
};