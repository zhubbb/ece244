#ifndef RESISTOR_H
#define RESISTOR_H
#include <iomanip>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Resistor
{
private:
   double resistance; // resistance (in Ohms)
   string name; // C++ string holding the label
   int endpointNodeIDs[2]; // IDs of nodes it attaches to
   Resistor *next;
public:
   Resistor(double resistance_,string name_,int endpoints_[2]);
   // rIndex_ is the index of this resistor in the resistor array   gan ma yong de ?/kanyou meiyou exceed?
   // endpoints_ holds the node indices to which this resistor connects

   ~Resistor(); // zhe ge yao zi ji xie ma??????????
   int* getendpoints();
   string getName() const; // returns the name
   double getResistance() const; // returns the resistance
   Resistor*& getNext();
   void setResistance (double resistance_);

   // you *may* create either of the below to print your resistor
   void print ();
   friend ostream& operator<<(ostream&,const Resistor&);
};

ostream& operator<<(ostream&,const Resistor&);

#endif	/* RESISTOR_H */

