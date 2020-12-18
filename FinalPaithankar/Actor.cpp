#include <iostream>
using namespace std;

#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Actor.h"
/*
Pre: none
Post: none
Description: contructor of the program.
*/
Actor::Actor() {

}
/*
Pre: takes in if stream file
Post: none
Description: inputs all the information from the file and
stores it in a binary search tree
*/
void Actor::inputFile(ifstream& infile) {

	
	string line;
	stringstream ss;
	ActorData actor;
	//infile.open("actor-actress.csv");

	while (!infile.eof()) {

		getline(infile, line, ',');
		ss << line;
		ss >> actor.year;

		getline(infile, line, ',');
		actor.award = line;
		ss.clear();

		getline(infile, line, ',');
		ss << line;
		ss >> actor.winner;

		getline(infile, line, ',');
		actor.name = line;

		getline(infile, line);
		actor.film = line;

		actorTree.addNode(actor.name, actor);

	}
}
/*
Pre: none
Post: none
Description: This allows the user to choose the different options and
allow them to choose whether they want to add, change, delete or
modify from the stored info
*/
void Actor::userMenu()
{
	int input;
	string search, type;
	bool continueLoop = true;

	do
	{
		cout << "Enter number of the desired choice" << endl;
		cout << " 1. Search Name" << endl;
		cout << " 2. Search Winner" << endl;
		cout << " 3. Search Award" << endl;
		cout << " 4. Search Film" << endl;
		cout << " 5. Search Year" << endl;
		cout << " 6. Exit" << endl;

		cout << " -- Your choice is: ";
		cin >> input;
		cin.ignore(256, '\n');

		switch (input)
		{

		case 1:
		{
			cout << endl;
			cout << "Search Name" << endl;
			searchingOptionMenu("name");
			cout << endl;
			cout << "Search ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "Search Winner" << endl;
			searchingOptionMenu("winner");
			cout << endl;
			cout << "Search ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "Search Award" << endl;
			searchingOptionMenu("award");
			cout << endl;
			cout << "Search ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 4:
		{
			cout << endl;
			cout << "Search Film" << endl;
			searchingOptionMenu("film");
			cout << endl;
			cout << "Search ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 5:
		{
			cout << endl;
			cout << "Search Year" << endl;
			searchingOptionMenu("year");
			cout << endl;
			cout << "Search ";
			continueLoop = displayMenuAgain();
			break;

		}
		
		case 6:
		{
			continueLoop = false;
			break;
		}

		default:
			cout << "Your input was not valid. Try again" << endl;
			break;
		}

	} while (continueLoop);
}
/*
Pre : none
Post: retunr true if yes and returns false if no
Desc: this return true if the user wants to enter another option
and return false if they do not
*/
bool Actor::displayMenuAgain()
{
	char input;

	do {
		cout << " Do you want to choose again? Press y for yes and n for no" << endl;
		cin >> input;
		cin.ignore(256, '\n');
		input = tolower(input);
	} while (input != 'y' && input != 'n');

	input = tolower(input);

	if (input == 'y')
		return true;
	else
		return false;
}
/*
Pre : none
Post: none
Desc: prints vector which has been put inorder
*/
void Actor::printVector()
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << endl << endl;
		cout << "Name: " << vector[i].name << endl;
		cout << "Winner: " << vector[i].winner << endl;
		cout << "Year: " << vector[i].year << endl;
		cout << "Award: " << vector[i].award << endl;
		
		
		cout << "Film: " << vector[i].film << endl;
	}
}
/*
Pre : takes in the type of search they want to do it on
Post: none
Desc: asks the user if they want to do an exact or partial search,
and uses vectors to look them up
*/
void Actor :: searchingOptionMenu(string type)
{
	int input;
	string search;
	bool repeat = true;

	do
	{
		cout << "Enter number of the desired choice" << endl;
		cout << " 1. Search exact" << endl;
		cout << " 2. Search contains" << endl;
		cout << " 3. Exit" << endl;

		cout << " -- Your choice is: ";
		cin >> input;
		cin.ignore(256, '\n');

		switch (input)
		{
		case 1:
		{
			cout << endl;
			cout << "Search for exact... " << endl;
			cout << "Enter search: ";
			getline(cin, search);
			exactSearch(search,type);
			repeat = false;
			break;
		}

		case 2:
		{
			cout << endl;
			cout << "Search for contains... " << endl;
			cout << "Enter search: ";
			getline(cin, search);
			partialSearch(search, type);
			repeat = false;
			break;
		}
		case 3:
		{
			repeat = false;
			break;
		}

		default:
			cout << "Your input was not valid. Try again" << endl;
			break;
		}
	} while (repeat);
}

