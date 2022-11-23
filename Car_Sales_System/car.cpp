#include "car.h"
#include <fstream>
#include <iostream>
#include <vector>



using namespace std;



car::car() :id(0), maker("unknow"), yearModel(0), information("unknow"), price(0.0), available("unknow"),
colors("unknow"), status("unknow") {

}

car::car(int i, string m, int Model, string information, float price, string available, string colors, string status)
	:id(i), maker(m), yearModel(Model) , information(information), price(price) , available(available), 
	colors(colors), status(status) {

}
int car::get_id() {
	return id;
}
string car::get_maker() {
	return maker;

}
int car::get_yearModel() {
	return yearModel;

}
string car::get_information() {
	return information;

}
float car::get_price() {
	return price;

}
string car::get_available() {
	return available;

}
string car::get_colors() {
	return colors;

}
string car::get_status() {
	return status;

}
void car::Set_atributes() {
	cout << "Please Enter car ID : ";
	cin >> id;
	cout << endl;
	cout << "Please Enter car Manufacturer : ";
	cin >> maker;
	cout << endl;
	cout << "Please Enter Year Model : ";
	cin >> yearModel;
	cout << endl;
	cout << "Please Enter Some information : ";
	cin >> information;
	cout << endl;
	cout << "Please Enter car price : ";
	cin >> price;
	cout << endl;
	cout << "Please Enter car available : ";
	cin >> available;
	cout << endl;
	cout << "Please Enter car colors : ";
	cin >> colors;
	cout << endl;
}
void car::Get_atributes() {

}


