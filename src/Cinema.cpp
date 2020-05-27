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
  здесь заполнение сеансами из файла (в массив days)
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
  cout << "Введите число месяца: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "Введите время сеанса (ХХ:ХХ): " << endl;
    string t_time;
    cin >> t_time;
    cout << "Пожалуйста, отдельно введите часы (если сеанс в 13:10, то введите '13' " << endl;
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
    cout << "Введите название фильма: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "В какой зоне вы хотите сидеть |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "Сколько мест Вам нужно: " << endl;
      int t_seats;
      cin >> t_seats;
      cout << "Вы бронировали билеты? |1-да|0-нет|" << endl;
      int tmp;
      cin >> tmp;
      if (tmp == 0) {
        double t_price;
        t_price = days[i][t_date].returnprice() * skidka * t_zone;
        cout << "Внесите " << t_price << " рублей для покупки билетов" << endl;
        cout << "ОПЛАТА..." << endl;
        if (t_zone == 1) {
          if (std_seats[i][t_date] >= t_seats) {
            std_seats[i][t_date] = std_seats[i][t_date] - t_seats;
            cout << "_________________________________________________" << endl;
            cout << "|Фильм: "<< t_film << "                          |" << endl;
            cout << "|Зал: "<< days[i][t_date].returnhall()<< "       |" << endl;
            cout << "|Время сеанса: "<< t_time<<"                     |" << endl;
            cout << "|Количество купленных мест: " << t_seats << "    |" << endl;
            cout << "|Время сеанса: "<<  t_time << "                  |" << endl;
            cout << "|               ПРИЯТНОГО ПРОСМОТРА              |" << endl;
            cout << "|________________________________________________|" << endl;
            break;
          }
          else {
            cout << "Пожалуйста,выберите другой сеанс, мест нет" << endl;
            break;
          }
        }
        else {
          if (vip_seats[i][t_date] >= t_seats) {
            vip_seats[i][t_date] = vip_seats[i][t_date] - t_seats;
            cout << "_________________________________________________" << endl;
            cout << "|Фильм: " << t_film << "                          |" << endl;
            cout << "|Зал: " << days[i][t_date].returnhall() << "       |" << endl;
            cout << "|Время сеанса: " << t_time << "                     |" << endl;
            cout << "|Количество купленных мест: " << t_seats << "    |" << endl;
            cout << "|Время сеанса: " << t_time << "                  |" << endl;
            cout << "|               ПРИЯТНОГО ПРОСМОТРА              |" << endl;
            cout << "|________________________________________________|" << endl;
            break;
          }
          else {
            cout << "Пожалуйста,выберите другой сеанс, мест нет" << endl;
            break;
          }
        }
      }
    }

    else {
      cout << "Введите код бронирования: " << endl;
      int code;
      cin >> code;
      for (int i = 0; i < 100; i++) {
        if (booking_code[i] == code) {
          double t_price;
          t_price = days[i][t_date].returnprice() * skidka*t_zone;
          cout << "Внесите "<<  t_price << " рублей для покупки билетов" << endl;
          cout << "ОПЛАТА..." << endl;
          cout << "_________________________________________________" << endl;
          cout << "|Фильм: " << t_film << "                         |" << endl;
          cout << "|Зал: " << days[i][t_date].returnhall() << "     |" << endl;
          cout << "|Время сеанса: " << t_time << "                  |" << endl;
          cout << "|Количество купленных мест: " << t_seats << "    |" << endl;
          cout << "|Время сеанса: " << t_time << "                  |" << endl;
          cout << "|               ПРИЯТНОГО ПРОСМОТРА              |" << endl;
          cout << "|________________________________________________|" << endl;
          break;
        }
      }
    }
  }
}