void Actor::exactSearch(string key)
{
	bool found = false;

	//Send exact search to tree
	if (actorTree.findAllNode(key, vector) != nullptr)
		found = true;

	if (found)
	{
		cout << endl;
		cout << "The following were the ones that were found in exact search " << endl;
		cout << endl << endl;
	}

	else
		cout << "No luck. There is nothing with this in the directory" << endl;
}
/*
Pre :  takes in a word to search and it's type
Post: none
Desc: does a partial search using vector
*/
void Actor :: partialSearch(string word, string type)
{
	//Read tree into vector
	actorTree.inorderVector(vector);

	//Define iterator for going through vector
	std::vector<ActorData>::iterator it = vector.begin();

	//If vector has items in it
	if (!vector.empty())
	{
		//If user chose name
		if (type == "name")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->name.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}
		if (type == "year")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->year.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "award")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->award.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "winner")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->winner.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "film")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->film.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}
	}

	//If there are no items to search
	else
		cout << "No luck, nothing was found." << endl;

	printVector();
}
/*
Pre : takes in the type they are searching for(name, year.. etc)
Post: none
Desc: conducts and exact search on the vector that is in order
*/
void Actor::exactSearch(string word, string type)
{
	std::vector<ActorData>::iterator it = vector.begin();

	if (type == "name")
	{
		//Prior search or vector has been sorted
		if (!vector.empty())
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].name != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		//word tree
		else
			exactSearch(word);
	}

	//If vector has items in it
	else if (!vector.empty())
	{
		//Read tree into vector
		actorTree.inorderVector(vector);

		//If user chose year
		if (type == "year")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].year != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		//If user chose award
		else if (type == "award")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].award != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		//If user chose winner
		else if (type == "winner")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].winner != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		//If user chose film
		else if (type == "film")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].film != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}
	}

	//If there are no items to word
	else
		cout << "There's nothing to word." << endl;
	    cout << "Your first exact word must be of key item, Name" << endl;

	printVector();
}

