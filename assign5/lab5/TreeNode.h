#ifndef _TREENODE_H
#define _TREENODE_H

#include "DBentry.h"

class TreeNode {
private:
    DBentry* entryPtr;
    TreeNode* left;
    TreeNode* right;

public:
    // A useful constructor
    TreeNode(DBentry* _entryPtr);

    // the destructor
    ~TreeNode();

    // sets the left child of the TreeNode.
    void setLeft(TreeNode* newLeft);

    // sets the right child of the TreeNode
    void setRight(TreeNode* newRight);

    // gets the left child of the TreeNode.
    TreeNode*& getLeft();
    bool remove(string, TreeNode*);
    // gets the right child of the TreeNode
    TreeNode*& getRight();
    TreeNode* findmax();
    void printProbes() const;
    // returns a pointer to the DBentry the TreeNode contains.
    DBentry* getEntry() const;
};

#endif

