#include <iostream>
#include <fstream>
using namespace std;
#include "BSTree.h"
//#include "BSTree.hpp"
#include "Actor.h"
#include "Picture.h"
void start();

int main()
{
	start();

	return 0;
}
/*
pre : none
post : none
Desc: This file starts the program and calls on menu functions and other ones to get the program going. 
*/
void start()
{
	
	ifstream actorFile, pictureFile;
	Actor actor;
	Picture picture;
	string header;

	int option;
	bool continueLoop = true;
	do
	{
		//Main menu
		cout << endl;
		
		cout << " 1. Read Actor File" << endl;
		cout << " 2. Read Picture File" << endl;
		cout << " 3. Add Data" << endl;
		cout << " 4. Modify Data" << endl;
		cout << " 5. Delete Data" << endl;
		cout << " 6. Search" << endl;
		cout << " 7. Sort" << endl; //make sort menu
		cout << " 8. Print Search/Sort to File" << endl;
		cout << " 9. Clear Last Search/Sort" << endl << endl;
		cout  << endl << endl;

		cout << "Enter your choice here : ";
		cin >> option;
		cin.ignore(256, '\n');

		switch (option)
		{
			//Call to read-in actors file
		case 1:
		{
			//Open actors file
			actorFile.open("actor-actress.csv");
			//Read actor header
			getline(actorFile, header);
			//Read actors file
			while (!actorFile.eof())
				actor.inputFile(actorFile); 	
			cout << "The tree in order " << endl;
			actor.printTree();
			break;
		}

		//Call to read-in pictures file
		case 2:
		{
			//Open actors file
			pictureFile.open("pictures.csv");
			//Read actor header
			getline(pictureFile, header);
			//Read actors file
			while (!pictureFile.eof())
				picture.inputFile(pictureFile);
			picture.printTree();
			break;
		}

		//Add new node to tree-database
		case 3:
		{
			cout << endl;
	
			cout << "Choose between :" << endl;
			cout << " 1. Add to actors database" << endl;
			cout << " 2. Add to pictures database" << endl;
			cout << " 3. Exit" << endl;

			cout << " Enter choice here : ";
			cin >> option;
			cin.ignore(256, '\n');
			cout << endl;
			switch (option)
			{
			case 1:
			{
				//Call to add to actors tree
				actor.add();
				break;
			}

			case 2:
			{
				//Call to add to pictures tree
				picture.add();
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Your input was not valid. Try again";
				break;
			}
			break;
		}

		//Modify tree-database contents
		case 4:
		{
			cout << endl;
			cout << "Choose between :" << endl;
			cout << " 1. Modify actors database" << endl;
			cout << " 2. Modify pictures database" << endl;
			cout << " 3. Exit" << endl;

			cout << "Enter your choice ";
			cin >> option;
			cin.ignore(256, '\n');
			cout << endl;
			switch (option)
			{
			case 1:
			{
				//Call to modify actors tree
				actor.modify();
				break;
			}
			case 2:
			{
				//Call to modify pictures tree
				picture.modify();
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Your input was not valid. Try again";
				break;
			}
			break;
		}

		case 5:
		{
			cout << endl;
			cout << endl << endl;
			cout << "Choose option" << endl;
			cout << " 1. Delete from actors database" << endl;
			cout << " 2. Delete from pictures database" << endl;
			cout << " 3. Exit" << endl;

			cout << "Enter your choice : ";
			cin >> option;
			cin.ignore(256, '\n');

			cout << endl;
			switch (option)
			{
			case 1:
			{
				//Call to search actors
				actor.deleteFromTree();
				break;
			}
			case 2:
			{
				//Call to search pictures
				picture.deleteFromTree();
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Your input was not valid. Try again";
				break;
			}
			break;
		}
		//Choose which to search
		case 6:
		{
			cout << endl;
			cout << "choose option" << endl;
			cout << " 1. Search actors database" << endl;
			cout << " 2. Search pictures database" << endl;
			cout << " 3. Exit" << endl;

			cout << " Enter your choice : ";
			cin >> option;
			cin.ignore(256, '\n');
			cout << endl;
			switch (option)
			{
			case 1:
			{
				//Call to search actors
				actor.userMenu();
				break;
			}
			case 2:
			{
				//Call to search pictures
				picture.userMenu();
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Your input was not valid. Try again";
				break;
			}
			break;
		}
		//Sort searches
		case 7:
		{
			cout << endl;
			cout << endl << endl;
			cout << "Choose between " << endl;
			cout << " 1. Actors sort" << endl;
			cout << " 2. Pictures sort" << endl;
			cout << " 3. Exit" << endl;

			cout << " Enter your choice: ";
			cin >> option;
			cin.ignore(256, '\n');
			cout << endl;
			switch (option)
			{
			case 1:
			{
				actor.sortMenu();
				break;
			}
			case 2:
			{
				//Call to sort
				picture.sortMenu();
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Your input was not valid. Try again";
				break;
			}
			break;
		}
		//Print searches to file
		case 8:
		{
			cout << endl;
			cout << endl << endl;
			cout << "Choose between :" << endl;
			cout << " 1. Print actors search" << endl;
			cout << " 2. Print pictures search" << endl;
			cout << " 3. Exit" << endl;

			cout << " Enter your choice : ";
			cin >> option;
			cin.ignore(256, '\n');
			cout << endl;
			switch (option)
			{
			case 1:
			{
				//Call to print actors search
				actor.printToFile();
				break;
			}
			case 2:
			{
				//Call to print
				picture.printToFile();
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Your input was not valid. Try again";
				break;
			}
			break;
		}
		case 9:
		{
			actor.clearVector();
			picture.clearVector();
			break;
		}
		default:
		{
			cout << "Your input was not valid. Try again";
			break;
		}
		}
	} while (continueLoop);
}
