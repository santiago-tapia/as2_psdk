#include "as2_psdk/as2_psdk_node.hpp"
#include "details/as2_psdk_node_impl.hpp"

namespace as2::as2_psdk
{

As2PsdkNode::As2PsdkNode()
: _impl(new As2PsdkNode_impl{}) {}

void As2PsdkNode::configureSensors()
{
  _impl->init(this);
  if (!_impl->setLocalPositionService.wait_for_service()) {
    // TODO: Since waiting is cancelled, is it neccesary any further action?
    RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
  }
}

bool As2PsdkNode::ownSendCommand()
{
  // TODO: Look for the service to set reference and get control authority
  if (platform_info_msg_.current_control_mode.control_mode == as2_msgs::msg::ControlMode::HOVER) {
    // send all zeros
    _impl->velocityCommand->axes[0] = 0.0f;  // x(m)
    _impl->velocityCommand->axes[1] = 0.0f;
    _impl->velocityCommand->axes[2] = 0.0f;
    _impl->velocityCommand->axes[3] = 0.0f;  // yaw (rad)
    _impl->velocityCommand.publish();
    RCLCPP_INFO(this->get_logger(), " HOVERING");
    return true;
  }
  /*
  if (!this->has_new_references_) {
    RCLCPP_DEBUG_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                          "No new references since mode change");
    return true;
  }
  double x, y, z, yaw;
  x = y = z = yaw = 0.0;

  if (platform_info_msg_.current_control_mode.yaw_mode == as2_msgs::msg::ControlMode::YAW_ANGLE) {
    tf2::Quaternion q(
        this->command_pose_msg_.pose.orientation.x, this->command_pose_msg_.pose.orientation.y,
        this->command_pose_msg_.pose.orientation.z, this->command_pose_msg_.pose.orientation.w);
    tf2::Matrix3x3 m(q);
    double _a, _b, yaw_;
    m.getRPY(_a, _b, yaw);
    yaw = -yaw * 180.0 / M_PI;
  } else if (platform_info_msg_.current_control_mode.yaw_mode ==
             as2_msgs::msg::ControlMode::YAW_SPEED) {
    yaw = -this->command_twist_msg_.twist.angular.z * 180.0 / M_PI;
  } else {
    RCLCPP_ERROR(this->get_logger(), "Unknown yaw mode");
    return false;
  }

  switch (platform_info_msg_.current_control_mode.control_mode) {
    // case as2_msgs::msg::ControlMode::POSITION: {
    // } break;
    case as2_msgs::msg::ControlMode::SPEED: {
      // Conversion from AS2 ENU frame into DJI NEU frame
      x = this->command_twist_msg_.twist.linear.y;
      y = this->command_twist_msg_.twist.linear.x;
      z = this->command_twist_msg_.twist.linear.z;
    } break;
    // case as2_msgs::msg::ControlMode::SPEED_IN_A_PLANE: {
    // } break;
    // case as2_msgs::msg::ControlMode::ACRO: {
    // } break;
    default:
      RCLCPP_ERROR(this->get_logger(), "Unknown control mode in send command");
      return false;
  }
  // vehicle_->flightController->setJoystickMode(dji_joystick_mode_);
  // FlightController::JoystickCommand joystick_cmd = {
  //     (float)x,
  //     (float)y,
  //     (float)z,
  //     (float)yaw,
  // };
  // vehicle_->flightController->setJoystickCommand(joystick_cmd);
  // vehicle_->flightController->joystickAction();
  */
  return true;
}

bool As2PsdkNode::ownSetArmingState(bool state) {return false;}

bool As2PsdkNode::ownSetOffboardControl(bool offboard) {return false;}

bool As2PsdkNode::ownSetPlatformControlMode(const as2_msgs::msg::ControlMode & msg) {return false;}

void As2PsdkNode::ownKillSwitch() {}

void As2PsdkNode::ownStopPlatform() {}

}  // namespace as2::as2_psdk
