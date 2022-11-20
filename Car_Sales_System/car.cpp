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
	ifstream file_read("saved/Cars.txt");
	if (file_read.is_open()) {
	ifstream file_read;
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

