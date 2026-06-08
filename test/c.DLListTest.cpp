#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../src/c.DoublyLinkedList/c.DoublyLinkedList.hpp"

// Тест добавления в голову
TEST(DLListTest, AddToHead) {
  // Arrange
  DoublyLinkedList<std::string> dll;

  // Act
  dll.addToHead("Russia");

  // Assert
  EXPECT_EQ(dll.getSize(), 1);
}

// Тест добавления в хвост
TEST(DLListTest, AddToTail) {
  // Arrange
  DoublyLinkedList<std::string> dll;

  // Act
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Assert
  EXPECT_EQ(dll.getSize(), 3);
}

// Тест удаления из головы
TEST(DLListTest, RemoveFromHead) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");

  // Act
  dll.removeFromHead();

  // Assert
  EXPECT_EQ(dll.getSize(), 1);
}

TEST(DLListTest, RemoveFromTail) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act
  dll.removeFromTail();

  // Assert
  EXPECT_EQ(dll.getSize(), 2);
}

TEST(DLListTest, RemoveFromTailSingleElement) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");

  // Act
  dll.removeFromTail();

  // Assert
  EXPECT_EQ(dll.getSize(), 0);
}

// Тест ошибки операции при пустом списке
TEST(DLListTest, EmptyList) {
  // Arrange
  DoublyLinkedList<std::string> dll;

  // Act & Assert
  EXPECT_THROW(dll.removeFromHead(), std::runtime_error);
  EXPECT_THROW(dll.removeFromTail(), std::runtime_error);
  EXPECT_THROW(dll.insertBefore("Russia", "France"), std::runtime_error);
  EXPECT_THROW(dll.insertAfter("Russia", "Germany"), std::runtime_error);
  EXPECT_THROW(dll.removeBefore("Russia"), std::runtime_error);
  EXPECT_THROW(dll.removeAfter("Russia"), std::runtime_error);
  EXPECT_THROW(dll.removeByValue("Russia"), std::runtime_error);
}

// Тест вставки перед указанным значением
TEST(DLListTest, InsertBefore) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act
  dll.insertBefore("Russia", "Spain");
  dll.insertBefore("France", "Italy");

  // Assert
  EXPECT_EQ(dll.getSize(), 5);
}

// Тест вставки после указанного значения
TEST(DLListTest, InsertAfter) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act
  dll.insertAfter("Russia", "Spain");

  // Assert
  EXPECT_EQ(dll.getSize(), 4);
}

TEST(DLListTest, InsertAfterNotFound) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act & Assert
  EXPECT_THROW(dll.insertAfter("Spain", "Italy"), std::runtime_error);
}

// Тест вставки элемента перед головой
TEST(DLListTest, InsertBeforeHead) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act
  dll.insertBefore("Russia", "Spain");

  // Assert
  EXPECT_EQ(dll.getSize(), 4);
}

// Тест удаления элемента перед целевым значением
TEST(DLListTest, RemoveBefore) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");
  dll.addToTail("Spain");

  // Act
  dll.removeBefore("Germany");

  // Assert
  EXPECT_EQ(dll.getSize(), 3);
}

// Тест удаления элемента после целевого значения
TEST(DLListTest, RemoveAfter) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");
  dll.addToTail("Spain");
  // Act
  dll.removeAfter("France");

  // Assert
  EXPECT_EQ(dll.getSize(), 3);
  EXPECT_EQ(dll.getTail()->data_, "Spain");
}

// Тест удаления элемента (головы)
TEST(DLListTest, RemoveBeforeHead) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");
  dll.addToTail("Spain");

  // Act
  dll.removeBefore("France");

  // Assert
  EXPECT_EQ(dll.getSize(), 3);
}

// Тест удаления элемента (хвоста)
TEST(DLListTest, RemoveAfterTail) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");
  dll.addToTail("Spain");

  // Act
  dll.removeAfter("Germany");

  // Assert
  EXPECT_EQ(dll.getSize(), 3);
}

// Тест удаления элемента с ошибкой (значение не найдено)
TEST(DLListTest, RemoveBeforeNotFound) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act & Assert
  EXPECT_THROW(dll.removeBefore("Spain"), std::runtime_error);
}

// Тест удаления элемента с ошибкой (значение не найдено)
TEST(DLListTest, RemoveAfterNotFound) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act & Assert
  EXPECT_THROW(dll.removeAfter("Spain"), std::runtime_error);
}

