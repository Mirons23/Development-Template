// Copyright 2020 Serebrennikov
#include <iostream>
#include <fstream>
#include "Classlonglong.h"

using namespace std;

int main() {
  longlong c1;
  longlong c2(3, 24566);
  longlong c8(0, 50000);
  longlong c9(0, 24365);
  longlong c10(1, 554334545);

  cout << "input number longlong type" << endl;
  c1.input();
  cout << "Your number: ";
  c1.output();

  longlong c3;
  c3 = c1 + c2;
  cout << "Addition(+) result: ";
  c3.output();

  longlong c4;
  c4 = c2 - c1;
  cout << "Subtraction(-) result: ";
  c4.output();

  longlong c6;
  c6 = c9 * c8;
  cout << "Multipicatin(*) result: ";
  c6.output();

  longlong c7;
  c7 = c10 / c9;
  cout << "Division(/) result: ";
  c7.output();

  longlong c5;
  c5 = c2;
  cout << "Assignmennt(=) example:" << endl;
  c2.output();
  cout << "=" << endl;
  c5.output();

  cout << "Comparison(==) example c1 and c2"<< endl;
  if (c1 == c2)
    cout << "c1 = c2";
  else
    cout << "c1 != c2";
  system("pause");

}
