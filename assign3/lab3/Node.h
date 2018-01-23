#ifndef NODE_H
#define NODE_H

#define MAX_RESISTORS_PER_NODE 5
#include <string>
#include <iostream>
#include "Resistor.h"
#include <iomanip>
using namespace std;

class Node
{
private:

   int numRes; // number of resistors currently connected
   int resIDArray[MAX_RESISTORS_PER_NODE]; // stores the index of each resistor connected

public:
   Node();
   ~Node();
   void numadding();
   // Updates resIDArray to show the resistor in position rIndex in
   // the resistor array is now connected to this node.
   // Returns true if successful
   bool addResistor (int rIndex);

   // prints the whole node
   // nodeIndex is the position of this node in the node array.
   void print (int nodeIndex,Resistor**& resistorpointer);

};

#endif	/* NODE_H */

