#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArrayHandler.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ArrayHandler<int> test(5);
    test.AppendElem(2);
    test.AppendElem(2);
    test.AppendElem(2);
    test.AppendElem(1);
    test.AppendElem(2);
    test.AppendElem(6);
    test.pprint();
    test.IsContains(1);
    test.GetMax();
    test.GetMin();

    
    return RUN_ALL_TESTS();
}