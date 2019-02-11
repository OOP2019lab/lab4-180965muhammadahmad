// cricketteam.cpp : Defines the entry point for the console application.
//

#include "cricketteam.h"
#include<iostream>
#include <string>
using namespace std;

int main()
{

	string filename = "input.txt";
	int temp_number;
	char *x = new char[100];
	string y;
	//Constructor with one default parameter
	cricketteam team1(filename);
	//constructor with no default parameters to only initialize the private elements
	cricketteam bezuban;
	bezuban.setno_of_members(temp_number);
	bezuban.setmembersarr(bezuban.getno_of_members());
	cout << "Enter the name of your team "<<endl;
	cin.getline(x, 100);
	bezuban.setteamnames(x); 
	cout << "Enter the rank of the team "<<endl;
	cin >>temp_number ;
	bezuban.setrank(temp_number);
	cin.ignore();
	cout << "Enter the name of the captain  "<<endl;
	getline(cin, y);
	bezuban.setcaptain(y);
	cout << "Enter the total members "<<endl;
	cin >> temp_number; 
	bezuban.inputTeamMember(bezuban.getcaptain()); 
	cin.ignore();
	for (int i = 1;i<11; i++) // "null" is the delimiter to stop accepting values.
	{
		cout << "Enter the name of the player" << endl;
		getline(cin, y);
		
		if (y != "null") 
			bezuban.inputTeamMember(y);
	}
	//taking the scores
	for (int i = 0; i < 10; i++)
	{
		cout << "enter the scores" << endl;
		cin >> temp_number;
		bezuban.inputScore(temp_number);
	}
	cout << "printing from file " << endl;
	team1.print();
	cout << endl << endl << "team 2 is " << endl;
	bezuban.print();
	team1.comparison(bezuban);



	

	return 0;
}

