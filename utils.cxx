#include <cmath>
#include <exception>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace my_std {

template <class ForwardIt, class T>
constexpr void iota(ForwardIt first, ForwardIt last, T val) {
  while (first != last) {
    *first++ = val++;
  }
}

template <class T> void printVector(std::vector<T> v) {
  std::cout << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) {
    std::cout << *itr;
    if (itr + 1 != v.end())
      std::cout << ",";
  }
  std::cout << "]\n";
}

int atoi(const char *digitString) {
  int acc = 0;

  bool isNeg = digitString[0] != '\0' and digitString[0] == '-';
  int ptr = isNeg ? 1 : 0;

  for (; digitString[ptr] != '\0'; ptr++) {
    if (digitString[ptr] > '9' or digitString[ptr] < '0')
      throw std::invalid_argument("non-digit character is found");
    acc = acc * 10 + digitString[ptr] - '0';
  }

  return acc;
}

std::string encodeBinary(const char *characterBuffer) {
  std::string res = "";

  for (int i = 0; characterBuffer[i] != '\0'; i++) {
    std::string temp = "";
    int charCode = characterBuffer[i];

    while (charCode > 0) {
      int rem = charCode % 2;

      temp = rem == 0 ? "0" : "1" + temp;
      charCode /= 2;
    }

    while (temp.size() < 8)
      temp = '0' + temp;

    res += temp;
  }

  return res;
}

static const char charSet[32]{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', '2', '3', '4', '5', '6', '7',
};

std::string encodeBase32(const char *characterBuffer) {
  std::string binaryBuffer = encodeBinary(characterBuffer);

  while (binaryBuffer.size() % 5 != 0)
    binaryBuffer = '0' + binaryBuffer;

  std::string result = "";

  for (int i = 0; i < binaryBuffer.size(); i += 5) {
    int value = 0;
    for (int j = 1; j <= 5; j++) {
      value += pow(2, 5 - j) * (binaryBuffer[i + j - 1] == '0' ? 0 : 1);
    }
    result += charSet[value];
  }

  return result;
}

std::string decodeBase32(const char *characterBuffer) { return ""; }

}; // namespace my_std

int main() {
  std::vector<int> v(3);
  my_std::iota(v.begin(), v.end(), 20);

  my_std::printVector<int>(v);

  const char *digitString = "08764939";
  int digitInt = my_std::atoi(digitString);
  int digitIntEmpty = my_std::atoi("");

  std::cout << "iota result: " << digitInt << std::endl;
  std::cout << "iota result: " << digitIntEmpty << std::endl;

  try {
    int digitIntAlphabet = my_std::atoi("abcdef");
    std::cout << "iota result: " << digitIntAlphabet << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error in atoi: " << e.what() << std::endl;
  }

  std::cout << my_std::encodeBinary("8") << std::endl;
  std::cout << my_std::encodeBase32("8") << std::endl;
  std::cout << my_std::encodeBase32("Hello World") << std::endl;
}