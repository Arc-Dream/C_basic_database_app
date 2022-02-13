#include <iostream>
#include <fstream>
#include <string>
#include "file_writer.h"

ENTRY New;

void entry_maker();

void recorder();

int main()
{	
	
	entry_maker();
	recorder();
	
	return 0;
}

void recorder()
{	
	std::fstream myFile;
	

	myFile.open("try_out.text", std::ios::app);
	
	if(!myFile.is_open()) {
		std::cout<<"Connection Proble with DB file";
	}
	
	if (myFile.is_open()) {
		std::string line;
		while (std::getline(myFile, line)) {
			int strpos = line.find(" ");
			std::string old_index_str = line.substr(0, strpos);
			int old_index = stoi(old_index_str);
			if (myFile.is_open()) {
				if (old_index > 0) {
					New.index = old_index + 1;
					myFile<< New.index << "*" << New.content <<std::endl;
					myFile<< 0; 
				}

			}		
		}
	}
	
	myFile.close();

	
	system("cls");
	std::cout<<"Data RECORDED"<<std::endl;
	std::cout<<"Please press a button for a new Entry";
	
	entry_maker();
}

void entry_maker() 
{
	std::string entry_instant;
	
	system("cls");
	std::cout<<"Please make your entry"<<std::endl;
	std::cout<<"(Type 0 to exit)-----:"<<std::endl;
	
	
	std::getline(std::cin, entry_instant);
	
	if(entry_instant == "0") {
		system("pause");
	} else {
		New.content = entry_instant;		
	}
}
