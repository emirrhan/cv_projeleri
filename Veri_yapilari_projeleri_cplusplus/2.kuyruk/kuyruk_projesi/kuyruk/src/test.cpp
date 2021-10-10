/**
* @file odev_2
* @description  Ödevde istenilen bütün fonksiyonları yerine getiriyor.
* @course 1.Ögretim C grubu
* @assignment 2.Ödev 
* @date 26.11.2019
* @author Mertcan Yeter///mertcan.yeter1@ogr.sakarya.edu.tr +++ Emirhan Ergen///emirhan.ergen2@ogr.sakarya.edu.tr
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "list.hpp"



int main()
{
	List* list = new List();

	/* 
	* kullanim : list->read("dosya_adi.txt") 'i çağırınca textteki bütün kelimeleri listeye ekler
	* 
	*
	*/
	
	// icerik.txt dosyası c klasörünün içine atılıp çalıstırılırsa yazılması gereken komut 
	//C:\icerik.txt
	list->read(".\\doc\\icerik.txt");
	list->print();
	return 0;
	system("pause");
}
