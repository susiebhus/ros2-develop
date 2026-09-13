#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SubscriberNode : public rclcpp::Node {
 public:
  SubscriberNode() : Node("subscriber_node") {
    subscription_ = create_subscription<std_msgs::msg::String>(
        "training_message", 10,
        [this](const std_msgs::msg::String::SharedPtr message) {
          RCLCPP_INFO(get_logger(), "Received: '%s'", message->data.c_str());
        });
  }

 private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SubscriberNode>());
  rclcpp::shutdown();
  return 0;
}
