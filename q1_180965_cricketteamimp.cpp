#include <iostream>
#include "cricketteam.h"
#include<string>
#include <cstring>
#include <fstream>
using namespace std;


// this is a default constructor inorder to initialize the value with its sentinl values
cricketteam::cricketteam()
{
	membernames = nullptr;
	no_of_members = 11;
	teamName=nullptr;
	for (int i = 0; i < 10; i++)
	{
		Scoreinlast10matches[i] = -10;
	}
    Rank=-1;
	captain="NULL";
    
}



//this constructor reads the value  from file
cricketteam::cricketteam(string filename)
{
	ifstream input;
	input.open(filename);
	if (input)
	{
		string arr_temp;
		getline(input, arr_temp, ':');
		getline(input, arr_temp, '\n');
		teamName = new char[sizeof(arr_temp)];
		strcpy_s(teamName, sizeof(arr_temp), arr_temp.c_str());
		getline(input, arr_temp, ':');
		input >> no_of_members;
		membernames = new string[no_of_members];
		input.ignore();
		for (int i = 0; i < no_of_members; i++)
		{
			getline(input, membernames[i], '\n');
		}
		getline(input, arr_temp, ':');
		input >> Rank;
		getline(input, arr_temp, ':');
		getline(input, captain, '\n');
		getline(input, arr_temp, ':');
		for (int i = 0; i < 10; i++)
		{
			input >> Scoreinlast10matches[i];
		}
		input.close();
	}
	else
	{
		cout << "file is not opened" << endl;
	}
	
}

//these all the setters and getters for the code
void cricketteam::setteamnames(char* name)
{
	teamName = name;

}
char* cricketteam::getteamnames()
{
	return teamName;
}
void cricketteam::setno_of_members(int no_player)
{
	no_of_members = no_player;
}
int cricketteam::getno_of_members()
{
	return no_of_members;
}
void cricketteam::setrank(int r)
{
	Rank = r;
}
int cricketteam::getrank()
{
	return Rank;
}
void cricketteam::setcaptain(string cap)
{
	captain = cap;
}
string cricketteam::getcaptain()
{
	return captain;
}
void cricketteam::setmembersarr(int x)
{
	membernames = new string[x];
	for (int i = 0; i < x; i++)
	{
		membernames[i] = "A";
	}
}


// THis function stores the name of the player
void cricketteam::inputTeamMember(string name)
{
	for (int i = 0; i < no_of_members; i++)
	{
		if (membernames[i] == "A")
		{
			membernames[i] = name;

		}
		
		

	}

}
// this is a constructor which set these two parameters
cricketteam::cricketteam(string teamname, int no_of_member)
{
	int temp_size = strlen(teamname.c_str());
	cricketteam::teamName = new char[temp_size];
	strcpy_s(cricketteam::teamName, temp_size, teamname.c_str());

	cricketteam::no_of_members = no_of_members;
}
//this function takes input of score
void cricketteam::  inputScore(int x)
{
	for (int i = 0; i < 10; i++)
	{
		if (Scoreinlast10matches[i] == -10)
		{
			Scoreinlast10matches[i] = x;

		}
		if (i == 10)
		{
			for (int i = 0; i < 9; i++)
			{
				Scoreinlast10matches[i] = Scoreinlast10matches[i + 1];
			}
			Scoreinlast10matches[i] = x;

		}
	}

}
//This function returns the average of the scores
float cricketteam::getavg()
{
	float sum = 0;
	
	for (int i = 0; i < 10; i++)
	{
		sum = sum + Scoreinlast10matches[i];
	}

	return sum / 10.0;

}
//this fuction prints the whole team
void cricketteam::print() 
{
	cout << "Team name =  " << teamName << endl;
	cout << "Captain name =  " << captain << endl;
	cout << "Totalmembers =  " << no_of_members << endl;
	cout << "Rank= " << Rank << endl;
	for (int i = 0; i < no_of_members; i++)
	{
		cout << "Player" << i + 1 << " = " << membernames[i] << endl;
	}
	cout << "Scores in last 10 matches played are = " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout <<Scoreinlast10matches[i] << " ";
	}
	
}
//This function compares which team is best
void cricketteam::comparison(cricketteam anoynymous)
{
	if (getavg() > anoynymous.getavg())
	{
		cout << "team " << teamName << " is better than" << anoynymous.teamName;
	}
	else
	{
		cout << "Team " << anoynymous.teamName << " is better than team " << teamName << endl;
	}

}


//this is destructorstructor
CricketTeam::~CricketTeam() 
{
	delete[]membernames;
	membernames = nullptr;

	delete[]teamName;
	teamName = nullptr;
}
