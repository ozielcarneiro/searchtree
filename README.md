This code was developed for an assignment for an Artificial Intelligence course at USC using C++. The assignment requested to program both Breadth First Search and Uniform Cost Search for a problem where there was a square board, with two characters A and B, and obstacles (meaning no character could use this place on the board), the movement of A is controlled and B moves based on the action of A. The goal is to make A and B reach the same spot on the board.

1 - Program Description

The program is divided in 4 classes, IO.cpp, Node.cpp, Search.cpp, main.cpp.
The class IO.cpp is responsible for writing and reading text files, with two methods fileToString(string fileName) which reads the file specified by the path in the string fileName, and stringToFile(string fileName, string text) which writes the string text into a file specified by the string fileName.
The class Node.cpp describes each node in the search tree. The class is designed based on the problem, so the variables and methods represent the details of the problem. The variables will hold the following information: previous node on tree, position of agents, cost to reach node, level of the node, map size, number of obstacles, position of obstacles and costs of moves. The methods moveUp(),moveRight(),moveDown() and moveLeft() are responsible to generate the following children nodes, there is a method to check if the node is a goal node, and a method to get the path to the node recursively. Also there is set and get methods to access the variables. There is a constructor in the node class that is responsible to read the information in the input file and assign values to the correspondent variables.
The class Search.cpp implements the two search algorithms, Breadth-First Search and Uniform Cost Search, as methods. Other methods like checkVisited(Node* node), to check if a node has been visited before, and sortQueue() to sort the queue holding the next nodes to be visited by the cost to reach each of them. The class hold two variables, to dynamic growing vectors to hold the queue and the visited nodes.
The last class, main.cpp, is the class responsible for running the program. It creates two Nodes, one using the constructor with the input file name, which will be the starting node, and other empty which will hold the goal node. Then it creates a Search object. When calling the search functions two nodes are required as parameters, the starting node and the empty goal node. The search method returns a boolean variable indicating success. If the search is successful the Level, for BFS, or the Cost, for UCS, is added to a string followed by the path to the goal node, if the search is not successful -1 is printed as the result of the search. Finally the string containing the results is written on the output file.

2 - Compile Instructions

To compile the program type the following command on the Terminal: g++ main.cpp IO.cpp Node.cpp Search.cpp

For the program to run correctly the input.txt file needs to be in the same directory as the output file generated after compilation.
To run the program after compiling type the following command on the Terminal: ./a.out

3 - Input and Output Files

The input file is a text file containing the board size, then the cost of each of the movements of A, then the position of A and B, and the position of the obstacles. The output file is a text file with the output of the run for both algorithms. The first value is the value for the evaluation variable for the set of actions (for BFS is the number of levels, for UCS is the total cost of actions), and then the sequence of A locations until reaches B. If no solution is possible the output will be -1.