/**
* @file Veri_ödev_1
* @description  Ödevde istenilen bütün fonksiyonları yerine getiriyor.
* @course 2.Ögretim C grubu
* @assignment 1.Ödev 
* @date 28.10.2019
* @author Mertcan Yeter///mertcan.yeter1@ogr.sakarya.edu.tr +++ Emirhan Ergen///emirhan.ergen2@ogr.sakarya.edu.tr
*/

#include "Kova.hpp"
	Kova::Kova(){
		renk = (rand() % 14)+1;
	}
	int renk;
	Top* top = NULL;
