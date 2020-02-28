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
	string h1 = "*H1";
	string h1Begin = "<h1>";
	string h1End = "</h1>";
	string h2 = "*H2";
	string h2Begin = "<h2>";
	string h2End = "</h2>";
	string h3 = "*H3";
	string h3Begin = "<h3>";
	string h3End = "</h3>";
	string h4 = "*H4";
	string h4Begin = "<h4>";
	string h4End = "</h4>";
	string h5 = "*H5";
	string h5Begin = "<h5>";
	string h5End = "</h5>";
	string h6 = "*H6";
	string h6Begin = "<h6>";
	string h6End = "</h6>";
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
			temp.insert(temp.find(c) - 1, tEnd);		// Insert string 'tEnd' one character position before <comment> within the temp string
		}

		size_t findC = temp.find(c);	  // Searching in temp string for '*C'
		if (findC != string::npos)	  // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(c), c.length(), cBegin); // Replaces *C with <comment>...parameters are the find(c) function, the length of string c, and the replacement string 'cBegin'
			temp.insert(temp.find(h) - 1, cEnd);		// Insert string 'cEnd' one character position before <header> within the temp string
		}

		size_t findH = temp.find(h);	 // Searching in temp string for '*H'
		if (findH != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h), h.length(), hBegin); // Replaces *H with <header>...parameters are the find(h) function, the length of string h, and the replacement string 'hBegin'
			temp.insert(temp.find("Example") + 8, hEnd);	// Insert string hEnd 8 characters after the word 'Example' within the header shorthand
		}

		//headers start done by ian waddell 2/28/20
		size_t findH1 = temp.find(h1);	 // Searching in temp string for '*H1'
		if (findH1 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h1), h1.length(), h1Begin); // Replaces *H with <h1>...parameters are the find(h1) function, the length of string h1, and the replacement string 'h1Begin'
			temp.insert(temp.find("headerone") + 9, h1End);	// Insert string h1End 8 characters after the word 'headerone' within the header shorthand
		}
		size_t findH2 = temp.find(h2);	 // Searching in temp string for '*H2'
		if (findH2 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h2), h2.length(), h2Begin); // Replaces *H2 with <h2>...parameters are the find(h2) function, the length of string h2, and the replacement string 'h2Begin'
			temp.insert(temp.find("headertwo") + 9, h2End);	// Insert string h2End 9 characters after the word 'headertwo' within the header shorthand
		}
		size_t findH3 = temp.find(h3);	 // Searching in temp string for '*H2'
		if (findH3 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h3), h3.length(), h3Begin); // Replaces *H3 with <h3>...parameters are the find(h3) function, the length of string h3, and the replacement string 'h3Begin'
			temp.insert(temp.find("headerthree") + 11, h3End);	// Insert string h1End 11 characters after the word 'headerthree' within the header shorthand
		}
		size_t findH4 = temp.find(h4);	 // Searching in temp string for '*H4'
		if (findH4 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h4), h4.length(), h4Begin); // Replaces *H4 with <h4>...parameters are the find(h4) function, the length of string h4, and the replacement string 'h4Begin'
			temp.insert(temp.find("headerfour") + 10, h4End);	// Insert string h1End 10 characters after the word 'headerfour' within the header shorthand
		}
		size_t findH5 = temp.find(h5);	 // Searching in temp string for '*H5'
		if (findH5 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h5), h5.length(), h5Begin); // Replaces *H5 with <h5>...parameters are the find(h5) function, the length of string h5, and the replacement string 'h5Begin'
			temp.insert(temp.find("headerfive") + 10, h5End);	// Insert string h5End 10 characters after the word 'headerfive' within the header shorthand
		}
		size_t findH6 = temp.find(h6);	 // Searching in temp string for '*H6'
		if (findH6 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h6), h6.length(), h6Begin); // Replaces *H6 with <h6>...parameters are the find(h6) function, the length of string h6, and the replacement string 'h6Begin'
			temp.insert(temp.find("headersix") + 9, h6End);	// Insert string h6End 9 characters after the word 'headersix' within the header shorthand
		}
		//headers finish done by ian waddell 2/28/20


		cout << endl << temp;			   // Display the change 'temp' string
		fout << temp << endl;			   // Stream the 'temp' string into the html output file
	}

	cout << "\n\nThe new file has been saved within resulthtml.html!\n";
	fout.close();					   // Close the output html file

	return 0;
}