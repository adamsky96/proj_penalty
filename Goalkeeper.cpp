#include "Goalkeeper.h"
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

vector <string> Goalkeeper::names;

void Goalkeeper::init()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Goalkeeper::Goalkeeper()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_defence = (rand() % 35 + 25);
}

void Goalkeeper::description()
{
	cout<<_name<<endl;
	cout<<"Obrona: "<<_defence<<endl;
	cout<<endl;
}