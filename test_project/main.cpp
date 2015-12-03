//
//  main.cpp
//  test_project
//
//  Created by 安田洋介 on 12/2/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "divide_and_conquer.h"

using namespace std;

TEST_CASE("divide_and_conquer"){
    long long int result1 = exec_devide_and_conquer("test1.txt");
    REQUIRE(result1 == 5);
    long long int result2 = exec_devide_and_conquer("test2.txt");
    REQUIRE(result2 == 18);
}

TEST_CASE("exec exam"){
    long long int result = exec_devide_and_conquer("IntegerArray.txt");
    REQUIRE(result == 2407905288);
}
