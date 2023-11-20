#ifndef AS2_NODE_AS2_PSDK_NODE_HPP_10982741902451
#define AS2_NODE_AS2_PSDK_NODE_HPP_10982741902451

#include <rclcpp/rclcpp.hpp>
#include "as2_core/aerial_platform.hpp"

namespace as2::as2_psdk {

class As2PsdkNode : public as2::AerialPlatform {
public:
  virtual void configureSensors() override;
  virtual bool ownSendCommand() override;
  virtual bool ownSetArmingState(bool state) override;
  virtual bool ownSetOffboardControl(bool offboard) override;
  virtual bool ownSetPlatformControlMode(const as2_msgs::msg::ControlMode &msg) override;
  virtual void ownKillSwitch() override;
  virtual void ownStopPlatform() override;
};

}//namespace

#endif
