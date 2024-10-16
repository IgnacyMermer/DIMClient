#include <iostream>
#include "../dim/dim/dic.hxx"
#include "../dim/dim/dis.hxx"
#include <unistd.h>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>

int main()
{
    std::cout<<"test\n" << std::flush;
    int counterTemp=0;
    while(1){
        std::cout<<"send command\n" << std::flush;
        //DimClient::sendCommand("LAB/READOUTCARDS/TCM0/REFRESH_COUNTERS_REQ", std::string("go").c_str());
        //DimClient::sendCommand("LAB/READOUTCARDS/TCM0/REFRESH_DATA_REQ", std::string("go").c_str());
        //DimClient::sendCommand("LAB/READOUTCARDS/TCM0/REFRESH_PM_COUNTERS_REQ", std::string("go").c_str());
        //DimClient::sendCommand("LAB/READOUTCARDS/TCM0/REFRESH_PMS_REQ", std::string("go").c_str());
        DimClient::sendCommand("LAB/READOUTCARDS/TCM0/REFRESH_MAPI_GROUP_REQ", std::string("go").c_str());
        DimClient::sendCommand("LAB/PM/PMA0/REFRESH_PM_MAPI_GROUP_REQ", std::string("go").c_str());
        DimClient::sendCommand("LAB/READOUTCARDS/TCM0/REFRESH_MAPI_CNT_GROUP_REQ", std::string("go").c_str());
        DimClient::sendCommand("LAB/PM/PMA0/REFRESH_MAPI_PM_CNT_GROUP_REQ", std::string("go").c_str());
        DimClient::sendCommand("LAB/PM/PMC0/REFRESH_PM_MAPI_GROUP_REQ", std::string("go").c_str());
        DimClient::sendCommand("LAB/PM/PMC0/REFRESH_MAPI_PM_CNT_GROUP_REQ", std::string("go").c_str());
        DimClient::sendCommand("LAB/READOUTCARDS/TCM0/REFRESH_FV0_REQ", std::string("go").c_str());

        /*if(counterTemp==2){
            //DimClient::sendCommand("FIT_FRED/READOUTCARDS/FIT0/REFRESH_MAPI_COUNTERS_GROUP_REQ", std::string("go").c_str());
            counterTemp=0;
        }
        else{
            counterTemp++;
        }*/
        //usleep(1000000);
        counterTemp+=1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
