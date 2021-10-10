/**
* @file Veri_ödev_1
* @description  Ödevde istenilen bütün fonksiyonları yerine getiriyor.
* @course 2.Ögretim C grubu
* @assignment 1.Ödev 
* @date 28.10.2019
* @author Mertcan Yeter///mertcan.yeter1@ogr.sakarya.edu.tr +++ Emirhan Ergen///emirhan.ergen2@ogr.sakarya.edu.tr
*/


#include "KovaKontrol.hpp"
#include <iostream>
#include <time.h>
#include<conio.h>
#include<windows.h>
using namespace std;

#include "Top.hpp"
#include "Kova.hpp"

void KovaKontrol::Ekle(Kova** kovalar)
{
	//static int counter = 0;
	bool topKlndi = false;
	for (int i = 0; i < kova_sayisi;i++) {
		if (kovalar[i]->top == NULL && topKlndi == false) {
			kovalar[i]->top = new Top();
			topKlndi = true;
		}
	}

}

void KovaKontrol::Yoket(Kova** kovalar)
{
	for (int i = 0; i < kova_sayisi; i++)
	{
		delete kovalar[i]->top;
		kovalar[i]->top = NULL;
	}
}

void KovaKontrol::KovaDegistir(Kova** kovalar, int index1, int index2)
{
	Kova* temp;

	if (index2 > kova_sayisi || index1 > kova_sayisi || index2 < 0 || index1 < 0)
	{
		return;
	}

	temp = kovalar[index1];
	kovalar[index1] = kovalar[index2];
	kovalar[index2] = temp;

	return;
}

void KovaKontrol::TopDegistir(Kova** kovalar, int index1, int index2)
{
	Top* temp;

	if (index2 > kova_sayisi || index1 > kova_sayisi || index2 < 0 || index1 < 0)
	{
		return;
	}

	temp = kovalar[index1]->top;
	kovalar[index1]->top = kovalar[index2]->top;
	kovalar[index2]->top = temp;

	return;
}


void KovaKontrol::KovaYazdir(Kova** kovalar)
{
	
	for (int i = 0; i < kova_sayisi; i++)
	{
		
		Kova* temp = kovalar[i];
		Color(temp->renk);
		cout  <<i+1<<".kova"<<endl;
		if (temp->top != NULL)
		{		
			cout  <<"         #\n       #   #\n      #     #   \n     #       #  \n     #       #  \n     #   "<<temp->top->harf<<"   #  \n     #       #  \n     #       #  \n""     #########  \n" << endl;
			cout  << "Top adresi : " << hex << showbase << 10 << temp->top << endl;
		}
		else
		{			
			cout << "         #\n       #   #\n      #     #   \n     #       #  \n     #       #  \n     #   " << "-" << "   #  \n     #       #  \n     #       #  \n""     #########  \n" << endl;
			cout  << "Top adresi : NULL" << endl;
		}
		cout <<"Kova adresi : " << hex << showbase << 10 << temp << endl;
	}
}

void KovaKontrol::KovalariTerstenYerlestir(Kova** kovalar)
{
	for (int i = 0; i < kova_sayisi / 2; i++)
	{
		Kova* tmp;

		tmp = kovalar[kova_sayisi - i - 1];
		kovalar[kova_sayisi - i - 1] = kovalar[i];
		kovalar[i] = tmp;
	}
}

void KovaKontrol::ToplariTerstenYerlestir(Kova** kovalar)
{
	for (int i = 0; i < kova_sayisi / 2; i++)
	{
		Top* tmp;

		tmp = kovalar[kova_sayisi - i - 1]->top;
		kovalar[kova_sayisi - i - 1]->top = kovalar[i]->top;
		kovalar[i]->top = tmp;
	}
}
void KovaKontrol::Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