// Тест поиска по значению
TEST(DLListTest, SearchByValue) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act
  DoublyNode<std::string>* res1 = dll.searchByValue("Russia");
  DoublyNode<std::string>* res2 = dll.searchByValue("France");
  DoublyNode<std::string>* res3 = dll.searchByValue("Germany");
  DoublyNode<std::string>* res4 = dll.searchByValue("Spain");

  // Assert
  // Проверка, что элементы существуют (указатели не равны nullptr)
  ASSERT_NE(res1, nullptr);
  ASSERT_NE(res2, nullptr);
  ASSERT_NE(res3, nullptr);
  EXPECT_EQ(res4, nullptr);  // Spain не должен найтись

  // Проверка, что узлы содержат правильные данные
  EXPECT_EQ(res1->data_, "Russia");
  EXPECT_EQ(res2->data_, "France");
  EXPECT_EQ(res3->data_, "Germany");
}

// Тест удаления по значению
TEST(DLListTest, RemoveByValue) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act
  dll.removeByValue("France");
  // Удаляю хвост
  dll.removeByValue("Germany");

  // Assert
  EXPECT_EQ(dll.getSize(), 1);
  EXPECT_EQ(dll.searchByValue("France"), nullptr);
  EXPECT_EQ(dll.searchByValue("Germany"), nullptr);
}

// Тест удаления по значению, когда элемент - голова
TEST(DLListTest, RemoveByValueFromHead) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");

  // Act
  dll.removeByValue("Russia");

  // Assert
  EXPECT_EQ(dll.getSize(), 0);
  EXPECT_EQ(dll.searchByValue("Russia"), nullptr);
}

// Тест удаления по значению, когда не существует
TEST(DLListTest, RemoveByValueNotFound) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");
  dll.addToTail("Germany");

  // Act & Assert
  EXPECT_THROW(dll.removeByValue("Spain"), std::runtime_error);
}

// Тест для записи и загрузки данных в/из файла
TEST(DLListTest, SaveAndLoadFromFile) {
  // Arrange (подготовка исходных данных)
  DoublyLinkedList<std::string> dll;

  // Act (запуск метода/функции)
  dll.addToTail("Russia");
  dll.addToTail("France");

  std::string filename = "testfile.txt";
  dll.saveToFile(filename);

  // Act (запуск метода/функции)
  DoublyLinkedList<std::string> loadedDll;
  loadedDll.addToTail("Italy");
  loadedDll.loadFromFile(filename);

  // Assert (проверка результата)
  EXPECT_EQ(loadedDll.getSize(), 2);
  EXPECT_EQ(loadedDll.searchByValue("Russia")->data_, "Russia");
  EXPECT_EQ(loadedDll.searchByValue("France")->data_, "France");

  remove(filename.c_str());
}

// Тест для метода print
TEST(DLListTest, Print) {
  // Arrange (подготовка исходных данных)
  DoublyLinkedList<std::string> dll;

  dll.addToTail("Russia");
  dll.addToTail("France");

  std::stringstream buffer;
  std::streambuf* old =
      std::cout.rdbuf(buffer.rdbuf());  // Перенаправляем std::cout

  // Act (запуск метода/функции)
  dll.print();
  std::string output = buffer.str();

  // Assert (проверка результата)
  EXPECT_NE(output.find("Russia"), std::string::npos);
  EXPECT_NE(output.find("France"), std::string::npos);

  std::cout.rdbuf(old);  // Восстанавливаем std::cout
}

// Тест для метода print с пустым списком
TEST(DLListTest, PrintEmptyList) {
  // Arrange (подготовка исходных данных)
  DoublyLinkedList<std::string> dll;

  std::stringstream buffer;
  std::streambuf* old =
      std::cout.rdbuf(buffer.rdbuf());  // Перенаправляем std::cout

  // Act (запуск метода/функции)
  dll.print();
  std::string output = buffer.str();

  // Assert (проверка результата)
  EXPECT_TRUE(output.empty());
  std::cout.rdbuf(old);  // Восстанавливаем std::cout
}

// Тест для ошибки при сохранении в файл
TEST(DLListTest, SaveToFileError) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");

  // Act & Assert
  EXPECT_THROW(dll.saveToFile("/invalid/path/test.txt"), std::exception);
}

// Тест для ошибки при загрузке из файла
TEST(DLListTest, LoadFromFileError) {
  // Arrange
  DoublyLinkedList<std::string> dll;
  dll.addToTail("Russia");
  dll.addToTail("France");

  // Act & Assert
  EXPECT_THROW(dll.loadFromFile("/invalid/path/test.txt"), std::exception);
}