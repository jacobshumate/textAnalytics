/*****************************************************************************
 * File: driver.cpp

 * Name: Jacob Shumate

 * Purpose: driver file for program demonstrating a word tree map class.
   driver also prompts user for input with multiple different choices and 
   continues to ask user until the user selects the choice of exiting the 
   program. For each choice contains different member functions from class 
   WTM. 

 * Instructions for use: 
   Once compiled
   To execute: directory/output_name
   Program will execute and print out
   1-3 choices for the user to select.
   Only integers 1-3 will execute the options.


 * Compile: g++ -c WTM.cpp driver.cpp
   g++ WTM.o driver.o - o <output_name>

 * Tested In: Linux Ubuntu/GNU Compiler/
*****************************************************************************/

#include "WTM.h"
#include <iostream>
#include <string> 

using namespace std;

//Enum containing menu option constants 
enum e_menu_options {READ_FILE = 1, PRINT_TREE, EXIT_MENU};

void printMenu()
{
                //Print menu 
                cout << '\n' << "STL Map Database Demo. Select one of the following options:" << "\n\n";
                cout << READ_FILE << " Read words from text file" << '\n';
		cout << PRINT_TREE << " Print statistics of word usage from file" << '\n';
		cout << EXIT_MENU << " Exit this program" << '\n';
}

//Get an int corresponding to a menu choice   
int getMenuChoice()
{
        int choice;

        cin >> choice;
        cin.clear();
        cin.ignore( 255, '\n' );
        return choice;

}

//Users choice and database is passed into
//to call WTM member functions to corresponding integer of choice
void runChoice(int choice, WTM &database)
{

        string str;

        //Process the user's choice from the menu and call the appropriate method 
        switch (choice)
        {
                case READ_FILE:  cout << '\n' << "Enter a filename: ";
				 cin >> str;
				 database.read_file(str);
				 break;
                
		case PRINT_TREE: cout << '\n' << "Printing statistics..." << '\n';
                        	 database.printTree();
				 break;

                default: 	 cout << '\n' << "Invalid choice" << '\n';
	}
}

int main()
{
        //Declare WTM class
        WTM database;

        //Run menu until user enters the exit constant 
        int choice;
        do
        {
                printMenu();
                std::cout << '\n' << "Please enter a choice: " ;
                choice = getMenuChoice();

                if (choice != EXIT_MENU)
                        
			runChoice(choice, database);

        } while (choice != EXIT_MENU);


        return 0;
}



