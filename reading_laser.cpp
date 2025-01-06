#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

class LaserFilter : public rclcpp::Node {
public:
  LaserFilter() : Node("laser_filter") {
    subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
      "/scan", 10,
      std::bind(&LaserFilter::scan_callback, this, std::placeholders::_1));
    publisher_ = this->create_publisher<sensor_msgs::msg::LaserScan>("/filtered_scan", 10);
  }

private:
  void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
    auto filtered_msg = *msg;
    for (size_t i = 0; i < msg->ranges.size(); ++i) {
      if (msg->angle_min + i * msg->angle_increment < -1.047 || 
          msg->angle_min + i * msg->angle_increment > 1.047) {
        filtered_msg.ranges[i] = std::numeric_limits<float>::infinity();
      }
    }
    publisher_->publish(filtered_msg);
  }
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
  rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr publisher_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LaserFilter>());
  rclcpp::shutdown();
  return 0;
}
