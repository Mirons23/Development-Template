// Copyright 2020 Serebrennikov
#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>
#include <fstream>
#include "ClassContacts.h"
#include "ClassContact.h"

using namespace std;

#define MAX 100

Contact::Contact() {
  surname = "�������������";
  name = "�����";
  patronymic = "����������";
  tel_number = "89229610000";
  birthday = "23.03.2001";
  sex = "M";
  favorites = 0;
}

Contact::Contact(string _surname, string _name, string _patronymic, string _tel_number,
string _birthday, string _sex, int _favorites) {
  surname = _surname;
  name = _name;
  patronymic = _patronymic;
  tel_number = _tel_number;
  birthday = _birthday;
  sex = _sex;
  favorites = _favorites;
}

Contact::Contact(const Contact& c) {
  surname = c.surname;
  name = c.name;
  patronymic = c.patronymic;
  tel_number = c.tel_number;
  birthday = c.birthday;
  sex = c.sex;
  favorites = c.favorites;
  
}

Contact& Contact::operator=(const Contact &c) {
  surname = c.surname;
  name = c.name;
  patronymic = c.patronymic;
  birthday = c.birthday;
  tel_number = c.tel_number;
  sex = c.sex;
  favorites = c.favorites;
  return *this;
}

std::istream& operator>>(std::istream& stream, Contact& c) {
  cout << "�������: ";
  stream >> c.surname;
  cout << "���: ";
  stream >> c.name;
  cout << "��������: ";
  stream >> c.patronymic;
  cout << "����� ��������: ";
  stream >> c.tel_number;
  cout << "���� ��������: ";
  stream >> c.birthday;
  cout << "���: ";
  stream >> c.sex;
  cout << "�������� � ���������: " << endl;
  cout << "1 - �� | 2 - ��� " << endl;
  cout << "��������?: ";
  stream >> c.favorites;
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const Contact& c) {
  stream << "���: " << c.surname << " " << c.name << " " << c.patronymic << endl;
  stream << "����� ��������: " << c.tel_number << endl;
  stream << "���� ��������: " << c.birthday << endl;
  stream << "���: " << c.sex << endl;
  stream << c.favorites << endl;
  stream << "� ���������: ";
  if (c.favorites == 1)
    stream << "��" << endl;
  else
    stream << "���" << endl;
  return stream;
}

int Contact::returnFavorites() {
  return favorites;
}

void Contact::setFavorites() {
  favorites = 1;
}

string Contact::returnSurname() {
  return surname;
}

string Contact::returnName() {
  return name;
}

string Contact::returnPatronymic() {
  return patronymic;
}

string Contact::returnTelNumber() {
  return tel_number;
}

string Contact::returnBirthday() {
  return birthday;
}

string Contact::returnSex() {
  return sex;
}


void Contact::create_input(Contact &new_contact) {
  cout << "�������� ������ ������������ � ����������:" << endl;
  cout << "�������: ";
  cin >> new_contact.surname;
  cout << "���: ";
  cin >> new_contact.name;
  cout << "��������: ";
  cin >> new_contact.patronymic;
  cout << endl;
  cout << "����� �������� � ������� 8(���)���-��-��: ";
  cin >> new_contact.tel_number;
  cout << endl;
  cout << "���� �������� � �������: " << endl;
  cout << "��.��.����: ";
  cin >> new_contact.birthday;
  cout << endl;
  cout << "��� (�/�) : ";
  cin >> new_contact.sex;
  cout << endl;
  cout << "���������� �� ������� � ���������?" << endl;
  cout << "1 - ��" << endl;
  cout << "0 - ���" << endl;
  cout << "� ���������: ";
  int tmp12;
  cin >> tmp12;
  if (tmp12 == 1)
    new_contact.favorites = 1;
  else
    new_contact.favorites = 0;
}