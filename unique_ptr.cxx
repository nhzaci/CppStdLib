#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "person.cxx"

namespace my_std {

  template <class T> class unique_ptr {
  private:
    T* item;

  public:
    // Start of special member functions
    unique_ptr(unique_ptr<T>&& other) : item{ std::move(other.item) } {};
    unique_ptr& operator=(unique_ptr<T>&& other) {
      item = std::move(other.item);
      delete other;
      return this;
    }
    ~unique_ptr() noexcept { delete item; }

    unique_ptr() = delete;
    unique_ptr(const unique_ptr<T>&) = delete;
    unique_ptr& operator=(const unique_ptr<T>&) = delete;
    // end of special member functions

    unique_ptr(T* tPtr) : item{ tPtr } {};
    T& operator*() { return *item; }
  };

  template <class _Tp, class... _Args>
  inline unique_ptr<_Tp> make_unique(_Args &...__args) {
    return unique_ptr<_Tp>(new _Tp(std::forward<_Args>(__args)...));
  }

} // namespace my_std

int main() {
  using namespace std;

  auto ptr = make_unique<Person>("hello");
  auto ptrArray = make_unique<char[]>(20);

  auto myPtr = my_std::make_unique<Person>("hello");

  cout << "person with std unique ptr is: " << *ptr << endl;
  cout << "person with my unique ptr is: " << *myPtr << endl;
};
