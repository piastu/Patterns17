#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Pas: public Wagon
{
  public:
    int seats;
    int price;
	int tippas;
  
  public:
    Pas(void) {seats=36; price=0; tippas=0;}; // констуктор по умолчанию
    Pas(int n,int m,int l) {seats=n; price=m; tippas=l;}; // констуктор копирования
    virtual int getseats(){return seats;}; // получение кол-ва мест вагона
    virtual int getprice() {return price;}; // получение цены вагона
    virtual int gettippas() {return tippas;}; // получение типа вагона
    virtual void setseats(int j) {seats=j;}; // изменение количества мест
	virtual void setprice(int j) {price=j;}; // изменение цены
    virtual void settippas(int j) {tippas=j;}; // изменение типа вагона
	virtual void firstprice(void); // первоначальная цена
	virtual Pas::~Pas() {cout << "Destructor(Pas)" << endl;}; //деструктор
};
