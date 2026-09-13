# ROS2-develop

RoboMaster-南京理工大学Alliance战队2026赛季培训使用。

本质上是 [RMCS](https://github.com/Alliance-Algorithm/RMCS) 去除了全部 ROS 2 包，提供一个 Docker 启动的 ROS 2 开发环境，供 2026 赛季算法组培训成员作业使用。

## 第一周任务一：ROS 2 发布者与订阅者

`rmcs_ws/src/rm_week1_pubsub` 是一个 `ament_cmake` ROS 2 包，包含两个可独立运行的节点：

- `publisher_node`：每 500 ms 向 `training_message` 话题发布一条带序号的 `std_msgs/msg/String` 消息，并打印发布日志。
- `subscriber_node`：订阅同一话题；每次接收消息后，通过 ROS 2 Logger 打印 `Received: '...'`。

在 ROS 2 Jazzy 容器中，从仓库根目录进入工作空间并构建：

```bash
source /opt/ros/jazzy/setup.bash
cd rmcs_ws
colcon build --packages-select rm_week1_pubsub
source install/setup.bash
```

分别打开两个已执行上述 `source` 命令的终端：

```bash
ros2 run rm_week1_pubsub subscriber_node
```

```bash
ros2 run rm_week1_pubsub publisher_node
```
