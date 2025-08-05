#include <behaviortree_cpp/bt_factory.h>
#include "condition/pedestrianrequest.h"


#include <iostream>


using namespace BT;


NodeStatus PedestrianRequest()
{
    int c = getchar();         
    if (c == 'a' || c == 'A')  
    {
        
        std::cout << "Piedestrian request received." << std::endl;
        
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "No request from the pedestrian received" << std::endl;
    return BT::NodeStatus::FAILURE;
}


    