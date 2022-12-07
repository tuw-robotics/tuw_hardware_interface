// Copyright 2022 Eugen Kaltenegger

#ifndef TUW_ROS_CONTROL_GENERIC_DESCRIPTION_GENERIC_HARDWARE_PARAMETER_DESCRIPTION_H
#define TUW_ROS_CONTROL_GENERIC_DESCRIPTION_GENERIC_HARDWARE_PARAMETER_DESCRIPTION_H

#include <map>
#include <memory>
#include <string>

#include <yaml-cpp/yaml.h>

namespace tuw_ros_control_generic
{
class GenericHardwareParameterDescription
{
public:
  explicit GenericHardwareParameterDescription(YAML::Node yaml);
  std::shared_ptr<std::string> getIdentifier();
  std::shared_ptr<std::string> getDescription();
  std::shared_ptr<int> getAddress();
  std::shared_ptr<int> getLength();
  std::shared_ptr<std::map<std::string, int>> getEnum();
  std::shared_ptr<std::map<std::string, int>> getRange();
protected:
  std::shared_ptr<std::string> identifier_ {nullptr};
  std::shared_ptr<std::string> description_ {nullptr};
  std::shared_ptr<int> address_ {nullptr};
  std::shared_ptr<int> length_ {nullptr};
  std::shared_ptr<std::map<std::string, int>> enum_ {nullptr};
  std::shared_ptr<std::map<std::string, int>> range_ {nullptr};
};
}  // namespace tuw_ros_control_generic

#endif  // TUW_ROS_CONTROL_GENERIC_DESCRIPTION_GENERIC_HARDWARE_PARAMETER_DESCRIPTION_H
