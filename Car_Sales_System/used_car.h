#pragma once
#include "car.h"
class used_car : public car
{
private:
	double kilometers;
public:
	used_car();
	used_car(int i, string m, int Model, string information, float price, string available, string colors, string status, double KM);
	void Add_car();
	void Set_atributes();
	void Delete_car();
	void edit_car();
	void search_car();
	void Displat_car();
};

