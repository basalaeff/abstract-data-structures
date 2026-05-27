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

// Тест ошибки при удалении из пустого списка
TEST(SLListTest, RemoveFromEmptyList) {
  // Arrange
  SinglyLinkedList<std::string> sll;

  // Act & Assert
  EXPECT_THROW(sll.removeFromHead(), std::runtime_error);
  EXPECT_THROW(sll.removeFromTail(), std::runtime_error);
  EXPECT_THROW(sll.insertBefore("Moscow", "London"), std::runtime_error);
  EXPECT_THROW(sll.insertAfter("Moscow", "London"), std::runtime_error);
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
