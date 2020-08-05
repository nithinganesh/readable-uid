#include "uidgen.h"

#include <string>
#include <gtest/gtest.h>

TEST(UID, UID_is_generated_within_length_limit) {

  for(auto index = 0; index < 10; index++)
  {
    std::string uid = uidgen();
    ASSERT_TRUE(uid.length() > 0 && uid.length()<=64);
  }
}

TEST(UID, UID_generated_doesnot_contain_more_than_5_digits_between_delimiters)
{
  std::string uid = uidgen();
  auto temp = uid;
  auto position = temp.find(".");
  while( position !=std::string::npos )
  {
      ASSERT_TRUE(temp.substr(0,position).length() < 6);
      temp = temp.substr(position +1);
      position = temp.find(".");
      
  }
  ASSERT_TRUE(temp.length() < 6);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
