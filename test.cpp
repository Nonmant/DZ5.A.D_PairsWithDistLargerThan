#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "4 4\n"
                "1 3 5 8\n"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "2"
    );
}

TEST_CASE("mine", ""){
    std::stringstream input(
            "5 3\n"
            "1 2 5 7 9\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "6"
    );
}

TEST_CASE("2, far enough", ""){
    std::stringstream input(
            "2 3\n"
            "1 1000000000\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1"
    );
}

TEST_CASE("2, too close", ""){
    std::stringstream input(
            "2 3\n"
            "1000000000 1000000001\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "0"
    );
}
