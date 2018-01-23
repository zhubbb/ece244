
/*
 * File:   parser.cpp
 * Author: zhang823
 * Name: Xian Zhang
 * Student number: 1000564766
 * This program help to parser the user input related to resistors.
 *
 * Created on September 22, 2014, 6:58 PM
 */

#include "Node.h"
#include "Rparser.h"
#include "Resistor.h"


bool allocated=0;


//we assume rescount is the "number of resistor added" start from 1.

bool checkrepeatition(string R_name, Resistor** resistorpointer,int rescount){
    bool repeated=0;
    for(int i=0;i<rescount-1&&!repeated;i++){
        if(R_name==(resistorpointer[i])->getName())
            repeated=1;
    }
    return repeated;
}

int search(string R_name, Resistor** resistorpointer,int rescount){
    bool repeated=0;
    int resIndex=-1;
    for(int i=0;i<rescount&&!repeated;i++){
        if(R_name==(resistorpointer[i])->getName()){
            resIndex=i;
            repeated=1;
        }
    }
    return resIndex;
}

//print >
void coutarrow(){
    cout << '>';
    coutspace();
    return;
}
void coutspace(){
    cout << ' ';
    return;
}
//we need to clear the space before we check eof to avoid the situation: 'space'-> thus no eof
void clearspace(stringstream &lineStream){
    while(lineStream.peek()==' '){
    lineStream.ignore(1);
    }
}
bool checkconsistence(stringstream &lineStream){
    //e.g. 12a >> int will read 12 first but leave char 'a'.
    //if next string is not space means the input is not consistent
    if(!lineStream.eof()&&lineStream.peek()!=' '){
    return 0;
    }
    return 1;
}
//detect eof
bool checkeof(stringstream &lineStream){
    clearspace(lineStream);
    return lineStream.eof();
}
//detect error invalid input
bool checkfail(stringstream &lineStream){
    if(lineStream.fail()){
    // fail beacause "spcae" and thus into eof
        if(lineStream.eof()){
            return 0;
        }
        else{
            lineStream.ignore(1000,'\n');
            //invalid command
            return lineStream.fail();
        }
    }
    else if(!checkconsistence(lineStream)){
        return 1;
    }
    return 0;
}
bool locateError(string command, stringstream &lineStream, bool few, string R_name, int R_value, int nodeid, int nodeid1, int nodeid2){
    if(checkfail(lineStream)){
        cout << "Error: invalid argument" << endl;
        return 0;
    }
    else if(R_value<0){ //else???????
        cout << "Error: negative resistance" << endl;
        return 0;

    }


    else if(((nodeid2 <0) || (nodeid2 > MAX_NODE_NUMBER )||(nodeid1 < 0)||(nodeid1 > MAX_NODE_NUMBER))&&command=="insertR" ){
        if ((nodeid2 <0) || (nodeid2 > MAX_NODE_NUMBER ))
        cout << "Error: node " << nodeid2 << " is out of permitted range 0-" << MAX_NODE_NUMBER <<endl;
        if ((nodeid1 <0) || (nodeid1 > MAX_NODE_NUMBER))
        cout << "Error: node " << nodeid1 << " is out of permitted range 0-" << MAX_NODE_NUMBER <<endl;
        return 0;

    }

    else if( (nodeid < 0||nodeid > MAX_NODE_NUMBER)&&command=="printNode" ){
        cout << "Error: node " << nodeid << " is out of permitted range 0-" << MAX_NODE_NUMBER <<endl;
        return 0;
    }
    else if((command=="insertR"||command=="modifyR")&&R_name=="all"){
        cout << "Error: resistor name cannot be the key word \"all\"" << endl;
        return 0;
    }
    //check this only when not too few argument and insertR modifyR,this works only when nodeid2 is the last term to input.!few
    else if((command=="insertR"||command=="modifyR")&&!few&&nodeid1==nodeid2){
        cout << "Error: both terminals of resistor connect to node " << nodeid1 << endl;
        return 0;
    }
    else if(!checkeof(lineStream)){
        cout << "Error: too many arguments" << endl;
        return 0;
    }
    else if(few){
        cout << "Error: too few arguments" << endl;
        return 0;
    }
    else if(command=="maxVal"&&(nodeid1<=0||nodeid2<=0)){
        cout <<"Error: maxVal arguments must be greater than 0" << endl;
        return 0;
    }
    return 1;
}


