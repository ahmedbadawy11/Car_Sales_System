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
void car::Add_car() {
	ofstream myfile;
	myfile.open("saved/Cars.txt", ios::out | ios::app);
	myfile << id << "," << maker << "," << yearModel << "," << information<< "," << price <<"," <<
		available <<"," << colors <<"," << status <<endl;
	myfile.close();
}
void car::Displat_car() {
	//vector<string>record;
	//car car_tmp;
	ifstream file_read("saved/Cars.txt",ios::in);
	if (file_read.is_open()) {
//	ifstream file_read;
		//file_read.open("saved/Cars.txt");
		string line;
		
		while (getline(file_read, line))
		{
			vector<string>record;

			//char* char_arr;
			////string str_obj("GeeksForGeeks");
			//char_arr = &line[0];
			////cout << char_arr;

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

			////file_read >> car_tmp.id >> car_tmp.maker >> car_tmp.yearModel >> car_tmp.information >> car_tmp.price >> car_tmp.available >> car_tmp.colors >> car_tmp.status;
			//file_read >> car_tmp.id;
			//file_read >> car_tmp.maker;
			//file_read >> car_tmp.yearModel;
			//file_read >> car_tmp.information;
			//file_read >> car_tmp.price;
			//file_read >> car_tmp.available;
			//file_read >> car_tmp.colors;
			//file_read >> car_tmp.status;


			////cout << " the id is" << car_tmp.id;
			////record.push_back(car_tmp);
		}


	/*	for (int i = 0; i < record.size(); i++) {
			record[i]
		}*/

		file_read.close();

	}
	else {
		cout << "Unable to open file " << endl;
		
	}

}
void car::edit_car() {
	string Car_id;
	string Car_maker;
	//string Model;
	string Car_yearModel;
	string Car_information;
	string Car_price;
	//double kilometers;
	string Car_available;
	string Car_colors;
	string Car_status;


	fstream car;
	fstream temp;
	int Car_ID;
	car.open("saved/Cars.txt", ios::in);
	temp.open("saved/tmp.txt", ios::out );
	cout << "Please Enter car ID to Update : ";
	cin >> Car_ID;

	//car >> Car_id >> Car_maker >> Car_yearModel >> Car_information >> Car_price >>
	//	Car_available >> Car_colors >> Car_status
	string line;

	while (getline(car, line)) {
		vector<string>record;

		//char* char_arr;
		////string str_obj("GeeksForGeeks");
		//char_arr = &line[0];
		////cout << char_arr;

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
			int car_id_New;
			string maker_New;
			//string Model;
			int yearModel_New;
			string information_New;
			float price_New;
			//double kilometers;
			string available_New;
			string colors_New;
			//string status;
			cout << "Please Enter car ID : ";
			cin >> car_id_New;
			cout << endl;
			cout << "Please Enter car Manufacturer : ";
			cin >> maker_New;
			cout << endl;
			cout << "Please Enter Year Model : ";
			cin >> yearModel_New;
			cout << endl;
			cout << "Please Enter Some information : ";
			cin >> information_New;
			cout << endl;
			cout << "Please Enter car price : ";
			cin >> price_New;
			cout << endl;
			cout << "Please Enter car available : ";
			cin >> available_New;
			cout << endl;
			cout << "Please Enter car colors : ";
			cin >> colors_New;
			cout << endl;

			temp << car_id_New << "," << maker_New << "," << yearModel_New << "," << information_New << "," << price_New << "," <<
				available_New << "," << colors_New << "," << "New" << endl;
			cout << "--> Record is Update to file \n";

		}
		else
		{
			temp << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," <<
				record[5] << "," << record[6] << "," << record[7] << endl;
		}

	}
	temp.close();
	car.close();
	remove("saved/Cars.txt");
	rename("saved/tmp.txt","saved/Cars.txt");


	
}
car::~car() {

}
void split(string str, char del) {
	// declaring temp string to store the curr "word" upto del
	string temp = "";

	for (int i = 0; i < (int)str.size(); i++) {
		// If cur char is not del, then append it to the cur "word", otherwise
		  // you have completed the word, print it, and start a new word.
		if (str[i] != del) {
			temp += str[i];
		}
		else {
			cout << temp << " ";
			temp = "";
		}
	}

	cout << temp;

}

