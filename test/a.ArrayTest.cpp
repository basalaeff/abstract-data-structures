#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../src/a.Array/a.Array.hpp"

// Тест добавления элемента в конец
TEST(ArrayTest, AddToTheEndWords) {
  // Arrange (подготовка исходных данных)
  const std::vector<std::string> words = {"Black", "White", "Red", "Green",
                                          "Blue"};
  // capcity: size_t -> int
  const int capacity = static_cast<int>(words.size());
  Array<std::string> arr(capacity);

  // Assert (проверка результата)
  EXPECT_EQ(arr.length(), 0);

  // Act (запуск метода/функции)
  for (int i = 0; i < capacity; ++i) {
    arr.addToTheEnd(words[i]);

    // Assert (проверка результата)
    EXPECT_EQ(arr.length(), i + 1);
    EXPECT_EQ(arr.get(i), words[i]);
  }
}

// Тест для конструктора и деструктора
TEST(ArrayTest, ConstructorAndDestructor) {
  Array<int> arr(10);
  EXPECT_EQ(arr.getSize(), 0);
  EXPECT_EQ(arr.getMaxCapacity(), 10);
}

// Тест для добавления элемента в конец (проверка увеличения размера)
TEST(ArrayTest, AddToTheEndResize) {
  // Arrange
  Array<std::string> arr(0);

  // Act
  arr.addToTheEnd("White");

  // Assert
  EXPECT_EQ(arr.getSize(), 1);
  EXPECT_EQ(arr.get(0), "White");
}

// Тест для добавления элемента по индексу (проверка увеличения размера)
TEST(ArrayTest, AddToTheIndexResize) {
  // Arrange
  Array<std::string> arr(0);

  // Act
  arr.addToTheIndex(0, "White");

  // Assert
  EXPECT_EQ(arr.getSize(), 1);
  EXPECT_EQ(arr.get(0), "White");
}

// Тест для добавления элемента по индексу
TEST(ArrayTest, AddToTheIndex) {
  // Arrange (подготовка исходных данных)
  const std::vector<std::string> words = {"Black", "White", "Red", "Green",
                                          "Blue"};
  // capcity: size_t -> int
  const int capacity = static_cast<int>(words.size());
  Array<std::string> arr(capacity);

  // Assert (проверка результата)
  EXPECT_EQ(arr.length(), 0);

  // Act (запуск метода/функции)
  for (int i = 0; i < capacity; ++i) {
    arr.addToTheIndex(i, words[i]);

    // Assert (проверка результата)
    EXPECT_EQ(arr.length(), i + 1);
    EXPECT_EQ(arr.get(i), words[i]);
  }
}

// Тест для получения элемента по индексу
TEST(ArrayTest, GetElement) {
  // Arrange (подготовка исходных данных)
  Array<std::string> arr(10);

  // Act (запуск метода/функции)
  arr.addToTheIndex(0, "White");
  arr.addToTheIndex(1, "Black");

  // Assert (проверка результата)
  EXPECT_EQ(arr.get(0), "White");
  EXPECT_EQ(arr.get(1), "Black");
}

// Тест для удаления элемента по индексу
TEST(ArrayTest, RemoveElementByIndex) {
  // Arrange (подготовка исходных данных)
  Array<std::string> arr(10);

  // Act (запуск метода/функции)
  arr.addToTheIndex(0, "White");
  arr.removeByIndex(0);

  // Assert (проверка результата)
  EXPECT_EQ(arr.getSize(), 0);
}

// Тест для замены элемента по индексу
TEST(ArrayTest, ReplaceElementByIndex) {
  // Arrange (подготовка исходных данных)
  Array<std::string> arr(10);

  // Act (запуск метода/функции)
  arr.addToTheIndex(0, "White");
  arr.addToTheIndex(1, "Black");
  arr.replaceByIndex(0, "Black");
  arr.replaceByIndex(1, "White");

  // Assert (проверка результата)
  EXPECT_EQ(arr.get(0), "Black");
  EXPECT_EQ(arr.get(1), "White");
}

// Тест для функции length
TEST(ArrayTest, LengthCheck) {
  // Arrange (подготовка исходных данных)
  Array<std::string> arr(10);

  // Act (запуск метода/функции)
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  // Assert (проверка результата)
  EXPECT_EQ(arr.length(), 2);
}

// Тест для записи и загрузки данных в/из файла
TEST(ArrayTest, SaveAndLoadFromFile) {
  // Arrange (подготовка исходных данных)
  Array<std::string> arr(10);

  // Act (запуск метода/функции)
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  std::string filename = "testfile.txt";
  arr.saveToFile(filename);

  // Act (запуск метода/функции)
  Array<std::string> loadedArr(10);
  loadedArr.loadFromFile(filename);

  // Assert (проверка результата)
  EXPECT_EQ(loadedArr.get(0), "White");
  EXPECT_EQ(loadedArr.get(1), "Black");

  remove(filename.c_str());
}

// Тест для метода print
TEST(ArrayTest, Print) {
  // Arrange (подготовка исходных данных)
  Array<std::string> arr(10);

  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  std::stringstream buffer;
  std::streambuf* old =
      std::cout.rdbuf(buffer.rdbuf());  // Перенаправляем std::cout

  // Act (запуск метода/функции)
  arr.print();
  std::string output = buffer.str();

  // Assert (проверка результата)
  EXPECT_NE(output.find("White"), std::string::npos);
  EXPECT_NE(output.find("Black"), std::string::npos);

  std::cout.rdbuf(old);  // Восстанавливаем std::cout
}

// Тест для проверки ошибок при доступе по неверному индексу
TEST(ArrayTest, InvalidIndexForGet) {
  // Arrange
  Array<std::string> arr(5);
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  // Act & Assert
  EXPECT_THROW(arr.get(10), std::out_of_range);
}

// Тест для проверки попытки добавить элемент с неверным индексом
TEST(ArrayTest, InvalidIndexForAdd) {
  // Arrange
  Array<std::string> arr(5);
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  // Act & Assert
  EXPECT_THROW(arr.addToTheIndex(10, "Red"), std::out_of_range);
}

// Тест для проверки попытки удалить элемент с неверным индексом
TEST(ArrayTest, RemoveInvalidIndex) {
  // Arrange
  Array<std::string> arr(5);
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  // Act & Assert
  EXPECT_THROW(arr.removeByIndex(10), std::out_of_range);
}

// Тест для проверки попытки заменить элемент с неверным индексом
TEST(ArrayTest, ReplaceInvalidIndex) {
  // Arrange
  Array<std::string> arr(5);
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  // Act & Assert
  EXPECT_THROW(arr.replaceByIndex(10, "Red"), std::out_of_range);
}

// Тест для удаления элемента сдвигом элементов
TEST(ArrayTest, RemoveAndShiftElements) {
  // Arrange
  Array<std::string> arr(5);
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");
  arr.addToTheEnd("Red");

  // Act
  arr.removeByIndex(1);

  // Assert
  EXPECT_EQ(arr.get(1), "Red");
}

// Тест для ошибки при сохранении в файл
TEST(ArrayTest, SaveToFileError) {
  // Arrange
  Array<std::string> arr(5);
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  // Act & Assert
  EXPECT_THROW(arr.saveToFile("/invalid/path/test.txt"), std::exception);
}

// Тест для ошибки при загрузке из файла
TEST(ArrayTest, LoadFromFileError) {
  // Arrange
  Array<std::string> arr(5);
  arr.addToTheEnd("White");
  arr.addToTheEnd("Black");

  // Act & Assert
  EXPECT_THROW(arr.loadFromFile("/invalid/path/test.txt"), std::exception);
}