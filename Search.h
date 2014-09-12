/* 
 * File:   Search.h
 * Author: ozielcarneiro
 *
 * Created on September 13, 2012, 6:43 PM
 */
#include "Node.h"
#include <list>
#include <vector>

#ifndef SEARCH_H
#define	SEARCH_H

class Search {
public:
    Search();
    Search(const Search& orig);
    virtual ~Search();
    bool bfs(Node* start, Node* goal);
    bool ucs(Node* start, Node* goal);
    bool checkVisited(Node* node);
    void sortQueue();
    vector<Node> mergeSort(vector<Node> queue);
    vector<Node> merge(vector<Node> a, vector<Node> b);
private:
    vector<Node> searchQueue;
    vector<Node> visited;
};

#endif	/* SEARCH_H */

