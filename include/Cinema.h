// Copyright 2020 Serebrennikov
#pragma once
#include <iostream>
#include "TicketOffice.h"

using namespace std;

class Cinema {
public:
  Cinema();


  void take_an_order(); // ������� ����� 
  void checking_places(); // �������� ���������� ��������� ����
  void booking(); //������������
  void total_cost(); // ����� ���������
  void unbooking(); // ������ �����

  Cinema& operator=(const Cinema &c);

private:
  TicketOffice days[18][30]; // 18 ������� � ���� .. 30 ���� 
  int vip_seats[18][30]; // ���������� ���� �� ������ ������
  int std_seats[18][30]; // ���������� ���� �� ������ ������
  int booking_code[100];
};
