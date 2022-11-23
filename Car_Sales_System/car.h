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

	void Set_atributes();
	void Get_atributes();

	int get_id();
	string get_maker();
	int get_yearModel();
	string get_information();
	float get_price();
	string get_available();
	string get_colors();
	string get_status();

	




	~car();
};


//
//private String model;
//private String manufacturer;
//private String information;
//private int year;
//private int price;
//private double kilometers;

