#pragma once
#include <string>

#include "../a.Array/a.Array.hpp"
#include "../b.SinglyLinkedList/b.SinglyLinkedList.hpp"

class ConsoleUI {
 private:
  Array& array_;
  SinglyLinkedList& singlyList_;

 public:
  // Конструктор принимает ссылки на структуру данных
  ConsoleUI(Array& a, SinglyLinkedList& sl);

  // Основной метод обработки запроса
  void processQuery(const std::string& query);

  // Загрузка данных из файла
  void loadData(const std::string& filename, const std::string& query);

  // Сохранение данных в файл
  void saveData(const std::string& filename, const std::string& query);
};