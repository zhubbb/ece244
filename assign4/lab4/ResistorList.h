/*
 * File:   Resistorlist.h
 * Author: zhang823
 *
 * Created on November 3, 2014, 7:28 PM
 */

#ifndef RESISTORLIST_H
#define	RESISTORLIST_H



#include "Resistor.h"
    class Resistorlist{
    public:
        void deleteAllR();
        Resistor *head;
        Resistorlist();
        ~Resistorlist();
        bool deleteResistor(string name);
        Resistor* findResistor(string name);
        void insertR(double R_value,string R_name, int endpoints[2]);
        void print();
        //double getReqbetween(Node*);

    };




#endif	/* RESISTORLIST_H */

