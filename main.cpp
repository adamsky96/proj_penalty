#include <iostream>
#include "Footballer.h"
#include "Goalkeeper.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>

#define TIME_LAG 1000000

using namespace std;

bool check(int i, int score,int goal_team2,int goal_team1)
{
	if(i<10)
	{
		if(score>5-score)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(i==10)
	{
		if(score>0)
		{
			return true;
		}
		else if(score==0)
		{
			return false;
		}	
	}
	else if(i>10)
	{
		if(score==2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else return false;
}

int main()
{ 
	srand (time(NULL));
	int who1=0,who2=0, team=1, score=0, i=0, end=0;
	int goal_team1=0, goal_team2=0;
	int agresiv;
	Goalkeeper goalkeeper1;
	Goalkeeper goalkeeper2;
	Footballer people[10];
	Footballer people2[10];
	
	cout<<"Sklad pierwszej druzyny:"<<endl;
	cout<<"Bramkarz: "<<endl;
    goalkeeper1.description();
	cout<<endl;
	
	cout<<"Pilkarze: "<<endl;
	for (int i = 0; i < 10; ++i)
	{
  	 	 people[i].description();
	}
	
    cout<<"Sklad drugiej druzyny:"<<endl;
	cout<<"Bramkarz: "<<endl;
    goalkeeper2.description();
	cout<<endl;
	
	cout<<"Pilkarze: "<<endl;
	for (int i = 0; i < 10; ++i)
	{
  	 	 people2[i].description();
	}
	
	do
	{
		usleep(TIME_LAG);
		if(team==1)
		{
			cout<<"Strzela pierwsza druzyna"<<endl;
			cout<<"Podchodzi do strzalu: "<<people[who1].name()<<endl;
			usleep(TIME_LAG);
			agresiv=(people[who1].attack()*people[who1].accuracy())/(45+i*2);
			if(goalkeeper2.defence()<agresiv)
			{
				goal_team1++;
				cout<<"GOOOOL!!!"<<endl;
				cout<<"Wynik: "<<goal_team1<<" "<<goal_team2<<endl;
			}
			else
			{
				cout<<goalkeeper2.name()<<" obronil!!!!"<<endl;
			}
			who1++;
			if(who1>9)
			{
				who1=0;
			}
		}
		if(team==2)
		{
			cout<<"Strzela druga druzyna"<<endl;
			cout<<"Podchodzi do strzalu: "<<people2[who2].name()<<endl;
			usleep(TIME_LAG);
			agresiv=(people[who2].attack()*people[who2].accuracy())/(45+i*2);
			if(goalkeeper1.defence()<agresiv)
			{
				goal_team2++;
				cout<<"GOOOOL!!!"<<endl;
				cout<<"Wynik: "<<goal_team1<<" "<<goal_team2<<endl;
			}
			else
			{
				cout<<goalkeeper1.name()<<" obronil!!!!"<<endl;
			}
			who2++;
			if(who2>9)
			{
				who2=0;
			}
		}
		cout<<endl;
		team++;
		if(team>2)
		{
			team=1;
		}
		score=goal_team2-goal_team1;
		if(score<0)
		{
			score=score*(-1);
		}
		//cout<<"Wynik: "<<score<<endl;
		i++;
		end=check(i, score, goal_team2, goal_team1);	
		//cout<<"Koniec "<<end<<endl;
	}while(end<1);
	
	cout<<"KONIEC!!!"<<endl;
	if(goal_team1>goal_team2)
	{
		cout<<"Wygrala pierwsza druzyna"<<endl;
	}
	else
	{
		cout<<"Wygrala druga druzyna"<<endl;
	}
	
    return 0;       
}