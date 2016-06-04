//
// tuto.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Jun  5 00:01:24 2016 avelin_j
// Last update Sun Jun  5 00:14:13 2016 avelin_j
//

#include "gtest.h"

class Block
{
public:

  Block() {}

  ~Block() {}

  int FirstMethod(int& val)
  {
    std::cout << "Val in First ---------> " << val << std::endl;
    val = 10;
    return 0;
  }

  int SecondMethod(int val)
  {
    std::cout << "Val in Second ---------> " << val << std::endl;
    return 0;
  }

  void setValue(int val)
  {
    value = val;
  }

  int value;
};

class BlockTest : public::testing::Test
{
public:

  // You can remove any or all of the following functions if its body
  // is empty.

  BlockTest()
  {
    // You can do set-up work for each test here.
  }

  virtual ~BlockTest()
  {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp()
  {
    t.setValue(5);

    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  Block t;

  // Objects declared here can be used by all tests in the test case for Block.
};

// Tests that the Block::FirstMethod() method does Abc.
TEST_F(BlockTest, FirstTest) {
  const std::string input_filepath  = "this/package/testdata/myinputfile.dat";
  const std::string output_filepath = "this/package/myinputfile.dat";

  ASSERT_EQ(0, t.FirstMethod(t.value));
  EXPECT_EQ(0, t.SecondMethod(t.value));
}

// Tests that Block does Xyz.
TEST_F(BlockTest, SecondTest) {
  Block f;

  EXPECT_EQ(0, t.SecondMethod(t.value));

  // Exercises the Xyz feature of Block.
}
