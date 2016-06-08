#pragma once

#include <string>
#include <vector>

using namespace std;

class Goalkeeper
{
	static vector <string> names;
	
	string _name;
	int _defence;
	
	static void init();

	
	public:
	
	Goalkeeper();
	
	string name() { return _name; }
	int defence() {return _defence;}
	void description();	
};