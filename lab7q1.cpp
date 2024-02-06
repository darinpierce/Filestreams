/*
* Author : Darin Pierce
* Date created: 10/23/2023
* Date modifed: 10/24/2023
* Purpose: Programs opens a file and uses a function to both calculate the pay of the employees as well as display the pay.
*/


#include<fstream>
#include<iostream>
using namespace std;
void outputLines(ifstream&);
int main()
{
	ifstream ifs;
	string fileName = "employees.txt";
	ifs.open(fileName);
	//checks that input file is open.
	if (!ifs.is_open())
	{
		cerr << "Could not open " << fileName;
		return 1;
	}
	//function is called
	outputLines(ifs);
	ifs.close();
	
	


	system("pause");

	return 0;
}
void outputLines(ifstream& ifstr)
{
	ofstream ofs;
	string fName, lName;
	int hours, rate;
	//Creates/opens results.txt and truncates it.
	ofs.open("results.txt"), ios :: trunc;
	if(ofs.fail())
	{
		cerr << "Could not open results.txt";

	}
	//Checks it's not end of file.
	while (!ifstr.eof())
	{
		ifstr >> fName >> lName >> hours >> rate;
		if (ifstr.eof())
			break;
		//Writes everything to results.txt
		ofs << fName << " " << lName << " " << hours * rate << endl;
		//Display to screen what is written in results.txt
		cout << fName << " " << lName << " " << hours * rate << endl;
	}
	cout << "Exiting Program..." << endl;
	ofs.close();

	
}