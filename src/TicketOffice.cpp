// Copyright 2020 Serebrennikov
#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Cinema.h"
#include "TicketOffice.h"

using namespace std;

TicketOffice::TicketOffice() {
  date = "25.05.2020";
  time = "12:00";
  film = "Red Wall";
  hall = 1;
  place = 1;
  zone = 0;
  price = 100;
}

TicketOffice::TicketOffice(string _date, string _time, string _film, int _hall,
  int _place, int _zone, int _price) {
  date = _date;
  time = _time;
  film = _film;
  hall = _hall;
  place = _place;
  zone = _zone;
  price = _price;
}

TicketOffice::TicketOffice(const TicketOffice& c) {
  date = c.date;
  time = c.time;
  film = c.film;
  hall = c.hall;
  place = c.place;
  zone = c.zone;
  price = c.price;
}

TicketOffice& TicketOffice::operator=(const TicketOffice &c) {
  date = c.date;
  time = c.time;
  film = c.film;
  hall = c.hall;
  place = c.place;
  zone = c.zone;
  price = c.price;
  return *this;
}

std::istream& operator>>(std::istream& stream, TicketOffice& c) {
  cout << "Дата: ";
  stream >> c.date;
  cout << "Время: ";
  stream >> c.time;
  cout << "Фильм: ";
  stream >> c.film;
  cout << "Зал: ";
  stream >> c.hall;
  cout << "Место : ";
  stream >> c.place;
  cout << "Цена: ";
  stream >> c.price;
  cout << "Vip?: " << endl;
  cout << "1 - НЕТ | 2 - ДА " << endl;
  cout << "Зона: ";
  stream >> c.zone;
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const TicketOffice& c) {
  stream << "Дата: " << c.date <<  endl;
  stream << "Время: " << c.time << endl;
  stream << "Фильм: " << c.film << endl;
  stream << "Зал: " << c.hall << endl;
  stream << "Место: " << c.place << endl;
  stream << "Цена: " << c.price << endl;
  stream << "Зона: ";
  if (c.zone == 1)
    stream << "Standart" << endl;
  else
    stream << "VIP" << endl;
  return stream;
}

string TicketOffice::returndate() {
  return date;
}

string TicketOffice::returntime() {
  return time;
}

string TicketOffice::returnfilm() {
  return film;
}

int TicketOffice::returnhall() {
  return hall;
}

int TicketOffice::returnplace() {
  return place;
}

int TicketOffice::returnzone() {
  return zone;
}

int TicketOffice::returnprice() {
  return price;
}