void Actor::add()
{
	ActorData newActor;

	cout << "Enter information about the actor" << endl << endl;

	cout << "Year: ";
	cin >> newActor.year;
	cin.ignore(256, '\n');

	cout << "Award: ";
	getline(cin, newActor.award);

	cout << "Winner: ";
	cin >> newActor.winner;
	cin.ignore(256, '\n');

	cout << "Name: ";
	getline(cin, newActor.name);

	cout << "Film: ";
	getline(cin, newActor.film);

	actorTree.addNode(newActor.name,newActor);
	actorTree.printInorder();
}
/*
Pre : none
Post: none
Desc: this uses a temporary node to search for the word and allows the user
to delete a certain node from the tree if it has been found
*/
void Actor::deleteFromTree()
{
	Node<ActorData, string>* tempNode = new Node<ActorData, string>;
	string word;

	//Clear the vector so we can get fresh info on next search
	vector.clear();

	//Get input from user
	cout << endl;
	cout << "Delete selected. " << endl;
	cout << "Search for a movie to delete" << endl;
	cout << "Search: ";
	getline(cin, word);

	if (actorTree.findNode(word) != nullptr)
	{
		//Find the node to modify
		tempNode->setData(actorTree.findNode(word)->Data());

		cout << endl;
		cout << "That node is deleted " << endl;
		cout << endl;

		//Delete the node
		actorTree.deleteNode(word);
	}
	else
	{
		cout << endl << "Couldn't find that" << endl;
		cout << "try again. " << endl << endl;;
	}
}
/*
Pre : nonde
Post: none
Desc: changes the tree node
*/
void Actor::modify()
{
	Node<ActorData, string>* tempNode = new Node<ActorData, string>;
	string search;

	//Clear the vector so we can get fresh info on next search
	vector.clear();

	//Get input from user
	cout << endl;
	cout << "Modify an entry" << endl;
	cout << "Search for an actors name to modify" << endl;
	cout << "Search: ";
	getline(cin, search);

	if (actorTree.findNode(search) != nullptr)
	{
		//Find the node to modify
		tempNode->setData(actorTree.findNode(search)-> Data());

		//Delete the 
		actorTree.deleteNode(search);

		//Show node data to user
		cout << endl;
		cout << "Year: " << tempNode-> Data().year << endl;
		cout << "Award: " << tempNode->Data().award << endl;
		cout << "Winner: " << tempNode->Data().winner << endl;
		cout << "Name: " << tempNode->Data().name << endl;
		cout << "Film: " << tempNode->Data().film << endl;

		//Send tempNode to modify menu
		changeMenu(search, tempNode);
	}
	else
	{
		cout << endl << "It does not exist" << endl;
		cout << "try again" << endl << endl;;
	}
}
void Actor:: changeMenu(string search, Node<ActorData, string>* tempNode)
{
    ActorData modified;
	int option;
	bool repeat = true;

	//User chooses data to access
	do
	{
		cout << endl;
		cout << "Enter number of the desired option" << endl;
		cout << " 1. Year" << endl;
		cout << " 2. Award" << endl;
		cout << " 3. Winner" << endl;
		cout << " 4. Name" << endl;
		cout << " 5. Film" << endl;
		cout << " 6. Exit" << endl;

		cout << " -- Your choice is: ";
		cin >> option;
		cin.ignore(256, '\n');

		switch (option)
		{
		case 1:
		{
			cout << "Year: ";
			cin >> modified.year;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << endl;
			cout << endl;
			cout << "Change ";

			if (!displayMenuAgain())
				repeat = false;
			break;
		}
		case 2:
		{
			cout << "Award: ";
			getline(cin, modified.award);

			//Modify again prompt
			cout << endl;
			cout << endl;
			cout << "Change ";

			if (!displayMenuAgain())
				repeat = false;
			break;
		}
		case 3:
		{
			cout << "Winner: ";
			cin >> modified.winner;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << endl;
			cout << endl;
			cout << "Change ";

			if (!displayMenuAgain())
				repeat = false;
			break;
		}
		case 4:
		{
			cout << "Name: ";
			getline(cin, modified.name);

			//Modify again prompt
			cout << endl;
			cout << endl;
			cout << "Change ";

			if (!displayMenuAgain())
				repeat = false;
			break;
		}
		case 5:
		{
			cout << "Film: ";
			getline(cin, modified.film);

			//Modify again prompt
			cout << endl;
			cout << endl;
			cout << "Change ";

			if (!displayMenuAgain())
				repeat = false;
			break;
		}
		case 6:
		{
			repeat = false;
			break;
		}
		default:
			cout << "Your input was not valid. Try again";
			break;
		}

	} while (repeat);

	//Verify if value has changed
	if (modified.year == "")

		modified.year = tempNode->Data().year;

	if (modified.award == "")

		modified.award = tempNode->Data().award;

	if (modified.winner == "")

		modified.winner = tempNode->Data().winner;

	if (modified.name == "")

		modified.name = tempNode->Data().name;

	if (modified.film == "")

		modified.film = tempNode->Data().film;

	actorTree.addNode(modified.name, modified);

	cout << endl;
	cout << "Updated entry" << endl << endl;
}
/*void Actor :: checkChangedVal(Node<ActorData, string>* tempNode, ActorData modified.film) {
	//Verify if value has changed
	if (modified.year == "")
		modified.year = tempNode->Data().year;
	if (modified.award == "")
		modified.award = tempNode->Data().award;
	if (modified.winner == "")
		modified.winner = tempNode->Data().winner;
	if (modified.name == "")
		modified.name = tempNode->Data().name;
	if (modified.film == "")
		modified.film = tempNode->Data().film;
}
*/
/*
Pre : takes in the type they want to sort
Post: none
Desc: has if statements to sort the vector
*/
void Actor::sort(string field)
{
	//Read tree into vector
	actorTree.inorderVector(vector);

	if (vector.empty())
		cout << "There's nothing to sort" << endl << endl;

	else
	{
		//Selection sort
		unsigned long size = vector.size();

		//Sort by name
		if (field == "year")
		{
			//Selection sort for vector
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].year > vector[index].year)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].year, vector[minCount].year);
			}
		}

		//Sort by award
		if (field == "award")
		{
			//Selection sort
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].award > vector[index].award)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].award, vector[minCount].award);
			}
		}

		//Sort by winner
		if (field == "winner")
		{
			//Selection sort
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].winner > vector[index].winner)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].winner, vector[minCount].winner);
			}
		}

		//Sort by name
		if (field == "name")
		{
			//Selection sort
			unsigned long size = vector.size();

			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].name > vector[index].name)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].name, vector[minCount].name);
			}
		}

		//Sort by film
		if (field == "film")
		{
			//Selection sort
			unsigned long size = vector.size();

			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].film > vector[index].film)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].film, vector[minCount].film);
			}
		}
		//Show sorted vector

		printVector();
	}
}
/*
Pre : takes in temp node to change it
Post: none
Desc: chnages a certain node if it is found in the tree.
*/
void Actor :: printTree() {
	actorTree.printInorder();
}
/*
Pre : none
Post: none
Desc: outputs to a file
*/
void Actor ::printToFile()
{
	ofstream output("pictures.txt");

	//Iterate through the vector to print all
	std::vector<ActorData>::iterator it;
		for (it = vector.begin(); it != vector.end(); it++)
		{
			output << "Year: " << it->year << endl;
			output << "Award: " << it->award << endl;
			output << "Winner: " << it->winner << endl;
			output << "Name: " << it->name << endl;
			output << "Film: " << it->film << endl << endl;
		}

}
/*
Pre : none
Post: none
Desc: clears and creates space for info in vector
*/
void Actor::clearVector()
{
	vector.clear();
}
void Actor::sortMenu() {
	//Call to sort
	int input;
	string search, type;
	bool continueLoop = true;

	cout << "Enter number of the desired choice" << endl;
	cout << " 1. Sort by Name" << endl;
	cout << " 2. Sort Winner" << endl;
	cout << " 3. Sort Award" << endl;
	cout << " 4. Sort Film" << endl;
	cout << " 5. Sort Year" << endl;
	cout << " 6. Exit" << endl;

	cout << " -- Your choice is: ";
	cin >> input;
	cin.ignore(256, '\n');

	switch (input)
	{

	case 1:
	{
		cout << endl;
		cout << "You chose sort by name" << endl;
		sort("name");
		cout << endl;
		continueLoop = false;
		break;
	}
	case 2:
	{
		cout << endl;
		cout << "You chose sort by winner" << endl;
		sort("winner");
		cout << endl;
		continueLoop = false;
		break;
	}
	case 3:
	{
		cout << endl;
		cout << "You chose sort by award " << endl;
		sort("award");
		cout << endl;
		continueLoop = false;
		break;
	}
	case 4:
	{
		cout << endl;
		cout << "You chose sort by film" << endl;
		sort("film");
		cout << endl;
		continueLoop = false;
		break;
	}
	case 5:
	{
		cout << endl;
		cout << "You chose sort by year" << endl;
		sort("year");
		cout << endl;
		continueLoop = false;
		break;

	}

	case 6:
	{
		continueLoop = false;
		break;
	}

	default:
		cout << "Your input was not valid. Try again" << endl;
		break;
	}
}