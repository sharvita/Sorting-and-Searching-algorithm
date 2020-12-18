//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.h"

// Constructor
//template <typename DATATYPE, typename KEYTYPE>
//BSTree<DATATYPE, KEYTYPE>::BSTree() {
//	root = nullptr;
//}
// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
	//Student must fill in
	//if the root is the leaf, delete that leaf
	if (Root() == leaf)
		delete leaf;
	// otherwise if the leaf is not null
	else if (leaf != NULL)
	{
		//recursive call of the leaf's left
		freeNode(leaf->Left());
		//recursive call of the leaf's right
		freeNode(leaf->Right());
		//now delete the leaf
		delete leaf;
	}
    
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);

	}
	else
		addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
	//Student must fill in
	//Don't forget to set your key, Parent, then left or right
	//Based on the case you use you will addNode recursively to the left or right

	//First check if root is null
	if (root == NULL) {
		//make a new node
		Node<DATATYPE, KEYTYPE> * newNode = new Node<DATATYPE, KEYTYPE>;
		//set the key and data
		newNode->setKey(key);
		newNode->setData(data);
		//set the root
		root = newNode;
	}
	//Otherwise
	//Check to see if the key is < the leaf's key
	else if (key < leaf->Key()) {
		// if left is not null then
		if (leaf->Left() != NULL) {
			//Add the node to the left (recursively)
			addNode(key, leaf->Left(), data);
		}
		else {// Otherwise make a new node and attach it to the left
			Node<DATATYPE, KEYTYPE> *tempNode = new Node<DATATYPE, KEYTYPE>;
			tempNode->setKey(key);
			tempNode->setData(data);
			leaf->setLeft(tempNode);
		}
	}

	//Check to see if the key >= leaf's key
	if (key >= leaf->Key())
	{
		// if leaf's right is not null then
		if (leaf->Right() != NULL)
		{
			//Add the node to the right (recursively)
			addNode(key, leaf->Right(), data);
		}
		else
		{
			// Otherwise make new node and attach it to the right
			Node<DATATYPE, KEYTYPE> *tempNode = new Node<DATATYPE, KEYTYPE>;
			tempNode->setKey(key);
			tempNode->setData(data);
			leaf->setRight(tempNode);
		}
	}
			
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
	//Student must fill in
	// trap nullptr first in case we've hit the end unsuccessfully.
	// success base case
	//Greater than (Right), Less than (Left)

	Node<DATATYPE, KEYTYPE> *currentNode = node;
	if (currentNode->Right() == NULL && currentNode->Left() == NULL && currentNode->Key() != key)
		return nullptr;
	if (currentNode != NULL)
	{
		if (currentNode->Key() == key)
		{
			return currentNode;
		}
		if (currentNode->Key() < key && currentNode->Right() != NULL)
		{
			findNode(key, currentNode->Right());
		}
		else if (currentNode->Key() > key && currentNode->Left() != NULL)
		{
			findNode(key, currentNode->Left());
		}

	}
	
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
	printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
	//Student must fill in.  Use recursive algorithm.
	//Note that this prints using an Inorder, Depth-first search
	//but you may want to do something else when "visiting" the node....
	//like moving visited data to another datastructure
	//Don't forget your base case!
	if (node == NULL)
		return;
	//refrenced this code from CodeForGeek.com

	/* first recur on left child */
	printInorder(node->Left());

	/* then print the data of node */
	cout << node->Data().name;
	cout << endl;

	/* now recur on right child */
	printInorder(node->Right());

}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
	out << data.number << "\t" << data.name << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		aRoot->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE> ::inorderVector(std::vector<DATATYPE>& vec)
{
	inorderVector(root, vec);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE> ::inorderVector(Node<DATATYPE, KEYTYPE>* node, vector<DATATYPE>& vec)
{
	//Not end of tree or empty
	if (node != nullptr)
	{
		inorderVector(node->Left(), vec);

		vec.push_back(node->Data());

		inorderVector(node->Right(), vec);
	}
}
/*
This stores all the nodes that have been found into a vector and returns the node of the tree. 
*/
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE> :: findAllNode(string key, std::vector<DATATYPE>& vec)
{
	return findAllNode(key, root, vec);
}
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE> :: findAllNode(string key, Node<DATATYPE, KEYTYPE> * node, std::vector<DATATYPE>& vec)
{
	//Check immediately if at root
	if (node->Key() == key)
	{
		//Get the record and put in vector
		vec.push_back(node->Data());

		//Keep going right until the end
		while (node->Right() != nullptr)
		{
			//Go right
			node = node->Right();

			//Get the recor and put in vector
			vec.push_back(node->Data());
		}
		return node;
	}

	//If key is to the left
	else if (key < node->Key())
	{
		if (node->Left() == nullptr)
			return nullptr;

		return(findAllNode(key, node->Left(), vec));
	}

	//If key is to the right
	else
	{
		if (node->Right() == nullptr)
			return nullptr;

		return(findAllNode(key, node->Right(), vec));
	}
}