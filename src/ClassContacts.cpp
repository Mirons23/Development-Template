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

Contacts::Contacts() {
  kolvo = 0;
}

Contacts::Contacts(int _kolvo) {
  kolvo = _kolvo;
  base = new Contact[kolvo];
}

Contacts::Contacts(int _kolvo, const Contact* c) {
  kolvo = _kolvo;
  base = new Contact[kolvo];
  for (int i = 0; i < kolvo; i++) {
    base[i] = c[i];
  }
}

Contacts::Contacts(const Contacts& c) {
  kolvo = c.kolvo;
  base = new Contact[kolvo];
  for (int i = 0; i < kolvo; i++) {
    base[i] = c.base[i];
  }
}

Contacts& Contacts::operator=(const Contacts &c) {
  base = c.base;
  kolvo = c.kolvo;
  return *this;
}

void Contacts::create_add(const Contact& new_contact) {
  Contact* new_base = new Contact[kolvo + 1];
  for (int i = 0; i < kolvo; i++) {
    new_base[i] = base[i];
  }
  new_base[kolvo] = new_contact;

  Contacts new_book(kolvo + 1, new_base);
  *this = new_book;
}

int Contacts::kolvo_contacts() {
  int count;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  /*ifstream f("D:\\user\\Desktop\\Tor Browser\\Contacts.txt");
  if (f.is_open()) {
    cout << "file open" << endl;
    f >> kolvo;
  } else {
    cout << "Unable to open file";
  }
  int count;
  count = kolvo;*/
  cout <<"���������� ��������� = " << /*count*/ kolvo << endl;
  //kolvo = count;
  return kolvo;
}

void Contacts::add_to_array() { //������ ���� � ��������� � ������ ��������
  int count;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
 
  ifstream f("D:\\user\\Desktop\\Tor Browser\\Contacts.txt");
  if (f.is_open())
  {
    f >> count;
    kolvo = count;
    for (int i = 0; i <= count; i++) {
      f >> base[i];                             // ����� ��� ����� ���� � �������� ���������� ��������� >> � Contact
    }
    f.close();
  } else {
    cout << "Unable to open file";
  }
}

void Contacts::all_favorites() {
  cout << "������ ���������: ";
  int tmp1 = 0;
  for (int i = 0; i <= kolvo; i++) {
    if (base[i].returnFavorites() == 1) {
      cout << endl << base[i] << endl;
      tmp1++;
    }
  }
  if (tmp1 == 0)
    cout << "����";
}

void Contacts::output_array() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  for (int i = 0; i <= kolvo - 1; i++) {
    cout << base[i] << endl;
  }
}


void Contacts::surname_input(string& _surname, string& _name, string& _patronymic) { //����� �� �������
  cout << "������� �������: ";
  cin >> _surname;
  cout << "������� ���: ";
  cin >> _name;
  cout << "������� ��������: ";
  cin >> _patronymic;
}

void Contacts::search_by_surname(string _surname, string _name, string _patronymic) {
  for (int i = 0; i < kolvo; i++) {
    if (base[i].returnSurname() == _surname) {
      if (base[i].returnName() == _name) {
        if (base[i].returnPatronymic() == _patronymic) {
          cout << base[i] << endl;
        } else {
          cout << "������� �� ������" << endl;
          break;
        }
      } else {
        cout << "������� �� ������" << endl;
        break;
      }
    }
  }
}

int Contacts::search_by_surname_return_index(string _surname, string _name, string _patronymic) {
  for (int i = 0; i < kolvo; i++) {
    if (base[i].returnSurname() == _surname) {
      if (base[i].returnName() == _name) {
        if (base[i].returnPatronymic() == _patronymic) {
          return i;
        }
        else {
          return -1;
        }
      }
    }
  }
}

void Contacts::add_to_favorites(string _surname, string _name, string _patronymic) {
  
  for (int i = 0; i < kolvo; i++) {
    if (base[i].returnSurname() == _surname) {
      if (base[i].returnName() == _name) {
        if (base[i].returnPatronymic() == _patronymic) {
          cout << "������� �������� � ������ ���������" << endl;
          base[i].setFavorites();
          break;
        } else {
          cout << "������� �� ������" << endl;
          break;
        }
      } else {
        cout << "������� �� ������" << endl;
        break;
      }
    }
  }
}

void Contacts::search_tel_number_input(string& tel_number) { //����� �� ������ ��������
  cout << "������� ����� �������� � ������� 8(���)���-��-��: ";
  cin >> tel_number;
}

void Contacts::search_tel_number_add(string tel_number) {
  int tmp1 = 0;
  for (int i = 0; i <= kolvo; i++) {
    if (base[i].returnTelNumber() == tel_number) {
      tmp1++;
      cout << "������ ��������: " << base[i].returnSurname() << " " << base[i].returnName() << endl;
      cout << "����� ��������: " << base[i].returnTelNumber() << endl;
      cout << "���� ��������: " << base[i].returnBirthday() << endl;
      cout << "���: " << base[i].returnSex() << endl;
      cout << "� ���������: ";
      if (base[i].returnFavorites() == 1)
        cout << "��" << endl;
      else
        cout << "���" << endl;
      break;
    }
  }
  if (tmp1 == 0)
    cout << "������� �� ������" << endl;
}