void car::Add_car() {
	
	car::Set_atributes();
	ofstream myfile;
	myfile.open("saved/Cars.txt", ios::out | ios::app);
	myfile << id << "," << maker << "," << yearModel << "," << information<< "," << price <<"," <<
		available <<"," << colors <<"," << "New" <<endl;
	myfile.close();
}
void car::Displat_car() {
	
	ifstream file_read("saved/Cars.txt",ios::in);
	if (file_read.is_open()) {
//	ifstream file_read;
		//file_read.open("saved/Cars.txt");
		string line;
		
		while (getline(file_read, line))
		{
			vector<string>record;

		

			string temp = "";

			for (int i = 0; i < (int)line.size(); i++) {
				// If cur char is not del, then append it to the cur "word", otherwise
				  // you have completed the word, print it, and start a new word.
				if (line[i] != ',') {
					temp += line[i];
				}
				else {
					//cout << temp << " ";
					record.push_back(temp);
					temp = "";
				}
			}
			record.push_back(temp);
			
			cout <<"The Car Information is \n"  << endl;

			id = stoi(record[0]);
			cout << "\t\t\t the id is : " << id <<endl;
			maker = record[1];
			cout << "\t\t\t the maker is : " << maker << endl;
			yearModel = stoi(record[2]);
			cout << "\t\t\t the yearModel is : " << yearModel << endl;
			information = record[3];
			cout << "\t\t\t the information is : " << information << endl;
			price = stof(record[4]);
			cout << "\t\t\t the price is : " << price << endl;
			available = record[5];
			cout << "\t\t\t the available is : " << available << endl;
			colors = record[6];
			cout << "\t\t\t the colors is : " << colors << endl;
			status = record[7];
			cout << "\t\t\t the status is : " << status << endl;
			if (record[7] == "Used") {
				cout << "\t\t\t the kilometers is : " << record[8] << endl;

			}

			
		}


	

		file_read.close();

	}
	else {
		cout << "Unable to open file " << endl;
		
	}

}
void car::edit_car() {
	


	fstream car;
	fstream temp;
	int Car_ID;
	car.open("saved/Cars.txt", ios::in);
	temp.open("saved/tmp.txt", ios::out );
	cout << "Please Enter car ID to Update : ";
	cin >> Car_ID;

	
	string line;

	while (getline(car, line)) {
		vector<string>record;


		string temp_line = "";

		for (int i = 0; i < (int)line.size(); i++) {
			// If cur char is not del, then append it to the cur "word", otherwise
			  // you have completed the word, print it, and start a new word.
			if (line[i] != ',') {
				temp_line += line[i];
			}
			else {
				//cout << temp << " ";
				record.push_back(temp_line);
				temp_line = "";
			}
		}
		record.push_back(temp_line);

		//car.getline(Car_id,);
		if (Car_ID == stoi(record[0])) {
			//int car_id_New;
			//string maker_New;
			////string Model;
			//int yearModel_New;
			//string information_New;
			//float price_New;
			////double kilometers;
			//string available_New;
			//string colors_New;
			double KM;
			////string status;
			//cout << "Please Enter car ID : ";
			//cin >> car_id_New;
			//cout << endl;
			//cout << "Please Enter car Manufacturer : ";
			//cin >> maker_New;
			//cout << endl;
			//cout << "Please Enter Year Model : ";
			//cin >> yearModel_New;
			//cout << endl;
			//cout << "Please Enter Some information : ";
			//cin >> information_New;
			//cout << endl;
			//cout << "Please Enter car price : ";
			//cin >> price_New;
			//cout << endl;
			//cout << "Please Enter car available : ";
			//cin >> available_New;
			//cout << endl;
			//cout << "Please Enter car colors : ";
			//cin >> colors_New;
			//cout << endl;
			car::Set_atributes();

			if (record[7] == "Used") {
				cout << "Please Enter car kilometers : ";
				cin >> KM;
				cout << endl;
				//cout << "\t\t\t the kilometers is : " << record[8] << endl;
				temp << id << "," << maker << "," << yearModel << "," << information << "," << price << "," <<
					available << "," << colors << "," << "Used" << "," << KM << endl;
				cout << "--> Record is Update to file \n";


			}
			else
			{
				temp << id << "," << maker << "," << yearModel << "," << information << "," << price << "," <<
					available << "," << colors << "," << "New" << endl;
				cout << "--> Record is Update to file \n";
			}

			

		}
		else
		{
			if (record[7] == "Used") {
				temp << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," <<
					record[5] << "," << record[6] << "," << record[7] << "," << record[8] << endl;
			}

			
			else
			{
				temp << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," <<
					record[5] << "," << record[6] << "," << record[7] << endl;
			}
			
		}

	}
	temp.close();
	car.close();
	remove("saved/Cars.txt");
	rename("saved/tmp.txt","saved/Cars.txt");


	
}
void car::Delete_car() {
	
	fstream car;
	fstream temp;
	int Car_ID;
	car.open("saved/Cars.txt", ios::in);
	temp.open("saved/tmp.txt", ios::out);
	cout << "Please Enter car ID to Delete : ";
	cin >> Car_ID;

	
	string line;

	while (getline(car, line)) {
		vector<string>record;

		

		string temp_line = "";

		for (int i = 0; i < (int)line.size(); i++) {
			// If cur char is not del, then append it to the cur "word", otherwise
			  // you have completed the word, print it, and start a new word.
			if (line[i] != ',') {
				temp_line += line[i];
			}
			else {
				//cout << temp << " ";
				record.push_back(temp_line);
				temp_line = "";
			}
		}
		record.push_back(temp_line);

		//car.getline(Car_id,);
		if (Car_ID == stoi(record[0])) {
			continue;

		}
		else
		{
			if (record[7] == "Used") {
				temp << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," <<
					record[5] << "," << record[6] << "," << record[7] << "," << record[8] << endl;
			}
			else {
				temp << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," <<
					record[5] << "," << record[6] << "," << record[7] << endl;
			}
			
		}

	}
	temp.close();
	car.close();
	remove("saved/Cars.txt");
	rename("saved/tmp.txt", "saved/Cars.txt");



}
void car::search_car() {
	


	fstream car;
	
	int Car_ID;
	car.open("saved/Cars.txt", ios::in);
	
	cout << "Please Enter car ID to Search About it : ";
	cin >> Car_ID;
	string line;
	bool found=false;
	while (getline(car, line)) {
		vector<string>record;

		

		string temp_line = "";

		for (int i = 0; i < (int)line.size(); i++) {
			// If cur char is not del, then append it to the cur "word", otherwise
			  // you have completed the word, print it, and start a new word.
			if (line[i] != ',') {
				temp_line += line[i];
			}
			else {
				//cout << temp << " ";
				record.push_back(temp_line);
				temp_line = "";
			}
		}
		record.push_back(temp_line);

		//car.getline(Car_id,);
		if (Car_ID == stoi(record[0])) {
			cout << "The Car Information is \n" << endl;

			id = stoi(record[0]);
			cout << "\t\t\t the id is : " << id << endl;
			maker = record[1];
			cout << "\t\t\t the maker is : " << maker << endl;
			yearModel = stoi(record[2]);
			cout << "\t\t\t the yearModel is : " << yearModel << endl;
			information = record[3];
			cout << "\t\t\t the information is : " << information << endl;
			price = stof(record[4]);
			cout << "\t\t\t the price is : " << price << endl;
			available = record[5];
			cout << "\t\t\t the available is : " << available << endl;
			colors = record[6];
			cout << "\t\t\t the colors is : " << colors << endl;
			status = record[7];
			cout << "\t\t\t the status is : " << status << endl;
			if (record[7] == "Used") {
				cout << "\t\t\t the kilometers is : " << record[8] << endl;

			}
			found = true;
			break;
		}
		

	}
	if (!found) {
		cout << "\n\t\t\t   Not Found !!!!! " << status << endl;

	}
}
car::~car() {

}


