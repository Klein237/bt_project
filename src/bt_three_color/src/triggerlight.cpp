#include "action/triggerlight.hpp"
#include <iostream>
#include <behaviortree_cpp/bt_factory.h>

TriggerLight::TriggerLight(const std::string& name, const BT::NodeConfig& config)
    : BT::StatefulActionNode(name, config)
{
}

BT::PortsList TriggerLight::providedPorts()
{
    return {BT::InputPort<std::string>("current_state"), 
            BT::OutputPort<std::string>("current_state"),
            BT::InputPort<std::string>("state")};
}


// BT::NodeStatus TriggerLight::tick()
// {
//     std::string current_state, state;
//     if ( !getInput<std::string>("current_state", current_state) ||
//         !getInput<std::string>("state",         state))
//     {
//         throw BT::RuntimeError("missing required port");
//     }

//     if (state == current_state)
//     {
//         std::cout << "Light is already in the desired state: " << state << std::endl;
//         //setOutput("current_state", state);
//         return BT::NodeStatus::FAILURE;
//     }else 
//     {
//         std::cout << "Light changed from: " << current_state << std::endl;
//         current_state = state;
//         setOutput("current_state", current_state);
//          // Simulate triggering the light with the specified color
//         std::cout << "Triggering light with color: " << state << std::endl;
        
//         return BT::NodeStatus::SUCCESS;
//     }

   

//     // Return success after triggering the light
//     return BT::NodeStatus::SUCCESS;
// }


BT::NodeStatus TriggerLight::onStart() {
    std::string current_state, state;
    if (!getInput<std::string>("current_state", current_state) ||
        !getInput<std::string>("state", state)) {
        throw BT::RuntimeError("missing required port");
    }
    
    // Store the target state for later use
    _target_state = state;
    
    if (current_state == state) {
        return BT::NodeStatus::SUCCESS;
    }
    
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus TriggerLight::onRunning() {
    // Update the blackboard directly
    config().blackboard->set("current_state", _target_state);
    std::cout << "Light changed to: " << _target_state << std::endl;
    return BT::NodeStatus::SUCCESS;
}


    void TriggerLight::onHalted()
    {
        StatefulActionNode::halt();
        std::cout << "TriggerLight halted." << std::endl;

    // You can add any cleanup code here if needed
    }