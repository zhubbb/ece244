
#include "Node.h"
#include "Resistor.h"


#include "ResistorList.h"
#include "NodeList.h"
Node::Node(){
    voltage=0;
    settledV=0;
    numRes=0;
    nodeid=0;
    next=NULL;
}
//double Node::getReqbetween(Node* Node2){
 //   Rlist.getReqbetween(Node2);

//}

Node::Node(int id){
    voltage=0;
    settledV=0;
    numRes=0;
    nodeid=id;
    next=NULL;
}
double Node::solve(Node* listhead,Node* myNode){
    double Vleft=0;
    double Vright=0;
	int anotherid=0;
    Resistor* Rptr=myNode->Rlist.head;

    while(Rptr!=NULL){



        if(Vleft==0)
                Vleft=Rptr->getResistance();
        else
                Vleft=1/(1/Vleft+1/Rptr->getResistance());

        int* id=Rptr->getendpoints();
        if(id[0]==this->getid())
            anotherid=id[1];
        else
            anotherid=id[0];
        Node* Nptr=listhead;
		for(Nptr=listhead; Nptr!=NULL&&Nptr->getid()!=anotherid; Nptr=Nptr->getNext())
			;

		if(Nptr==NULL)
			cout<<"ERROR"<<endl;
		else
			Vright=Vright+(Nptr->getOrsetvoltage())/(Rptr->getResistance());

        Rptr=Rptr->getNext();
    }
        double v=Vleft*Vright;
        return v;
}



Node::~Node(){


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

int Node::getid(){
    return nodeid;
}

Resistor* Node::findResistor(string name){
     return Rlist.findResistor(name);
}
bool Node::deleteResistor(string name){
    bool deleted=Rlist.deleteResistor(name);
    //if(Rlist.head==NULL) //check if the Rlist is empty we done this in nodelist
    if(deleted)
        numdelete();
    return deleted;


}
bool& Node::getOrsetflagV(){
    return settledV;
}
double& Node::getOrsetvoltage(){

    return voltage;

}
void Node::initialnumRes(){
    numRes=0;
}
bool Node::checkempty(){
    return (Rlist.head==NULL&&voltage==0&&settledV==0);

}
Node*& Node::getNext(){
    return next;
}

Resistorlist& Node::getRlist(){
    return Rlist;

}
void Node::print(){
    if(Rlist.head!=NULL)
        cout << "Connections at node " << nodeid  << ": " << numRes << " resistor(s)" << endl;
    Rlist.print();
}

void Node::numadding(){
    numRes++;
}
void Node::numdelete(){
    numRes--;
}