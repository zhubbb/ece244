#include "Resistor.h"


Resistor::Resistor(int rIndex_,string name_,double resistance_,int endpoints_[2]){
    name=name_;
    resistance=resistance_;
    endpointNodeIDs[0]=endpoints_[0];//[0]=[0]????
    endpointNodeIDs[1]=endpoints_[1];
    rIndex=rIndex_;
}


void Resistor::setResistance (double resistance_){
    resistance=resistance_;
}

string Resistor::getName() const{
    return name;
}

double Resistor::getResistance() const{
    return resistance;
}

Resistor::~Resistor(){

}
void Resistor::print(){
    cout << left << setfill(' ') <<setw(20) << name << " " << right << setw(8)  <<fixed << setprecision(2) << resistance << " Ohms " << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << endl;
}