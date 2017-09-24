// kurs1.1.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "Wagon.h"
#include "Wagon.cpp"
#include "Pas.h"
#include "Pas.cpp"
#include "Slu.h"
#include "Slu.cpp"
#include <vector>
#include "time.h"
#include <algorithm>
#include <clocale>
#include "Form1.h"


using namespace kurs11;

[STAThreadAttribute]
void main(void)
{
		// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());

}
