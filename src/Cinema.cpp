// Copyright 2020 Serebrennikov
#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Cinema.h"
#include "TicketOffice.h"

using namespace std;

int bn=0; // booking number

Cinema::Cinema() {
  /*
  ����� ���������� �������� �� ����� (� ������ days)
  */

  for (int i = 0; i < 18; i++) {
    for (int j = 0; j < 30; j++) {
      std_seats[i][j] = 30;
      vip_seats[i][j] = 15;
    }
  }
}

void Cinema::take_an_order() {
  int t_zone;
  int t_seats;
  cout << "������� ����� ������: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "������� ����� ������ (��:��): " << endl;
    string t_time;
    cin >> t_time;
    cout << "����������, �������� ������� ���� (���� ����� � 13:10, �� ������� '13' " << endl;
    int t_hour;
    cin >> t_hour;
    double skidka;
    if (t_hour < 12) {
      skidka = 0.75;
    }
    if (t_hour >= 12 && t_hour < 18) {
      skidka = 1;
    }
    if (t_hour >= 18) {
      skidka = 1.5;
    }
    cout << "������� �������� ������: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "� ����� ���� �� ������ ������ |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "������� ���� ��� �����: " << endl;
      int t_seats;
      cin >> t_seats;
      cout << "�� ����������� ������? |1-��|0-���|" << endl;
      int tmp;
      cin >> tmp;
      if (tmp == 0) {
        double t_price;
        t_price = days[i][t_date].returnprice() * skidka * t_zone;
        cout << "������� " << t_price << " ������ ��� ������� �������" << endl;
        cout << "������..." << endl;
        if (t_zone == 1) {
          if (std_seats[i][t_date] >= t_seats) {
            std_seats[i][t_date] = std_seats[i][t_date] - t_seats;
            cout << "_________________________________________________" << endl;
            cout << "|�����: "<< t_film << "                          |" << endl;
            cout << "|���: "<< days[i][t_date].returnhall()<< "       |" << endl;
            cout << "|����� ������: "<< t_time<<"                     |" << endl;
            cout << "|���������� ��������� ����: " << t_seats << "    |" << endl;
            cout << "|����� ������: "<<  t_time << "                  |" << endl;
            cout << "|               ��������� ���������              |" << endl;
            cout << "|________________________________________________|" << endl;
            break;
          }
          else {
            cout << "����������,�������� ������ �����, ���� ���" << endl;
            break;
          }
        }
        else {
          if (vip_seats[i][t_date] >= t_seats) {
            vip_seats[i][t_date] = vip_seats[i][t_date] - t_seats;
            cout << "_________________________________________________" << endl;
            cout << "|�����: " << t_film << "                          |" << endl;
            cout << "|���: " << days[i][t_date].returnhall() << "       |" << endl;
            cout << "|����� ������: " << t_time << "                     |" << endl;
            cout << "|���������� ��������� ����: " << t_seats << "    |" << endl;
            cout << "|����� ������: " << t_time << "                  |" << endl;
            cout << "|               ��������� ���������              |" << endl;
            cout << "|________________________________________________|" << endl;
            break;
          }
          else {
            cout << "����������,�������� ������ �����, ���� ���" << endl;
            break;
          }
        }
      }
    }

    else {
      cout << "������� ��� ������������: " << endl;
      int code;
      cin >> code;
      for (int i = 0; i < 100; i++) {
        if (booking_code[i] == code) {
          double t_price;
          t_price = days[i][t_date].returnprice() * skidka*t_zone;
          cout << "������� "<<  t_price << " ������ ��� ������� �������" << endl;
          cout << "������..." << endl;
          cout << "_________________________________________________" << endl;
          cout << "|�����: " << t_film << "                         |" << endl;
          cout << "|���: " << days[i][t_date].returnhall() << "     |" << endl;
          cout << "|����� ������: " << t_time << "                  |" << endl;
          cout << "|���������� ��������� ����: " << t_seats << "    |" << endl;
          cout << "|����� ������: " << t_time << "                  |" << endl;
          cout << "|               ��������� ���������              |" << endl;
          cout << "|________________________________________________|" << endl;
          break;
        }
      }
    }
  }
}

