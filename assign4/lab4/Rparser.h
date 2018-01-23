/*
 * File:   Rparser.h
 * Author: zhang823
 *
 * Created on October 10, 2014, 9:04 PM
 */

#ifndef RPARSER_H
#define	RPARSER_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Node.h"
#include "Resistor.h"
#include "NodeList.h"



using namespace std;
void clear(Node*& nodepointer, Resistor**& resistorpointer,int rescount);
void reset(int& rescount, bool& allocated);
void allocation(Node*& nodepointer, Resistor**& resistorpointer);
void coutarrow();
void coutspace();
void clearspace(stringstream &lineStream);
bool checkconsistence(stringstream &lineStream);
bool checkeof(stringstream &lineStream);
bool checkfail(stringstream &lineStream);
bool locateError(string command, stringstream &lineStream, bool few, string R_name, int R_value, int nodeid, int nodeid1, int nodeid2);
int parser(Nodelist& Nlist);

#endif	/* RPARSER_H */

