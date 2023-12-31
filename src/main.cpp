// Copyright (c) UPM 2023 Santiago Tapia-Fernández

#include "as2_psdk/as2_psdk_node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<as2::as2_psdk::As2PsdkNode>();
  // node->preset_loop_frequency(50);  // Node frequency for run and callbacks
  // // Node with only callbacks
  // as2::spinLoop(node);
  // // Node with run
  // // as2::spinLoop(node,std::bind(&As2NodeTemplate::run, node));
  rclcpp::shutdown();
  return 0;
}
