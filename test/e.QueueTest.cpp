#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../src/e.Queue/e.Queue.hpp"

// Тест добавления элемента в стек
TEST(QueueTest, Push) {
  // Arrange
  Queue<std::string> queue;

  // Act
  queue.push("E001");
  queue.push("E002");
  queue.push("E003");

  // Assert
  EXPECT_EQ(queue.getSize(), 3);
  EXPECT_EQ(queue.getFront()->data_, "E001");
  EXPECT_EQ(queue.getFront()->next_->data_, "E002");
  EXPECT_EQ(queue.getFront()->next_->next_->data_, "E003");
}

TEST(QueueTest, Pop) {
  // Arrange
  Queue<std::string> queue;

  // Act
  queue.push("E001");
  queue.push("E002");
  queue.push("E003");

  // Assert
  EXPECT_EQ(queue.getSize(), 3);
  EXPECT_EQ(queue.getFront()->data_, "E001");
  EXPECT_EQ(queue.getFront()->next_->data_, "E002");
  EXPECT_EQ(queue.getFront()->next_->next_->data_, "E003");

  // Act
  queue.pop();

  // Assert
  EXPECT_EQ(queue.getSize(), 2);
  EXPECT_EQ(queue.getFront()->data_, "E002");
  EXPECT_EQ(queue.getFront()->next_->data_, "E003");

  // Act
  queue.pop();

  // Assert
  EXPECT_EQ(queue.getSize(), 1);
  EXPECT_EQ(queue.getFront()->data_, "E003");

  // Act
  queue.pop();

  // Assert
  EXPECT_EQ(queue.getSize(), 0);
  EXPECT_EQ(queue.getFront(), nullptr);
}

// Тест для записи и загрузки данных в/из файла
TEST(QueueTest, SaveAndLoadFromFile) {
  // Arrange
  Queue<std::string> queue;

  queue.push("E001");
  queue.push("E002");
  queue.push("E003");

  std::string filename = "testfile.txt";
  queue.saveToFile(filename);

  // Act (запуск метода/функции)
  Queue<std::string> loadedQueue;
  loadedQueue.loadFromFile(filename);

  // Assert (проверка результата)
  EXPECT_EQ(loadedQueue.getSize(), 3);
  EXPECT_EQ(loadedQueue.getFront()->data_, "E001");
  EXPECT_EQ(loadedQueue.getFront()->next_->data_, "E002");
  EXPECT_EQ(loadedQueue.getFront()->next_->next_->data_, "E003");

  remove(filename.c_str());
}

// Тест для метода print
TEST(QueueTest, Print) {
  // Arrange
  Queue<std::string> queue;

  queue.push("E001");
  queue.push("E002");
  queue.push("E003");

  std::stringstream buffer;
  std::streambuf* old =
      std::cout.rdbuf(buffer.rdbuf());  // Перенаправляем std::cout

  // Act
  queue.print();
  std::string output = buffer.str();

  // Assert
  EXPECT_NE(output.find("E001"), std::string::npos);
  EXPECT_NE(output.find("E002"), std::string::npos);
  EXPECT_NE(output.find("E003"), std::string::npos);

  std::cout.rdbuf(old);  // Восстанавливаем std::cout
}

// Тест для ошибки при сохранении в файл
TEST(QueueTest, SaveToFileError) {
  // Arrange
  Queue<std::string> queue;
  queue.push("E001");
  queue.push("E002");

  // Act & Assert
  EXPECT_THROW(queue.saveToFile("/invalid/path/test.txt"), std::exception);
}

// Тест для ошибки при загрузке из файла
TEST(QueueTest, LoadFromFileError) {
  // Arrange
  Queue<std::string> queue;
  queue.push("E001");
  queue.push("E002");

  // Act & Assert
  EXPECT_THROW(queue.loadFromFile("/invalid/path/test.txt"), std::exception);
}

// Тест ошибки удаления при пустой очереди
TEST(QueueTest, PopFromEmptyQueue) {
  // Arrange
  Queue<std::string> queue;

  // Act & Assert
  EXPECT_THROW(queue.pop(), std::exception);
}