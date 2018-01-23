/*
 * File:   main.cpp
 * Author: zhang823
 *
 * Created on November 11, 2014, 8:07 PM
 */

#include <cstdlib>
#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    TreeDB bst;

    while (!cin.eof()){
        cout << "> ";
        string line;
        getline(cin,line);
        stringstream ls(line);
        string command;
        string name;
        int address;
        string status;
        string garbage;

        ls>>command;
        if(command=="insert"){
            ls>>name>>address>>status;
//            if(ls.fail()){
//                if(ls.eof())
//                    cout<<"too few"<<endl;
//                else
//                    cout<<"invalid"<<endl;
//            }
//            else{
//                ls>>garbage;
//                if (!ls.fail())
//                    cout<<"too many"<<endl;
//                else if(ls.fail()){
//                    if(ls.eof())
//                        ;
//                        //normal
//                    else
//                        cout<<"invalid"<<endl;
//                }
//            }
            DBentry* ptr=new DBentry(name,address,(status=="active"));
            if (bst.insert(ptr))
                cout<<"Success"<<endl;
            else{
                cout<<"Error: entry already exists"<<endl;
                delete ptr;
            }

        }
        if(command=="find"){
            ls>>name;
            cout<<bst.findNode(bst.getroot(),name);
        }
        if(command=="updatestatus"){
            ls>>name>>status;
            DBentry* ptr=bst.find(name);
            if(ptr!=NULL){
                ptr->setActive(status=="active");
                cout<<"Success"<<endl;
            }
            else
                cout<<"Error: entry does not exist"<<endl;
        }
        if(command=="printall"){
            bst.printall(bst.getroot());
        }
        if(command=="remove"){
            ls>>name;
            if(bst.remove(name))
                cout<<"Success"<<endl;
            else
                cout<<"Error: entry does not exist"<<endl;
        }
        if(command=="printprobes"){
            ls>>name;
            if(bst.find(name)!=NULL)
                bst.printProbes();
            else
                cout<<"Error: entry does not exist"<<endl;
        }
        if(command=="countactive"){
            bst.countActive();
        }
        if(command=="removeall"){
            bst.clear();
            cout<<"Success"<<endl;
        }

    }
    return 0;
}

