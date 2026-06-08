// ================================================
// Сохранение данных
// ================================================

template <typename T>
void ConsoleUI<T>::saveData(const std::string& filename,
                            const std::string& query, Format format) {
  if (!filename.empty() && !query.empty()) {
    std::stringstream ss(query);
    std::string command;
    ss >> command;
    char cmd = command[0];
    try {
      // Проверка команд для массива и списка
      if (cmd == 'A') {
        if (format == Format::BINARY) {
          array_.saveToBinaryFile(filename);
        } else {
          array_.saveToFile(filename);
        }
      } else if (cmd == 'B') {
        if (format == Format::BINARY) {
          singlyList_.saveToBinaryFile(filename);
        } else {
          singlyList_.saveToFile(filename);
        }
      } else if (cmd == 'C') {
        if (format == Format::BINARY) {
          doublyList_.saveToBinaryFile(filename);
        } else {
          doublyList_.saveToFile(filename);
        }
      } else if (cmd == 'D') {
        if (format == Format::BINARY) {
          stack_.saveToBinaryFile(filename);
        } else {
          stack_.saveToFile(filename);
        }
      } else if (cmd == 'E') {
        if (format == Format::BINARY) {
          queue_.saveToBinaryFile(filename);
        } else {
          queue_.saveToFile(filename);
        }
      } else if (cmd == 'F') {
        if (format == Format::BINARY) {
          cbtree_.saveToBinaryFile(filename);
        } else {
          cbtree_.saveToFile(filename);
        }
      }
    } catch (const std::exception& e) {
      std::cerr << "Save error: " << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown error occurred while saving data." << std::endl;
    }
  }
}