#include "TreeDB.h"
#include "TreeNode.h"
#include "DBentry.h"
#include "iostream"
TreeDB::TreeDB(){
    root=NULL;
    probesCount=0;
}
TreeDB::~TreeDB(){
    if(root==NULL)
        return;//make it efficient to add this
    deletetree(root);
}
void TreeDB::deletetree(TreeNode* myroot){
    if(myroot==NULL)
        return;
    deletetree(myroot->getRight());
    deletetree(myroot->getLeft());
    delete myroot; //recursive func delete itself lastly
}
bool TreeDB::remove(string name){// so bst u need to search each time. since you need the parent node
    if(root==NULL)
        return 0;
    TreeNode* fakeroot=new TreeNode(NULL);
    fakeroot->setLeft(root);
    bool flag=root->remove(name,fakeroot);
    root=fakeroot->getLeft();
    delete fakeroot;
    return flag;
}
TreeNode*& TreeDB::getroot(){
    return root;
}

//bool TreeDB::removeHelper(string name, TreeNode* myroot){
//    if(myroot==NULL)
//        return 0;
//    if(myroot->getEntry()->getName()<name){
//        removeHelper(name,myroot->getRight());
//    }
//
//    else if(myroot->getEntry()->getName()>name)
//        removeHelper(name,myroot->getLeft());
//    else{ //found?
//        if(myroot->getRight()==NULL&&myroot->getLeft()==NULL){//case 1 no child
//            delete myroot;
//            myroot=NULL;
//            return 1;
//        }
//        else if(myroot->getRight()==NULL){//case 2 one child
//            TreeNode* ptr=myroot;
//            myroot=myroot->getLeft();
//            delete ptr;
//            ptr=NULL;
//            return 1;
//        }
//        else if(myroot->getLeft()==NULL){
//            TreeNode* ptr=myroot;
//            myroot=myroot->getRight();
//            delete ptr;
//            ptr=NULL;
//            return 1;
//        }
//        else { //case 3 2 child
//            /*while (ptr->getRight()!=NULL){ //find the largest of left node of temp
//            pptr=ptr;
//            ptr=ptr->getRight();
//            }
//            temp->setEntry(ptr->getEntry());
//            ptr->setEntry(NULL); //remember to set the entryPTR to null before delete ptr!!!!!!!!!!!!!
//            delete ptr; // if an entry points to null it lose its value so delete it!!!!!!!!!!!
//            pptr=NULL; // point to null since ptr is the no child node;*/
//            TreeNode* ptr=findmax(myroot->getLeft());
//            myroot->setEntry(ptr->getEntry());
//            ptr->setEntry(NULL);//remember to set the entryPTR to null before delete ptr!!!!!!!!!!!!!
//            removeHelper(myroot->getEntry()->getName(),myroot->getLeft());
//            return 1;
//        }
//
//    }
//
//}



//
//TreeNode* TreeDB::find(string name){ //find the parent
//    if(root=NULL) return NULL;
//    return findNode(root,name);
//}

TreeNode* TreeDB::findNode(TreeNode* myroot, string name){
    if(myroot==NULL) // restriction . base state
        return NULL;
    if(myroot->getEntry()==NULL)
        return NULL;
    probesCount++;
    if(myroot->getEntry()->getName()==name) //what does it do in each recursive step
        return myroot;
    else if(myroot->getEntry()->getName()<name) //string directly compare in c++
        return findNode(myroot->getRight(),name);
    else
        return findNode(myroot->getLeft(),name);
}
DBentry* TreeDB::find(string name){
    probesCount=0; //initialize reset
    TreeNode* ptr=findNode(root,name);
    if(ptr==NULL)
        return NULL;
    else
        return ptr->getEntry();
}

bool TreeDB::insert(DBentry* newEntry){
    return insertHelper(newEntry,root);
}
bool TreeDB::insertHelper(DBentry* newEntry, TreeNode*& myroot){//instead use reference we can change the root at "insert" by using root= inserthelper. the rest dont need to
    if(myroot==NULL){
        myroot=new TreeNode(newEntry);
        return 1;
    }
    if(myroot->getEntry()->getName()==newEntry->getName())
        return 0;
    else if(myroot->getEntry()->getName()<newEntry->getName()){
        if(myroot->getRight()==NULL){
            TreeNode* ptr=new TreeNode(newEntry);
            myroot->setRight(ptr);
            return 1;
        }
        else
            return insertHelper(newEntry, myroot->getRight());
    }
    else //name less than , on the left
        if(myroot->getLeft()==NULL){
            TreeNode* ptr=new TreeNode(newEntry);
            myroot->setLeft(ptr);
            return 1;
        }
        else
            return insertHelper(newEntry,myroot->getLeft());
}


void TreeDB:: clear(){
    clearHelper(root);
}
void TreeDB:: clearHelper(TreeNode*& myroot){
    if(myroot==NULL)
        return;
    clearHelper(myroot->getLeft());
    clearHelper(myroot->getRight());
    delete myroot; //remember that delete need to use post order , cause if you delete it you lose the path to left and right
    myroot=NULL;
}
void TreeDB::printProbes() const{
    cout << probesCount<<endl;
}


void TreeDB::countActive() const{
    cout<<countActiveHelper(root)<<endl;
}

int TreeDB::countActiveHelper (TreeNode* myroot) const{
    if(myroot==NULL)
        return 0;
    return (myroot->getEntry()->getActive()==1)+countActiveHelper(myroot->getLeft())+countActiveHelper(myroot->getRight());
}

void TreeDB::printall(TreeNode* myroot){
    if(myroot==NULL)
        return;
    printall(myroot->getLeft());
    cout<<myroot;
    printall(myroot->getRight());
}


ostream& operator<< (ostream& out, TreeNode* rhs){
    if(rhs==NULL)
        return out<<"Error: entry does not exist"<<endl;
    out<<rhs->getEntry()->getName()<<" : "<< rhs->getEntry()->getIPaddress();
    if (rhs->getEntry()->getActive())
        return out<<" : active"<<endl;
    else
        return out<<" : inactive"<<endl;
}

