#include <fstream>
#include <sstream>

#include "ConsoleUI.hpp"

// ================================================
// Сохранение данных
// ================================================
void ConsoleUI::saveData(const std::string& filename,
                         const std::string& query) {
  if (!filename.empty() && !query.empty()) {
    std::stringstream ss(query);
    std::string command;
    ss >> command;
    try {
      // Проверка команд для массива и списка
      if (command[0] == 'A') {
        array_.saveToFile(filename);
      } else if (command[0] == 'B') {
        singlyList_.saveToFile(filename);
      } else if (command[0] == 'C') {
        doublyList_.saveToFile(filename);
      } else if (command[0] == 'D') {
        stack_.saveToFile(filename);
      } else if (command[0] == 'E') {
        queue_.saveToFile(filename);
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