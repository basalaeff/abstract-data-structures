#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "UI/ConsoleUI.hpp"

int main(int argc, char *argv[]) {
  // BINARY || TEXT
  const Format currentFormat = Format::BINARY;

  std::string query;
  std::string filename;
  Array<std::string> array(10);              // Массив
  SinglyLinkedList<std::string> singlyList;  // Односвязный список
  DoublyLinkedList<std::string> doublyList;  // Двусвязный список
  Stack<std::string> stack;                  // Стек
  Queue<std::string> queue;                  //
  CBTree<std::string> cbtree;                // Дерево

  ConsoleUI ui(array, singlyList, doublyList, stack, queue, cbtree);

  // Чтение аргументов командной строки
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--file" && i + 1 < argc) {
      filename = argv[++i];
    }
    if (arg == "--query" && i + 1 < argc) {
      query = argv[++i];
    }
  }

  // ================================================
  // Загрузка данных
  // ================================================
  ui.loadData(filename, query, currentFormat);

  // ================================================
  // Выполнение запроса
  // ================================================
  if (!query.empty()) {
    ui.processQuery(query);
  } else {
    std::cout << "Error: query not specified." << std::endl;
    return 1;
  }

  // ================================================
  // Сохранение данных
  // ================================================
  ui.saveData(filename, query, currentFormat);

  return 0;
}