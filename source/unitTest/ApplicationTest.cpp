//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 15:51:21 2016 avelin_j
//

#include "Application.hpp"
#include "gtest.h"

class ApplicationTest : public::testing::Test
{
public:
  ApplicationTest()
  {
  }

  virtual ~ApplicationTest()
  {
  }

  bbman::Application t;
};

TEST_F(ApplicationTest, ApplicationStateAssert) {
  ASSERT_EQ(bbman::ApplicationState::AS_NONE, t.testGetApplicationState());
}

TEST_F(ApplicationTest, boolCloseAssert) {
  ASSERT_EQ(0, t.testGetClose());
}

TEST_F(ApplicationTest, irrAssert) {
  ASSERT_TRUE(t.testGetIrrlicht() == NULL);
}

TEST_F(ApplicationTest, GameAssert) {
  ASSERT_TRUE(t.testGetGame() == NULL);
}

TEST_F(ApplicationTest, MenuAssert) {
  ASSERT_TRUE(t.testGetMenu() == NULL);
}
