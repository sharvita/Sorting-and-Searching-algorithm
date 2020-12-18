#ifndef Picture_h
#define Picture_h

#include <iostream>
using namespace std;
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include "BSTree.h"
#include "Node.h"
//#include "BSTree.hpp"



class Picture
{
private:
	BSTree<PictureData, string> pictureTree;
	std::vector<PictureData> vector;
	Node<PictureData, string>* tempPictureNode;
public:

	Picture();
	void inputFile(ifstream&);
	void userMenu();
	void add();
	void modify();
	void deleteFromTree();
	void searchingOptionMenu(string);
	void changeMenu(string, Node<PictureData, string>*);
	bool displayMenuAgain();
	void printVector();
	void exactSearch(string);
	void exactSearch(string, string);
	void partialSearch(string, string);
	void sort(string);
	void checkChangedVal(Node<PictureData, string>*, PictureData);
	void printTree();
	void printToFile();
	void clearVector();
	void sortMenu();


};
#endif
