#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* The program, so far, will read in the text, change the desired characters
and insert the corresponding string... 
I will continue working on it - Gabriel Woodburn...February 21st*/

int main()
{
	string temp;
	string a = "</title>"; 
	string b = " </comment>"; 
	string c = " </header>";
	ifstream file1;
	ofstream fout;

	file1.open("testhtml.txt");	// Open the test file
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

	fstream input("testhtml.txt", ios::in);  // Get input from test file
	if (file1) {
		file1.seekg(0, ios::end);  // Seek until the end of the file
		size_t len = file1.tellg();
		file1.seekg(0);
		string temp(len + 1, '\0');
		file1.read(&temp[0], len); // Reads the data into 'temp' string
		file1.close();		   // Close the input text file
		cout << temp << endl;	   // Used for testing purposes...shows temp info

		size_t found = temp.find("*T");  // Searching in temp string for '*T'
		if (found!=string::npos)         // If the size_t doesn't point to a null position
		{
			temp.replace(0, 3, "<title>");  // Replaces *T with <title>...the 0 indicates the character position, the following 2 indicates the number of characters to replace, i.e "*T"
			temp.insert(17, a);		// Insert string 'a' at character position 131 within the temp string
		}
		
		size_t findnew = temp.find("*C"); // Searching in temp string for '*C'
		if (found!=string::npos)	  // If the size_t doesn't point to a null position
		{
			temp.replace(27, 2, "<comment>"); // Replaces *C with <comment>...the 27 indicates the character position, the following 2 indicates the number of characters to replace, i.e "*C"
			temp.insert(95, b);	  	  // Insert string 'b' at character position 95 within the temp string
		}
		
		size_t findagain = temp.find("*H");  // Searching in temp string for '*H'
		if (findagain != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(107, 2, "<header>");  // Replaces *H with <Header>...the 107 indicates the character position, the following 2 indicates the number of characters to replace, i.e "*H"
			temp.insert(131, c);		   // Insert string 'c' at character position 131 within the temp string
		}
		
		cout << endl << temp;			   // Display the change 'temp' string
		fout << temp << endl;			   // Stream the 'temp' string into the html output file
	}
	
	cout << "\n\nThe new file has been saved within resulthtml.html!\n";
	fout.close();					   // Close the output html file

	return 0;
}
