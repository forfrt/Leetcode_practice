//! http://cis.stvincent.edu/html/tutorials/swd/hash/hash.cpp

#include "hash.h"

void Error(char *msg){
    cerr<< msg << endl;
    exit(1);
}

void HashTableClass::HandleOpenRead(char * FileName){

    NodeType Node;

    NodeSize=sizeof(Node);

    DataFile.open(FileName, ios::in | ios::binary);
    if(DataFile.fail())
        Error("Binary data file cannot be opened for input");

    DataFile.read(reinterpret_cast<car *>(&Node), NodeSize);

    if(DataFile.fail())
        NumItems=0
    else
        NumItems=Node.Info.KeyField;
}

void HashTableClass::HandleOpenWrite(char * FileName){
    NodeType Node;
    long k;

    NodeSize=sizeof(Node);

    DataFile.open(FileName, ios::out|ios::in|ios::binary|ios::trunc);
    if(DataFile.fail())
        Error("Binary Data file cannot be opened for input/output");

    Node.Info.KeyField=0;
    Node.Next=NilPtr;

    for(k=0; k<=MaxFile; k++)
        DataFile.write(reinterpret_cast<char *> (&Node), NodeSize);
    NumItems=0;
    OverflowIndex=Prime+1;
}

HashTableClass::HashTableClass(char Mode, char * FileName){

    OpenMode=Mode;

    if(Mode=='r')
        HandleOpenRead(FileName);
    else if(Mode=='w')
        HandleOpenWrite(FileName);
    else
        Error("Incorrect mode given to HashTableClass constructor");

}



























