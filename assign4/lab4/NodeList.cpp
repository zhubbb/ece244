
#include "NodeList.h"

using namespace std;
Nodelist::Nodelist(){
    head=NULL;
}

Nodelist::~Nodelist(){
    Node* tpr;
    while(head!=NULL){
        tpr=head;
        head=head->getNext();// or head=tpr->next;
        delete tpr;
        tpr=NULL;
    }
}


Node* Nodelist:: findNode(int id){
    Node* tpr=head;  // cause we dont want to change the head // point to null is ok
    while(tpr!=NULL&&tpr->getid()!=id)
        tpr=tpr->getNext();
    return tpr;


}

bool Nodelist::checksetV(){
    Node* ptr=head;
    while(ptr!=NULL){
        if(ptr->getOrsetflagV())
            return 1;
        ptr=ptr->getNext();
    }
    return 0;


}
bool Nodelist::checknonsetV(){//check is there nonsetv????????
    for(Node* ptr=head;ptr!=NULL;ptr=ptr->getNext()){
        if(!ptr->getOrsetflagV())
            return 1;
    }
    return 0;


}

void Nodelist::solve(){

    bool alldone=0;
    bool donothing=0;
    if(!checknonsetV())
        donothing=1;
    while(!alldone&&!donothing){ // change is an absolute value
        double change=100;
        alldone=1;


        for(Node* ptr=head;ptr!=NULL;ptr=ptr->getNext()){   // this is and must must bebebebebebebbe a for loop!!!!!!!!!!!!!!!


            if(!ptr->getOrsetflagV()){//for any none--setv value

                change=(ptr->solve(this->head,ptr))-(ptr->getOrsetvoltage());//change=f-i
                ptr->getOrsetvoltage()=(ptr->getOrsetvoltage()+change);
                //ptr->getOrsetflagV()=0;//remember that it is still not a setv value which is a fixed value.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

                if(change<0)
                    change=-change;//make abs();

                if(change>MIN_ITERATION_CHANGE)//if anyone fails
                    alldone=0; // then not all done
            }

        }




    }

}
void Nodelist::printsolve(){
    deleteNode();
    cout<<"Solve:"<<endl;
    for(Node* ptr=head;ptr!=NULL;ptr=ptr->getNext()){   // this is and must must bebebebebebebbe a for loop!!!!!!!!!!!!!!!

                cout<<"  Node "<<ptr->getid()<< ": " << ptr->getOrsetvoltage() <<" V"<<endl;



    }
}


Node* Nodelist:: findOrInsert(int id){
    Node* nptr=findNode(id);
    if(nptr!=NULL)                 //means find it and the list is not empty
        return nptr;

    nptr=new Node(id);
    Node* ptr=head;
    if(head==NULL){           //but we still check if empty just for fun! (in case of at head)
        head=nptr;
        nptr->getNext()=NULL;

    }
    else{
        while(ptr->getNext()!=NULL&&ptr->getNext()->getid()<=id) // fine the last one (in case of  at tail )or the last one smaller than id;
            ptr=ptr->getNext();


        if(head->getid()>id){              //check the situation when there everything in the list is bigger than id, (e.g when only head ,head id> id)
            nptr->getNext()=head;
            head=nptr;



        }

        else if(ptr->getNext()==NULL){               // could not found the bigger node id , at the tail
            ptr->getNext()=nptr;
            nptr->getNext()=NULL;

        }

        else if(ptr->getid()<id&&ptr->getNext()->getid()>id) {    // make sure it's smaller id so add middle
            nptr->getNext()=ptr->getNext();
            ptr->getNext()=nptr;
        }

    }




    return nptr;    // in case ?????? default case..

}
void Nodelist::insertRtoN(double value, string name, int id[2]){ // if we have this we dont need insertR inside the Rlist cause it's combined together here
    Node* ptr1=findOrInsert(id[0]); // we got the node //find Node receive single int
    Node* ptr2=findOrInsert(id[1]); // the second node...
    ptr1->getRlist().insertR(value,name,id); // insertR receive int [2];
    ptr2->getRlist().insertR(value,name,id); // a copy of R

    ptr1->numadding();
    ptr2->numadding();
}





