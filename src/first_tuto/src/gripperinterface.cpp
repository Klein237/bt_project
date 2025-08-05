#include "action/gripperinterface.hpp"
#include <iostream>

GripperInterface::GripperInterface() : _open(false)  
{}

BT::NodeStatus GripperInterface::open() 
{
    if(!_open) {
        _open = true;
        std::cout << "Gripper is open." << std::endl;
        return BT::NodeStatus::SUCCESS; // Gripper is already open
    }
    std::cout << "Gripper is already open." << std::endl;
    return BT::NodeStatus::FAILURE; // Gripper was not open, so we opened it
}   


BT::NodeStatus GripperInterface::close() 
{
    if(_open) {
        _open = false;
        std::cout << "Gripper is closed." << std::endl;
        return BT::NodeStatus::SUCCESS; // Gripper is already closed
    }
    std::cout << "Gripper is already close." << std::endl;
    return BT::NodeStatus::FAILURE;
}
