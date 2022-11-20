#include "user.h"
#include <iostream>
#include <fstream>
using namespace std;
int user::login(string user, string pass, string file) {
	//
//	"saved/Admin.txt"
	int count = 0;
	string  saved_id, saved_pass;
	//system("cls");
	
	ifstream log(file);
	while (log >> saved_id >> saved_pass)
	{
		if (saved_id == user && saved_pass == pass) {
			count = 1;
			//system("cls");

		}
	}
	log.close();
	return count;
}

void user::Registration(string file)
{
	string ruserid, rpass;
	system("cls");
	cout << " Enter the username : ";
	cin >> ruserid;
	cout << " Enter the password : ";
	cin >> rpass;

	ofstream reg;
	reg.open(file, ios::app);
	reg << ruserid << ' ' << rpass << endl;
	system("cls");
	cout << "\n\t\t\ Registration is succeessfull! \n ";

}
