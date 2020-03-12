// Copyright 2020 Serebrennikov
#include <iostream>
#include <fstream>
#include "ClassHex.h"


#define MAX 1000

using namespace std;



int numberInt1_[1000];
int numberInt2_[1000];

Hex::Hex() {
  size = 5;
  number = 0;
  char* number = new char[1000];
  for (int i = 0; i < size; i++)
    number[i] = '0';
}

Hex::Hex(const Hex& c) {
  size = c.size;
  number = c.number;
  const int s = size;
  char* number = new char[s];
}

Hex::Hex(const char _number[], int _size) {
  size = _size;
  number = (char*)_number;
  const int s = size;
  char* number = new char[s];
}

ostream& operator<<(ostream& stream, const Hex& c);
istream& operator>>(istream& stream, Hex& c);

Hex& Hex::operator=(const Hex& c) {
  const int size_ = size;
  (*this).number = new char[size_];
  for (int i = size; i >= 0; i--) {
    (*this).number[i] = c.number[i];
    number[i] = c.number[i];
  }
  return *this;
}

bool Hex::operator!=(const Hex& c) {
  bool res = true;
  if (size != c.size) {
    for (int i = 0; i < c.size; i++) {
      if (number[i] == c.number[i]) {
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

int u = 0;

void Hex::output() {
  
  

   cout << "Number = ";
     
   for (int i =0; i<u; i++) {
     cout << number[i];
   }
   cout << endl;
}

ostream& operator<<(ostream& stream, const Hex& c) {

  

  stream << "Number = ";

  for (int i = 0; i < u; i++) {
    stream << c.number[i];
  }

  cout << endl;
  return stream;
}

void Hex::input() {
  cout << "Innput size of Hex number: ";
  cin >> size;
  cout << endl;
  cout << "Input Hex Number: " << endl;
  const int _s = size;
  number = new char[_s];

  for (int i = 0; i < size; i++) {
    cin >> number[i];
  }
}

istream& operator>>(istream& stream_, Hex& c) {

  cout << "Input size of Hex number: ";
  stream_ >> c.size;
  cout << endl;
  cout << "Input Hex Number: " << endl;

  const int _s = c.size;
  c.number = new char[_s];


  for (int i = 0; i < c.size; i++)
    stream_ >> c.number[i];

  return stream_;

}

Hex Hex::operator+(const Hex& c) {

  int numberInt1[1000];
  int numberInt2[1000];

  int res_numberInt[1000];
  int s = 0;
  if (size > c.size || size==c.size)
    s = size;
  else
    s = c.size;
  u = s;
  for (int i = 0; i < s; i++) {
    switch (c.number[i])
    {
    case '0':
    {
      numberInt2[i] = 0;
      break;
    }
    case '1':
    {
      numberInt2[i] = 1;
      break;
    }
    case '2':
    {
      numberInt2[i] = 2;
      break;
    }
    case '3':
    {
      numberInt2[i] = 3;
      break;
    }
    case '4':
    {
      numberInt2[i] = 4;
      break;
    }
    case '5':
    {
      numberInt2[i] = 5;
      break;
    }
    case '6':
    {
      numberInt2[i] = 6;
      break;
    }
    case '7':
    {
      numberInt2[i] = 7;
      break;
    }
    case '8':
    {
      numberInt2[i] = 8;
      break;
    }
    case '9':
    {
      numberInt2[i] = 9;
      break;
    }
    case 'A':
    {
      numberInt2[i] = 10;
      break;
    }
    case 'B':
    {
      numberInt2[i] = 11;
      break;
    }
    case 'C':
    {
      numberInt2[i] = 12;
      break;
    }
    case 'D':
    {
      numberInt2[i] = 13;
      break;
    }
    case 'E':
    {
      numberInt2[i] = 14;
      break;
    }
    case 'F':
    {
      numberInt2[i] = 15;
      break;
    }
    case ' ':          // тут если не ' ', то '\0';
    {
      numberInt2[i] = 0;
      break;
    }
    
    }
  }

  for (int i = 0; i < s; i++) {
    switch (number[i])
    {
    case '0':
    {
      numberInt1[i] = 0;
      break;
    }
    case '1':
    {
      numberInt1[i] = 1;
      break;
    }
    case '2':
    {
      numberInt1[i] = 2;
      break;
    }
    case '3':
    {
      numberInt1[i] = 3;
      break;
    }
    case '4':
    {
      numberInt1[i] = 4;
      break;
    }
    case '5':
    {
      numberInt1[i] = 5;
      break;
    }
    case '6':
    {
      numberInt1[i] =6;
      break;
    }
    case '7':
    {
      numberInt1[i] = 7;
      break;
    }
    case '8':
    {
      numberInt1[i] = 8;
      break;
    }
    case '9':
    {
      numberInt1[i] = 9;
      break;
    }
    case 'A':
    {
      numberInt1[i] = 10;
      break;
    }
    case 'B':
    {
      numberInt1[i] = 11;
      break;
    }
    case 'C':
    {
      numberInt1[i] = 12;
      break;
    }
    case 'D':
    {
      numberInt1[i] = 13;
      break;
    }
    case 'E':
    {
      numberInt1[i] = 14;
      break;
    }
    case 'F':
    {
      numberInt1[i] = 15;
      break;
    }
    case ' ':                        // тут если не ' ', то '\0';
    {
      numberInt1[i] = 0;
      break;
    }
    }
  }
  int tmp = 0;

  for (int i = 0; i < size/2; i++) {              // переворачиваем число
    tmp = numberInt1[i];
    numberInt1[i] = numberInt1[size - 1 - i];
    numberInt1[size - 1 - i] = tmp;
  }
  for(int i = 0; i < c.size/2;i++) {
    tmp = numberInt2[i];
    numberInt2[i] = numberInt2[c.size - 1 - i];
    numberInt2[c.size - 1 - i] = tmp;
  }

  Hex res;
  const int _s = s;
  res.number = new char[_s];
  
  for (int i = 0; i<s; i++) {           // складываем в массив инт
    if (numberInt1[i] < 0) {
      numberInt1[i] = 0;
    }
    if (numberInt2[i] < 0) {
      numberInt2[i] = 0;
    }
      res_numberInt[i] =  numberInt1[i] + numberInt2[i];
      if (res_numberInt[i] > 15) {
        if (numberInt1[i+1] < 0) 
          numberInt1[i+1] = 1;
         else
        numberInt1[i + 1]++;
        res_numberInt[i] = res_numberInt[i] - 16;
        if (abs(size - c.size) <1 || abs(c.size - size) <1)   ///// 
        s++;
      }
  }
      
  
  
  for (int i = 0; i < s; i++) {
    if (res_numberInt[i] > 9) {
      switch (res_numberInt[i])
      {
      case 10:
      {
        res.number[i] = 'A';
        break;
      }
      case 11:
      {
        res.number[i] = 'B';
        break;
      }
      case 12:
      {
        res.number[i] = 'C';
        break;
      }
      case 13:
      {
        res.number[i] = 'D';
        break;
      }
      case 14:
      {
        res.number[i] = 'E';
        break;
      }
      case 15:
      {
        res.number[i] = 'F';
        break;
      }
      }
    }
    else {
      res.number[i] = (res_numberInt[i]) + '0';
    }
  }

  int tmp3 = 0;

  for (int i = 0; i < _s / 2; i++) {
    tmp3 = res.number[i];
    res.number[i] = res.number[u - 1 - i];
    res.number[u - 1 - i] = tmp3;
  }
  
    return res;
}

Hex Hex::operator-(const Hex& c) {  
  int numberInt1_[1000];
  int numberInt2_[1000];
  int res_numberInt_[1000];
  int s = 0;
  int sMin = 0;
  if (size > c.size || size == c.size) {
    s = size;
    sMin = c.size;
  }
  else{
    s = c.size;
  sMin = size;
  }
  
  u = s;
  for (int i = 0; i < s; i++) {
    switch (c.number[i])
    {
    case '0':
    {
      numberInt2_[i] = 0;
      break;
    }
    case '1':
    {
      numberInt2_[i] = 1;
      break;
    }
    case '2':
    {
      numberInt2_[i] = 2;
      break;
    }
    case '3':
    {
      numberInt2_[i] = 3;
      break;
    }
    case '4':
    {
      numberInt2_[i] = 4;
      break;
    }
    case '5':
    {
      numberInt2_[i] = 5;
      break;
    }
    case '6':
    {
      numberInt2_[i] = 6;
      break;
    }
    case '7':
    {
      numberInt2_[i] = 7;
      break;
    }
    case '8':
    {
      numberInt2_[i] = 8;
      break;
    }
    case '9':
    {
      numberInt2_[i] = 9;
      break;
    }
    case 'A':
    {
      numberInt2_[i] = 10;
      break;
    }
    case 'B':
    {
      numberInt2_[i] = 11;
      break;
    }
    case 'C':
    {
      numberInt2_[i] = 12;
      break;
    }
    case 'D':
    {
      numberInt2_[i] = 13;
      break;
    }
    case 'E':
    {
      numberInt2_[i] = 14;
      break;
    }
    case 'F':
    {
      numberInt2_[i] = 15;
      break;
    }
    case ' ':          // тут если не ' ', то '\0';
    {
      numberInt2_[i] = 0;
      break;
    }

    }
  }

  for (int i = 0; i < s; i++) {
    switch (number[i])
    {
    case '0':
    {
      numberInt1_[i] = 0;
      break;
    }
    case '1':
    {
      numberInt1_[i] = 1;
      break;
    }
    case '2':
    {
      numberInt1_[i] = 2;
      break;
    }
    case '3':
    {
      numberInt1_[i] = 3;
      break;
    }
    case '4':
    {
      numberInt1_[i] = 4;
      break;
    }
    case '5':
    {
      numberInt1_[i] = 5;
      break;
    }
    case '6':
    {
      numberInt1_[i] = 6;
      break;
    }
    case '7':
    {
      numberInt1_[i] = 7;
      break;
    }
    case '8':
    {
      numberInt1_[i] = 8;
      break;
    }
    case '9':
    {
      numberInt1_[i] = 9;
      break;
    }
    case 'A':
    {
      numberInt1_[i] = 10;
      break;
    }
    case 'B':
    {
      numberInt1_[i] = 11;
      break;
    }
    case 'C':
    {
      numberInt1_[i] = 12;
      break;
    }
    case 'D':
    {
      numberInt1_[i] = 13;
      break;
    }
    case 'E':
    {
      numberInt1_[i] = 14;
      break;
    }
    case 'F':
    {
      numberInt1_[i] = 15;
      break;
    }
    case ' ':                        // тут если не ' ', то '\0';
    {
      numberInt1_[i] = 0;
      break;
    }
    }
  }
  int tmp = 0;

  for (int i = 0; i < size / 2; i++) {              // переворачиваем число
    tmp = numberInt1_[i];
    numberInt1_[i] = numberInt1_[size - 1 - i];
    numberInt1_[size - 1 - i] = tmp;
  }
  for (int i = 0; i < c.size / 2; i++) {
    tmp = numberInt2_[i];
    numberInt2_[i] = numberInt2_[c.size - 1 - i];
    numberInt2_[c.size - 1 - i] = tmp;
  }
  
    for (int i = 0; i < s; i++) {
      if (numberInt2_[i] < 0) {
        res_numberInt_[i] = numberInt1_[i];
      }
      else {
        if (numberInt1_[i] > numberInt2_[i]) {
          res_numberInt_[i] = numberInt1_[i] - numberInt2_[i];
        }
        else {
          if (numberInt1_[i] == numberInt2_[i]) {
            res_numberInt_[i] = 0;
          }
          else {
            if (numberInt1_[i] < numberInt2_[i]) {
              numberInt1_[i + 1] --;
              numberInt1_[i] = numberInt1_[i] + 16;
              res_numberInt_[i] = numberInt1_[i] - numberInt2_[i];
            }
          }
        }
      }
    }
  
  

  Hex res;
  const int _s = s;
  res.number = new char[_s];

  for (int i = 0; i < s ; i++) {
    if (res_numberInt_[i] > 9) {
      switch (res_numberInt_[i])
      {
      case 10:
      {
        res.number[i] = 'A';
        break;
      }
      case 11:
      {
        res.number[i] = 'B';
        break;
      }
      case 12:
      {
        res.number[i] = 'C';
        break;
      }
      case 13:
      {
        res.number[i] = 'D';
        break;
      }
      case 14:
      {
        res.number[i] = 'E';
        break;
      }
      case 15:
      {
        res.number[i] = 'F';
        break;
      }
      }
    }
    else {
      res.number[i] = (res_numberInt_[i]) + '0';
    }
  }
  if (size < c.size) {
    res.number[s-1] = '-';
    
  }
  int tmp3 = 0;

  for (int i = 0; i < u / 2; i++) {
    tmp3 = res.number[i];
    res.number[i] = res.number[u - 1 - i];
    res.number[u - 1 - i] = tmp3;

  }

  return res;
}
