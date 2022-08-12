#include <iostream>

#include "person.cxx"

namespace my_std {
template <class T> class vector {
private:
  T *arr;
  size_t capacity;
  size_t currSize;

  void expand_array() {
    std::cout << "Expanding array\n";
    T *newArray = new T[2 * capacity];

    for (size_t i = 0; i < currSize; i++)
      newArray[i] = arr[i];

    delete[] arr;
    arr = newArray;
    capacity *= 2;
  }

public:
  vector(size_t size) : capacity{size}, arr{new T[size]}, currSize{0} {};

  vector(std::initializer_list<T> list)
      : capacity{list.size()}, arr{new T[list.size()]}, currSize{0} {
    for (auto item : list)
      arr[currSize++] = item;
  }

  void push_back(const T &t) {
    std::cout << "capacity: " << capacity << "; currSize: " << currSize
              << std::endl;
    if (capacity > currSize) {
      arr[currSize++] = t;
      return;
    }

    expand_array();
    arr[currSize++] = t;
  }

  void push_back(T &&t) {
    if (capacity > currSize) {
      arr[currSize] = std::move(t);
      currSize++;
      return;
    }

    expand_array();
    arr[currSize++] = std::move(t);
  }

  void print() {
    std::cout << "[";

    for (size_t index = 0; index < currSize; index++) {
      std::cout << arr[index];

      if (index + 1 < currSize)
        std::cout << ",";
    }

    std::cout << "]\n";
  }

  T &operator[](int i) { return arr[i]; }

  const T &operator[](int i) const { return arr[i]; }

  int size() { return currSize; }

  ~vector() noexcept { delete[] arr; }
};
}; // namespace my_std

int main() {
  my_std::vector<int> v(2);
  v.print();

  v.push_back(3);

  v.print();

  v.push_back(2);
  v.push_back(10);

  v.print();

  my_std::vector<int> v2{1, 2, 3, 4, 5, 6, 7};

  v2.print();

  v2.push_back(20);

  v2.print();
}
