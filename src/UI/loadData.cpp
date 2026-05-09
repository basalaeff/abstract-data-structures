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
      }
    } else {
      std::cout << "Error: unrecognized command type." << std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << "Load error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred while loading data." << std::endl;
  }
}
