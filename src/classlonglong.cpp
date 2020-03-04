// Copyright 2020 Serebrennikov
#include <iostream>
#include <fstream>
#include "Classlonglong.h"

using namespace std;
/*construction and distruction realization*/

longlong::longlong() {
  st = 0;
  ml = 0;
}

longlong::longlong(const longlong &c) {
  st = c.st;
  ml = c.ml;
}

longlong::longlong(int _st, unsigned int _ml) : st(_st), ml(_ml) { }

void longlong::input() {
  cout << "input older number part (< 1kkk): ";
  cin >> st;
  cout << endl;
  cout << "input younger number part (< 1kkk): ";
  cin >> ml;
  cout << endl;
}


void longlong::output() {
  int k = 0, z;
  if (st == 0) {
    cout << ml << endl;
  }
  else {
    z = ml;
    while ((z /= 10) > 0)
      k++;
    k = 9 - k - 1;
    cout << st;
    for (int i = 0; i < k; i++)
      cout << "0";
    cout << ml << endl;
  }
}

longlong longlong::operator+(const longlong &c) {
  longlong res;
  res.st = st + c.st;
  res.ml = ml + c.ml;
  return res;
}

longlong longlong::operator-(const longlong &c) {
  longlong res;
  int p = st;
  int p2 = ml;
  if (ml < c.ml) {
    p2 = ml + pow(10, 9);
    p--;
    res.ml = p2 - c.ml;
    res.st = p - c.st;
  }
  else {
    res.st = st - c.st;
    res.ml = ml - c.ml;
  }

  return res;
}
/*
longlong longlong::operator*(const longlong &c) {
  longlong res;
  for (int i = 0; i < c.ml; i++) {
    res.ml = res.ml + ml;
    if (res.ml >= pow(10, 9)) {
      res.ml = (res.ml - (res.ml / pow(10, 9)));
    }
  }
  return res;
}*/

longlong longlong::operator*(const longlong &c) {
  longlong res;
  // peremnozhenie ml & c.ml chastei
  int p = ml;
  while (p != 0) {
    res.ml = res.ml + c.ml;
    p--;
    if (res.ml >= 1000000000) {
      res.ml = (res.ml - pow(10, 9));
      res.st++;
    }
  }
  // peremnozhenie st & c.st chastei
  if (st != 0 || c.st != 0) {
    res.st = (res.st + ((st * c.st) * pow(10, 18)));

    // peremnozhenie st & c.ml
    if (st != 0) {
      for (int i = 0; i < c.ml; i++) {
        res.st = res.st + 0 + st;
      }
    }
    // peremnozhenie c.st & ml
    if (c.st != 0) {
      for (int i = 0; i < ml; i++) {
        res.st = res.st + 0 + c.st;
      }
    }
  }
  return res;
}

// peremnozhenie rabotaet tol'ko kogda delitel' <10^9
longlong longlong::operator/(const longlong &c) {
  longlong res;
  if (c.ml != 0) {
    res.ml = (st* pow(10, 9)) / c.ml;
    res.ml = res.ml + ml / c.ml;
    res.st = 0;
  }
  else {
    cout << "Nel'zya delit' na 0";
  }
  return res;
}

longlong& longlong::operator=(const longlong& c) {
  (*this).st = c.st;
  ml = c.ml;
  return *this;
}



bool longlong::operator!=(const longlong& c) {
  if (c.st != st || c.ml != ml)
    return true;
  else
    return false;
}

