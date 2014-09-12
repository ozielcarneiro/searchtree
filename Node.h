/* 
 * File:   Node.h
 * Author: ozielcarneiro
 *
 * Created on September 11, 2012, 10:01 PM
 */
#include <string>

using namespace std;

#ifndef NODE_H
#define	NODE_H

class Node {
public:
    Node();
    Node(const Node& orig);
    Node(string fileName);
    ~Node();
    Node* moveUp();
    Node* moveRight();
    Node* moveDown();
    Node* moveLeft();
    bool checkGoal();
    string getPath();
    void setA(int xA,int yA);
    void setB(int xB,int yB);
    void setMapSize(int n);
    void setObstaclesN(int n);
    void setObstacles(int xObs[], int yObs[]);
    void setCost(int x);
    void setLevel(int l);
    void setMoveCost(int costRight, int costLeft, int costUp, int costDown);
    void setFather(Node *node);
    int getCost();
    int getLevel();
    int getXA();
    int getXB();
    int getYA();
    int getYB();
    Node* getFather();
private:
    Node* father;
    int xA;
    int xB;
    int yA;
    int yB;
    int cost;
    int level;
    int mapSize;
    int obstaclesN;
    int* xObstacle;
    int* yObstacle;
    int moveRightCost, moveLeftCost, moveUpCost, moveDownCost;
};

#endif	/* NODE_H */

