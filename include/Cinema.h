// Copyright 2020 Serebrennikov
#pragma once
#include <iostream>
#include "TicketOffice.h"

using namespace std;

class Cinema {
public:
  Cinema();


  void take_an_order(); // принять заказ 
  void checking_places(); // проверка количества свободных мест
  void booking(); //бронирование
  void total_cost(); // общая стоимость
  void unbooking(); // отмена брони

  Cinema& operator=(const Cinema &c);

private:
  TicketOffice days[18][30]; // 18 сеансов в день .. 30 дней 
  int vip_seats[18][30]; // количество мест на каждом сеансе
  int std_seats[18][30]; // количество мест на каждом сеансе
  int booking_code[100];
};
