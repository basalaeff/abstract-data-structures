#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

template <typename T>
class ConsoleUI {
 private:
  Array<T>& array_;
  SinglyLinkedList<T>& singlyList_;
  DoublyLinkedList<T>& doublyList_;
  Stack<T>& stack_;
  Queue<T>& queue_;

 public:
  // Конструктор принимает ссылки на структуру данных
  ConsoleUI(Array<T>& a, SinglyLinkedList<T>& sl, DoublyLinkedList<T>& dl, Stack<T>& s, Queue<T>& q)
      : array_(a), singlyList_(sl), doublyList_(dl), stack_(s), queue_(q) {};

  // Основной метод обработки запроса
  void processQuery(const std::string& query);

  // Загрузка данных из файла
  void loadData(const std::string& filename, const std::string& query);

  // Сохранение данных в файл
  void saveData(const std::string& filename, const std::string& query);
};

#include "loadData.tpp"
#include "saveData.tpp"
#include "processQuery.tpp"