#ifndef Actor_h
#define Actor_h
#include <iostream>
using namespace std;
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include "BSTree.h"
#include "Node.h"
//#include "BSTree.hpp"




class Actor
{
private:
	BSTree<ActorData, string> actorTree;
	std :: vector<ActorData> vector;
	Node<ActorData, string>* tempActorNode;
public:

	Actor();
	void inputFile(ifstream&);
	void userMenu();
	void add();
	void modify();
	void deleteFromTree();
	void searchingOptionMenu(string);
	void changeMenu(string, Node<ActorData, string>*);
	bool displayMenuAgain();
	void printVector();
	void exactSearch(string);
	void exactSearch(string, string);
	void partialSearch(string, string);
	void sort(string);
	//void checkChangedVal(Node<ActorData, string>*, ActorData);
	void printTree();
	void printToFile();
	void clearVector();
	void sortMenu();


};
#endif
