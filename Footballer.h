#pragma once

#include <string>
#include <vector>

using namespace std;

class Footballer
{
	static vector <string> names;
	
	string _name;
	int _attack;
	int _accuracy;
	
	static void init();

	
	public:
	
	Footballer();
	
	string name() { return _name; }
	int attack() {return _attack;}
	int accuracy() {return _accuracy;}
	void description();	
	
	
};