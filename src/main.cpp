#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <dis.h>
#include <fstream>
#include <iostream>
//#include "../dim/dim/dis.hxx"
#include "../dim/dim/dic.hxx"
#include "../dim/dim/dis.hxx"


/*
DimInfo runNumber("DELPHI/RUN_NUMBER",5,-1);
//  ...
cout << "Run Number " << runNumber.getInt() << endl;
*/

/*class RunNumber : public DimInfo
{
    void infoHandler()
    {s
        std::cout<<("Run Number ");
        std::cout<<(getInt());
    }
    public :
        RunNumber() : DimInfo("DELPHI/RUN_NUMBER",-1) {};
};*/

int main()
{
    //DimInfo runNumber("DELPHI/RUN_NUMBER",5,-1);
    DimServer::start("DelphiServer");
//  ...
    //std::cout << "Run Number " << runNumber.getInt() << endl;
    int a=10;
    std::cout<<a;
}
