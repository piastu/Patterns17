#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Slu: public Wagon
{
  private:
    int tipslu;
    
  public:
    Slu(void) {tipslu=0;}; // констуктор по умолчанию
	Slu(int ptipslu) {tipslu=ptipslu;}; // стандартный конструктор
    int gettipslu() {return tipslu;}; // получение цены вагона
    virtual void settipslu(int j) {tipslu=j;}; // изменение типа вагона
	//virtual string print(); // печать сведений о вагоне 
	virtual char *getname (void) {return("Slu");}; //печать названия класса
	virtual Slu::~Slu() {cout << "Destructor(Pas)" << endl;}; //деструктор
};
