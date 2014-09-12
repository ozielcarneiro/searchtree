/* 
 * File:   Node.cpp
 * Author: ozielcarneiro
 * 
 * Created on September 11, 2012, 10:01 PM
 */

#include <sstream>
#include <vector>
#include <fstream>
#include "Node.h"
#include "IO.h"

using namespace std;

Node::Node() {
}

Node::Node(const Node& orig) {
    father = orig.father;
    xA = orig.xA;
    xB = orig.xB;
    yA = orig.yA;
    yB = orig.yB;
    cost = orig.cost;
    level = orig.level;
    mapSize = orig.mapSize;
    obstaclesN = orig.obstaclesN;
    xObstacle = orig.xObstacle;
    yObstacle = orig.yObstacle;
    moveRightCost = orig.moveRightCost;
    moveLeftCost = orig.moveLeftCost;
    moveUpCost = orig.moveUpCost;
    moveDownCost = orig.moveDownCost;
}

Node::Node(string fileName) {
    IO io;
    string data = io.fileToString(fileName);
    stringstream ss(data);
    vector<string> lines;
    string line;
    while (getline(ss, line, '\n')) {
        lines.push_back(line);
    }
    int values[(5 + (lines.size() - 5)*2)];
    int j = 0;
    for (int i = 0; i < lines.size(); i++) {
        stringstream linestream(lines.at(i));
        if (i < 5) {
            linestream >> values[j];
            j++;
        } else {
            linestream >> values[j] >> values[j + 1];
            j += 2;
        }
    }

    mapSize = values[0];
    moveUpCost = values[1];
    moveRightCost = values[2];
    moveDownCost = values[3];
    moveLeftCost = values[4];
    xA = values[5];
    yA = values[6];
    xB = values[7];
    yB = values[8];
    obstaclesN = lines.size() - 7;
    if (obstaclesN > 0) {
        xObstacle = new int[obstaclesN];
        yObstacle = new int[obstaclesN];
        for (int i = 0; i < obstaclesN; i++) {
            xObstacle[i] = values[9 + i * 2];
            yObstacle[i] = values[9 + i * 2 + 1];
        }
    }
    father = NULL;
    cost = 0;
    level = 0;
}

Node::~Node() {
}

Node* Node::moveUp() {
    Node newNode;
    int nextXA = xA;
    int nextYA = yA - 1;
    int nextXB = xB + 1;
    int nextYB = yB;

    if (nextYA < 1 || nextXB > mapSize) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveUpCost, moveRightCost, moveDownCost, moveLeftCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveUpCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

Node* Node::moveRight() {
    Node newNode;
    int nextXA = xA + 1;
    int nextYA = yA;
    int nextXB = xB;
    int nextYB = yB + 1;

    if (nextXA > mapSize || nextYB > mapSize) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveUpCost, moveRightCost, moveDownCost, moveLeftCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveRightCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

Node* Node::moveDown() {
    Node newNode;
    int nextXA = xA;
    int nextYA = yA + 1;
    int nextXB = xB - 1;
    int nextYB = yB;

    if (nextYA > mapSize || nextXB < 1) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveUpCost, moveRightCost, moveDownCost, moveLeftCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveDownCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

Node* Node::moveLeft() {
    Node newNode;
    int nextXA = xA - 1;
    int nextYA = yA;
    int nextXB = xB;
    int nextYB = yB - 1;

    if (nextXA < 1 || nextYB < 1) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveUpCost, moveRightCost, moveDownCost, moveLeftCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveLeftCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

bool Node::checkGoal() {
    if (xA == xB && yA == yB) {
        return 1;
    } else {
        return 0;
    }
}

string Node::getPath() {
    string out;
    if (father != NULL) {
        out = (*father).getPath();
    } else {
        out = "";
    }
    stringstream stream;
    stream << out << xA << " " << yA << "\n";
    return stream.str();
}

void Node::setA(int xA, int yA) {
    this->xA = xA;
    this->yA = yA;
}

void Node::setB(int xB, int yB) {
    this->xB = xB;
    this->yB = yB;
}

void Node::setMapSize(int n) {
    mapSize = n;
}

void Node::setMoveCost(int costUp, int costRight, int costDown, int costLeft) {
    moveDownCost = costDown;
    moveUpCost = costUp;
    moveRightCost = costRight;
    moveLeftCost = costLeft;
}

void Node::setObstaclesN(int n) {
    obstaclesN = n;
}

void Node::setCost(int x) {
    cost = x;
}

void Node::setLevel(int l) {
    level = l;
}

void Node::setFather(Node* node) {
    if (node != NULL) {
        father = new Node(*node);
    } else {
        father = NULL;
    }
}

void Node::setObstacles(int xObs[], int yObs[]) {
    xObstacle = xObs;
    yObstacle = yObs;
}

int Node::getCost() {
    return cost;
}

int Node::getLevel() {
    return level;
}

Node* Node::getFather() {
    return father;
}

int Node::getXA() {
    return xA;
}

int Node::getXB() {
    return xB;
}

int Node::getYA() {
    return yA;
}

int Node::getYB() {
    return yB;
}