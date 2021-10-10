/**
* @file Veri_ödev_1
* @description  Ödevde istenilen bütün fonksiyonları yerine getiriyor.
* @course 2.Ögretim C grubu
* @assignment 1.Ödev 
* @date 28.10.2019
* @author Mertcan Yeter///mertcan.yeter1@ogr.sakarya.edu.tr +++ Emirhan Ergen///emirhan.ergen2@ogr.sakarya.edu.tr
*/


#include "KovaKontrol.hpp"
#include "Top.hpp"
#include "Kova.hpp"
#include <iostream>
#include <time.h>
#include<conio.h>
#include<windows.h>
using namespace std;

#include "Top.hpp"
#include "Kova.hpp"

int main()
{
	KovaKontrol kk;
	srand(time(NULL));
	static int counter = 0;
	int secenek, n1, n2;
	
	cout << "Kova sayisi giriniz : " << endl;
	cin >> kk.kova_sayisi;

	Kova** kovalar = new Kova * [kk.kova_sayisi];

	for (int i = 0; i < kk.kova_sayisi; i++)
	{
		kovalar[i] = new Kova();
	}
	kk.Yoket(kovalar);
	while (1)
	{
		kk.Color(7);
		cout << "[1] Toplari Yerlestir " << endl << "[2] Toplari Yoket" << endl << "[3] Kova Degistir" << endl << "[4] Top Degistir" << endl << "[5] Kovalari Tersten Yerlestir" << endl << "[6] Toplari Tersten Yerlestir" << endl << "[7] Cikis\n" << endl;
		cin >> secenek;
		switch (secenek)
		{
		case 1:
		{
			
			kk.Ekle(kovalar);
			kk.KovaYazdir(kovalar);
			break;
		}

		case 2:
		{
			kk.Yoket(kovalar);
			kk.KovaYazdir(kovalar);
			break;
		}

		case 3:
		{
			cout << "Kova 1 : ";
			cin >> n1;
			cout << "Kova 2 : ";
			cin >> n2;

			kk.KovaDegistir(kovalar, n1 - 1, n2 - 1);
			kk.KovaYazdir(kovalar);
			break;
		}

		case 4:
		{
			cout << "Top 1 : ";
			cin >> n1;
			cout << "Top 2 : ";
			cin >> n2;

			kk.TopDegistir(kovalar, n1 - 1, n2 - 1);
			kk.KovaYazdir(kovalar);
			break;
		}

		case 5:
		{
			kk.KovalariTerstenYerlestir(kovalar);
			kk.KovaYazdir(kovalar);
			break;
		}

		case 6:
		{
			kk.ToplariTerstenYerlestir(kovalar);
			kk.KovaYazdir(kovalar);
			break;
		}

		case 7: return 0;

		default: break;
		}
	}

	return 0;
}