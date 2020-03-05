// ** CIS164 - 22264
// ** Week #6 & 7
// ** HTML Group Project
// ** Gabriel Woodburn, Elijah Morishita, Bradley Owens, Robert Knar, Ian Waddell, Lyle Reicks, Jian Shi, Skyler Brown
// ** March 4th, 2020
// ** This program will will read in the text starting file "testhtml.txt", change the desired characters
// ** and insert the corresponding string and formatting for the output file "resulthtml.html"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

// Start, Gabriel Woodburn
int main()
{
	string temp;
	const string delim = "\"";
	const string lang = "lang=";
	const string u = "-US";
	const string head = "<head>\n";
	const string headEnd = "\n</head>\n";
	const string charset = "utf-8";
	const string InLinkRef = "Information</a>";
	const string body = "<body>\n";
	const string bodyEnd = "\n</body>\n";
	const string htmlEnd = "\n</html>";
	const string anchor = "*A";
	const string anchorBegin = "<a";
	const string anchorEnd = "</a>";
	const string br = "*R";
	const string breakBegin = "<br />";
	const string internalLink = "*L";
	const string inLinkBegin = "<a";
	const string inLinkEnd = "</a>";
	const string image = "*IM";
	const string imageStart = "<img src=";
	const string list = "*O";
	const string listBegin = "<ol>";
	const string listItem = "<li>";
	const string listItemEnd = "</li>";
	const string t = "*T";
	const string tBegin = "<title>";
	const string tEnd = "</title>";
	const string c = "*C";
	const string cBegin = "<comment>";
	const string cEnd = " </comment>";
	const string h = "*H";
	const string hBegin = "<header>";
	const string hEnd = "</header>";
	const string h1 = "*H1";
	const string h1Begin = "<h1>";
	const string h1End = "</h1>";
	const string h2 = "*H2";
	const string h2Begin = "<h2>";
	const string h2End = "</h2>";
	const string h3 = "*H3";
	const string h3Begin = "<h3>";
	const string h3End = "</h3>";
	const string h4 = "*H4";
	const string h4Begin = "<h4>";
	const string h4End = "</h4>";
	const string h5 = "*H5";
	const string h5Begin = "<h5>";
	const string h5End = "</h5>";
	const string h6 = "*H6";
	const string h6Begin = "<h6>";
	const string h6End = "</h6>";
	const string p = "*P";
	const string pBegin = "<p>\n";
	const string pEnd = "\n</p>";
	const string italics = "*I";
	const string iBegin = "<i>";
	const string iEnd = "</i>";
	const string bold = "*B";
	const string bBegin = "<strong>";
	const string bEnd = "</strong>";
	const string emphasis = "*E";
	const string emBegin = "<em>";
	const string emEnd = "</em>";
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

	fstream input("testhtml.txt");  // Get input from test file
	if (file1) {
		file1.seekg(0, ios::end);   // Seek until the end of the file
		size_t len = file1.tellg(); // Get the position in the input stream
		file1.seekg(0);
		string temp(len + 1, '\0');
		file1.read(&temp[0], len); // Reads the data into 'temp' string
		file1.close();		       // Close the input text file
		cout << temp << endl;	   // Used for testing purposes...shows temp info

		temp.insert(0, "<!DOCTYPE html>\n<html lang=en-US>\n");  // Formatting... html doctype, US - english as language
		temp.insert(temp.find(lang) + 5, delim);				 // Insert string delim 5 characters after the string lang
		temp.insert(temp.find(u) + 3, delim);					 // Insert string delim 3 characters after the string u
		temp.insert(temp.find(t), head);						 // Insert string head before string t

		size_t findT = temp.find(t);     // Searching in temp string for '*T'
		if (findT != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(t), t.length(), tBegin);	// Replaces *T with <title>...parameters are the find(t) function, the length of string t, and the replacement string 'tBegin'
			temp.insert(temp.find(c) - 1, tEnd);			// Insert string 'tEnd' one character position before <comment> within the temp string
		}

		size_t findC = temp.find(c);	  // Searching in temp string for '*C'
		if (findC != string::npos)		  // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(c), c.length(), cBegin);		 // Replaces *C with <comment>...parameters are the find(c) function, the length of string c, and the replacement string 'cBegin'
			temp.insert(temp.find(h) - 1, cEnd);			     // Insert string 'cEnd' one character position before <header> within the temp string
			temp.insert(temp.find(h), "<meta charset=utf-8 />"); // Insert formatting characters 'meta charset=utf-8 /> before *H
			temp.insert(temp.find(charset), delim);				 // Insert string delim before string charset
			temp.insert(temp.find(charset) + 5, delim);			 // Insert string delim 5 characters after string charset
			temp.insert(temp.find(h), headEnd);					 // Insert string headEnd before *H
			temp.insert(temp.find(h), body);					 // Insert string body before *H
			temp.insert(temp.find(h), pBegin);					 // Insert string pBegin before *H
		}

		size_t findH = temp.find(h);	 // Searching in temp string for '*H'
		if (findH != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h), h.length(), hBegin); // Replaces *H with <header>...parameters are the find(h) function, the length of string h, and the replacement string 'hBegin'
			temp.insert(temp.find("Welcome!") + 8, hEnd);	// Insert string hEnd 8 characters after the word 'Example' within the header shorthand
		}

		size_t findHH = temp.find(h);	// Searching in temp string for '*H'
		if (findHH != string::npos)     // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h), h.length(), hBegin);       // Replaces *H with <header>...parameters are the find(h) function, the length of string h, and the replacement string 'hBegin'
			temp.replace(temp.find(bold), bold.length(), bBegin); // Replaces *B with <strong>...parameters are the find(bold) function, the length of string bold, and the replacement string 'bBegin'
			temp.insert(temp.find("FUN!") + 4, bEnd);			  // Insert string bEnd 4 characters after the word 'FUN!' within the header shorthand
			temp.insert(temp.find(bEnd) + 9, hEnd);				  // Insert string hEnd 9 characters after the string bEnd within the header shorthand
		}

		size_t findImage = temp.find(image); // Searching in temp string for '*IM'
		if (findImage != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(image), image.length(), imageStart);  // Replaces *IM with <img src=...parameters are the find(image) function, the length of string image, and the replacement string 'imageStart'
			temp.insert(temp.find(".jpg") + 4, " />");					 // Insert characters ' /> ' 4 characters after the characters '.jpg' within the image shorthand
			temp.insert(temp.find("Eftkilla"), delim);					 // Insert string delim after the characters 'Eftkilla' within the image shorthand
			temp.insert(temp.find(".jpg") + 4, delim);					 // Insert string delim 4 characters after the characters '.jpg' within the image shorthand
		} // End, Gabriel Woodburn

		// Start, Ian Waddell
		size_t findH1 = temp.find(h1);	 // Searching in temp string for '*H1'
		if (findH1 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h1), h1.length(), h1Begin); // Replaces *H with <h1>...parameters are the find(h1) function, the length of string h1, and the replacement string 'h1Begin'
			temp.insert(temp.find("Friends") + 7, h1End);	// Insert string h1End 8 characters after the word 'headerone' within the header shorthand
		}

		size_t findH2 = temp.find(h2);	 // Searching in temp string for '*H2'
		if (findH2 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h2), h2.length(), h2Begin); // Replaces *H2 with <h2>...parameters are the find(h2) function, the length of string h2, and the replacement string 'h2Begin'
			temp.insert(temp.find("yourself") + 8, h2End);	// Insert string h2End 9 characters after the word 'headertwo' within the header shorthand
		}

		size_t findH3 = temp.find(h3);	 // Searching in temp string for '*H2'
		if (findH3 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h3), h3.length(), h3Begin); // Replaces *H3 with <h3>...parameters are the find(h3) function, the length of string h3, and the replacement string 'h3Begin'
			temp.insert(temp.find("whenever") + 8, h3End);	// Insert string h1End 11 characters after the word 'headerthree' within the header shorthand
		}

		size_t findH4 = temp.find(h4);	 // Searching in temp string for '*H4'
		if (findH4 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h4), h4.length(), h4Begin); // Replaces *H4 with <h4>...parameters are the find(h4) function, the length of string h4, and the replacement string 'h4Begin'
			temp.insert(temp.find("however") + 7, h4End);	// Insert string h1End 10 characters after the word 'headerfour' within the header shorthand
		}

		size_t findH5 = temp.find(h5);	 // Searching in temp string for '*H5'
		if (findH5 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h5), h5.length(), h5Begin); // Replaces *H5 with <h5>...parameters are the find(h5) function, the length of string h5, and the replacement string 'h5Begin'
			temp.insert(temp.find("GAME") + 4, h5End);	// Insert string h5End 10 characters after the word 'headerfive' within the header shorthand
		}

		size_t findH6 = temp.find(h6);	 // Searching in temp string for '*H6'
		if (findH6 != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(h6), h6.length(), h6Begin); // Replaces *H6 with <h6>...parameters are the find(h6) function, the length of string h6, and the replacement string 'h6Begin'
			temp.insert(temp.find("out") + 3, h6End);	// Insert string h6End 9 characters after the word 'headersix' within the header shorthand
		} // End, Ian Waddell

		// Start, Gabriel Woodburn
		size_t findList = temp.find(list); // Searching in temp string for '*O'
		if (findList != string::npos)      // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(list), list.length(), listBegin);  // Replaces *O with <ol>...parameters are the find(list) function, the length of string list, and the replacement string 'listBegin'
			temp.insert(temp.find("PC"), listItem);					  // Insert string listItem after characters 'PC' within the list shorthand
			temp.insert(temp.find("PC") + 2, listItemEnd);			  // Insert string listItemEnd 2 characters after characters 'PC' within the list shorthand
			temp.insert(temp.find("Playstation"), listItem);		  // Insert string listItem after characters 'Playstation' within the list shorthand
			temp.insert(temp.find("Playstation") + 11, listItemEnd);  // Insert string listItemEnd 11 characters after characters 'Playstation' within the list shorthand
			temp.insert(temp.find("Xbox"), listItem);				  // Insert string listItem after characters 'Xbox' within the list shorthand
			temp.insert(temp.find("Xbox") + 4, listItemEnd);          // Insert string listItemEnd 4 characters after characters 'Xbox' within the list shorthand
		} // End, Gabriel Woodburn

		// Start, Lyle Reicks
		size_t findP = temp.find(p);	 // Searching in temp string for '*P'
		if (findP != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(p), p.length(), pBegin); // Replaces *P with <p>...parameters are the find(p) function, the length of string p, and the replacement string 'h6Begin'
		} // End, Lyle Reicks

		// Start, Bradley Owens
		size_t findI = temp.find(italics);	 // Searching in temp string for '*I'
		if (findI != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(italics), italics.length(), iBegin); // Replaces *I with <i>...parameters are the find(italics) function, the length of string i, and the replacement string 'iBegin'
			temp.insert(temp.find("LIFE!") + 5, iEnd);	// Insert string iEnd 7 characters after the word 'italics' within the header shorthand
		}

		size_t findB = temp.find(bold);	 // Searching in temp string for '*B'
		if (findB != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(bold), bold.length(), bBegin); // Replaces *B with <strong>...parameters are the find(bold) function, the length of string b, and the replacement string 'bBegin'
			temp.insert(temp.find("FUN!") + 4, bEnd);	// Insert string bEnd 4 characters after the word 'bold' within the header shorthand
		} // End, Bradley Owens

		// Start, Robert Knar
		size_t findE = temp.find(emphasis);	 // Searching in temp string for '*E'
		if (findE != string::npos)       // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(emphasis), emphasis.length(), emBegin); // Replaces *E with <em>...parameters are the find(emphasis) function, the length of string, and the replacement string 'emBegin'
			temp.insert(temp.find("HAPPY!") + 6, bEnd);	// Insert string bEnd 6 characters after
		}
		//End, Robert Knar

		// Start, Gabriel Woodburn
		size_t findBr = temp.find(br);  // Searching in temp string for '*R'
		if (findBr != string::npos)     // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(br), br.length(), breakBegin);  // Replaces *R with <br />...parameters are the find(br) function, the length of string br, and the replacement string 'breakBegin'
		}

		size_t findAnchor = temp.find(anchor);  // Searching in temp string for '*A'
		if(findAnchor !=string::npos)			// If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(anchor), anchor.length(), anchorBegin);  // Replace *A with <a ... parameters are the find(anchor) function, the length of string anchor, and the replacement string 'anchorBegin'
			temp.insert(temp.find("Club") + 4, anchorEnd);					// Insert string anchorEnd 4 characters after characters 'club'
		}

		size_t findBrBr = temp.find(br); // Searching in temp string for '*R'
		if (findBrBr != string::npos)    // If the size_t doesn't point to a null position
		{
			temp.replace(temp.find(br), br.length(), breakBegin);	// Replaces *R with <br />...parameters are the find(br) function, the length of string br, and the replacement string 'breakBegin'
			temp.replace(temp.find(internalLink), internalLink.length(), inLinkBegin);  // Replaces *L with <a ... parameters are the find(internalLink) function, the length of the internalLink string, and the inLinkBegin string
			temp.insert(temp.find("Information") + 11, inLinkEnd);						// Insert string inLinkEnd 11 characters after the characters "Information"
		}

		size_t findInEnd = temp.find(inLinkEnd); // Searching in temp string for '</a>'...adding additional closing formatting
		if (findInEnd != string::npos)			 // If the size_t doesn't point to a null position
		{
			temp.insert(temp.find(InLinkRef) + 19, bodyEnd);  // Insert string bodyEnd 19 characters after string InLinkRef
			temp.insert(temp.find(bodyEnd) - 1, pEnd);		  // Insert string pEnd 1 character before string bodyEnd
			temp.insert(temp.find(bodyEnd) + 8, htmlEnd);	  // Insert string htmlEnd 8 characters after bodyEnd
		}
		cout << endl << temp;			   // Display the change 'temp' string
		fout << temp << endl;			   // Stream the 'temp' string into the html output file
		
	}

	cout << "\n\nThe new file has been saved within resulthtml.html!\n";
	fout.close();					   // Close the output html file

	return 0;  // End, Gabriel Woodburn
}
