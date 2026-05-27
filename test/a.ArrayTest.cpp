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
  Array<std::string> array(capacity);

  // Assert (проверка результата)
  EXPECT_EQ(array.length(), 0);

  // Act (запуск метода/функции)
  for (int i = 0; i < capacity; ++i) {
    array.addToTheEnd(words[i]);

    // Assert (проверка результата)
    EXPECT_EQ(array.length(), i + 1);
    EXPECT_EQ(array.get(i), words[i]);
  }
}

// Тест для конструктора и деструктора
TEST(ArrayTest, ConstructorAndDestructor) {
    Array<int> arr(10);
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getMaxCapacity(), 10);
}