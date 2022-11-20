#pragma once
#include <string>
using namespace std;
class user
{
private:
	string user_nmae;
	string password;
public:
	//user();
	int login(string user, string pass, string file);
	void Registration(string file);

	//~user();

};

