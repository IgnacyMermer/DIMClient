#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "../dim/dim/dic.hxx"
#include "../dim/dim/dis.hxx"



int main()
{
    DimInfo runNumber("DELPHI/RUN_NUMBER",-2);
    DimInfo runNumber2("DELPHI/RUN_NUMBER2",-2);
    int index = 0;
    int services;
    DimBrowser br;
    std::cout<< "from "<< DimClient::getServerName() << " services:";
    std::cout<<"DelphiServer started and run service with updating number";
    int n = br.getServices("*");
	std::cout << "found " << n << " services"; 
    char *server, *ptr, *ptr1;
    int type;
	
	while((type = br.getNextService(ptr, ptr1))!= 0){
		//std::cout << "type = " << type << " - " << ptr << " " << ptr1;
	}

    DimInfo scoreNumber("CALCULATOR/SCORE", 0);

    sleep(1);
    while(1){
        std::cout << scoreNumber.getInt()<<"\n";
        std::string command;
        int firstNumber, secondNumber;
        std::cout<<"Podaj komende (ADD, SUBSTRACT, MULT, DIVIDE)"<<'\n';
        std::cin>>command;
        std::cout<<'\n'<<"Pierwsza liczba"<<'\n';
        std::cin>>firstNumber;
        std::cout<<'\n'<<"Druga liczba:"<<'\n';
        std::cin>>secondNumber;
        std::string fullCommand = (command+"_"+std::to_string(firstNumber)+"_"+std::to_string(secondNumber));
        std::cout<<fullCommand.c_str()<<'\n';
        DimClient::sendCommand("CALCULATOR/OPERATION", fullCommand.c_str());
        sleep(2);
    }

    /*for(int i=0; i<10; i++){
        //run+=1;
        std::cout<<"Run Number ";
        std::cout<<(std::to_string(runNumber.getInt()))<<'\n';
        std::cout<<(std::to_string(runNumber2.getInt()))<<'\n';
        DimClient::sendCommand("DELPHI/TEST/CMND","DO_IT");
        sleep(5);
    }*/

    //std::cout<<runNumber.getInt();

    /*DimInfo runNumber("DELPHI/RUN_NUMBER", -1);
    while(1)
    {
            std::cout << runNumber.getInt()<<"\n";
    }

    /*DimInfo runNumber("DELPHI/RUN_NUMBER", -1);
    while(1)
    {
            std::cout<<(std::to_string(runNumber.getInt()))<<'\n';
    }

}*/
/*class RunNumber : public DimInfo{
    
    void infoHandler()
    {
        std::cout << "Run Number " << getInt() << '\n';
    }
    public :
        RunNumber() : DimInfo("DELPHI/RUN_NUMBER",-1) {};

};

int main(){
    RunNumber runNumber;
    DimBrowser br;
    int n = br.getServices("*");
    DimInfo runNumber2("DELPHI/RUN_NUMBER2",-1);
    
    while(1){
        std::cout << "Run Number2 " << runNumber2.getInt() << '\n';
        pause();
    }
*/
}
