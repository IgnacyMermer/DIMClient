#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "../dim/dim/dic.hxx"
#include "../dim/dim/dis.hxx"
#include <csignal>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

class RunVars : public DimClient
{
    DimInfo runNumber;
    DimInfo runType;
    std::atomic<bool> running;
    std::thread listenerThread;
    /*void listener() {
        while (running) {
            std::unique_lock<std::mutex> lock(mtx);
            //std::this_thread::sleep_for(std::chrono::seconds(1));
            infoHandler();
            //pause();
            lock.unlock();
            cv.notify_all();
            //std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }*/

public:
    RunVars():
        runNumber("CALCULATOR/SCORE", -1, this), 
        runType("DELPHI/RUN_TYPE", "not available", this),
        running(true)
        {}
        /*{
            listenerThread = std::thread(&RunVars::listener, this);
        }*/

    ~RunVars() {
        running = false;
        /*if (listenerThread.joinable()) {
            listenerThread.join();
        }*/
    }
    void infoHandler() {
        std::unique_lock<std::mutex> lock(mtx);
        DimInfo *curr = getInfo();
        std::cout<<"herer";
        if(curr == &runNumber) { 
            int run = curr->getInt(); 
            std::cout<<run<<'\n';
        }
        else { 
            char *type = curr->getString(); 
        };
        lock.unlock();
        cv.notify_all();
    }

    /*void run() {

        std::string input;
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
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
            std::cout<<"sended";
            sleep(3);
            //std::cout << scoreNumber.getInt()<<"\n";
            lock.unlock();
            cv.notify_all();
            //sleep(1);
            //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }*/
};


int main()
{
    DimInfo runNumber("DELPHI/RUN_NUMBER",-2);
    DimInfo runNumber2("DELPHI/RUN_NUMBER2",-2);
    int index = 0;
    int services;
    DimBrowser br;
    //std::signal(SIGINT, RunVars::infoHandler);
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
    RunVars runVars;

    sleep(1);
    bool isUpdate=false;
    while(1){
        //std::unique_lock<std::mutex> lock(mtx);
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
        //sleep(3);
        //std::cout << scoreNumber.getInt()<<"\n";
        //lock.unlock();
        //cv.notify_all();
        //sleep(1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    //RunVars rv;
    //rv.run();
    return 0;
}
