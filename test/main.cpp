//
// Created by Konstantin Gredeskoul on 5/16/17.
//
#include "gtest/gtest.h"
#include "src/division/division.h"

using namespace std;

#define VI vector<long long>

class DividerTestMain : public ::testing::Test {
 protected:
  VI numerators = {5, 9, 17, 933345453464353416L};
  VI denominators = {2, 3, 19, 978737423423423499L};
  VI divisions = {2, 3, 0, 0};
  VI remainders = {1, 0, 17, 933345453464353416};

  virtual void SetUp(){};

  virtual void TearDown(){};

  virtual void verify(int index) {
    Fraction f = Fraction{numerators.at(index), denominators.at(index)};
    DivisionResult expected =
        DivisionResult{divisions.at(index), remainders.at(index)};
    DivisionResult result = Division(f).divide();
    EXPECT_EQ(result.division, expected.division);
    EXPECT_EQ(result.remainder, expected.remainder);
  }
};

TEST_F(DividerTestMain, TheFirstCases) { verify(0); }

TEST_F(DividerTestMain, TheSecondCases) { verify(1); }

TEST_F(DividerTestMain, TheThirdCases) { verify(1); }

TEST_F(DividerTestMain, LongLongDivider) { verify(3); }

TEST_F(DividerTestMain, DivisionByZero_Exception) {
  Division d = Division(Fraction{1, 0});
  try {
    d.divide();
    FAIL() << "Expected divide() method to throw DivisionByZeroException";
  } catch (DivisionByZero const &err) {
    EXPECT_EQ(err.what(), DIVISION_BY_ZERO_MESSAGE);
  } catch (...) {
    FAIL() << "Expected DivisionByZeroException!";
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
