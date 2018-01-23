#include "ResistorList.h"


Resistorlist::Resistorlist(){
    head=NULL;
}
void Resistorlist::deleteAllR(){
    Resistor *ptr;
    while(head != NULL) {
    ptr = head;
    head = ptr->getNext();
    delete ptr;
    }

}
Resistorlist::~Resistorlist(){
    Resistor *ptr;
    while(head != NULL) {
    ptr = head;
    head = ptr->getNext();
    delete ptr;
    }
}

void Resistorlist::insertR(double R_value, string R_name,int endpoints[2]){ //at the tail // type int [2]  , name ""endpoint""
    Resistor* newtemp=new Resistor(R_value, R_name, endpoints); // linked list is dynamic allocateds

    if (head==NULL){
        head=newtemp;
        newtemp->getNext()=NULL;
    }
    else{
        Resistor* ptr=head;
        while(ptr->getNext()!=NULL) // check if the """""""""""""""""next """"""""""""" of ptr is null. Find the  last one.
            ptr=ptr->getNext();
        ptr->getNext()=newtemp;
        newtemp->getNext()=NULL;

    }





}





Resistor* Resistorlist::findResistor(string name){
    Resistor* ptr=head; //Rlist.head point to a Resistance

    while(ptr!=NULL&&ptr->getName()!=name){
        //->name is private ,we have to use func getName

        ptr=ptr->getNext();
    }
    //return ptpr; // return previous pointer to tpr!!!
    return ptr;
}

// so we should check if Rlist is empty , if is then delete the Node;
bool Resistorlist::deleteResistor(string name){ // when delete the only resistor we also need to delete Node cause  node.Rlist wouldn't work and is empty , we meet seg fault if get access to a NULL
    if(head==NULL)
        return 0;
    Resistor* ptr=head;
    Resistor* pptr=NULL;
    while(ptr!=NULL&&ptr->getName()!=name){//check NULL fist otherwise segment fault
        pptr=ptr;
        ptr=ptr->getNext();

    }
    if(ptr==NULL)  // return means end it
        return 0;
    if(ptr==head){
        head=head->getNext();
        //head->getNext()=NULL; we cannot do that cause what if it is null or it has some other value next to it, we cannot fail it.
        delete ptr;
        ptr=NULL;
        return 1;
    }

    pptr->getNext()=ptr->getNext();
    delete ptr;
    ptr=NULL;
    return 1;


}




void Resistorlist::print(){
    Resistor* ptr= head;
    while(ptr!=NULL){
        cout << "  ";
        ptr->print();
        ptr=ptr->getNext();    //we could have numRes++ here to get number of Resistor.


    }

}