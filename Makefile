
# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g -pthread -I.
TARGET = dbms

# Исходные файлы
SRCS = src/main.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Сборка
all: $(TARGET)

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