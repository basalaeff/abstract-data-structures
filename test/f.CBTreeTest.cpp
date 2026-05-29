#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../src/f.CompleteBinaryTree/f.CBTree.hpp"

// Тест вставки элемента в дерево
TEST(CBTreeTest, Insert) {
  // Arrange
  CBTree<std::string> tree;

  // Act
  tree.insert("F1");
  tree.insert("F2");
  tree.insert("F3");

  // Assert
  EXPECT_EQ(tree.getRoot()->data_, "F1");
  EXPECT_EQ(tree.getRoot()->left_->data_, "F2");
  EXPECT_EQ(tree.getRoot()->right_->data_, "F3");
}

// Тест для поиска элемента в дереве
TEST(CBTreeTest, GetValue) {
  // Arrange
  CBTree<std::string> tree;
  tree.insert("F1");
  tree.insert("F2");
  tree.insert("F3");

  // Act & Assert
  EXPECT_EQ(tree.get_value("F1"), true);
  EXPECT_EQ(tree.get_value("F2"), true);
  EXPECT_EQ(tree.get_value("F3"), true);
  EXPECT_EQ(tree.get_value("F4"), false);
}

// Тест для проверки дерева на Complete
TEST(CBTreeTest, IsComplete) {
  // Arrange
  CBTree<std::string> tree;
  tree.insert("F1");
  tree.insert("F2");
  tree.insert("F3");

  // Act & Assert
  EXPECT_EQ(tree.isCBT(), true);
}

// Тест для метода print
TEST(CBTreeTest, Print) {
  // Arrange
  CBTree<std::string> tree;

  tree.insert("F1");
  tree.insert("F2");
  tree.insert("F3");


  std::stringstream buffer;
  std::streambuf* old =
      std::cout.rdbuf(buffer.rdbuf());  // Перенаправляем std::cout

  // Act
  tree.print();
  std::string output = buffer.str();

  // Assert
  EXPECT_NE(output.find("F1"), std::string::npos);
  EXPECT_NE(output.find("F2"), std::string::npos);
  EXPECT_NE(output.find("F3"), std::string::npos);

  std::cout.rdbuf(old);  // Восстанавливаем std::cout
}

// Тест для записи и загрузки данных в/из файла
TEST(CBTreeTest, SaveAndLoadFromFile) {
  // Arrange
  CBTree<std::string> tree;

  tree.insert("F1");
  tree.insert("F2");
  tree.insert("F3");


  std::string filename = "testfile.txt";
  tree.saveToFile(filename);

  // Act (запуск метода/функции)
  CBTree<std::string> loadedTree;
  loadedTree.loadFromFile(filename);

  // Assert (проверка результата)
  EXPECT_EQ(loadedTree.getRoot()->data_, "F1");
  EXPECT_EQ(loadedTree.getRoot()->left_->data_, "F2");
  EXPECT_EQ(loadedTree.getRoot()->right_->data_, "F3");

  remove(filename.c_str());
}

// Тест для ошибки при сохранении в файл
TEST(CBTreeTest, SaveToFileError) {
  // Arrange
  CBTree<std::string> tree;
  tree.insert("F1");
  tree.insert("F2");


  // Act & Assert
  EXPECT_THROW(tree.saveToFile("/invalid/path/test.txt"), std::exception);
}

// Тест для ошибки при загрузке из файла
TEST(CBTreeTest, LoadFromFileError) {
  // Arrange
  CBTree<std::string> tree;
  tree.insert("F1");
  tree.insert("F2");

  // Act & Assert
  EXPECT_THROW(tree.loadFromFile("/invalid/path/test.txt"), std::exception);
}

// Тест сохранения пустого дерева
TEST(CBTreeTest, SaveEmptyTree) {
  // Arrange
  CBTree<std::string> tree;

  // Act & Assert
  EXPECT_THROW(tree.saveToFile("empty_tree.txt"), std::exception);
}

// Тест вывода пустого дерева
TEST(CBTreeTest, PrintEmptyTree) {
  // Arrange
  CBTree<std::string> tree;

  // Act & Assert
  EXPECT_THROW(tree.print(), std::exception);
}