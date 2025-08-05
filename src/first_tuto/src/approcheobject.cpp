#include "action/approcheobject.hpp"
#include <iostream>
#include <string>



ApproachObject::ApproachObject(const std::string& name, const BT::NodeConfig& config) : BT::SyncActionNode(name, config)   
{ }

 BT::PortsList ApproachObject::providedPorts()
{
    return {BT::InputPort<std::string>("message")};
}


BT::NodeStatus ApproachObject::tick() 
{
    std::string message; 
    if (!getInput("message", message))
    {
        throw BT::RuntimeError("Missing required input [type_alarm] ");
    }
    std::cout << "ApproachObject: "<< message << std::endl;
    return BT::NodeStatus::SUCCESS;
}
