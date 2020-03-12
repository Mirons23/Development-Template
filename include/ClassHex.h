// Copyright 2020 Serebrennikov
#include <iostream>
#include <fstream>

#define MAX 1000

using namespace std;

class Hex {
public:
  Hex();
  Hex(const Hex& c);
  Hex(const char _number[], int _size);

  void input();
  void output();
  friend ostream& operator<<(ostream& stream, const Hex& c);
  friend istream& operator>>(istream& stream, Hex& c);

  Hex& operator=(const Hex& c);

  bool operator!=(const Hex& c);

  bool operator==(const Hex& c) {
    bool res = true;
    if (size == c.size) {
      for (int i = 0; i < c.size; i++) {
        if (number[i] != c.number[i]) {
          res = false;
          break;
        }
      }
    }
    else {
      res = false;
    }
    return res;
  }

  friend bool operator==(const Hex& left, const Hex& right) {
    bool res = true;
    if (left.size == right.size) {
      for (int i = 0; i < left.size; i++) {
        if (left.number[i] != right.number[i]) {
          res = false;
          break;
        }
      }
    }
    else {
      res = false;
    }
    return res;
  }

  Hex operator+(const Hex& c);
  Hex operator-(const Hex& c);

private: 
  int size;
  char* number;
};
