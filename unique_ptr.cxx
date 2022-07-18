#include <iostream>
#include <memory>
#include <string>
#include <utility>

namespace my_std {

template <class T> class unique_ptr {
private:
  T *item;

public:
  // Start of special member functions
  unique_ptr(unique_ptr<T> &&other) : item{std::move(other.item)} {};
  unique_ptr &operator=(unique_ptr<T> &&other) {
    item = std::move(other.item);
    delete other;
    return this;
  }
  ~unique_ptr() noexcept { delete item; }

  unique_ptr() = delete;
  unique_ptr(const unique_ptr<T> &) = delete;
  unique_ptr &operator=(const unique_ptr<T> &) = delete;
  // end of special member functions

  unique_ptr(T *tPtr) : item{tPtr} {};
  T &operator*() { return *item; }
};

template <class T, class... _Args> unique_ptr<T> make_unique(_Args &..._args) {
  return unique_ptr<T>(new T(std::forward<_Args>(_args)...));
}

} // namespace my_std

struct Person {
  std::string name;
  Person(std::string _name) : name{_name} {};
};

std::ostream &operator<<(std::ostream &os, Person &p) {
  return os << "Person(name:" << p.name << ");";
}

int main() {
  using namespace std;

  auto ptr = make_unique<Person>("hello");
  auto myPtr = my_std::make_unique<Person>("hello");

  cout << "person with std unique ptr is: " << *ptr << endl;
  cout << "person with my unique ptr is: " << *myPtr << endl;
};
