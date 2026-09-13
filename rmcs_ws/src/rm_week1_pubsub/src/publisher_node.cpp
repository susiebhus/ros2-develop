#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node {
 public:
  PublisherNode() : Node("publisher_node"), sequence_(0) {
    publisher_ = create_publisher<std_msgs::msg::String>("training_message", 10);
    timer_ = create_wall_timer(500ms, std::bind(&PublisherNode::publish_message, this));
  }

 private:
  void publish_message() {
    std_msgs::msg::String message;
    message.data = "RoboMaster ROS 2 training message #" + std::to_string(sequence_++);
    publisher_->publish(message);
    RCLCPP_INFO(get_logger(), "Published: '%s'", message.data.c_str());
  }

  std::size_t sequence_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PublisherNode>());
  rclcpp::shutdown();
  return 0;
}
