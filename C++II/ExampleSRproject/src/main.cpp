#include <iostream>
#include <vector>
#include "Digits.h"
#include <algorithm>
#include <stdlib.h>
#include "Stud_Rcrd.h"
using namespace std;

int main()
{
	vector<Stud_Rcrd>	VR1(25);
	int					rcr_count(0);

	for (int i = 0; i < 1; i++)
		{
			VR1[i].Stud_Rcrd::Write_Rcrds(cin); 
			rcr_count++;
		}
	/*
	printf("\n\t********SORTED by ID*********\n");
	stable_sort(VR1.begin(), (VR1.begin() + rcr_count));
	for (int i = 0; i < rcr_count; ++i)
		{
			VR1[i].Get_Rcrd();
		}
	*/
	qsort(&VR1.front(), rcr_count, sizeof(Stud_Rcrd), Stud_Rcrd::Compare_Name);
		for (int i = 0; i < rcr_count; ++i)
		{
			VR1[i].Get_Rcrd();
		}

	ofstream Outfile; 
	Outfile.open("Test.txt", ios::app);
	for (int i = 0; i < rcr_count; i++)
		{
			VR1[i].Write_File(Outfile);  
		}	
		Outfile.close(); 
		
	fstream		File;
	char		line[81];
	string		s1; 

	File.open("Test.txt", ios_base::in | ios_base::out);
	if (!File.is_open())
		{
			cout << "File not found" << endl;
		}
	else
		{
			while (File.getline(line, 81))
				{
					cout << line << endl; 
				}
		File.close();
		}
	
}		


