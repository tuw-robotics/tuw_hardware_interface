// Copyright 2022 Eugen Kaltenegger

#include <gtest/gtest.h>

#include "../tuw_ros_control_generic_test_util/include/file_loader.h"

#include <tuw_ros_control_generic/description/generic_connection_description.h>
#include <tuw_ros_control_generic/generic_connection.h>

using tuw_ros_control_generic_test::FileLoader;
using tuw_ros_control_generic::GenericConnection;
using tuw_ros_control_generic::GenericConnectionDescription;

#define TEST_FILE_PATH "/test/resources/test_generic_connection.yaml"

class GenericConnectionTest : public ::testing::Test
{
protected:
  GenericConnectionDescription generic_connection_description_ =
          GenericConnectionDescription(FileLoader::loadYAMLFromFile(TEST_FILE_PATH));
};

TEST_F(GenericConnectionTest, verifyPointer)
{
  ASSERT_EQ(GenericConnection::getConnection(generic_connection_description_).get(), nullptr);
}
