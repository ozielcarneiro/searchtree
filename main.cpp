/* 
 * File:   main.cpp
 * Author: ozielcarneiro
 *
 * Created on September 11, 2012, 10:09 AM
 */

#include <cstdlib>
#include <sstream>

#include "IO.h"
#include "Node.h"
#include "Search.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {




    Node node("input.txt");


    Search search;
    stringstream sstream;
    Node goal;
    bool success = search.bfs(&node, &goal);
    if (success) {
        sstream << goal.getLevel() << endl;
        sstream << goal.getPath() << endl;
    } else {
        sstream << -1 << endl << endl;
    }

    success = search.ucs(&node, &goal);
    if (success) {
        sstream << goal.getCost() << endl;
        sstream << goal.getPath() << endl;
    } else {
        sstream << -1 << endl;
    }

    IO io;

    io.stringToFile("output.txt", sstream.str());


    return 0;
}

