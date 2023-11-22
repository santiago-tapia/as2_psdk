#ifndef AS2_NODE_AS2_PSDK_NODE_HPP_IMPL_15980375293057295U9
#define AS2_NODE_AS2_PSDK_NODE_HPP_IMPL_15980375293057295U9

#include "output.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "service_client.hpp"
#include "std_srvs/srv/trigger.hpp"

namespace as2::as2_psdk
{

struct VelocityCommand
{
  using Msg_t = sensor_msgs::msg::Joy;
  inline static std::string name = "/psdk_ros2/flight_control_setpoint_ENUposition_yaw";
  // TODO: Check the actual command name
};

// Service to set initial reference should be called before any control command
struct SetLocalPositionService
{
  using Msg_t = std_srvs::srv::Trigger;
  inline static std::string name = "/psdk_ros2/set_local_position_ref";
};

class As2PsdkNode_impl
{
public:
  Output<VelocityCommand> velocityCommand;
  ServiceClient<SetLocalPositionService> setLocalPositionService;

public:
  As2PsdkNode_impl();
  void init(rclcpp::Node *);
};

}  // namespace as2::as2_psdk

#endif
