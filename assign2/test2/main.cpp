/* 
 * File:   main.cpp
 * Author: zhang823
 *
 * Created on September 23, 2014, 12:15 PM
 */


#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#define MAX_NODE_NUMBER = 5000;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string line, command, name ,argument, test;
    int nodeid1, nodeid2;
    
    double resistance;
    
    cout << ">" ;
    getline (cin, line);
    cin.clear();
    
    while(!cin.eof()){  // spcae kong ge ye ke tong guo eof cin     except ^d // shi eof er bu shi cin.fail because we want it repeat even fail until user type eof
     stringstream linestream(line);     // shua xin line    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! fo ze chong fu shu ru 
    linestream >>command;
       if(linestream.fail()){ //fail beacause "kong ge ---> eof"                
            if(linestream.eof()){
                linestream.clear();
                //set few =0 here;
               
            }
            else{
                linestream.ignore(1000,'\n');
                linestream.clear();  
                
                        
            }
               
        }
    else if (command=="insertR"){
        linestream >> name >> resistance >> nodeid1 ;
        linestream >> nodeid2;
       
        
        
        
        if(linestream.fail()){
            if(linestream.eof()){
                linestream.clear();
               
            }
            else{
                linestream.ignore(1000,'\n');
                linestream.clear();  
                
                        
            }
               
        }
        else{
            
        
        
       
        
        cout << "Inserted: resistor " << name << " " << fixed <<setprecision(2) <<resistance << " ohms ";
            cout << nodeid1 << "->" << nodeid2;
        }
    }
    
    getline (cin, line);// line meiyou qing kong
   
           
    }
    
    
    
    
    
    
    
    return 0;
}

