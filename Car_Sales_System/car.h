#pragma once
#include <string>
#include <vector>
using namespace std;
class car
{
private:
	int id;
	string maker;
	//string Model;
	int yearModel;
	string information;
	float price;
	//double kilometers;
	string available;
	string colors;
	string status;
public:
	car();
	car(int i, string m, int Model,string information,float price, string available,string colors,string status);
	void Add_car();
	void Delete_car();
	void edit_car();
	void search_car();

	void Displat_car();



	~car();
};


//
//private String model;
//private String manufacturer;
//private String information;
//private int year;
//private int price;
//private double kilometers;

