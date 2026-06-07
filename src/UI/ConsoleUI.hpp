#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <string>
#include <stdexcept>
#include "../a.Array/a.Array.hpp"
#include "../b.SinglyLinkedList/b.SinglyLinkedList.hpp"
#include "../c.DoublyLinkedList/c.DoublyLinkedList.hpp"
#include "../d.Stack/d.Stack.hpp"
#include "../e.Queue/e.Queue.hpp"
#include "../f.CompleteBinaryTree/f.CBTree.hpp"


template <typename T>
class ConsoleUI {
 private:
  Array<T>& array_;
  SinglyLinkedList<T>& singlyList_;
  DoublyLinkedList<T>& doublyList_;
  Stack<T>& stack_;
  Queue<T>& queue_;
  CBTree<T>& cbtree_;

 public:
  // Конструктор принимает ссылки на структуры данных
  ConsoleUI(Array<T>& a, SinglyLinkedList<T>& sl, DoublyLinkedList<T>& dl,
            Stack<T>& s, Queue<T>& q, CBTree<T>& cbt)
      : array_(a),
        singlyList_(sl),
        doublyList_(dl),
        stack_(s),
        queue_(q),
        cbtree_(cbt) {};

  // Основной метод обработки запроса
  void processQuery(const std::string& query);

  // Загрузка данных из файла
  void loadData(const std::string& filename, const std::string& query);

  // Сохранение данных в файл
  void saveData(const std::string& filename, const std::string& query);
};

#include "loadData.tpp"
#include "processQuery.tpp"
#include "saveData.tpp"
