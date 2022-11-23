#include <iostream>
#include <string>
#include "Car.h"
#include <stdlib.h>
#include <fstream>
#include "user.h"
#include "used_car.h"


using namespace std;


//void Login();
//void Registration();
//void Forget();

void Admin_main_program();
void Customer_main_program();

string Customer;



int main() {
	//_________________________    start Login            -----------------------------------

	int log;
	cout << "\t\t\t________________________________________________________________\n\n" << endl;
	cout << "\t\t\t                     Welcome To The Login Page                   \n\n" << endl;
	cout << "\t\t\t_____________________          MENU         ______________________\n" << endl;
	cout << "                                                                         \n" << endl;
	cout << "\t Please Enter 1 to Login" << endl;
	cout << "\t Please Enter 2 to Register" << endl;
	//cout << "\t Please Enter 3 if you forget your password" << endl;
	cout << "\t Please Enter 3 to Exit" << endl;
	cout << "\n\t\t Please Enter Your choice : " ;
	cin >> log;
	//cout << endl;

	user u1;


	switch (log) {
	case 1: {
		string luserid, lpass;
		cout << "\t\t\t Please Enter the username and password : \n";
		cout << " \t\t\t usernam : ";
		cin >> luserid;
		cout << " \t\t\t password : ";
		cin >> lpass;
		if (u1.login( luserid, lpass, "saved/Admin.txt") == 1) {
			cout << "\n\t\t\Your Login  is succeessfull! \n Thank you! \n";
			//main();
			Admin_main_program();

		}
		else if (u1.login( luserid, lpass, "saved/Customer.txt") == 1) {
			cout << "\n\t\t\Your Login  is succeessfull! \n Thank you! \n";
			Customer = luserid;

			Customer_main_program();
			//main();
			//main_program();

		}
		else {
			cout << "\n\t\t Login Erorr \n\t\t Please check your username and password \n ";
			main();

		}
		//Login();
		break;
	}
		
	case 2: {
		cout << "\t Please Enter 1 to Register AS Admin" << endl;
		cout << "\t Please Enter 2 to Register AS Customer" << endl;
		cout << "\n\t\t Please Enter Your choice : ";

		int Reg_choice;
		cin >> Reg_choice;
		//cout << endl;

		//user u1;


		switch (Reg_choice) {
		case 1:
			u1.Registration("saved/Admin.txt");
			main();

			break;
		case 2:
			u1.Registration("saved/Customer.txt");
			main();

			break;



		default:
			system("cls");
			cout << "\t\t\t Please Select from options given abov you! \n\n\n" << endl;
			main();

		}
		break;

	}
		//Registration();
	/*case 3:
		Forget();
		break;*/
	case 3:
		cout << "\t\t\t Thank you! \n" << endl;
		break;
	default: {
		system("cls");
		cout << "\t\t\t Please Select from options given abov you! \n\n\n" << endl;
		main();
	}
		

	}
	//_________________________    End Login            -----------------------------------


	

	return 0;
}

void Admin_main_program() {
	int choise;
	char Loop = 'y';

	do
	{
		cout << "Please Enter 1 to Add Car" << endl;
		cout << "Please Enter 2 to Display All Cars" << endl;
		cout << "Please Enter 3 to Delete Car" << endl;
		cout << "Please Enter 4 to Update Car" << endl;
		cout << "Please Enter 5 to Search Car" << endl;
		cout << "\n\t\t Please Enter Your choice : ";

		//cout << "Please Enter 5 to Exit" << endl;

		cin >> choise;
		switch (choise) {
		case 1:
		{

			int add_choise=0;
			

			cout << "Please Enter 1 to Add New Car" << endl;
			cout << "Please Enter 2 to Add Used Car" << endl;
			cout << "\n\t\t Please Enter Your choice : ";

			cin >> add_choise;
			if (add_choise == 1) {
				//(car_id, maker, yearModel, information, price, available, colors, "New")
				car New_car;
				New_car.Add_car();
				cout << "--> Record is added to file \n";

			}
			else if (add_choise == 2) {
				used_car car;
				car.Add_car();
				cout << "--> Record is added to file \n";

			}
			else {
				system("cls");
				cout << "\t\t\t Please Select from options given abov you! \n\n\n" << endl;
				main();
			}
			

			break;

		}
		case 2: {
			car c;
			c.Displat_car();
			break;

		}

		
		case 3: {
			car New_car;
			New_car.Delete_car();
			break;
		}
		
		case 4: {
			
			car New_car;
			New_car.edit_car();
			//cout << "--> Record is Update to file \n";

		
			break;
		}
		case 5: {

			car New_car;
			New_car.search_car();
			break;
		}
		default: {
			system("cls");
			cout << "\t\t\t Please Select from options given abov you! \n\n\n" << endl;
			Admin_main_program();
		}

			

		}





		cout << "Please Enter Y to Con \t (Y/N)" << endl;
		cin >> Loop;
	} while (Loop == 'y' || Loop == 'y');

}
void Customer_main_program() {
	int choise;
	char Loop = 'y';
	do {
		cout << "Please Enter 1 to Display All Cars" << endl;
		cout << "Please Enter 2 to Buy Car" << endl;
		cout << "\n\t\t Please Enter Your choice : ";
		cin >> choise;
		switch (choise) {
		case 1: {

			car c;
			c.Displat_car();
			break;
		}
		case 2: {

			car c;
			c.Buy_car(Customer);
			break;
		}
		default:
			system("cls");
			cout << "\t\t\t Please Select from options given abov you! \n\n\n" << endl;
			Customer_main_program();

		}


		cout << "Please Enter Y to Con \t (Y/N)" << endl;
		cin >> Loop;
	} while (Loop == 'y' || Loop == 'y');

}



//void Login() {
//	//int count=0;
//	//string luserid, lpass,saved_id,saved_pass;
//	////system("cls");
//	//cout << "\t\t\t Please Enter the username and password : \n";
//	//cout << " \t\t\t usernam : ";
//	//cin >> luserid;
//	//cout << " \t\t\t password : ";
//	//cin >> lpass;
//	//ifstream log("saved/Admin.txt");
//	//while (log>> saved_id>> saved_pass)
//	//{
//	//	if (saved_id== luserid && saved_pass== lpass) {
//	//		count = 1;
//	//		//system("cls");
//
//	//	}
//	//}
//	//log.close();
//
//
//	//user u1;
//	//
//	//if (u1.login("saved/Admin.txt") == 1) {
//	//	cout <<  "\n\t\t\Your Login  is succeessfull! \n Thank you! ";
//	//	//main();
//	//	main_program();
//
//	//}
//	//else if (u1.login("saved/Customer.txt") == 1) {
//	//	cout << "\n\t\t\Your Login  is succeessfull! \n Thank you! ";
//	//	//main();
//	//	main_program();
//	//}
//	//else {
//	//	cout <<  "\n\t\t Login Erorr \n\t\t Please check your username and password \n ";
//	//	main();
//
//	//}
//
//
//
//}
//void Registration() {
//	
//
//
//	main();
//
//
//
//}
//void Forget() {
//
//}

