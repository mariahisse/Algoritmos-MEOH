#include <iostream>
#include "gtest/gtest.h"
#include "node.h"
#include "classlist.h"
#include "test.h"

int main(int argc, char **argv)
{
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
