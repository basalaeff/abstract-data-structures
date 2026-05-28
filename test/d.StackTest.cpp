#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../src/d.Stack/d.Stack.hpp"

// Тест добавления элемента в стек
TEST(StackTest, Push) {
  // Arrange
  Stack<std::string> stack;

  // Act
  stack.push("Apple");
  stack.push("Banana");
  stack.push("Cherry");

  // Assert
  EXPECT_EQ(stack.getSize(), 3);
  EXPECT_EQ(stack.getTop()->data_, "Cherry");
  EXPECT_EQ(stack.getTop()->next_->data_, "Banana");
  EXPECT_EQ(stack.getTop()->next_->next_->data_, "Apple");
}

TEST(StackTest, Pop) {
  // Arrange
  Stack<std::string> stack;

  // Act
  stack.push("Apple");
  stack.push("Banana");
  stack.push("Cherry");

  // Assert
  EXPECT_EQ(stack.getSize(), 3);
  EXPECT_EQ(stack.getTop()->data_, "Cherry");
  EXPECT_EQ(stack.getTop()->next_->data_, "Banana");
  EXPECT_EQ(stack.getTop()->next_->next_->data_, "Apple");

  // Act
  stack.pop();

  // Assert
  EXPECT_EQ(stack.getSize(), 2);
  EXPECT_EQ(stack.getTop()->data_, "Banana");
  EXPECT_EQ(stack.getTop()->next_->data_, "Apple");

  // Act
  stack.pop();

  // Assert
  EXPECT_EQ(stack.getSize(), 1);
  EXPECT_EQ(stack.getTop()->data_, "Apple");

  // Act
  stack.pop();

  // Assert
  EXPECT_EQ(stack.getSize(), 0);
  EXPECT_EQ(stack.getTop(), nullptr);
}

// Тест для записи и загрузки данных в/из файла
TEST(StackTest, SaveAndLoadFromFile) {
  // Arrange
  Stack<std::string> stack;

  stack.push("Apple");
  stack.push("Banana");
  stack.push("Cherry");


  std::string filename = "testfile.txt";
  stack.saveToFile(filename);

  // Act (запуск метода/функции)
  Stack<std::string> loadedStack;
  loadedStack.loadFromFile(filename);

  // Assert (проверка результата)
  EXPECT_EQ(loadedStack.getSize(), 3);
  EXPECT_EQ(loadedStack.getTop()->data_, "Cherry");
  EXPECT_EQ(loadedStack.getTop()->next_->data_, "Banana");
  EXPECT_EQ(loadedStack.getTop()->next_->next_->data_, "Apple");

  remove(filename.c_str());
}

// Тест для метода print
TEST(StackTest, Print) {
  // Arrange
  Stack<std::string> stack;

  stack.push("Apple");
  stack.push("Banana");
  stack.push("Cherry");


  std::stringstream buffer;
  std::streambuf* old =
      std::cout.rdbuf(buffer.rdbuf());  // Перенаправляем std::cout

  // Act
  stack.print();
  std::string output = buffer.str();

  // Assert
  EXPECT_NE(output.find("Apple"), std::string::npos);
  EXPECT_NE(output.find("Banana"), std::string::npos);
  EXPECT_NE(output.find("Cherry"), std::string::npos);

  std::cout.rdbuf(old);  // Восстанавливаем std::cout
}

// Тест для ошибки при сохранении в файл
TEST(StackTest, SaveToFileError) {
  // Arrange
  Stack<std::string> stack;
  stack.push("Apple");
  stack.push("Banana");

  // Act & Assert
  EXPECT_THROW(stack.saveToFile("/invalid/path/test.txt"), std::exception);
}

// Тест для ошибки при загрузке из файла
TEST(StackTest, LoadFromFileError) {
  // Arrange
  Stack<std::string> stack;
  stack.push("Apple");
  stack.push("Banana");

  // Act & Assert
  EXPECT_THROW(stack.loadFromFile("/invalid/path/test.txt"), std::exception);
}

// Тест ошибки удаления при пустом стеке
TEST(StackTest, PopFromEmptyStack) {
  // Arrange
  Stack<std::string> stack;

  // Act & Assert
  EXPECT_THROW(stack.pop(), std::exception);
}