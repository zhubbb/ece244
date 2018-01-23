/*
 * File:   Nodelist.h
 * Author: zhang823
 *
 * Created on November 3, 2014, 8:09 PM
 */

#ifndef NODELIST_H
#define	NODELIST_H


#define MIN_ITERATION_CHANGE 0.0001
#include "Node.h"
#include "Resistor.h"
using namespace std;

class Nodelist{
public:
    Node* head;
    Nodelist();
    ~Nodelist();
    Node* findOrInsert(int id);
    Node* findNode(int id);//merge in to findor inset
    void insertRtoN(double value, string name, int id[2]);
    bool checksetV();
    Resistor** findResistor(string name);
    bool changeResistance(double, string);
    bool deleteResistor(string name);
    bool deleteNode();
    void deleteAllR();
    void print();
    void solve();
    bool checknonsetV();
    void printsolve();
};



#endif	/* NODELIST_H */

