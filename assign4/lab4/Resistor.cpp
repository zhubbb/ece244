#include "Resistor.h"


Resistor::Resistor(double resistance_, string name_,int endpoints_[2]){
    name=name_;
    resistance=resistance_;
    endpointNodeIDs[0]=endpoints_[0];//[0]=[0]????
    endpointNodeIDs[1]=endpoints_[1];
    next=NULL;
}


Resistor*& Resistor::getNext(){
    return next;
}



void Resistor::setResistance (double resistance_){
    resistance=resistance_;
}

string Resistor::getName() const{
    return name;
}
int* Resistor::getendpoints(){
    return endpointNodeIDs;

}
double Resistor::getResistance() const{
    return resistance;
}

Resistor::~Resistor(){

//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    do nothing here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
void Resistor::print(){
    cout << left << setfill(' ') <<setw(20) << name << " " << right << setw(8)  <<fixed << setprecision(2) << resistance << " Ohms " << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << endl;
}