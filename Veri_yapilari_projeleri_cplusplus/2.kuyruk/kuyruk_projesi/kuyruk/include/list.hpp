/**
* @file odev_2
* @description  Ödevde istenilen bütün fonksiyonları yerine getiriyor.
* @course 1.Ögretim C grubu
* @assignment 2.Ödev 
* @date 26.11.2019
* @author Mertcan Yeter///mertcan.yeter1@ogr.sakarya.edu.tr +++ Emirhan Ergen///emirhan.ergen2@ogr.sakarya.edu.tr
*/


#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include <fstream>
class List{
	public:
	
		string GetString() 
		{
			return str;
		}
		void add(string filename); 
		void print();
		void read(string filename);

	private:
	
		List* next = NULL;
		List* prev = NULL;
		List* head = this;
		int distance = 0;//mesafe için
		string str;
		int m_order;	
		int total_wins = 0;
		
		int find_occurance_Left(List* toAdd, string comperand);
		bool is_unique(string text);
};

#endif