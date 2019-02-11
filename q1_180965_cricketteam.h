#include <string>
#include<iostream>
using namespace std;

class cricketteam
{
private:
	string * membernames;	
	int no_of_members;
	char *teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
	
public:
	cricketteam();
	cricketteam(string teamname, int no_of_members);
	cricketteam(string filename);
	string getcaptain();
	int getno_of_members();
	char* getteamnames();
	int getrank();
	void setno_of_members(int );
	void setcaptain(string );
	void setteamnames(char* );
	void setmembersarr(int );
	void setrank(int );
	void inputTeamMember(string );
	void inputScore(int );
	float getavg();
	void print();
	void comparison(cricketteam);
	












};