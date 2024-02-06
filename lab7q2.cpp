/*
* Author : Darin Pierce
* Date created: 10/23/2023
* Date modifed: 10/24/2023
* Purpose: Programs opens a file full of different scores and uses a function to calculate high score and average score, which it then displays from main().
*/



#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

void avgAndHigh(ifstream&, double&, double&);
int main()
{
	ifstream ifs;
	string fileName;
	double avg, high;
	cout << "Enter file name: ";
	cin >> fileName;
	ifs.open(fileName);
	//checks that input file is open.
	if (!ifs.is_open())
	{
		cerr << "Could not open " << fileName;
		return 1;
	}
	//function is called 
	avgAndHigh(ifs, avg, high);
	ifs.close();
	cout << "Average score is: " << avg << endl;
	cout << "Highest score is: " << high << endl;



	system("pause");

	return 0;
}
void avgAndHigh(ifstream& ifstr, double& average, double& highscore)
{
	string junk1, junk2;
	int curScore;
	float total = 0;
	vector <int>  scores;
	//creates scores vector
	while (!ifstr.eof())
	{
			ifstr >> junk1 >> junk2 >> curScore;
			if (ifstr.eof())
				break;
			else
				scores.push_back(curScore);
	
	}
	//finds high score
	highscore = scores.at(0);
	//finds average;
	for (int i = 1; i < scores.size(); i++)
	{
		if (scores.at(i) > highscore)
		{
			highscore = scores.at(i);
		}
	}
	for (int i = 0; i < scores.size(); i++)
	{
		total += scores.at(i);
	}
	average = total / scores.size();
}