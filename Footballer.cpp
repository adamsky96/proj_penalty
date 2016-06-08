#include "Footballer.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator> 
#include <sstream>
#include <time.h>

using namespace std;

template<typename T>
string to_string(const T& obj)
{
    stringstream ss;
    ss << obj;
    return ss.str();
}

vector <string> Footballer::names;

void Footballer::init()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Footballer::Footballer()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_attack= (rand() % 60 + 30);
	_accuracy = (rand() % 45 + 25); //celnosc
}

void Footballer::description()
{
	cout<<_name<<endl;
	cout<<"Atak: "<<_attack<<endl;
	cout<<"Celnosc: "<<_accuracy<<endl;
	cout<<endl;
}