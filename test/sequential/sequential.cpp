#include "gtest/gtest.h"

namespace
{

TEST(FooTest, DoesXyz)
{
    EXPECT_TRUE(true);
}

} /* namespace */

int
main(int argc,
     char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
