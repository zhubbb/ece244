#ifndef NODE_H
#define NODE_H

#define MAX_RESISTORS_PER_NODE 5
#include <string>
#include <iostream>
#include "Resistor.h"
#include <iomanip>
#include "ResistorList.h"

using namespace std;

class Node
{
private:
   int nodeid;
   int numRes; // number of resistors currently connected
   Resistorlist Rlist;
   Node* next;
   double voltage;
   bool settledV;

public:

   Node();
   Node(int id);
   ~Node();
   void initialnumRes();
   bool& getOrsetflagV();
   double& getOrsetvoltage();
   void numdelete();
   void numadding(); // add numRes when success
   Node*& getNext();
   int getid();
   Resistor* findResistor(string name);
   double solve(Node*,Node*);
   double getReqbetween();
   bool deleteResistor(string name);
   bool checkempty();
   Resistorlist& getRlist();

   // Updates resIDArray to show the resistor in position rIndex in
   // the resistor array is now connected to this node.
   // Returns true if successful

   // prints the whole node
   // nodeIndex is the position of this node in the node array.
   void print();

};



#endif	/* NODE_H */

