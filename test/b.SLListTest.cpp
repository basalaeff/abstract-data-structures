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
  EXPECT_EQ(sll.getHead()->data_, "Moscow");
  EXPECT_EQ(sll.getHead()->next_->data_, "London");
  EXPECT_EQ(sll.getHead()->next_->next_->data_, "Paris");
}

