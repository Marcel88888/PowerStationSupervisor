#define CATCH_CONFIG_MAIN
#include "tests.h"
#include "manager.h"
TEST_CASE(" Does the program work correctly? ") {
    Manager man;
    man.testingArguments();
    man.calculatePower();

    SECTION ("Does the program read types from the file correctly?") {
        REQUIRE (man.getReactor(0)->getType() == 1);
        REQUIRE (man.getReactor(1)->getType() == 1);
        REQUIRE (man.getReactor(2)->getType() == 2);
        REQUIRE (man.getReactor(3)->getType() == 1);
        REQUIRE (man.getReactor(4)->getType() == 3);
        REQUIRE (man.getReactor(5)->getType() == 3);
        REQUIRE (man.getReactor(6)->getType() == 2);
        REQUIRE (man.getReactor(7)->getType() == 3);
        REQUIRE (man.getReactor(8)->getType() == 2);
        REQUIRE (man.getReactor(9)->getType() == 2);
        REQUIRE (man.getReactor(10)->getType() == 3);
        REQUIRE (man.getReactor(11)->getType() == 1);
        REQUIRE (man.getReactor(12)->getType() == 1);
        REQUIRE (man.getReactor(13)->getType() == 1);
        REQUIRE (man.getReactor(14)->getType() == 3);
        REQUIRE (man.getReactor(15)->getType() == 2);
    }

    SECTION("Does the program read numbers from the file correctly?") {
        REQUIRE (man.getReactor(0)->getNumber() == 12489);
        REQUIRE (man.getReactor(1)->getNumber() == 36974);
        REQUIRE (man.getReactor(2)->getNumber() == 39874);
        REQUIRE (man.getReactor(3)->getNumber() == 33348);
        REQUIRE (man.getReactor(4)->getNumber() == 49926);
        REQUIRE (man.getReactor(5)->getNumber() == 77264);
        REQUIRE (man.getReactor(6)->getNumber() == 11236);
        REQUIRE (man.getReactor(7)->getNumber() == 77826);
        REQUIRE (man.getReactor(8)->getNumber() == 46210);
        REQUIRE (man.getReactor(9)->getNumber() == 10008);
        REQUIRE (man.getReactor(10)->getNumber() == 10084);
        REQUIRE (man.getReactor(11)->getNumber() == 14589);
        REQUIRE (man.getReactor(12)->getNumber() == 45654);
        REQUIRE (man.getReactor(13)->getNumber() == 41234);
        REQUIRE (man.getReactor(14)->getNumber() == 21100);
        REQUIRE (man.getReactor(15)->getNumber() == 96541);
    }

    SECTION("Does the program read powers from the file correctly?") {
        REQUIRE (man.getReactor(0)->getPower() == 1.0);
        REQUIRE (man.getReactor(1)->getPower() == 0.3);
        REQUIRE (man.getReactor(2)->getPower() == 0.1);
        REQUIRE (man.getReactor(3)->getPower() == 0.9);
        REQUIRE (man.getReactor(4)->getPower() == 0.4);
        REQUIRE (man.getReactor(5)->getPower() == 0.5);
        REQUIRE (man.getReactor(6)->getPower() == 0.3);
        REQUIRE (man.getReactor(7)->getPower() == 2.0);
        REQUIRE (man.getReactor(8)->getPower() == 3.6);
        REQUIRE (man.getReactor(9)->getPower() == 3.3);
        REQUIRE (man.getReactor(10)->getPower() == 2.7);
        REQUIRE (man.getReactor(11)->getPower() == 2.5);
        REQUIRE (man.getReactor(12)->getPower() == 2.8);
        REQUIRE (man.getReactor(13)->getPower() == 1.9);
        REQUIRE (man.getReactor(14)->getPower() == 1.0);
        REQUIRE (man.getReactor(15)->getPower() == 3.5);
    }

    SECTION ("Does the program calculate how long it will take to produce 1000 GJ of energy correctly?") {
        REQUIRE (man.calculateTime(1000) == 432);
    }

    SECTION ("Does the program calculate the number of reactors correctly?") {
        REQUIRE (man.getSize() == 16);
    }

}