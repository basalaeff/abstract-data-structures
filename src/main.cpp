#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "a.Array/a.Array.hpp"
#include "b.SinglyLinkedList/b.SinglyLinkedList.hpp"
#include "c.DoublyLinkedList/c.DoublyLinkedList.hpp"
#include "d.Stack/d.Stack.hpp"
#include "e.Queue/e.Queue.hpp"
#include "f.CompleteBinaryTree/f.CBTree.hpp"
#include "UI/consoleUI.hpp"

int main(int argc, char *argv[]) {
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
  ui.loadData(filename, query);

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
  ui.saveData(filename, query);

  return 0;
}