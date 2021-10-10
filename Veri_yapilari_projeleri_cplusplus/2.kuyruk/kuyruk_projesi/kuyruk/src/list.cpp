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


	void List::add(string text){
		List* toadd = new List(), *itr; //heapte ekleme yapıyor
		int dist = 0;

		toadd->str = text;//textin içindekini str atadık
		toadd->head = this;

		itr = this;

		while (itr->next)
		{
			itr = itr->next;
		}

		if (!is_unique(text))
		{
			total_wins += (itr->str).length();
			
			toadd->distance = find_occurance_Left(itr, text);
			toadd->str = "0";
		}

		itr->next = toadd;
		itr->next->prev = itr;

	}
	
	void List::print()
	{
		system("cls");
		List* itr = head;
		cout << "NULL<-";
		bool first = true;
		
		while ((itr = itr->next))
		{
			if (itr->distance)
			{
				cout << "<->: - "<< itr->distance << ":";
				
				string character = "";
				character = itr->distance;
				
				total_wins -= character.length();
			}
			else
			{
				if(first == true){
					cout << ":" << itr->GetString() + " - 0:";
					first = false;
				}else{
					cout << "<->:" + itr->GetString() + " - 0:";
				}
				
			}
			
		}
		cout << "->NULL"<<endl;
		cout << "Toplam Kazanc = " << total_wins <<endl;
		
	}
	void List::read(string filename)//text dosyasını okuma yapıyor
	{
		filebuf fbuf;
		string str = "", text;
		// icerik.txt dosyası c klasörünün içine atılıp çalıstırılırsa yazılması gereken komut 
		//C:\icerik.txt
		fbuf.open(".\\doc\\icerik.txt", std::ios::in);
		istream stream(&fbuf);
		
		getline(stream, text);
		text += " ";

		int i = 0;
		while (i != text.rfind(" ") + 1)
		{
			if (text.at(i) != 32) {
				str += text.at(i);
			}
			else
			{
				this->add(str);
				str = "";
			}
			i++;
		}

	}
	int List::find_occurance_Left(List* toAdd, string comperand)//kaçtane solunda oldugunu bulmak için
	{
		int counter = 0;
		List* itr = toAdd->prev;
		do {
			if (!itr->GetString().compare(comperand))//compare karşılastırma
				return (++counter + 1);
			++counter;
			itr = itr->prev;
		} while (itr != this);
	}
	bool List::is_unique(string text)//eşitlik varmı kontrolü
	{
		List* itr = this;

		while (itr)
		{
			if ((itr->GetString().compare("0") != 0) && !(text.compare(itr->GetString())))
			{
				return false;
			}
			itr = itr->next;
		}

		return true;
	}
