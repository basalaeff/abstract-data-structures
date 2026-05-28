#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../src/b.SinglyLinkedList/b.SinglyLinkedList.hpp"

// Тест добавления в голову
TEST(SLListTest, AddToHead) {
  // Arrange
  SinglyLinkedList<std::string> sll;

  // Act
  sll.addToHead("Moscow");

  // Assert
  EXPECT_EQ(sll.getSize(), 1);
}

// Тест добавления в хвост
TEST(SLListTest, AddToTail) {
  // Arrange
  SinglyLinkedList<std::string> sll;

  // Act
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Assert
  EXPECT_EQ(sll.getSize(), 3);
}

// Тест удаления из головы
TEST(SLListTest, RemoveFromHead) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");

  // Act
  sll.removeFromHead();

  // Assert
  EXPECT_EQ(sll.getSize(), 1);
}

TEST(SLListTest, RemoveFromTail) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act
  sll.removeFromTail();

  // Assert
  EXPECT_EQ(sll.getSize(), 2);
}

TEST(SLListTest, RemoveFromTailSingleElement) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");

  // Act
  sll.removeFromTail();

  // Assert
  EXPECT_EQ(sll.getSize(), 0);
}

// Тест ошибки операции при пустом списке
TEST(SLListTest, RemoveFromEmptyList) {
  // Arrange
  SinglyLinkedList<std::string> sll;

  // Act & Assert
  EXPECT_THROW(sll.removeFromHead(), std::runtime_error);
  EXPECT_THROW(sll.removeFromTail(), std::runtime_error);
  EXPECT_THROW(sll.insertBefore("Moscow", "London"), std::runtime_error);
  EXPECT_THROW(sll.insertAfter("Moscow", "London"), std::runtime_error);
  EXPECT_THROW(sll.removeBefore("Moscow"), std::runtime_error);
  EXPECT_THROW(sll.removeAfter("Moscow"), std::runtime_error);
  EXPECT_THROW(sll.removeByValue("Moscow"), std::runtime_error);
}

// Тест вставки перед указанным значением
TEST(SLListTest, InsertBefore) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act
  sll.insertBefore("London", "Berlin");

  // Assert
  EXPECT_EQ(sll.getSize(), 4);
}

// Тест вставки после указанного значения
TEST(SLListTest, InsertAfter) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act
  sll.insertAfter("London", "Berlin");

  // Assert
  EXPECT_EQ(sll.getSize(), 4);
}

// Тест вставки с ошибкой (значение не найдено)
TEST(SLListTest, InsertBeforeNotFound) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act & Assert
  EXPECT_THROW(sll.insertBefore("Berlin", "Moscow"), std::runtime_error);
}

TEST(SLListTest, InsertAfterNotFound) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act & Assert
  EXPECT_THROW(sll.insertAfter("Berlin", "Moscow"), std::runtime_error);
}

// Тест вставки элемента перед головой
TEST(SLListTest, InsertBeforeHead) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act
  sll.insertBefore("Moscow", "Berlin");

  // Assert
  EXPECT_EQ(sll.getSize(), 4);
}

// Тест удаления элемента перед целевым значением
TEST(SLListTest, RemoveBefore) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");
  sll.addToTail("Berlin");

  // Act
  sll.removeBefore("Paris");

  // Assert
  EXPECT_EQ(sll.getSize(), 3);
}

// Тест удаления элемента после целевого значения
TEST(SLListTest, RemoveAfter) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");
  sll.addToTail("Berlin");

  // Act
  sll.removeAfter("London");

  // Assert
  EXPECT_EQ(sll.getSize(), 3);
}

// Тест удаления элемента (головы)
TEST(SLListTest, RemoveBeforeHead) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");
  sll.addToTail("Berlin");

  // Act
  sll.removeBefore("London");

  // Assert
  EXPECT_EQ(sll.getSize(), 3);
}

// Тест удаления элемента с ошибкой (значение не найдено)
TEST(SLListTest, RemoveBeforeNotFound) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act & Assert
  EXPECT_THROW(sll.removeBefore("Berlin"), std::runtime_error);
}

// Тест удаления элемента с ошибкой (значение не найдено)
TEST(SLListTest, RemoveAfterNotFound) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act & Assert
  EXPECT_THROW(sll.removeAfter("Berlin"), std::runtime_error);
}

// Тест удаления элемента после хвоста
TEST(SLListTest, RemoveAfterTail) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act & Assert
  EXPECT_THROW(sll.removeAfter("Paris"), std::runtime_error);
}

// Тест поиска по значению
TEST(SLListTest, SearchByValue) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act
  Node<std::string>* res1 = sll.searchByValue("Moscow");
  Node<std::string>* res2 = sll.searchByValue("London");
  Node<std::string>* res3 = sll.searchByValue("Paris");
  Node<std::string>* res4 = sll.searchByValue("Berlin");

  // Assert
  // Проверка, что элементы существуют (указатели не равны nullptr)
  ASSERT_NE(res1, nullptr);
  ASSERT_NE(res2, nullptr);
  ASSERT_NE(res3, nullptr);
  EXPECT_EQ(res4, nullptr);  // Berlin не должен найтись

  // Проверка, что узлы содержат правильные данные
  EXPECT_EQ(res1->data_, "Moscow");
  EXPECT_EQ(res2->data_, "London");
  EXPECT_EQ(res3->data_, "Paris");
}

// Тест удаления по значению
TEST(SLListTest, RemoveByValue) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");
  sll.addToTail("London");
  sll.addToTail("Paris");

  // Act
  sll.removeByValue("London");

  // Assert
  EXPECT_EQ(sll.getSize(), 2);
  EXPECT_EQ(sll.searchByValue("London"), nullptr);
}

// Тест удаления по значению, когда элемент - голова
TEST(SLListTest, RemoveByValueFromHead) {
  // Arrange
  SinglyLinkedList<std::string> sll;
  sll.addToTail("Moscow");

  // Act
  sll.removeByValue("Moscow");

  // Assert
  EXPECT_EQ(sll.getSize(), 0);
  EXPECT_EQ(sll.searchByValue("Moscow"), nullptr);
}

// Тест удаления по значению, когда не существует
TEST(SLListTest, RemoveByValueNotFound) {
  // Arrange
  SinglyLinkedList<std::string> sll;

  // Act & Assert
  EXPECT_THROW(sll.removeByValue("Moscow"), std::runtime_error);
}
