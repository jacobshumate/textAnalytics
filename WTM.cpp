/*****************************************************************************
 * File: WTM.cpp

 * Name: Jacob Shumate

 * Purpose: Word tree map class with implemented STL map container. Collects 
   basic statistics about the word usage in a file by counting and reporting 
   back in sorted order the words used and the frequency of word occurrences. 

 * Instructions for use: Refer to driver.cpp

 * Compile: g++ -c WTM.cpp driver.cpp
   g++ WTM.o driver.o - o <output_name>

 * Tested In: Linux Ubuntu/GNU Compiler/
*****************************************************************************/

#include "WTM.h"
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

/***************************************************************************************************/
void WTM::incrementTree(const string &new_word)
{
	//if iterator can not find new_word in tree
	//then new_word is added to key string value with data integer of 1
	if (tree.find(new_word) == tree.end())
	{
		tree[new_word] = 1;
	}

	//else new_word already exist in tree, so
	//add 1 to the data value for that particular word
	else
	{
		tree[new_word] = tree[new_word] + 1;
	}
}
/***************************************************************************************************/
void WTM::printTree()
{
	//sets iterator to beginning of tree, prints key string value and data integer
	//until the end of tree
	for (map<string, int>::iterator print_it = tree.begin(); print_it != tree.end(); ++print_it)
	{
		cout << print_it->first << " => " << print_it->second << '\n';
	}
}
/***************************************************************************************************/
void WTM::read_file(string file_name)
{
	 //open file
        ifstream infile(file_name.c_str());

	//if file is good
        if (infile)
        {
		string word;

		//while not end of file, 
		//get a line from file and insert into word
		while(getline(infile, word))
		{
			// Convert the string to lowercase
			transform(word.begin(), word.end(), word.begin(), ptr_fun <int, int> (tolower));
			
			//replace with white space if not alphabet
			replace_if(word.begin(), word.end(), not1(ptr_fun <int, int> (isalnum)), ' ');
			
			//string buffer input
			istringstream ss(word);
			
			//string buffer inserts characters into word until white
			//space, then word is added into incremenTree, string buffer repeats
			while(ss >> word)
				incrementTree(word);
		}
        }
	
	//else file can't be located or Invalid
	//and exits function
        else 
	{
		cerr << '\n' << "Invalid file" << '\n';
		return;
	}
        infile.close();
}
