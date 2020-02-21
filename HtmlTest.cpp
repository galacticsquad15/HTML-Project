#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

/* The program, so far, will read in the text and change the desired characters... 
BUT it won't stream the 'temp' string to the output file 'resulthtml.html' if the strings are changed...
The commented out lines are not working properly.
I will continue working on it - Gabriel Woodburn...February 20th*/

int main()
{
	string temp;
	ifstream file1;
	ofstream fout;

	file1.open("testhtml.txt");		// Open the test file
	if (file1.fail())
	{
		cout << "\nError opening .txt file";
		exit(EXIT_FAILURE);
	}

	fout.open("resulthtml.html");  // Open the out file
	{
		if (!fout)
		{
			cout << "\nError opening .html file";
			exit(EXIT_FAILURE);
		}
	}

	fstream input("testhtml.txt");  // Get input from test file
	if (file1) {
		file1.seekg(0, ios::end);  // Seek until the end of the file
		size_t len = file1.tellg();
		file1.seekg(0);
		string temp(len + 1, '\0');
		file1.read(&temp[0], len); // Reads the data into 'temp' string
		file1.close();			   // Close the input text file
		cout << temp;			   // Used for testing purposes...shows temp info

		size_t found = temp.find("*T");  // Searching in temp string for '*T'
		if (found!=string::npos)		 // If the size_t doesn't point to a null position
		{
			temp.replace(0, 2, "\n<title>");  // Replaces *T with <title>...the 0 indicates the character position
		}					  // the following 2 indicates the number of characters to replace, i.e "*T"

		size_t findnew = temp.find("*C"); // Searching in temp string for '*C'
		if (found!=string::npos)		  // If the size_t doesn't point to a null position
		{
			temp.replace(21, 2, "<comment>"); // Replaces *C with <comment>...the 21 indicates the character position
		}					  // the following 2 indicates the number of characters to replace, i.e "*C"

		size_t findagain = temp.find("*H");  // Searching in temp string for '*T'
		if (findagain != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(90, 2, "<Header>");  // Replaces *H with <Header>...the 90 indicates the character position
		}					  // the following 2 indicates the number of characters to replace, i.e "*H"
		
		cout << endl << temp;				  // Display the change 'temp' string
	}
	file1.close();						  // Close the input text file
	fout << temp << endl;					  // Stream the 'temp' string into the html output file
	cout << "\n\nThe new file has been saved within resulthtml.html!\n";
	//file1.close();
	fout.close();							  // Close the output html file

	return 0;
}
