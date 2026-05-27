// ============================================================================
// КОНСТРУКТОР
// ============================================================================
template <typename T>
Array<T>::Array(int capacity)
    : maxCapacity_(capacity), size_(0), data_(new T[capacity]) {}

// ============================================================================
// ДЕСТРУКТОР
// ============================================================================
// Освобождает память

template <typename T>
Array<T>::~Array() {
  delete[] data_;
}

template <typename T>
void Array<T>::resize(int new_capacity) {
  T* new_data = new T[new_capacity];
  for (int i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }
  delete[] data_;
  data_ = new_data;
  maxCapacity_ = new_capacity;
}