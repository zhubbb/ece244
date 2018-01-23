


#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
string line, command;
string R_name;
int nodeid1=NULL;
int nodeid2=NULL;
double R_value=NULL;
// May have some setup code here
getline (cin, line); // Get a line from standard input
while ( !cin.eof () ) {
// Put the line in a stringstream for parsing
// Making a new stringstream for each line so flags etc. are in a known state
    
stringstream lineStream (line);//turn line string into stream
lineStream >> command;         //get the first word from stream as command       

   


if (command == "insertR") {
// parse an insertR command
    if(lineStream.fail()){
        if(lineStream.eof()){
            lineStream.clear();
                        
            //print out inserted message       
        }
        else{
            cout << "Error: Invalid argument";
            lineStream.ignore(1000,'\n');//ignore the whole phrase until meet \n
            lineStream.clear();
            
                    
        }   
    }
    else
        
           
            
    
          
        //get name o if(R_name==NULL)  f resistor if name is null
    lineStream >> R_name;
        //get resistance value
    if(lineStream.fail()){
        if(lineStream.eof()){
            lineStream.clear();
                        
            //print out inserted message       
        }
        else{
            cout << "Error: Invalid argument";
            lineStream.ignore(1000,'\n');//ignore the whole phrase until meet \n
            lineStream.clear();
            
                    
        }   
    }
    else

    lineStream >> R_value;
        //get nodeid1
    if(lineStream.fail()){
        if(lineStream.eof()){
            lineStream.clear();
                        
            //print out inserted message       
        }
        else{
            cout << "Error: Invalid argument";
            lineStream.ignore(1000,'\n');//ignore the whole phrase until meet \n
            lineStream.clear();
            
                    
        }   
    }
    else
     
    lineStream >> nodeid1;
    if(lineStream.fail()){
        if(lineStream.eof()){
            lineStream.clear();
                        
            //print out inserted message       
        }
        else{
            cout << "Error: Invalid argument";
            lineStream.ignore(1000,'\n');//ignore the whole phrase until meet \n
            lineStream.clear();
            
                    
        }   
    }
    else
        //get nodeid2
  
    lineStream >> nodeid2;
    
    //test to see if there is any invalid argument
    if(lineStream.fail()){
        if(lineStream.eof()){
            lineStream.clear();
                        
            //print out inserted message       
         }
         else{
             cout << "Error: Invalid argument";
             lineStream.ignore(1000,'\n');//ignore the whole phrase until meet \n
             lineStream.clear();
             
                    
         }   
    }
    else{

          cout << "Inserted: resistor " << R_name << setprecision(2)/*the setprecision has problem here neither 2 nor 0.2*/ << " " << R_value << " ohms ";
          cout << nodeid1 << "->" << nodeid2 << endl;
    }
    
    if(lineStream.fail()){
        if(lineStream.eof()){
            lineStream.clear();
                        
            //print out inserted message       
        }
        else{
            cout << "Error: Invalid argument";
            lineStream.ignore(1000,'\n');//ignore the whole phrase until meet \n
            lineStream.clear();
            
                    
        }   
    }
    else
        ;
  
    
    
}
        

    
    
    
   

    
    
    
    
    
    

else
;


getline (cin, line);
} // End input loop until EOF.
return 0;
}