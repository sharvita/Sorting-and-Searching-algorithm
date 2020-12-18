*******************************************************
*  Name      :    Sharvita Paithankar      
*  Student ID:      108172438           
*  Class     :  CSC 2421           
*  Due Date  :  May 2nd 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program takes in two files : actors and picture. It then 
stores the files into their binary search tree and uses key
as the name. After it has been put into the file, it then uses 
menu functions which asks users to choose whether they want to 
search, sort, add, change or delete something regarding the 
information from the files. Once the user enters their choice, 
information is put into the vector in order and it then searches, 
modifies, adds or deletes from the vector. 


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from an input file, use the data to prompt user with 
   options.

Name:  Actor.h
   Contains the definition for the class Actor

Name: Actor.cpp
   Defines and implements the Actor class, which implements reading 
   in file from the user, using the BSTree to store objects, creating a 
   vector to store information in order and contains all the menus to ask 
   the user if they want to add, modify, delete or exit the program. This 
   file uses the BST.h for the binary array. 

Name:  Picture.h
   Contains the definition for the class Actor

Name: Picture.cpp
   Defines and implements the Actor class, which implements reading 
   in file from the user, using the BSTree to store objects, creating a 
   vector to store information in order and contains all the menus to ask 
   the user if they want to add, modify, delete or exit the program. This 
   file uses the BST.h for the binary array. 

Name:  BSTree.h
   Contains the definition for the class BSTree

Name: BSTree.hpp
   Includes functions to create a binary search tree. It uses Node.h 
   to create a pointer node and has functions to add, delete, find and 
   other things for this program to work. 

Name Node.h
   Contains code to create a node for bstree
   
*******************************************************
*  Status of program
*******************************************************

   The program an error on search and since that is not working,
   my delete and modify functions are being affected. I tested the delete 
   and modify functions separately and they work perfectly fine. Other than 
   this issue, everything else works just fine on visual studios. I was having 
   trouble in compiling it in cse grid but it worked a few times after fixing a
   few things. I believe that it should be able to compile but it sometimes runs 
   into an issue.    
   
   The program was developed and tested on Visual Studios g++.  It was 
   compiled, run, and tested on csegrid.ucdenver.pvt. 

