#ifndef GRIPPERINTERFACE_HPP
#define GRIPPERINTERFACE_HPP
#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_cpp/action_node.h>
#include <string>

class GripperInterface 
{
public:

    GripperInterface(); 

    // Method to open the gripper
    BT::NodeStatus open() ;
    

    // Method to close the gripper
    BT::NodeStatus close() ;
   
        

private:
    bool _open; // shared information to track the state of the gripper
};

#endif // GRIPPERINTERFACE_HPP  