/*****************************************************************************
 * File: WTM.h

 * Name: Jacob Shumate

 * Purpose: Word tree map class with implemented STL map container. Collects 
   basic statistics about the word usage in a file by counting and reporting 
   back in sorted order the words used and the frequency of word occurrences. 

 * Instructions for use: Refer to driver.cpp

 * Compile: g++ -c WTM.cpp driver.cpp
   g++ WTM.o driver.o - o <output_name>

 * Tested In: Linux Ubuntu/GNU Compiler/
*****************************************************************************/

#ifndef WTM_H
#define WTM_H

#include <map>
#include <string>

using namespace std;

class WTM{

private:
	map<string, int> tree;
	
public:

	void incrementTree(const string &new_word);
	//Purpose: Passes string in by reference. iterates through 
	//tree until the same word is found which then increments
	//the data integer value, or if iterator meets the end of
	//map container, then the word is added to key string and 
	//data integer is set to 1.
	//Precondition: Validation of type string.
	//Postcondition: Map container gains a word or if word
	//already exists, increment data integer value for that word.

	void printTree();
	//Purpose: Iterator is set to beginning of map container, 
	//prints out matching key string values and data integer values 
	//until end of map container is met.
	//Postcondition: Prints out matching key string values and
	//data integer values.

	void read_file(string file_name);
	//Purpose: Passes in string containing name of file to be read.
	//Reads txt file containing words, each word is passes into
	//the function incrementTree to be added to map container.
	//Precondition: Validation of type string.
	//Postcondition: One or multiple words and matching integer 
	//data values added to map container.

};
#endif
