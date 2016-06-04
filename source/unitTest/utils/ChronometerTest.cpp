//
// BoardTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/environment
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 17:33:32 2016 avelin_j
// Last update Sat Jun  4 22:57:04 2016 avelin_j
//

#include "Chronometer.hpp"
#include "gtest.h"

class ChronometerTest : public::testing::Test
{
public:
  ChronometerTest()
  {
  }

  virtual ~ChronometerTest()
  {
  }

  tools::Chronometer t;
};

TEST_F(ChronometerTest, valueAssert) {
  ASSERT_EQ(t.testGetValue(), 0);
}

TEST_F(ChronometerTest, runningAssert) {
  ASSERT_EQ(t.testGetRunning(), 0);
}

TEST_F(ChronometerTest, timerAssert) {
  ASSERT_TRUE(t.testGetTimer() == NULL);
}
