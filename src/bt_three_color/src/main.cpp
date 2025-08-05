#include "behaviortree_cpp/bt_factory.h"
#include "action/triggerlight.hpp"
#include "condition/pedestrianrequest.h"
#include <iostream>
#include "config/keymonitor.cpp"
#include <behaviortree_cpp/loggers/groot2_publisher.h>      // pour la visualisation en temps réel :contentReference[oaicite:0]{index=0}
#include <behaviortree_cpp/loggers/bt_file_logger_v2.h>



int main()
{
    // Configure the terminal for non-canonical mode and non-blocking input
    configureTerminal();

    // We use the BehaviorTreeFactory to register our custom nodes
    BT::BehaviorTreeFactory factory;

    // Registering the TriggerLight action node
    factory.registerNodeType<TriggerLight>("TriggerLight");

    // Registering the CheckRequest condition node
    // factory.registerSimpleCondition("PedestrianRequest", PedestrianRequest);
    factory.registerSimpleCondition("PedestrianRequest", [&](BT::TreeNode&) { return PedestrianRequest(); });

    // Create a tree from an XML file
    auto tree = factory.createTreeFromFile("/home/klein/BT_project/src/bt_three_color/src/traffic_color.xml");

    tree.rootBlackboard()->set("current_state", std::string("RED"));

    //BT::FileLogger2 file_logger(tree, "/home/klein/BT_project/src/bt_three_color/src/bt_trace2.btlog");
    //BT::PublisherZMQ publisher(tree, "tcp://*:5555");
    // BT::Groot2Publisher groot_publisher(tree, "tcp://*:5555");
    BT::Groot2Publisher publisher(tree);

    // To "execute" a Tree you need to "tick" it.
    tree.tickWhileRunning();

    //BT::Groot2Publisher publisher(tree);
    //tree.tickOnce();

    

    // Restore the terminal settings before exiting
    restoreTerminal();

    return 0;
}