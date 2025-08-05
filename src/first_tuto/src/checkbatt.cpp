#include <behaviortree_cpp/bt_factory.h>
#include "action/checkbatt.h"

#include <iostream>


using namespace BT;


NodeStatus CheckBattery()
{
  std::cout << "[ Battery: OK ]" << std::endl;
  return NodeStatus::SUCCESS;
}


