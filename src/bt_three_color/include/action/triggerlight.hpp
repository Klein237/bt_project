#ifndef TRIGGERLIGHT_HPP
#define TRIGGERLIGHT_HPP

#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_cpp/action_node.h>
#include <string>

class TriggerLight : public BT::StatefulActionNode
{
public:
    TriggerLight(const std::string& name, const BT::NodeConfig& config);

    static BT::PortsList providedPorts();

    // BT::NodeStatus tick() override;

    BT::NodeStatus onStart() override;

    BT::NodeStatus onRunning() override;

    void onHalted() override;

private:
    std::string _target_state;

};
#endif // TRIGGERLIGHT_HPP