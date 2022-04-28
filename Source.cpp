#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class STUDENT {
	//Create values such as name, student ID, Course details, units and grades.
public: 
		int ID;
	    string NAME;
	    string COURSE;
	    int NUM_UNITS = 4;
	    map<string, int> GRADES;
};
class STAFF {
	//Create values such as name, student ID, Course details, units and grades.
public:
	int ID;
	string NAME;
	string COURSE;
	int NUM_UNITS = 4;
	map<string, string> TIMETABLE;
};

void Student_Print(STUDENT student),Append_Student(STUDENT student,string file),Create_Student();
void Staff_Print(STAFF staff), Append_Staff(STAFF staff, string file), Create_Staff();
void Print_File(string file_path);

int main() { 
	int option;
	cout << "Please select from the options below.\n";
	cout << "Press number 1 - Enter a new student details to the record\n";
	cout << "Press number 2 - Enter a new Staff details to the record\n";
	cout << "Press number 3 - Display student record\n";
	cout << "Press number 4 - Display staff record\n";
	cin >> option;
	switch (option) {
	case 1:
		Create_Student();
		break;
	case 2:
		Create_Staff();
		break;
	case 3:
		Print_File("student.txt");
		break;
	case 4:
		Print_File("staff.txt");
		break;
	default:
		{
			cout << "Invalid option\n";
			main();
		}
	}
}

void Student_Print(STUDENT student) {
	cout << "Student ID: " << student.ID << "\n";
	cout << "Student Name: " << student.NAME << "\n";
	cout << "Course: " << student.COURSE << "\n";
	for (std::pair<std::string, int> element : student.GRADES) {
		// Accessing KEY from element
		std::string Unit = element.first;
		int grade = element.second;
		std::cout << "Unit: " << Unit << " Grade: " << grade << std::endl;
	}
}
void Append_Student(STUDENT student, string file) {
	ofstream outfile;
	outfile.open(file.c_str(), std::ios_base::app); // append instead of overwrite
	outfile << "Student ID: " << student.ID << "\n";
	outfile << "Student Name: " << student.NAME << "\n";
	outfile << "Course: " << student.COURSE << "\n";
	for (std::pair<std::string, int> element : student.GRADES) {
		string Unit = element.first;
		int grade = element.second;
		outfile << "Unit: " << Unit << " Grade: " << grade << std::endl;
	}
}
void Create_Student() {
		STUDENT temp;
		cout << "Please Input the new students information: \n";
		cout << "Enter Student ID: ";
		cin >> temp.ID;
		cout << "Enter Student Name: ";
		cin >> temp.NAME;
		cout << "Enter Student Course: ";
		cin >> temp.COURSE;
		cout << "Enter Number of Units: ";
		cin >> temp.NUM_UNITS;
		for (int i = 0; i < temp.NUM_UNITS; i++) {
			string unit;
			int score;
			cout << "Enter Unit Name: ";
			cin >> unit;
			cout << "Enter Unit Score: ";
			cin >> score;
			temp.GRADES.insert(pair<string, int>(unit, score));
		}
		Student_Print(temp);
		Append_Student(temp, "student.txt");
}

void Staff_Print(STAFF staff) {
	cout << "Staff ID: " << staff.ID << "\n";
	cout << "Staff Name: " << staff.NAME << "\n";
	cout << "Course: " << staff.COURSE << "\n";
	for (std::pair<std::string, string> element : staff.TIMETABLE) {
		// Accessing KEY from element
		std::string Unit = element.first;
		string grade = element.second;
		std::cout << "Unit: " << Unit << " TimeSlot: " << grade << std::endl;
	}
}
void Append_Staff(STAFF staff, string file) {
	ofstream outfile;
	outfile.open(file.c_str(), std::ios_base::app); // append instead of overwrite
	outfile << "Staff ID: " << staff.ID << "\n";
	outfile << "Staff Name: " << staff.NAME << "\n";
	outfile << "Course: " << staff.COURSE << "\n";
	for (std::pair<std::string, string> element : staff.TIMETABLE) {
		string Unit = element.first;
		string grade = element.second;
		outfile << "Unit: " << Unit << " Time Slot: " << grade << std::endl;
	}
}
void Create_Staff() {
	STAFF temp;
	cout << "Please Input the new staff members information: \n";
	cout << "Enter Staff ID: ";
	cin >> temp.ID;
	cout << "Enter Staff Name: ";
	cin >> temp.NAME;
	cout << "Enter Staff Course: ";
	cin >> temp.COURSE;
	cout << "Enter Number of Units: ";
	cin >> temp.NUM_UNITS;
	for (int i = 0; i < temp.NUM_UNITS; i++) {
		string unit;
		string score;
		cout << "Enter Unit Name: ";
		cin >> unit;
		cout << "Enter Unit Timeslot: ";
		cin >> score;
		temp.TIMETABLE.insert(pair<string, string>(unit, score));
	}
	Staff_Print(temp);
	Append_Staff(temp, "staff.txt");
}

void Print_File(string file_path) {
	ifstream file;
	string line;
	file.open(file_path.c_str(), std::ios_base::in);
	while( getline(file, line)) {
		cout << line << endl;
	}
}