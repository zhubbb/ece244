
#include "TreeNode.h"
TreeNode::TreeNode(DBentry* _entryPtr){
    entryPtr=_entryPtr;
    left=NULL;
    right=NULL;
}
TreeNode::~TreeNode(){
    if(entryPtr!=NULL)
        delete entryPtr;
}
void TreeNode::setRight(TreeNode* newRight){
    right=newRight;
}
void TreeNode::setLeft(TreeNode* newLeft){
    left=newLeft;
}
TreeNode*& TreeNode::getRight(){
    return right;
}
TreeNode*& TreeNode::getLeft(){
    return left;
}
DBentry* TreeNode::getEntry() const{
    return entryPtr;
}


bool TreeNode::remove(string name, TreeNode* parent){
    if(this==NULL)
        return 0;
//    if(parent==NULL)//base case
//        return 0;
    if(name>(this->getEntry()->getName())){
        return right->remove(name,this);
    }
    else if(name<this->getEntry()->getName())
        return left->remove(name,this);
    else{//found??
        //case 1
        if(left==NULL&&right==NULL){
            delete this;
            if(parent->left==this)
                parent->left=NULL;//point to NULL!!!!!!!!!!!!!
            if(parent->right==this)
                parent->right=NULL;//point to NULL!!!!!!!!!!!!!
        }
        else if(left==NULL){ //has only right node
            if(parent->left==this)
                parent->left=right;
            if(parent->right==this)
                parent->right=right;
            delete this;
        }
        else if(right==NULL){
            if(parent->left==this)
                parent->left=left;
            if(parent->right==this)
                parent->right=left;
            delete this;
        }
        else if(left!=NULL&&right!=NULL){
            //delete entryPtr;//if we delete it we need to rebuild it
            TreeNode* leftmax=left->findmax();
            entryPtr->setActive(leftmax->entryPtr->getActive());
            entryPtr->setIPaddress(leftmax->entryPtr->getIPaddress());
            entryPtr->setName(leftmax->entryPtr->getName());
            //leftmax->entryPtr=NULL;//dont need point null cause we delete from left side node//make sure it's point to null after replace the value
            left->remove(entryPtr->getName(),this);//equilvalent to delete leftmax;
        }
        return 1;

    }
}

TreeNode* TreeNode::findmax(){
    if(this->getRight()==NULL)
        return this;
    return right->findmax();
}

