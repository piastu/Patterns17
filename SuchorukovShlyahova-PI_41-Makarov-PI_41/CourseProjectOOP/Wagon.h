#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Wagon
{
  private:
    int n;
  public:
    Wagon(void);  // констуктор по умолчанию
    Wagon(int pn);  // стандартный конструктор
    Wagon(Wagon *aWagon);  // конструктор копирования
	virtual Wagon::~Wagon(void) {cout << "Destructor called" << endl;};  //деструктор
};






