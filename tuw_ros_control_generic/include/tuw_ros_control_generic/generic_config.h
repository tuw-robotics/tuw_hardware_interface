// Copyright 2022 Eugen Kaltenegger

#ifndef TUW_ROS_CONTROL_GENERIC_GENERIC_CONFIG_MANAGER_H
#define TUW_ROS_CONTROL_GENERIC_GENERIC_CONFIG_MANAGER_H

#include <memory>

#include <ddynamic_reconfigure/ddynamic_reconfigure.h>

#include <tuw_ros_control_generic/description/generic_config_description.h>
#include <tuw_ros_control_generic/description/generic_hardware_parameter_description.h>

namespace tuw_ros_control_generic
{
class GenericJoint;
class GenericHardware;
class GenericHardwareParameter;
class GenericConfig
{
public:
  GenericConfig(std::shared_ptr<GenericJoint> joint,
                std::shared_ptr<GenericHardware> hardware);
  GenericConfig(std::shared_ptr<GenericJoint> joint,
                std::shared_ptr<GenericHardware> hardware,
                GenericConfigDescription config_description);
protected:
  void setupReconfigureServer();
  void registerReconfigureVariable(GenericHardwareParameter hardware_parameter);
  void registerReconfigureEnumVariable(GenericHardwareParameter hardware_parameter);
  void registerReconfigureRangeVariable(GenericHardwareParameter hardware_parameter);

  void reconfigureConfig();
  void reconfigureValue(GenericHardwareParameter hardware_parameter, int target_value);

  void setInitialConfig(GenericConfigDescription config_description);

  std::shared_ptr<GenericJoint> joint_ {nullptr};
  std::shared_ptr<GenericHardware> hardware_ {nullptr};

  ddynamic_reconfigure::DDynamicReconfigure reconfigure_;

  std::map<std::string, int> target_config_values_ {std::map<std::string, int>()};
  std::map<std::string, int> actual_config_values_ {std::map<std::string, int>()};
};
}  // namespace tuw_ros_control_generic

#endif  // TUW_ROS_CONTROL_GENERIC_GENERIC_CONFIG_MANAGER_H