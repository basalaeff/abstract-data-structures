// ================================================
// Сохранение данных
// ================================================

template<typename T>
void ConsoleUI<T>::saveData(const std::string& filename,
                         const std::string& query) {
  if (!filename.empty() && !query.empty()) {
    std::stringstream ss(query);
    std::string command;
    ss >> command;
    char cmd = command[0];
    try {
      // Проверка команд для массива и списка
      if (cmd == 'A') {
        array_.saveToFile(filename);
      } else if (cmd == 'B') {
        singlyList_.saveToFile(filename);
      } else if (cmd == 'C') {
        doublyList_.saveToFile(filename);
      } else if (cmd == 'D') {
        stack_.saveToFile(filename);
      } else if (cmd == 'E') {
        queue_.saveToFile(filename);
      } else if (cmd == 'F') {
        cbtree_.saveToFile(filename);
      } else {
        std::cout << "Error: unrecognized command type." << std::endl;
      }
    } catch (const std::exception& e) {
      std::cerr << "Save error: " << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown error occurred while saving data." << std::endl;
    }
  }
}