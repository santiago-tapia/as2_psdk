#ifndef AS2_NODE_AS2_PSDK_NODE_HPP_IMPL_15980375293057295U9
#define AS2_NODE_AS2_PSDK_NODE_HPP_IMPL_15980375293057295U9

#include <sensor_msgs/msg/joy.hpp>
#include "output.hpp"

namespace as2::as2_psdk {

struct VelocityCommand {
  inline static std::string name = "/psdk_ros2/flight_control_setpoint_ENUposition_yaw";
};

class As2PsdkNode_impl {
public:
  Output<VelocityCommand, sensor_msgs::msg::Joy> velocityCommand;

public:
  As2PsdkNode_impl();
  void init(rclcpp::Node *);
};

}  // namespace as2::as2_psdk

#endif
