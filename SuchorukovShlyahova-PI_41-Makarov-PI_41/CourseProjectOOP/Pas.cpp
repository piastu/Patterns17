#pragma once
#include <string.h>
#include "Pas.h"
#include <fstream>
using namespace std;
int tippas, price;


void Pas::firstprice(void)
{
	if (tippas==1) price=100;
	if (tippas==2) price=200;
	if (tippas==3) price=300;
	if (tippas==4) price=400;
	if (tippas==5) price=350;

}

