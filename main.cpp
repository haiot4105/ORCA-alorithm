#include <iostream>
#include "Agent.h"
#include "Point.h"
#include "XmlLogger.h"
#include "Mission.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> numAg = vector<int>();
    //vector<int> numAg;
    int sup, inf, step;
    bool fileOpend;
    string log;
    if(argc < 2)
    {
        std::cout<<"Pathfinding log file (XML) is not specified!"<<std::endl;
        log = "logfile.txt";
        std::cout<<"Common log file name will be set: logfile.txt"<<std::endl;
        sup = 210, inf = 15, step = 15;
    }
    else
    {
        log = string(argv[1]);
        if (argc > 4)
        {
            try
            {
                string tmp = string(argv[2]);
                inf = stoi(tmp);
                tmp = string(argv[3]);
                step = stoi(tmp);
                tmp = string(argv[4]);
                sup = stoi(tmp);

            }
            catch(std::invalid_argument)
            {
                std::cout<<"Error reading arguments."<<std::endl;
                sup = 210, inf = 15, step = 15;
            }
        }
        else
        {
            std::cout<<"Number of agents is not specified!"<<std::endl;
            sup = 210, inf = 15, step = 15;
        }
    }

    std::cout<<"The number of agents will be set to the following values: ";
    for(int i = inf; i <= sup; i+= step)
    {
        numAg.push_back(i);
        cout<<i<<" ";
    }
    cout<<"\n";
    ofstream pre_log(log);
    pre_log<< "Success\tRuntime\tFlowtime\tMakespan\tCollisions\n";
    pre_log.close();
    pre_log.open("aaa.txt");
    pre_log.close();

    string tmpinp = "_task.xml";

    for(auto &num : numAg)
    {
        cout<<"Number of agents: "<<num<<"\n";
        for(int i = 0; i < 100; i++)
        {
            string inp = std::to_string(i) + tmpinp;
            string locallog = std::to_string(i) + "_" + std::to_string(num) + "_log.xml";
            cout<<"File: "<<inp<<"\n";
            Mission mission(inp, log, locallog, num, &fileOpend);
            if(fileOpend)
            {
                mission.StartMission();
            }
            else
            {
                break;
            }

        }
    }


    return 0;
}