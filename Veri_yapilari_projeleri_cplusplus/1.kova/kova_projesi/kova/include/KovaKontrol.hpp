/**
* @file Veri_ödev_1
* @description  Ödevde istenilen bütün fonksiyonları yerine getiriyor.
* @course 2.Ögretim C grubu
* @assignment 1.Ödev 
* @date 28.10.2019
* @author Mertcan Yeter///mertcan.yeter1@ogr.sakarya.edu.tr +++ Emirhan Ergen///emirhan.ergen2@ogr.sakarya.edu.tr
*/

#ifndef KOVAKONTROL_HPP
#define KOVAKONTROL_HPP

#include <iostream>
#include <time.h>
#include<conio.h>
#include<windows.h>
using namespace std;

#include "Top.hpp"
#include "Kova.hpp"

class KovaKontrol{
	public:
int kova_sayisi = 0;

void Ekle(Kova**);

void Yoket(Kova**);

void KovaDegistir(Kova**, int, int);


void TopDegistir(Kova**, int, int);

void KovaYazdir(Kova**);


void KovalariTerstenYerlestir(Kova**);


void ToplariTerstenYerlestir(Kova**);

void Color(int);	
};




#endif