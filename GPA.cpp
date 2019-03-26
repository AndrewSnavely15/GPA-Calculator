#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class GPA {
public:
	void display();
	void optionDisplay();
	void calculate_GPA();
	void calculate_WGPA();
	

private:
	double units;
	int nClasses; //number of classes 
	string grade;
	double gradeNumber;
	double totalGradeNumber;
	double totalUnits;
	double gpa;
	double weighted_gpa;
	string subject; //name of the class
	string quarter;
	vector<string> g; //vector of grades
	vector<string> s; //vector of subjects
	vector<double> u; //vector of units
};

void GPA :: display()
{
	cout << setw(75) << "Welcome to Andrew's GPA calculator" << endl; // Title of program
	optionDisplay();
}

void GPA :: optionDisplay()
{
	int option;
	// menu
	cout << setw(3) << "1. Check GPA" << endl;
	cout << setw(3) << "2. Calculate GPA" << endl;
	cout << setw(3) << "3. Calculate weighted GPA" << endl;
	cout << "\n\nPlease enter an option: ";
	cin >> option;
	if (option == 1)
	{
		//getGPA();
	}
	if(option == 2)
	{
		calculate_GPA();
	}
	if(option == 3)
	{
		calculate_WGPA();
	}
	else
	{
		display();
	}
}

void GPA::calculate_GPA()
{
	cin.ignore();
	cout << "Enter quarter/Semester: ";
	getline(cin, quarter);
	cout << endl;
	cout << "Enter the number of classes taken: ";
	cin >> nClasses;
	cout << endl;
	for (int i = 1; i <= nClasses; ++i)
	{
		if (i == 1) {
			cin.ignore();
		}

		cout << "Enter the name of the class: ";
		getline(cin, subject);
		s.push_back(subject);
		cout << "\nEnter the grade you got in the class: ";
		getline(cin, grade);
		g.push_back(grade);

		cout << endl;
	}
	cout << setw(20) << quarter << endl;
	for (int i = 0; i < g.size(); i++)
	{
		if (s[i].size() == 7) //formatting 
		{
			cout << s[i] << ": " << setw(20) << g[i] << endl;
		}
		if (s[i].size() == 8) //formatting
		{
			cout << s[i] << ": " << setw(19) << g[i] << endl;

		}

		if (g[i] == "A")
		{
			gradeNumber = 4;
		}
		if (g[i] == "A-")
		{
			gradeNumber = 3.7;
		}
		if (g[i] == "B+")
		{
			gradeNumber = 3.3;
		}
		if (g[i] == "B")
		{
			gradeNumber = 3;
		}
		if (g[i] == "B-")
		{
			gradeNumber = 2.7;
		}
		if (g[i] == "C+")
		{
			gradeNumber = 2.3;
		}
		if (g[i] == "C")
		{
			gradeNumber = 2;
		}
		if (g[i] == "C-")
		{
			gradeNumber = 1.7;
		}
		if (g[i] == "D+")
		{
			gradeNumber = 1.3;
		}
		if (g[i] == "D")
		{
			gradeNumber = 1;
		}
		if (g[i] == "D-")
		{
			gradeNumber = 0.7;
		}
		if (g[i] == "F")
		{
			gradeNumber = 0;
		}
		totalGradeNumber += gradeNumber;

		gpa = totalGradeNumber / nClasses;

		
	}
	cout << setw(50) << "GPA: " << gpa << endl;
}

void GPA::calculate_WGPA()
{
	cin.ignore();
	cout << "Enter quarter/Semester: ";
	getline(cin, quarter);
	cout << endl;
	cout << "Enter the number of classes taken: ";
	cin >> nClasses;
	cout << endl;
	for (int i = 1; i <= nClasses; ++i)
	{
		if (i == 1) {
			cin.ignore();
		}

		cout << "Enter the name of the class: ";
		getline(cin, subject);
		s.push_back(subject);
		cout << "\nEnter number of units: ";
		cin >> units;
		u.push_back(units);
		cin.ignore();
		cout << "\nEnter the grade you got in the class: ";
		getline(cin, grade);
		g.push_back(grade);

		cout << endl;
	}

	cout << setw(20) << quarter << endl;
	fstream mytext("C:/Users/Andrew Snavely/Desktop/Grades.txt", ios::out | ios::app);
	mytext << setw(30) << quarter << endl;
	mytext << "Class:" << setw(12) << "Units:" << setw(12) << "Grade" << endl;
	
	for (int i = 0; i < s.size(); i++)
	{
		
		if (g[i] == "A")
		{
			gradeNumber = 4;
		}
		if (g[i] == "A-")
		{
			gradeNumber = 3.7;
		}
		if (g[i] == "B+")
		{
			gradeNumber = 3.3;
		}
		if (g[i] == "B")
		{
			gradeNumber = 3;
		}
		if (g[i] == "B-")
		{
			gradeNumber = 2.7;
		}
		if (g[i] == "C+")
		{
			gradeNumber = 2.3;
		}
		if (g[i] == "C")
		{
			gradeNumber = 2;
		}
		if (g[i] == "C-")
		{
			gradeNumber = 1.7;
		}
		if (g[i] == "D+")
		{
			gradeNumber = 1.3;
		}
		if (g[i] == "D")
		{
			gradeNumber = 1;
		}
		if (g[i] == "D-")
		{
			gradeNumber = 0.7;
		}
		if (g[i] == "F")
		{
			gradeNumber = 0;
		}
		totalGradeNumber += gradeNumber * u[i];
		totalUnits += u[i];

		weighted_gpa = totalGradeNumber  / totalUnits;
		
		if (s[i].size() == 7) //formatting 
		{
			if (g[i].size() == 2)
			{
				mytext << s[i] << setw(9) << u[i] << setw(12) << g[i] << endl;
			}
			else
				mytext << s[i] << setw(9) << u[i] << setw(11) << g[i] << endl;
		}
		if (s[i].size() == 8) //formatting
		{
			if (g[i].size() == 2)
			{
				mytext << s[i] << setw(8) << u[i] << setw(12) << g[i] << endl;
			}
			else
				mytext << s[i] << setw(8) << u[i] << setw(11) << g[i] << endl;

		}
		
	}
	mytext << setw(50) << " Weighted GPA: " << weighted_gpa << endl;
	string end = "-----------------------------------------------------------";
	mytext << end << endl;
	mytext.close();
	
}




int main()
{
	GPA Andrew;
	Andrew.display();
	system("pause");
	return 0;
}