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
	string t = "*T";
	string tBegin = "<title>";
	string tEnd = "</title>";
	string c = "*C";
	string cBegin = "<comment>";
	string cEnd = " </comment>";
	string h = "*H";
	string hBegin = "<header>";
	string hEnd = "</header>";
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
		file1.seekg(0, ios::end);  	 // Seek until the end of the file
		size_t len = file1.tellg();
		file1.seekg(0);
		string temp(len + 1, '\0');
		file1.read(&temp[0], len);       // Reads the data into 'temp' string
		file1.close();		         // Close the input text file
		cout << temp << endl;	  	 // Used for testing purposes...shows temp info
		size_t findT = temp.find(t);     // Searching in temp string for '*T'
		if (findT != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(t), t.length(), tBegin);	// Replaces *T with <title>...parameters are the find(t) function, the length of string t, and the replacement string 'tBegin'
			temp.insert(19, tEnd);				// Insert string 'tEnd' at character position 19 within the temp string
		}

		size_t findC = temp.find(c);	  // Searching in temp string for '*C'
		if (findC != string::npos)	  // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(c), c.length(), cBegin); // Replaces *C with <comment>...parameters are the find(c) function, the length of string c, and the replacement string 'cBegin'
			temp.insert(96, cEnd);	  			// Insert string 'cEnd' at character position 96 within the temp string
		}

		size_t findH = temp.find(h);	 // Searching in temp string for '*H'
		if (findH != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h), h.length(), hBegin); // Replaces *H with <header>...parameters are the find(h) function, the length of string h, and the replacement string 'hBegin'
			temp.insert(133, hEnd);				// Insert string 'hEnd' at character position 133 within the temp string
		}

		cout << endl << temp;			   // Display the change 'temp' string
		fout << temp << endl;			   // Stream the 'temp' string into the html output file
	}

	cout << "\n\nThe new file has been saved within resulthtml.html!\n";
	fout.close();					   // Close the output html file

	return 0;
}