int parser(Node*& nodepointer, Resistor**& resistorpointer) {
    int rescount=0;
    string line;
    void coutarrow();
    void coutspace();


    // May have some setup code here
    coutarrow();
    getline (cin, line); // Get a line from standard input

    while ( !cin.eof () ) {
    //reset value to 0;  string will reset to \0 when redeclare.

        string command, R_name;
        double R_value=0;
        //Make sure the id1 and 2 are different when initialize
        int nodeid1=0, nodeid2=1;
        int nodeid=0;
        bool printed=0;
        bool few=0;
        bool printresult=1;
        stringstream lineStream (line);//turn line string into stream
        lineStream >> command;

        //there are 2 situations: space->cin.fail()->eof ; "something" ->eof ,and cin.fail() falg will not be generated.
        //the problem is that when we have '\n' read into command it will be thought as nothing and thus will not go through the if else process/procedure.


        if (command == "insertR"&&allocated) {
        //rescount didnot update here at first
        // parse an insertR command
        //get name o if(R_name==NULL)  f resistor if name is null
            lineStream >> R_name >> R_value >> nodeid1;
            few=checkeof(lineStream);
            //get nodeid2
            lineStream >> nodeid2;
            if(locateError(command, lineStream, few, R_name, R_value, nodeid, nodeid1, nodeid2)){
                if(rescount >= maxResistors){
                cout << "Error: resistor array is full" << endl;
                }
                else if(!nodepointer[nodeid1].addResistor(rescount)||!nodepointer[nodeid2].addResistor(rescount)){
                        cout << "Error: node is full" << endl;
                }
                else if(checkrepeatition(R_name,resistorpointer,rescount+1))
                    cout << "Error: resistor " << R_name << " already exists" << endl;
                else{
                    cout << "Inserted: resistor " << R_name << " " << fixed << setprecision(2) << R_value << " Ohms ";
                            cout << nodeid1 << " -> " << nodeid2 << endl;
                            int nodeidarray[2]={nodeid1,nodeid2};
                            resistorpointer[rescount]=new Resistor(rescount,R_name,R_value,nodeidarray);
                            rescount++;//updated the rescount only when success
                            nodepointer[nodeid1].numadding();//add numRes
                            nodepointer[nodeid2].numadding();
                }
            }
        }




        else if (command=="maxVal"){
            int tempmaxNodeNumber=0,tempmaxResistors=0;
            lineStream >> tempmaxNodeNumber;
            few=checkeof(lineStream);
            lineStream >> tempmaxResistors;
            // max XXXX  pass to the position that suppose to be nodeid1 and nodeid2
            if(locateError(command, lineStream, few, R_name, R_value, nodeid, tempmaxNodeNumber, tempmaxResistors)){
                maxNodeNumber=tempmaxNodeNumber;
                maxResistors=tempmaxResistors;
                if(allocated)
                    clear(nodepointer,resistorpointer,rescount);
                reset(rescount,allocated);
                cout << "New network: max node number is " << tempmaxNodeNumber << "; max resistors is " << tempmaxResistors << endl;
                allocation(nodepointer,resistorpointer);
                allocated=1;
            }
        }
        else if (command == "modifyR" ) {
        // read name and resistance
            lineStream >> R_name;
            few=checkeof(lineStream);
            lineStream >> R_value;
            if(locateError(command, lineStream, few, R_name, R_value, nodeid, nodeid1, nodeid2)){

                int indice= search(R_name, resistorpointer, rescount);//indice==-1 do not find
                if(indice!=-1){
                    cout << "Modified: resistor " << R_name << " from " << fixed << setprecision(2) << resistorpointer[indice]->getResistance() <<" Ohms to " << fixed << setprecision(2) << R_value << " Ohms " << endl;
                    resistorpointer[indice]->setResistance(R_value);
                }
                else
                    cout << "Error: resistor " << R_name << " not found" << endl;
            }
        }
        else if (command == "deleteR") {
            few=checkeof(lineStream);
            lineStream >> R_name;
            if(locateError(command, lineStream, few, R_name, R_value, nodeid, nodeid1, nodeid2)){
                if(R_name=="all"){
                    cout << "Deleted: all resistors" << endl;
                    if(allocated){
                        clear(nodepointer,resistorpointer,rescount);
                        reset(rescount,allocated);
                        allocation(nodepointer,resistorpointer);
                        allocated=1;
                    }
                }
                else
                cout << "Deleted: resistor " << R_name << endl;

            }
        }
        else if (command == "printNode"){
            // eof itself cannot generate cin.fail flag at first, but i will generate fail and eof when the eof if caused by space// but it can generate eof without fail
            few=checkeof(lineStream);
            bool printall=0;
            string nodename;                          //node name user typed, cannot use "line" because line contains two words
            lineStream >> nodename;
            stringstream lineStream_2(nodename);
            lineStream_2 >> nodeid;
            //to see if there is a white space but nothing else
            //check if the stream pass a number int
            if(checkfail(lineStream_2)){
                if(nodename=="all"){
                        printall=1;

                }
                else{
                    lineStream_2.ignore('\n');//ignore the whole phrase until meet \n
                    lineStream_2.clear();
                    cout << "Error: invalid argument" << endl;
                    printed=1;
                }
            }

            if(!printed && locateError(command, lineStream, few, R_name, R_value, nodeid, nodeid1, nodeid2)){
                cout << "Print:" << endl;
                if( printall==0&&nodepointer!=NULL)
                    nodepointer[nodeid].print(nodeid,resistorpointer);

                else if(printall==1&&nodepointer!=NULL){
                    for(int i=0;i<=maxNodeNumber;i++){
                        nodepointer[i].print(i,resistorpointer);
                    }
                }
            }
        }
        else if(command=="printR"){
            // eof itself cannot generate cin.fail flag at first, but i will generate fail and eof when the eof if caused by space// but it can generate eof without fail
            few=checkeof(lineStream);
            lineStream >> R_name;
            if(locateError(command, lineStream, few, R_name, R_value, nodeid, nodeid1, nodeid2)){
                int indice= search(R_name, resistorpointer, rescount);//indice==-1 do not find

                if(R_name=="all"){
                    cout << "Print:" << endl;
                    for(int i=0;i<rescount&&resistorpointer[i]!=NULL;i++)
                        resistorpointer[i]->print();
                }
                else if(indice!=-1){
                    cout << "Print:" << endl;
                    resistorpointer[search(R_name,resistorpointer,rescount)]->print();
                }

                else if(indice==-1)
                    cout << "Error: resistor "<< R_name <<" not found" << endl;
            }
        }
        else {
            cout << "Error: invalid command" << endl;
                printed=1;
                printresult=0;
        }

    //since we want to save the flag eof to determine if is too many we can clear the flag at last.
    cin.clear();
    lineStream.clear();
    coutarrow();
    getline (cin, line);
    } // End input loop until EOF.
return 0;
}