Resistor** Nodelist::findResistor(string name){ // we can also pass the two parameter Resistor*& by reference as output
    Node* tpr=head;
    bool foundR2=0;
    bool foundR1=0;


    Resistor** R= new Resistor* [2];  //remember to delete it after use it;

    while(tpr!=NULL&&!foundR2){
        Resistor* temp= tpr->findResistor(name);

        if(!foundR1&&temp!=NULL) { //instead use found1,2 we can use R1==NULL.
            R[0]=temp;
            foundR1=1;
        }
        else if(temp!=NULL){
            R[1]=temp;
            foundR2=1;
        }
        tpr=tpr->getNext();



    }

     return R; //return by value copy

}

bool Nodelist::changeResistance(double R_value, string name){
    Resistor** R=findResistor(name);
    bool settled=0;
    if(R[0]==NULL||R[1]==NULL)
        settled=0;
    else{
        R[0]->setResistance(R_value); //findResistor() return the address
        R[1]->setResistance(R_value);
        settled=1;
    }
    delete[] R;    //dynamic allocate deleted!
    return settled;

}


bool Nodelist::deleteResistor(string name){


    Node* tpr = head;  //ptr is tpr

    bool deleted1=0,deleted2=0;

    while(tpr!=NULL&&!deleted2){
        if(!deleted1 && tpr->deleteResistor(name))
            deleted1=1;
        else if(deleted1&&tpr->deleteResistor(name)){
            deleted2=1;
        }
        tpr=tpr->getNext();

    }
    deleteNode();

    return (deleted2&&deleted1);
}
 bool Nodelist::deleteNode(){
     if(head==NULL)
         return 0;
     bool deleted=0;
     Node* ptr=head;
     Node* pptr=NULL;
     while(ptr!=NULL){ // we have nested while loop, remember that we need to go through the whole list to find all of the empty list to be deleted ; // even though we probably only have 2 to be deleted (due to 2 copy of R be deleted once). we still go through just to make sure.
        while(ptr!=NULL&&!ptr->checkempty()){// when not empty continue search , when meet the empty stop;
            pptr=ptr;
            ptr=ptr->getNext();

        }
        Node* tobedeleted=ptr;
        if(ptr!=NULL)
            ptr=ptr->getNext(); //move to the next one. so the loop keep going..

        if(tobedeleted==NULL){
            if(deleted==0)//didnt delete anything yet.
                deleted=0;  // deleted=0 means nothing tobedeleted . the nodelist is fine. no empty one shows up.
            //return 0;//shouldnt return here otherwise end loop
        }
        else if(tobedeleted==head){
            head=head->getNext();
            delete tobedeleted;
            tobedeleted=NULL;
            deleted=1;
            //return 1;  remember that we cannot return when the func is no finished
        }

        else{               // normal situation , delete middle
            pptr->getNext()=tobedeleted->getNext();
            delete tobedeleted;
            tobedeleted=NULL;
            deleted=1;
        }
        //ptr=ptr->getNext();//this ptr has been deleted , how to search the next one? //so we do it after the first while loop when it is not deleted.
        // or we can initialize it to head and go through the whole loop again which will be time consuming
    }




    return deleted;

 }

void Nodelist::deleteAllR(){ //means delete all nodes.
    Node* tpr=head;
    while(tpr!=NULL){
        tpr->getRlist().deleteAllR();
        tpr->initialnumRes();
        tpr=tpr->getNext();

    }

    deleteNode();
}


void Nodelist::print(){

    Node* ptr=head;
    deleteNode();
    while(ptr!=NULL){
        ptr->print();
        ptr=ptr->getNext();
    }



}
