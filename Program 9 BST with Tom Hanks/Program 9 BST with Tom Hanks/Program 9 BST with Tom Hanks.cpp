//Jared Swislow
//Program 9: Binary Search Tree With Tom Hanks's Movie Roles

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "MovieRole.h"

using namespace::std;

const string TOM_HANKS_FILE_NAME = "TomHanksMovieRoles.txt";

int main()
{

    ifstream fin;

    fin.open(TOM_HANKS_FILE_NAME);
    assert(!fin.fail());

    BinarySearchTree<string, MovieRole> tomHanksBST;
    MovieRole currentMovieRole;
    while (fin >> currentMovieRole) {
        tomHanksBST.insert(currentMovieRole.getTitle(), currentMovieRole);
    }

    cout << "**SEARCHING**" << endl;
    MovieRole splashPayload;
    tomHanksBST.find("Splash", splashPayload);
    MovieRole toyStory99Payload;
    tomHanksBST.find("Toy Story 99", toyStory99Payload);
    cout << endl;

    cout << "**OUTPUT**" << endl;
    cout << "**Tom Hank's Movie Roles**" << endl;
    cout << tomHanksBST;
}