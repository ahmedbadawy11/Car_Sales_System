#include "used_car.h"
#include <fstream>
#include <iostream>
#include <vector>

used_car::used_car():car() {
	kilometers = 0;

}

used_car::used_car(int i, string m, int Model, string information, float price, string available, string colors, string status, double KM)
	:car( i,  m,  Model,  information,  price,  available,  colors,  status) {
	kilometers = KM;

}
void used_car::Set_atributes() {
	car::Set_atributes();
	cout << "Please Enter car kilometers : ";
	cin >> kilometers;
	cout << endl;
}

void used_car::Add_car() {
	//int car_id;
	//string maker;
	////string Model;
	//int yearModel;
	//string information;
	//float price;
	////double kilometers;
	//string available;
	//string colors;
	//double KM;

	////string status;
	//cout << "Please Enter car ID : ";
	//cin >> car_id;
	//cout << endl;
	//cout << "Please Enter car Manufacturer : ";
	//cin >> maker;
	//cout << endl;
	//cout << "Please Enter Year Model : ";
	//cin >> yearModel;
	//cout << endl;
	//cout << "Please Enter Some information : ";
	//cin >> information;
	//cout << endl;
	//cout << "Please Enter car price : ";
	//cin >> price;
	//cout << endl;
	//cout << "Please Enter car kilometers : ";
	//cin >> KM;
	//cout << endl;
	//
	//cout << "Please Enter car available : ";
	//cin >> available;
	//cout << endl;
	//cout << "Please Enter car colors : ";
	//cin >> colors;
	//cout << endl;

	used_car::Set_atributes();
	ofstream myfile;
	myfile.open("saved/Cars.txt", ios::out | ios::app);
	myfile << car::get_id() << "," << car::get_maker() << "," << car::get_yearModel() << "," << car::get_information() << "," << car::get_price() << "," <<
		car::get_available() << "," << car::get_colors() << "," << "Used" << "," << kilometers << endl;
	myfile.close();
}

