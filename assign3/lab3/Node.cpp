
#include "Node.h"
Node::Node(){
    numRes=0;
    for(int i=0; i<MAX_RESISTORS_PER_NODE; i++){
        resIDArray[i]=0;
    }
}

bool Node::addResistor (int rIndex){
    if(numRes<MAX_RESISTORS_PER_NODE)
        resIDArray[numRes]=rIndex;//serve as indice before numRes is updated
    else
        return 0;
    //if success numRes++ and return 1 updated here become "number of resistor" instead of indice
    //but we cannot make sure if success here , so we do it latter
    //numRes++;
    return 1;
}

Node::~Node(){

}

void Node::print(int nodeIndex,Resistor**& resistorpointer){
    cout << "Connections at node " << nodeIndex  << ": " << numRes << " resistor(s)" << endl;
    for(int i=0;i<numRes;i++){
        cout << "  ";
        resistorpointer[resIDArray[i]]->print();

    }
}

void Node::numadding(){
    numRes++;
}