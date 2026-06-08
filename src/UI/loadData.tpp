// ================================================
// Загрузка данных
// ================================================
template <typename T>
void ConsoleUI<T>::loadData(const std::string& filename,
                            const std::string& query, Format format) {
  try {
    if (!filename.empty() && !query.empty()) {
      std::stringstream ss(query);
      std::string command;
      ss >> command;
      char cmd = command[0];
      // Проверка команд для массива
      if (cmd == 'A') {
        if (format == Format::BINARY) {
          array_.loadFromBinaryFile(filename);
        } else {
          array_.loadFromFile(filename);
        }
      } else if (cmd == 'B') {
        if (format == Format::BINARY) {
          singlyList_.loadFromBinaryFile(filename);
        } else {
          singlyList_.loadFromFile(filename);
        }
      } else if (cmd == 'C') {
        doublyList_.loadFromFile(filename);
      } else if (cmd == 'D') {
        stack_.loadFromFile(filename);
      } else if (cmd == 'E') {
        queue_.loadFromFile(filename);
      } else if (cmd == 'F') {
        cbtree_.loadFromFile(filename);
      } else if (command == "PRINT") {
        std::ifstream file(filename);
        if (!file.is_open()) {
          std::cerr << "Error: could not open file " << filename << std::endl;
          return;
        }
        std::string line;
        while (std::getline(file, line)) {
          std::cout << line << std::endl;
        }
        file.close();  // Закрытие файла
      }
    }
  } catch (const std::exception& e) {
    std::cerr << "Load error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred while loading data." << std::endl;
  }
}
