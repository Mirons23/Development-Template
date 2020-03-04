// Copyright 2020 Serebrennikov 
#ifndef INCLUDE_COMPLEX_H_
#define INCLUDE_COMPLEX_H_

#include <iostream>
#include <fstream>

using namespace std;

class longlong {
private:
  int st;            // strshaya chast' chisla
  unsigned int ml;  // mladshaya chast' chisla

public:
  longlong();
  longlong(const longlong &c);
  longlong(int _st, unsigned int _ml);

  void input();                    // input operation
  void output();                  // output operation

  longlong operator+(const longlong &c);     // overloaded + operation
  longlong operator-(const longlong &c);    // overloaded - operation
  longlong operator/(const longlong &c);   // overloaded / operation
  longlong operator*(const longlong &c);  // overloaded * operation

  longlong& operator=(const longlong& c);   // overloaded = operation

  bool operator!=(const longlong& c);

  bool operator==(const longlong& c) {
    if (c.st == st && c.ml == ml)
      return true;
    else
      return false;
  }  // overloaded == operation

  friend bool operator==(const longlong& left, const longlong& right) {
    if (left.st == right.st && left.ml == right.ml)
      return true;
    else
      return false;
  }

};

#endif