void Cinema::checking_places() {
  cout << "Введите число месяца: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "Введите время сеанса (ХХ:ХХ): " << endl;
    string t_time;
    cin >> t_time;
    cout << "Введите название фильма: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "Наличие мест в какой зоне нужно проверить? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "Сколько мест Вам нужно: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
        cout << "В выбранной зоне " << std_seats[i][t_date] << " свободных мест" << endl;
      } else {
        cout << "В выбранной зоне "<< vip_seats[i][t_date]<< " свободных мест" << endl;
      }
    } else {
      cout << "Такого сеанса не существует! " << endl;
      break;
    }
  }
}

void Cinema::booking() {
  cout << "Введите число месяца: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "Введите время сеанса (ХХ:ХХ): " << endl;
    string t_time;
    cin >> t_time;
    cout << "Введите название фильма: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "В какой зоне вы хотите сидеть? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "Сколько мест Вам нужно: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
        if (std_seats[i][t_date] >= t_seats) {
          std_seats[i][t_date] = std_seats[i][t_date] - t_seats;
          cout << "Места забронированы" << endl;
          cout << "Введите код **** для своего бронирования (он будет использоваться для покупки или снятия брони): " << endl;
          cin >> booking_code[bn];
          bn++;
          break;
        }
        else {
          cout << "Пожалуйста,выберите другой сеанс, мест нет" << endl;
          break;
        }
      }
      else {
        if (vip_seats[i][t_date] >= t_seats) {
          vip_seats[i][t_date] = vip_seats[i][t_date] - t_seats;
          cout << "Места забронированы" << endl;
          cout << "Введите код **** для своего бронирования (он будет использоваться для покупки или снятия брони): " << endl;
          cin >> booking_code[bn];
          bn++;
          break;
        }
        else {
          cout << "Пожалуйста,выберите другой сеанс, мест нет" << endl;
          break;
        }
      }
    }
    else {
      cout << "Такого сеанса не существует! " << endl;
      break;
    }
  }
}

void Cinema::total_cost() {
  cout << "Введите число месяца: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "Введите время сеанса (ХХ:ХХ): " << endl;
    string t_time;
    cin >> t_time;
    cout << "Пожалуйста, отдельно введите часы (если сеанс в 13:10, то введите '13' " << endl;
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
    cout << "Введите название фильма: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "Наличие мест в какой зоне нужно проверить? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "Сколько мест Вам нужно: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
        double t_price;
        t_price = days[i][t_date].returnprice() * skidka * t_zone;
        cout << "сумма заказа составит "<< t_price << " рублей" << endl;
        break;
      }
      else {
        double t_price;
        t_price = days[i][t_date].returnprice() * skidka * t_zone;
        cout << "сумма заказа составит "<< t_price<< " рублей" << endl;
        break;
      }
    }
    else {
      cout << "Такого сеанса не существует! " << endl;
      break;
    }
  }
}

void Cinema::unbooking() {
  cout << "Введите число месяца: " << endl;
  int t_date;
  cin >> t_date;
  for (int i = 0; i < 30; i++) {
    cout << "Введите время сеанса (ХХ:ХХ): " << endl;
    string t_time;
    cin >> t_time;
    cout << "Введите название фильма: " << endl;
    string t_film;
    cin >> t_film;
    if (days[i][t_date].returntime() == t_time && days[i][t_date].returnfilm() == t_film) {
      cout << "В какой зоне вы хотите сидеть? |2-VIP|1-Standart|: " << endl;
      int t_zone;
      cin >> t_zone;
      cout << "Сколько мест Вы бронировали: " << endl;
      int t_seats;
      cin >> t_seats;
      if (t_zone == 1) {
          std_seats[i][t_date] = std_seats[i][t_date] + t_seats;
          cout << "Бронь снята" << endl;
          break;
      } else {
        vip_seats[i][t_date] = vip_seats[i][t_date] + t_seats;
        cout << "Бронь снята" << endl;
        break;
      }
    }
    else {
      cout << "Такого сеанса не существует! " << endl;
      break;
    }
  }
}
