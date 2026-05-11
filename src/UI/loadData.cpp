#include <fstream>
#include <sstream>

#include "ConsoleUI.hpp"

// ================================================
// Загрузка данных
// ================================================
void ConsoleUI::loadData(const std::string& filename,
                         const std::string& query) {
  try {
    if (!filename.empty() && !query.empty()) {
      std::stringstream ss(query);
      std::string command;
      ss >> command;

      // Проверка команд для массива
      if (command[0] == 'A') {
        array_.loadFromFile(filename);
      } else if (command[0] == 'B') {
        singlyList_.loadFromFile(filename);
      } else if (command[0] == 'C') {
        doublyList_.loadFromFile(filename);
      } else if (command[0] == 'D') {
        stack_.loadFromFile(filename);
      } else if (command[0] == 'E') {
        queue_.loadFromFile(filename);
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
      } else {
        std::cout << "Error: unrecognized command type." << std::endl;
      }
    }
  } catch (const std::exception& e) {
    std::cerr << "Load error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred while loading data." << std::endl;
  }
}
