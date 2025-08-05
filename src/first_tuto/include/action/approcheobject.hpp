#ifndef APPPROCHEOBJECT_HPP
#define APPPROCHEOBJECT_HPP


#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_cpp/action_node.h>
#include <string>


class ApproachObject : public BT::SyncActionNode
{
public:
    
    ApproachObject(const std::string& name, const BT::NodeConfig& config);

   
    static BT::PortsList providedPorts();

   
    BT::NodeStatus tick() override;
};

#endif // APPPROCHEOBJECT_HPP