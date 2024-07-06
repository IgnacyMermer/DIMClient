#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <dis.h>
#include <fstream>
#include <iostream>
//#include <stdin.h>
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
    DimServer::start("DelphiServer");
    int run = 1;
    //DimInfo runNumber("DELPHI/RUN_NUMBER",-1);
    DimInfo runNumber("TEST/INTVAL",-1);
    //DimService runNumber2("DELPHI/RUN_NUMBER",run);
    //runNumber2.updateService();
//  ...
    //std::cout << "Run Number " << runNumber.getInt();
    int index = 0;
    int services;
    DimBrowser br;
    //services = br.getServerServices("DelphiServer");
    std::cout<< "from "<< DimClient::getServerName() << " services:";
    std::cout<<"DelphiServer started and run service with updating number";
    int n = br.getServices("*");
	std::cout << "found " << n << " services"; 
    char *server, *ptr, *ptr1;
    int type;
	
	/*while((type = br.getNextService(ptr, ptr1))!= 0)
	{
		std::cout << "type = " << type << " - " << ptr << " " << ptr1;
	}*/

    /*for(int i=0; i<10; i++){
        run+=1;
        runNumber2.updateService();
        std::cout<<"Run Number ";
        std::cout<<(std::to_string(runNumber.getInt()));
        sleep(5);
    }*/

    /*while(services[index])
    {
        std::cout << services[index];
        index++;
    }*/
    std::cout<<runNumber.getInt();
    int a=10;
    std::cout<<a;
}
