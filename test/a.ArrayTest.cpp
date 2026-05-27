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

  // Act (запуск метода/функции)
  arr.addToTheEnd("Yellow");
  const int index = capacity;
  EXPECT_EQ(arr.get(index), "Yellow");
  EXPECT_EQ(arr.getSize(), capacity + 1);
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
  arr.addToTheEnd("White");
  arr.removeByIndex(0);

  // Assert (проверка результата)
  EXPECT_EQ(arr.length(), 0);
}
