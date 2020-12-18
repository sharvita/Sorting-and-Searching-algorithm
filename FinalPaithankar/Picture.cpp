#include <ctype.h>

#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Picture.h"
/*
Pre: none 
Post: none 
Description: contructor of the program.
*/
Picture::Picture()
{
	//left blank on purpose
}
/*
Pre: takes in if stream file 
Post: none 
Description: inputs all the information from the file and 
             stores it in a binary search tree
*/
void Picture:: inputFile(ifstream& infile)
{
	
	string line;
	stringstream ss;
	PictureData picture;
	infile.open("");

	//Gets line
	getline(infile, line, ',');
	//If the line is empty, place nothing
	if (line.empty())
		picture.name = "";
	else
	{
		//Erase that beginning space
		line.erase(line.begin());
		//Traverses line
		for (int i = 0; i < line.length(); i++)
		{
			//If not a good character erase
			if (!isalnum(line[i]))
			{
				if (line[i] == ' ')
					continue;
				if (line[i] == ',')
					continue;
				if (line[i] == '"')
					continue;
				if (line[i] == '.')
					continue;
				else
				{
					line.erase(i);
					--i;
				}
			}
		}
	}

	picture.name = line;

	getline(infile, line, ',');
	if (line.empty())
		picture.year = "";
	else
	{
		ss << line;
		ss >> line;
	}
	picture.year = line;

	getline(infile, line, ',');
	if (line.empty())
		picture.nominations = "";
	else
	{
		ss << line;
		ss >> line;
	}
	picture.nominations = line;

	getline(infile, line, ',');
	for (int i = 0; i < line.length(); i++)
		if (!line.empty())
			picture.rating = "";
		else
		{
			ss << line;
			ss >> line;
		}
	picture.rating = line;

	getline(infile, line, ',');
	if (line.empty())
		picture.duration = "";
	else
	{
		ss << line;
		ss >> line;
	}
	picture.duration = line;

	getline(infile, line, ',');
	if (line.empty())
		picture.genre1 = "";
	else
	{
		for (int i = 0; i < line.length(); i++)
		{

			if (!isalnum(line[i]))
			{
				if (line[i] == ' ')
					continue;
				if (line[i] == ',')
					continue;
				if (line[i] == '"')
					continue;
				if (line[i] == '.')
					continue;
				else
				{
					line.erase(i);
					--i;
				}
			}
		}
	}
	picture.genre1 = line;

	getline(infile, line, ',');
	if (line.empty())
		picture.genre2 = "";
	else
	{
		for (int i = 0; i < line.length(); i++)
		{

			if (!isalnum(line[i]))
			{
				if (line[i] == ' ')
					continue;
				if (line[i] == ',')
					continue;
				if (line[i] == '"')
					continue;
				if (line[i] == '.')
					continue;
				else
				{
					line.erase(i);
					--i;
				}
			}
		}
	}
	picture.genre2 = line;

	getline(infile, line, ',');
	if (line.empty())
		picture.release = "";
	else
	{
		for (int i = 0; i < line.length(); i++)
		{

			if (!isalnum(line[i]))
			{
				if (line[i] == ' ')
					continue;
				if (line[i] == ',')
					continue;
				if (line[i] == '"')
					continue;
				if (line[i] == '.')
					continue;
				else
				{
					line.erase(i);
					--i;
				}
			}
		}
	}
	picture.release = line;
	ss.clear();

	getline(infile, line, ',');
	if (line.empty())
		picture.metacritic = "";
	else
	{
		for (int i = 0; i < line.length(); i++)
		{

			if (!isalnum(line[i]))
			{
				if (line[i] == ' ')
					continue;
				if (line[i] == ',')
					continue;
				if (line[i] == '"')
					continue;
				if (line[i] == '.')
					continue;
				else
				{
					line.erase(i);
					--i;
				}
			}
		}
	}
	picture.metacritic = line;

	getline(infile, line, '\n');
	if (line.empty())
		picture.synopsis = "";
	else
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (!isalnum(line[i]))
			{
				if (line[i] == ' ')
					continue;
				if (line[i] == ',')
					continue;
				if (line[i] == '"')
					continue;
				if (line[i] == '.')
					continue;
				else
				{
					line.erase(i);
					--i;
				}
			}
		}
	}
	picture.synopsis = line;

	pictureTree.addNode(picture.name, picture);
}
/*
Pre: none 
Post: none 
Description: This allows the user to choose the different options and 
             allow them to choose whether they want to add, change, delete or 
			 modify from the stored info
*/
void Picture:: userMenu()
{
	int input;
	string search, type;
	bool continueLoop = true;

	//User chooses data to access
	do
	{
		cout << endl;
		cout << "Enter number of your choice" << endl;
		cout << " 1. Name" << endl;
		cout << " 2. Year" << endl;
		cout << " 3. Nominations" << endl;
		cout << " 4. Rating" << endl;
		cout << " 5. Duration" << endl;
		cout << " 6. Genre 1" << endl;
		cout << " 7. Genre 2" << endl;
		cout << " 8. Release" << endl;
		cout << " 9. Metacritic" << endl;
		cout << " 10. Synopsis" << endl;

		cin >> input;
		cin.ignore(256, '\n');

		switch (input)
		{
		case 1:
		{
			cout << "\nSearch Name" << endl;
			searchingOptionMenu("name");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 2:
		{
			cout << "\nSearch Year" << endl;
			searchingOptionMenu("year");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 3:
		{
			cout << "\nSearch Nominations" << endl;
			searchingOptionMenu("nominations");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 4:
		{
			cout << "\nSearch Rating" << endl;
			searchingOptionMenu("rating");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 5:
		{
			cout << "\nSearch Duration" << endl;
			searchingOptionMenu("duration");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 6:
		{
			cout << "\nSearch Genre 1" << endl;
			searchingOptionMenu("genre1");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 7:
		{
			cout << "\nSearch Genre 2" << endl;
			searchingOptionMenu("genre2");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 8:
		{
			{
				cout << "\nSearch Release" << endl;
				searchingOptionMenu("release");
				cout << "\nSearch ";
				continueLoop = displayMenuAgain();
				break;
			}
		}
		case 9:
		{
			cout << "\nSearch Metacritic" << endl;
			searchingOptionMenu("metacritic");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		case 10:
		{
			cout << "\nSearch Duration" << endl;
			searchingOptionMenu("duration");
			cout << "\nSearch ";
			continueLoop = displayMenuAgain();
			break;
		}
		default:
			cout << "Your input was not valid. Try again";
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

bool Picture::displayMenuAgain()
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
void Picture::printVector()
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << endl << endl;
		cout << "Name: " << vector[i].name << endl;
		cout << "Year: " << vector[i].year << endl;
		cout << "Nominations: " << vector[i].nominations << endl;
		cout << "Rating: " << vector[i].rating << endl;
		cout << "Duration: " << vector[i].duration << endl;
		cout << "Genre 1: " << vector[i].genre1 << endl;
		cout << "Genre 2: " << vector[i].genre2 << endl;
		cout << "Release: " << vector[i].release << endl;
		cout << "Metacritic: " << vector[i].metacritic << endl;
		cout << "Synopsis: " << vector[i].synopsis << endl;
	}
}
/*
Pre : none
Post: none
Desc: this uses a temporary node to search for the word and allows the user
      to delete a certain node from the tree if it has been found
*/
void Picture:: deleteFromTree()
{
	Node<PictureData, string>* tempNode = new Node<PictureData, string>;
	string word;

	//Clear the vector so we can get fresh info on next search
	vector.clear();

	//Get input from user
	cout << "\nDelete an entry" << endl;
	cout << "Search for a films name to delete" << endl;
	cout << "Search: ";
	getline(cin, word);

	//search for node 
	if (pictureTree.findNode(word) != nullptr)
	{
		//Find the node to modify
		tempNode->setData(pictureTree.findNode(word)->Data());

		cout << endl;
		cout << "That node is deleted " << endl;
		cout << endl;

		//Delete the node
		pictureTree.deleteNode(word);
	}
	else
	{
		cout << endl << "Couldn't find that" << endl;
		cout << "try again. " << endl << endl;;
	}
	
}
/*
Pre : takes in the type of search they want to do it on 
Post: none
Desc: asks the user if they want to do an exact or partial search,
      and uses vectors to look them up
*/
void Picture :: searchingOptionMenu(string type) {
	int input;
	string search;
	bool continueLoop = true;

	do
	{
		cout << "Enter number of the desired input" << endl;
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
			cout << "\nSearch for exact... " << endl;
			cout << "Enter search: ";
			getline(cin, search);

			exactSearch(search, type);

			continueLoop = false;
			break;
		}

		case 2:
		{
			cout << "\nSearch for contains... " << endl;
			cout << "Enter search: ";
			getline(cin, search);

			partialSearch(search, type);

			continueLoop = false;
			break;
		}

		case 3:
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
Pre : takes in the type they are searching for(name, year.. etc)
Post: none 
Desc: conducts and exact search on the vector that is in order 
*/
void Picture::exactSearch(string key)
{
	bool found = false;

	//Send exact search to tree
	if (pictureTree.findAllNode(key, vector) != nullptr)
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
void Picture::partialSearch(string word, string type)
{
	//Read tree into vector
	pictureTree.inorderVector(vector);

	//Define iterator for going through vector
	std::vector<PictureData>::iterator it = vector.begin();

	//If vector has items in it
	if (!vector.empty())
	{
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

		else if (type == "nominations")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->nominations.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "rating")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->rating.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "duration")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->duration.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "genre1")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->genre1.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "genre2")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->genre2.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "release")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->release.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "metacritic")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->metacritic.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "synopsis")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (it->synopsis.find(word) == string::npos)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}
	}


	else
		cout << "No luck. Nothing was found" << endl;

	printVector();
}
/*
Pre : takes in a word to search and its type
Post: none
Desc: does an exact search using vectors
*/
void Picture::exactSearch(string word, string type)
{
	//Define iterator for going through vector
	std::vector<PictureData>::iterator it = vector.begin();

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
		pictureTree.inorderVector(vector);

		if (type == "name")
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

		else if (type == "year")
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

		else if (type == "nominations")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].nominations != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "rating")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].rating != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "duration")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].duration != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "genre1")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].genre1 != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "genre2")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].genre2 != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "release")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].release != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "metacritic")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].metacritic != word)
					it = vector.erase(it); 
				else
				{
					it++; pos++;
				}
			}
		}

		else if (type == "synopsis")
		{
			for (int pos = 0; it != vector.end(); )
			{
				if (vector[pos].synopsis != word)
					it = vector.erase(it);
				else
				{
					it++; pos++;
				}
			}
		}
	}

	//If there are no items to word
	else {
		cout << "There's nothing to word." << endl;
		cout << "Your first exact word must be of key item, Name" << endl;
	}
	printVector();
}
/*
Pre : takes in the type they want to sort
Post: none
Desc: has if statements to sort the vector 
*/
void Picture::sort(string type)
{
	//Read tree into vector
	pictureTree.inorderVector(vector);

	if (vector.empty())
		cout << "There's nothing to sort" << endl;

	else
	{
		//Selection sort
		unsigned long size = vector.size();

		//Sort by name
		if (type == "name")
		{
			//Selection sort the vector
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
		if (type == "year")
		{
			//Selection sort
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

		if (type == "nominations")
		{
			//Selection sort
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].nominations > vector[index].nominations)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].nominations, vector[minCount].nominations);
			}
		}

		if (type == "rating")
		{
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].rating > vector[index].rating)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].rating, vector[minCount].rating);
			}
		}

		if (type == "duration")
		{
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].duration > vector[index].duration)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].duration, vector[minCount].duration);
			}
		}

		if (type == "genre1")
		{
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].genre1 > vector[index].genre1)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].genre1, vector[minCount].genre1);
			}
		}

		if (type == "genre2")
		{
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].genre2 > vector[index].genre2)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].genre2, vector[minCount].genre2);
			}
		}

		if (type == "release")
		{
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].release > vector[index].release)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].release, vector[minCount].release);
			}
		}

		if (type == "metacritic")
		{
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].metacritic > vector[index].metacritic)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].metacritic, vector[minCount].metacritic);
			}
		}

		if (type == "synopsis")
		{
			for (int i = 0; i < size - 1; i++)
			{
				int minCount = i;
				for (int index = i + 1; index < size; index++)
				{
					if (vector[minCount].synopsis > vector[index].synopsis)
						minCount = index;
				}

				if (minCount != i)
					swap(vector[i].synopsis, vector[minCount].synopsis);
			}
		}
		
		printVector();
	}
}
/*
Pre : none 
Post: none 
Desc: prints the tree in order
*/
void Picture:: printTree()
{
	pictureTree.printInorder();
}
/*
Pre : takes in temp node to change it 
Post: none
Desc: chnages a certain node if it is found in the tree. 
*/
void Picture::changeMenu(string search, Node<PictureData, string>* tempNode) {
	PictureData modified;
	int option;
	bool continueLoop = true;

	//User chooses data to access
	do
	{
		cout << endl;
		cout << "Enter number of the desired option" << endl;
		cout << " 1. Name" << endl;
		cout << " 2. Year" << endl;
		cout << " 3. Nominations" << endl;
		cout << " 4. Rating" << endl;
		cout << " 5. Duration" << endl;
		cout << " 6. Genre 1" << endl;
		cout << " 7. Genre 2" << endl;
		cout << " 8. Release" << endl;
		cout << " 9. Metacritic" << endl;
		cout << " 10. Synopsis" << endl;
		cout << " 11. Exit" << endl;

		cout << " -- Your choice is: ";
		cin >> option;
		cin.ignore(256, '\n');

		switch (option)
		{
		case 1:
		{
			cout << "Name: ";
			cin >> modified.name;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "Modify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 2:
		{
			cout << "Year: ";
			cin >> modified.year;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 3:
		{
			cout << "Nominations: ";
			cin >> modified.nominations;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 4:
		{
			cout << "Rating: ";
			cin >> modified.rating;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 5:
		{
			cout << "Duration: ";
			cin >> modified.duration;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 6:
		{
			cout << "Genre 1: ";
			cin >> modified.genre1;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 7:
		{
			cout << "Genre 2: ";
			cin >> modified.genre2;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 8:
		{
			cout << "Release: ";
			cin >> modified.release;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 9:
		{
			cout << "Metacritic: ";
			cin >> modified.metacritic;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 10:
		{
			cout << "Duration: ";
			cin >> modified.duration;
			cin.ignore(256, '\n');

			//Modify again prompt
			cout << "\n\nModify";

			if (!displayMenuAgain())
				continueLoop = false;
			break;
		}
		case 11:
		{
			continueLoop = false;
			break;
		}
		default:
			cout << "Your input was not valid. Try again";
			break;
		}

	} while (continueLoop);

	//Check against beginning value to know what to change
	if (modified.name == "")

		modified.name = tempNode->Data().name;

	if (modified.year == "")

		modified.year = tempNode->Data().year;

	if (modified.nominations == "")
		modified.nominations = tempNode->Data().nominations;
	if (modified.rating == "")
		modified.rating = tempNode->Data().rating;
	if (modified.duration == "")
		modified.duration = tempNode->Data().duration;
	if (modified.genre1 == "")
		modified.genre1 = tempNode->Data().genre1;
	if (modified.genre2 == "")
		modified.genre2 = tempNode->Data().genre2;
	if (modified.release == "")
		modified.release = tempNode->Data().release;
	if (modified.metacritic == "")
		modified.metacritic = tempNode->Data().metacritic;
	if (modified.synopsis == "")
		modified.synopsis = tempNode->Data().synopsis;

	pictureTree.addNode(modified.name, modified);

	cout << "\nUpdated entry" << endl;
}
/*
Pre : none
Post: none
Desc: adds to tree
*/
void Picture::add()
{
	PictureData newPicture;

	cout << "Enter each type below" << endl << endl;

	cout << "Name of the picture: ";
	getline(cin, newPicture.name);

	cout << "Year of the picture: ";
	cin >> newPicture.year;
	cin.ignore(256, '\n');

	cout << "Nominations of the picture: ";
	getline(cin, newPicture.nominations);

	cout << "Rating of the picture: ";
	cin >> newPicture.rating;
	cin.ignore(256, '\n');

	cout << "Duration of the picture: ";
	getline(cin, newPicture.duration);

	cout << "Genre 1 of the picture: ";
	getline(cin, newPicture.genre1);

	cout << "Genre 2 of the picture: ";
	getline(cin, newPicture.genre2);

	cout << "Release of the picture: ";
	getline(cin, newPicture.release);

	cout << "Metacritic of the picture: ";
	getline(cin, newPicture.metacritic);

	cout << "Synopsis of the picture: ";
	getline(cin, newPicture.genre1);

	pictureTree.addNode(newPicture.name, newPicture);
}
/*
Pre : nonde
Post: none
Desc: changes the tree node
*/
void Picture::modify()
{
	Node<PictureData, string>* tempNode = new Node<PictureData, string>;
	string search;

	//Clear the vector so we can get fresh info on next search
	vector.clear();

	//Get input from user
	cout << "\nModify an entry" << endl;
	cout << "Search for a films name to modify" << endl;
	cout << "Search: ";
	getline(cin, search);

	if ((pictureTree.findNode(search)) != nullptr)
	{
		//Find the node to modify
		tempNode->setData(pictureTree.findNode(search)->Data());

		//Delete the
		pictureTree.deleteNode(search);

		//Send tempNode to modify menu
		changeMenu(search, tempNode);
	}
	else
	{
		cout << endl << "Couldn't find that" << endl;
		cout << "Please be more exact next time" << endl << endl;;
	}
}
/*
Pre : none
Post: none
Desc: outputs to a file 
*/
void Picture::printToFile()
{
	ofstream output("pictures.txt");

	//Iterate through the vector to print all
	std::vector<PictureData>::iterator it;
	for (it = vector.begin(); it != vector.end(); it++)
	{
		output << "\n";
		output << "Name: " << it->name << endl;
		output << "Year: " << it->year << endl;
		output << "Nominations: " << it->nominations << endl;
		output << "Rating: " << it->rating << endl;
		output << "Duration: " << it->duration << endl;
		output << "Genre 1: " << it->genre1 << endl;
		output << "Genre 2: " << it->genre2 << endl;
		output << "Release: " << it->release << endl;
		output << "Metacritic: " << it->metacritic << endl;
		output << "Synopsis: " << it->synopsis << endl;
	}

}
/*
Pre : none
Post: none
Desc: clears and creates space for info in vector 
*/
void Picture::clearVector()
{
	vector.clear();
}
void Picture ::sortMenu() {
	int input;
	string search, type;
	bool continueLoop = true;

	//User chooses data to access
	do
	{
		cout << endl;
		cout << "Enter number of your choice" << endl;
		cout << " 1. Name" << endl;
		cout << " 2. Year" << endl;
		cout << " 3. Nominations" << endl;
		cout << " 4. Rating" << endl;
		cout << " 5. Duration" << endl;
		cout << " 6. Genre 1" << endl;
		cout << " 7. Genre 2" << endl;
		cout << " 8. Release" << endl;
		cout << " 9. Metacritic" << endl;
		cout << " 10. Synopsis" << endl;

		cin >> input;
		cin.ignore(256, '\n');

		switch (input)
		{
		case 1:
		{
			cout << "Sort Name" << endl;
			sort("name");
			continueLoop = false;
			break;
		}
		case 2:
		{
			cout << "Sort Year" << endl;
			sort("year");
			continueLoop = false;
			break;
		}
		case 3:
		{
			cout << "Sort Nominations" << endl;
			sort("nominations");
			continueLoop = false;
			break;
		}
		case 4:
		{
			cout << "Sort Rating" << endl;
			sort("rating");
			continueLoop = false;
			break;
		}
		case 5:
		{
			cout << "Sort Duration" << endl;
			sort("duration");
			continueLoop = false;
			break;
		}
		case 6:
		{
			cout << "Sort Genre 1" << endl;
			sort("genre1");
		
			continueLoop = false;
			break;
		}
		case 7:
		{
			cout << "Sort Genre 2" << endl;
			sort("genre2");
			continueLoop = false;
			break;
		}
		case 8:
		{
			{
				cout << "Sort Release" << endl;
				sort("release");
				
				continueLoop = false;
				break;
			}
		}
		case 9:
		{
			cout << "Sort Metacritic" << endl;
			sort("metacritic");

			continueLoop = false;
			break;
		}
		case 10:
		{
			cout << "Sort Duration" << endl;
			sort("duration");
			
			continueLoop = false;
			break;
		}
		default:
			cout << "Your input was not valid. Try again";
			break;
		}

	} while (continueLoop);
}