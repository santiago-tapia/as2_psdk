
#ifndef AS2_OUTPUT_HPP_10348241798
#define AS2_OUTPUT_HPP_10348241798

namespace as2::as2_psdk {

template <typename Name, typename Msg>
class Output {
public:
  using PublisherSharedPtr = typename rclcpp::Publisher<Msg>::SharedPtr;

  void init(rclcpp::Node* node) { publisher_ = node->create_publisher<Msg>(Name::name, 10); }

  void publish() const { publisher_->publish(state_variable); }

  Msg* operator->() { return &state_variable; }

protected:
  Msg state_variable;
  PublisherSharedPtr publisher_;
};

}  // namespace as2::as2_psdk

#endif