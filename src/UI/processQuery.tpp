// ============================================================================
// ФУНКЦИЯ ОБРАБОТКИ ЗАПРОСОВ
// ============================================================================
template <typename T>
void ConsoleUI<T>::processQuery(const std::string& query) {
  std::vector<std::string> tokens;
  std::stringstream ss(query);
  std::string token;

  while (std::getline(ss, token, ' ')) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }

  if (tokens.empty()) {
    std::cout << "Error: empty query." << std::endl;
    return;
  }

  const std::string& cmd = tokens[0];

  // ============================================================================
  // МАССИВ(A)
  // ============================================================================

  // ============================================================================
  // A1 Добавление элемента(в конец массива): AADD value
  // ============================================================================
  if (cmd == "AADD") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      array_.addToTheEnd(value);
    } else {
      std::cout << "Error: AADD command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // A2 Добавление элемента(по индексу): AINSERT index value
    // ============================================================================
  } else if (cmd == "AINSERT") {
    if (tokens.size() == 3) {
      int index = stoi(tokens[1]);
      T value = tokens[2];
      array_.addToTheIndex(index, value);
    } else {
      std::cout << "Error: AINSERT command requires 2 arguments." << std::endl;
    }
    // ============================================================================
    // A3 Получение элемента(по индексу): AGET index
    // ============================================================================
  } else if (cmd == "AGET") {
    if (tokens.size() == 2) {
      int index = stoi(tokens[1]);
      T item = array_.get(index);
      std::cout << "Item by index " << index << ": " << item << std::endl;
    } else {
      std::cout << "Error: AGET command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // A4 Удаление элемента(по индексу): ADEL index
    // ============================================================================
  } else if (cmd == "ADEL") {
    if (tokens.size() == 2) {
      int index = stoi(tokens[1]);
      array_.removeByIndex(index);
    } else {
      std::cout << "Error: ADEL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // A5 Замена элемента(по индексу): ASET index value
    // ============================================================================
  } else if (cmd == "AREPLACE") {
    if (tokens.size() == 3) {
      int index = stoi(tokens[1]);
      T value = tokens[2];
      array_.replaceByIndex(index, value);
    } else {
      std::cout << "Error: AREPLACE command requires 2 arguments." << std::endl;
    }
    // ============================================================================
    // A6 Получение длины массива: ALENGTH
    // ============================================================================
  } else if (cmd == "ALEN") {
    if (tokens.size() == 1) {
      std::cout << "Length of the array: " << array_.length() << std::endl;
    } else {
      std::cout << "Error: ALEN command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // B1 Добавление элемента (в голову): BADDHEAD value
    // ============================================================================
  } else if (cmd == "BADDHEAD") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      singlyList_.addToHead(value);
    } else {
      std::cout << "Error: BADDHEAD command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // B2 Добавление элемента (в хвост): BADDTAIL value
    // ============================================================================
  } else if (cmd == "BADDTAIL") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      singlyList_.addToTail(value);
    } else {
      std::cout << "Error: BADDTAIL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // B3 Удаление элемента (из головы): BDELHEAD
    // ============================================================================
  } else if (cmd == "BDELHEAD") {
    if (tokens.size() == 1) {
      singlyList_.removeFromHead();
    } else {
      std::cout << "Error: BDELHEAD command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // B4 Удаление элемента (из хвоста): BDELTAIL
    // ============================================================================
  } else if (cmd == "BDELTAIL") {
    if (tokens.size() == 1) {
      singlyList_.removeFromTail();
    } else {
      std::cout << "Error: BDELTAIL command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // B5 Вставка элемента перед указанным значением: BINSERTBEFORE targetValue
    // newValue
    // ============================================================================
  } else if (cmd == "BINSERTBEFORE") {
    if (tokens.size() == 3) {
      T targetValue = tokens[1];
      T newValue = tokens[2];
      singlyList_.insertBefore(targetValue, newValue);
    } else {
      std::cout << "Error: BINSERTBEFORE command requires 2 arguments."
                << std::endl;
    }
    // ============================================================================
    // B6 Вставка элемента после указанного значения: BINSERTAFTER targetValue
    // newValue
    // ============================================================================
  } else if (cmd == "BINSERTAFTER") {
    if (tokens.size() == 3) {
      T targetValue = tokens[1];
      T newValue = tokens[2];
      singlyList_.insertAfter(targetValue, newValue);
    } else {
      std::cout << "Error: BINSERTAFTER command requires 2 arguments."
                << std::endl;
    }
    // ============================================================================
    // B7 Удаление элемента перед указанным значением: BDELBEFORE targetValue
    // ============================================================================
  } else if (cmd == "BDELBEFORE") {
    if (tokens.size() == 2) {
      T targetValue = tokens[1];
      singlyList_.removeBefore(targetValue);
    } else {
      std::cout << "Error: BDELBEFORE command requires 1 arguments."
                << std::endl;
    }
    // ============================================================================
    // B8 Удаление элемента после указанного значения: BDELAFTER targetValue
    // ============================================================================
  } else if (cmd == "BDELAFTER") {
    if (tokens.size() == 2) {
      T targetValue = tokens[1];
      singlyList_.removeAfter(targetValue);
    } else {
      std::cout << "Error: BDELAFTER command requires 1 arguments."
                << std::endl;
    }
    // ============================================================================
    // B9 Поиск элемента по значению: BSEARCH value
    // ============================================================================
  } else if (cmd == "BSEARCH") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      Node<T>* result = singlyList_.search(value);
      if (result != nullptr) {
        std::cout << "Value " << value << " found in the list." << std::endl;
      } else {
        std::cout << "Value " << value << " not found in the list."
                  << std::endl;
      }
    } else {
      std::cout << "Error: BSEARCH command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // B10 Удаление элемента по значению: BDEL value
    // ============================================================================
  } else if (cmd == "BDEL") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      singlyList_.removeByValue(value);
    } else {
      std::cout << "Error: BDEL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // C1 Добавление элемента (в голову): CADDHEAD value
    // ============================================================================
  } else if (cmd == "CADDHEAD") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      doublyList_.addToHead(value);
    } else {
      std::cout << "Error: CADDHEAD command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // C2 Добавление элемента (в хвост): CADDTAIL value
    // ============================================================================
  } else if (cmd == "CADDTAIL") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      doublyList_.addToTail(value);
    } else {
      std::cout << "Error: CADDTAIL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // C3 Удаление элемента (из головы): CDELHEAD
    // ============================================================================
  } else if (cmd == "CDELHEAD") {
    if (tokens.size() == 1) {
      doublyList_.removeFromHead();
    } else {
      std::cout << "Error: CDELHEAD command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // C4 Удаление элемента (из хвоста): CDELTAIL
    // ============================================================================
  } else if (cmd == "CDELTAIL") {
    if (tokens.size() == 1) {
      doublyList_.removeFromTail();
    } else {
      std::cout << "Error: CDELTAIL command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // C5 Вставка элемента перед указанным значением: CINSERTBEFORE targetValue
    // newValue
    // ============================================================================
  } else if (cmd == "CINSERTBEFORE") {
    if (tokens.size() == 3) {
      T targetValue = tokens[1];
      T newValue = tokens[2];
      doublyList_.insertBefore(targetValue, newValue);
    } else {
      std::cout << "Error: CINSERTBEFORE command requires 2 arguments."
                << std::endl;
    }
    // ============================================================================
    // C6 Вставка элемента после указанного значения: CINSERTAFTER targetValue
    // newValue
    // ============================================================================
  } else if (cmd == "CINSERTAFTER") {
    if (tokens.size() == 3) {
      T targetValue = tokens[1];
      T newValue = tokens[2];
      // doublyList_.insertAfter(targetValue, newValue);
    } else {
      std::cout << "Error: CINSERTAFTER command requires 2 arguments."
                << std::endl;
    }
    // ============================================================================
    // C7 Удаление элемента перед указанным значением: CDELBEFORE targetValue
    // ============================================================================
  } else if (cmd == "CDELBEFORE") {
    if (tokens.size() == 2) {
      T targetValue = tokens[1];
      // doublyList_.removeBefore(targetValue);
    } else {
      std::cout << "Error: CDELBEFORE command requires 1 arguments."
                << std::endl;
    }
    // ============================================================================
    // C8 Удаление элемента после указанного значения: CDELAFTER targetValue
    // ============================================================================
  } else if (cmd == "CDELAFTER") {
    if (tokens.size() == 2) {
      T targetValue = tokens[1];
      // doublyList_.removeAfter(targetValue);
    } else {
      std::cout << "Error: CDELAFTER command requires 1 arguments."
                << std::endl;
    }
    // ============================================================================
    // C9 Поиск элемента по значению: CSEARCH value
    // ============================================================================
  } else if (cmd == "CSEARCH") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      DoublyNode<T>* result = doublyList_.searchByValue(value);
      if (result != nullptr) {
        std::cout << "Value " << value << " found in the list." << std::endl;
      } else {
        std::cout << "Value " << value << " not found in the list."
                  << std::endl;
      }
    } else {
      std::cout << "Error: CSEARCH command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // C10 Удаление элемента по значению: CDEL value
    // ============================================================================
  } else if (cmd == "CDEL") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      // doublyList_.removeByValue(value);
    } else {
      std::cout << "Error: CDEL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // D1 Добавление элемента: DPUSH value
    // ============================================================================
  } else if (cmd == "DPUSH") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      stack_.push(value);
    } else {
      std::cout << "Error: DPUSH command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // D2 Удаление элемента: DPOP
    // ============================================================================
  } else if (cmd == "DPOP") {
    if (tokens.size() == 1) {
      stack_.pop();
    } else {
      std::cout << "Error: DPOP command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // E1 Добавление элемента: EPUSH value
    // ============================================================================
  } else if (cmd == "EPUSH") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      queue_.push(value);
    } else {
      std::cout << "Error: EPUSH command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // E2 Удаление элемента: EPOP
    // ============================================================================
  } else if (cmd == "EPOP") {
    if (tokens.size() == 1) {
      queue_.pop();
    } else {
      std::cout << "Error: EPOP command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // F1 Добавление элемента: FINSERT digit
    // ============================================================================
  } else if (cmd == "FINSERT") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      cbtree_.insert(value);
    } else {
      std::cout << "Error: FINSERT command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // F2 Поиск элемента(по значению): FFIND value
    // ============================================================================
  } else if (cmd == "FFIND") {
    if (tokens.size() == 2) {
      T value = tokens[1];
      if (cbtree_.get_value(value)) {
        std::cout << "Value " << value << " found in the tree." << std::endl;
      } else {
        std::cout << "Value " << value << " not found in the tree."
                  << std::endl;
      }
    } else {
      std::cout << "Error: FFIND command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // F3 Проверка дерева на завершённость: FISCBT
    // ============================================================================
  } else if (cmd == "FISCBT") {
    if (tokens.size() == 1) {
      if (cbtree_.isCBT()) {
        std::cout << "The tree is a complete binary tree." << std::endl;
      } else {
        std::cout << "The tree is not a complete binary tree." << std::endl;
      }
    } else {
      std::cout << "Error: FISCBT command requires 0 arguments." << std::endl;
    }
  } else if (cmd == "FPRINT") {
    if (tokens.size() == 1) {
      cbtree_.print();
    } else {
      std::cout << "Error: FPRINT command requires 0 arguments." << std::endl;
    }
  } else if (cmd == "PRINT") {
    if (tokens.size() == 1) {
      array_.print();
      singlyList_.print();
      // doublyList_.print();
      stack_.print();
      queue_.print();
    } else {
      std::cout << "Error: PRINT command requires 0 arguments." << std::endl;
    }
  } else {
    std::cout << "Unknown command: " << cmd << std::endl;
  }
}
