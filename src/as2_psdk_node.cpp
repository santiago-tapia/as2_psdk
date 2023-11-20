#include "as2_psdk/as2_psdk_node.hpp"

namespace as2::as2_psdk {

void As2PsdkNode::configureSensors() {}

bool As2PsdkNode::ownSendCommand() {}

bool As2PsdkNode::ownSetArmingState(bool state) {}

bool As2PsdkNode::ownSetOffboardControl(bool offboard) {}

bool As2PsdkNode::ownSetPlatformControlMode(const as2_msgs::msg::ControlMode &msg) {}

void As2PsdkNode::ownKillSwitch() {}

void As2PsdkNode::ownStopPlatform() {}

}  // namespace as2::as2_psdk
