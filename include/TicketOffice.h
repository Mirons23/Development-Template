// Copyright 2020 Serebrennikov
#pragma once
#include <iostream>

using namespace std;

class TicketOffice {
public:
  TicketOffice();
  TicketOffice(string _data, string _time, string _film, int _hall,
    int _place, int _zone, int _price);
  TicketOffice(const TicketOffice& c);

  string returndate();
  string returntime();
  string returnfilm();
  int returnhall();
  int returnplace();
  int returnzone();
  int returnprice();


  TicketOffice& operator=(const TicketOffice &c);
  friend std::istream& operator>>(std::istream& stream, TicketOffice& c);
  friend std::ostream& operator<<(std::ostream& stream, const TicketOffice& c);

private:
  string date; // ����
  string time;  // �����
  string film;  // �������� ������
  int hall; // ����� ���� 
  int place; // ���-�� ����
  int zone;  // ��� ���� 1- vip; 0 - std
  int price; // 100 ���� ����
};