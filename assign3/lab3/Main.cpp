/*
 * File:   main.cpp
 * Author: zhang823
 *
 * Created on October 10, 2014, 3:40 PM
 */
#include "Node.h"
#include "Resistor.h"
#include "Rparser.h"
#include <cstdlib>
//global
int maxNodeNumber=0, maxResistors=0;
using namespace std;

/*
 *
 */
//global variables

void allocation(Node*& nodepointer, Resistor**& resistorpointer){
    nodepointer=new Node[maxNodeNumber+1];
    resistorpointer= new Resistor* [maxResistors];
    for(int i=0;i<maxResistors;i++)
        resistorpointer[i]=NULL; //allocated to NULL instead of random value;
    return;
}
void clear(Node*& nodepointer, Resistor**& resistorpointer,int rescount){
     if(nodepointer!=NULL){
        delete []nodepointer;
        nodepointer=NULL;
      }

    for(int i=0;i<rescount;i++){
        if (resistorpointer[i]!=NULL){  //make sure it is null instead of random value // null is the initial state for resistorpointer[i];
            delete resistorpointer[i];
            resistorpointer[i]=NULL; //initialize after delete

        }
    }
    if(resistorpointer!=NULL){
        delete []resistorpointer;
        resistorpointer=NULL;
    }

}
void reset(int& rescount, bool& allocated){
    rescount=0;
    allocated=0;
}

int main() {
    Node* nodepointer=NULL;
    Resistor** resistorpointer=NULL;

    parser(nodepointer,resistorpointer);

    clear(nodepointer,resistorpointer,maxResistors);

    return 0;
}

