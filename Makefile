# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g -pthread -I.
TARGET = dbms

# Исходные файлы
SRCS = src/main.cpp
SRCS_FORMAT = src/main.cpp
SRCS_FORMAT += $(wildcard src/a.Array/*.hpp)
SRCS_FORMAT += $(wildcard src/a.Array/*.tpp)
SRCS_FORMAT += $(wildcard src/b.SinglyLinkedList/*.hpp)
SRCS_FORMAT += $(wildcard src/b.SinglyLinkedList/*.tpp)
SRCS_FORMAT += $(wildcard src/c.DoublyLinkedList/*.hpp)
SRCS_FORMAT += $(wildcard src/c.DoublyLinkedList/*.tpp)
SRCS_FORMAT += $(wildcard src/d.Stack/*.hpp)
SRCS_FORMAT += $(wildcard src/d.Stack/*.tpp)
SRCS_FORMAT += $(wildcard src/e.Queue/*.hpp)
SRCS_FORMAT += $(wildcard src/e.Queue/*.tpp)
SRCS_FORMAT += $(wildcard src/f.CompleteBinaryTree/*.tpp)
# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Сборка
all: format dbms

format:
	clang-format -i $(SRCS_FORMAT)

$(TARGET): $(OBJS)
	@echo "🔗 Линковка..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "🧹 Очистка объектных файлов..."
	rm -f $(OBJS)
	@echo "✅ Сборка завершена! Запустите: ./$(TARGET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	@echo "🗑️ Удаление старых файлов..."
	rm -f $(TARGET) $(OBJS) *.db
	@echo "✅ Очистка завершена!"

# Запуск
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run