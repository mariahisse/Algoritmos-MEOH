#include <iostream>
#include "gtest/gtest.h"
#include "imp_matriz.cpp"
#include "teste.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