void Cinema::checking_places() {
  cout << "������� ����� ������: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "������� ����� ������ (��:��): " << endl;
    string t_time;
    cin >> t_time;
    cout << "������� �������� ������: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "������� ���� � ����� ���� ����� ���������? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "������� ���� ��� �����: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
        cout << "� ��������� ���� " << std_seats[i][t_date] << " ��������� ����" << endl;
      } else {
        cout << "� ��������� ���� "<< vip_seats[i][t_date]<< " ��������� ����" << endl;
      }
    } else {
      cout << "������ ������ �� ����������! " << endl;
      break;
    }
  }
}

void Cinema::booking() {
  cout << "������� ����� ������: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "������� ����� ������ (��:��): " << endl;
    string t_time;
    cin >> t_time;
    cout << "������� �������� ������: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "� ����� ���� �� ������ ������? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "������� ���� ��� �����: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
        if (std_seats[i][t_date] >= t_seats) {
          std_seats[i][t_date] = std_seats[i][t_date] - t_seats;
          cout << "����� �������������" << endl;
          cout << "������� ��� **** ��� ������ ������������ (�� ����� �������������� ��� ������� ��� ������ �����): " << endl;
          cin >> booking_code[bn];
          bn++;
          break;
        }
        else {
          cout << "����������,�������� ������ �����, ���� ���" << endl;
          break;
        }
      }
      else {
        if (vip_seats[i][t_date] >= t_seats) {
          vip_seats[i][t_date] = vip_seats[i][t_date] - t_seats;
          cout << "����� �������������" << endl;
          cout << "������� ��� **** ��� ������ ������������ (�� ����� �������������� ��� ������� ��� ������ �����): " << endl;
          cin >> booking_code[bn];
          bn++;
          break;
        }
        else {
          cout << "����������,�������� ������ �����, ���� ���" << endl;
          break;
        }
      }
    }
    else {
      cout << "������ ������ �� ����������! " << endl;
      break;
    }
  }
}

void Cinema::total_cost() {
  cout << "������� ����� ������: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "������� ����� ������ (��:��): " << endl;
    string t_time;
    cin >> t_time;
    cout << "����������, �������� ������� ���� (���� ����� � 13:10, �� ������� '13' " << endl;
    int t_hour;
    cin >> t_hour;
    double skidka;
    if (t_hour < 12) {
      skidka = 0.75;
    }
    if (t_hour >= 12 && t_hour < 18) {
      skidka = 1;
    }
    if (t_hour >= 18) {
      skidka = 1.5;
    }
    cout << "������� �������� ������: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "������� ���� � ����� ���� ����� ���������? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "������� ���� ��� �����: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
        double t_price;
        t_price = days[i][t_date].returnprice() * skidka * t_zone;
        cout << "����� ������ �������� "<< t_price << " ������" << endl;
        break;
      }
      else {
        double t_price;
        t_price = days[i][t_date].returnprice() * skidka * t_zone;
        cout << "����� ������ �������� "<< t_price<< " ������" << endl;
        break;
      }
    }
    else {
      cout << "������ ������ �� ����������! " << endl;
      break;
    }
  }
}

void Cinema::unbooking() {
  cout << "������� ����� ������: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "������� ����� ������ (��:��): " << endl;
    string t_time;
    cin >> t_time;
    cout << "������� �������� ������: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "� ����� ���� �� ������ ������? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "������� ���� �� �����������: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
          std_seats[i][t_date] = std_seats[i][t_date] + t_seats;
          cout << "����� �����" << endl;
          break;
      } else {
        vip_seats[i][t_date] = vip_seats[i][t_date] + t_seats;
        cout << "����� �����" << endl;
        break;
      }
    }
    else {
      cout << "������ ������ �� ����������! " << endl;
      break;
    }
  }
}
