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

// Тест ошибки при удалении из пустого списка
TEST(SLListTest, RemoveFromEmptyList) {
  // Arrange
  SinglyLinkedList<std::string> sll;

  // Act & Assert
  EXPECT_THROW(sll.removeFromHead(), std::runtime_error);
  EXPECT_THROW(sll.removeFromTail(), std::runtime_error);
}
