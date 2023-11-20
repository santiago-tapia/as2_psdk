#include "as2_psdk_node_impl.hpp"
#include "rclcpp/rclcpp.hpp"

namespace as2::as2_psdk {

As2PsdkNode_impl::As2PsdkNode_impl() {}

void As2PsdkNode_impl::init(rclcpp::Node *node) { velocityCommand.init(node); }

}  // namespace as2::as2_psdk