void Contacts::change_contact_input(string& new_surname, string& new_name, string& new_patronymic, Contact& modifide_contact) {
   cout << "������� ����� ������ ��������: " << endl;
   cin >> modifide_contact;
}


void Contacts::change_contact_add(string _surname, string _name, string _patronymic, const Contact& modifide_contact) {
  int index = search_by_surname_return_index(_surname, _name, _patronymic);
  if (index != -1) {
    base[index] = modifide_contact;
  } else {
     cout << "������� �� ������" << endl;
  }
}

void Contacts::search_letter_input(char &b) {
  cout << "������� ������ ����� �������: ";
  cin >> b;
}
void Contacts::search_letter_add(char b) {
  int tmp1 = 0;
  for (int i = 0; i <= kolvo; i++) {
    string tmppp = base[i].returnSurname();
    if (tmppp[0] ==  b) {
      tmp1++;
      cout << "������ ��������: " << base[i].returnSurname() << " " << base[i].returnName() << endl;
      cout << "����� ��������: " << base[i].returnTelNumber() << endl;
      cout << "���� ��������: " << base[i].returnBirthday() << endl;
      cout << "���: " << base[i].returnSex() << endl;
      cout << "� ���������: ";
      if (base[i].returnFavorites() == 1)
        cout << "��" << endl;
      else
        cout << "���" << endl;
      break;
    }
  }
  if (tmp1 == 0)
    cout << "������� �� ������" << endl;
}


void Contacts::delete_surname_add(Contact &contact) {
  Contact delete_("", "", "", "", "", "", 3);
  Contact offset;

  if (kolvo == 1) {
    base[0] = delete_;
  } else {
    for (int i = 0; i <= kolvo; i++) {
      if (base[i].returnSurname() == contact.returnSurname()) {
        if (base[i].returnName() == contact.returnName()) {
          if (base[i].returnPatronymic() == contact.returnPatronymic()) {
            int ii = i;
            cout << "������� ������" << endl;
            base[i] = delete_;

            for (ii; ii <= kolvo; ii++) {
              offset = base[i];
              base[i] = base[i + 1];
              base[i + 1] = offset;
            }
            kolvo--;
            break;
          }
          else {
            cout << "������� �� ������" << endl;
            break;
          }
        }
        else {
          cout << "������� �� ������" << endl;
          break;
        }
      }
    }
  }
}

void Contacts::delete_tel_number_input(Contact &contact) {
  cout << "������� ����� �������� � ������� 8(���)���-��-��: ";
  cin >> contact.returnTelNumber();
}
void Contacts::delete_tel_number_add(Contact &contact) {
  int p = 0;
  
  Contact delete_("","","","","","",3);
  Contact offset;

  for (int i = 0; i <= kolvo; i++) {
    if (base[i].returnTelNumber() == contact.returnTelNumber()) {
      int ii = i;
      cout << "������� ������" << endl;
      base[i] = delete_;

      for (ii; ii <= kolvo; ii++) {
        offset = base[i];
        base[i] = base[i + 1];
        base[i + 1] = offset;

        /*string tmppp;
        int tmppp1;
        tmppp = base[i + 1].returnSurname;
        base[i + 1].returnSurname = base[i].returnSurname;
        base[i].returnSurname = tmppp;
        tmppp = base[i + 1].returnName;
        base[i + 1].returnName = base[i].returnName;
        base[i].returnName = tmppp;
        tmppp = base[i + 1].returnPatronymic;
        base[i + 1].returnPatronymic = base[i].returnPatronymic;
        base[i].returnPatronymic = tmppp;
        tmppp = base[i + 1].returnBirthday;
        base[i + 1].returnBirthday = base[i].returnBirthday;
        base[i].returnBirthday = tmppp;
        tmppp = base[i + 1].returnTelNumber;
        base[i + 1].returnTelNumber = base[i].returnTelNumber;
        base[i].returnTelNumber = tmppp;
        tmppp = base[i + 1].returnSex;
        base[i + 1].returnSex = base[i].returnSex;
        base[i].returnSex = tmppp;
        tmppp1 = base[i + 1].returnFavorites;
        base[i + 1].returnFavorites = base[i].returnFavorites;
        base[i].returnFavorites = tmppp1;*/
      }
      kolvo--; p++;
      break;
    }
  }
  if (p == 0)
    cout << "������� �� ������" << endl;
}

void Contacts::end() {
  int count;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  ofstream f("D:\\user\\Desktop\\Tor Browser\\Contacts.txt");
  if (f.is_open())
  {
    f << kolvo << endl;

    for (int i = 0; i <= kolvo - 1; i++) {
      f << base[i].returnSurname() << endl;
      f << base[i].returnName() << endl;
      f << base[i].returnPatronymic() << endl;
      f << base[i].returnTelNumber() << endl;
      f << base[i].returnBirthday() << endl;
      f << base[i].returnSex() << endl;
      f << base[i].returnFavorites() << endl;
    }
    f.close();
  }
  else
  {
    cout << "Unable to open file";
  }
}