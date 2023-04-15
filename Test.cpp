#include "doctest.h"
#include "Fraction.hpp"
using namespace ariel;
using namespace std;
TEST_CASE("Fraction tests") {
    SUBCASE("Constructing a fraction") {
        
        Fraction f1;
        CHECK(f1.getNumerator() == 0);
        CHECK(f1.getDenominator() == 1);
        
        Fraction f2(3, 4);
        CHECK(f2.getNumerator() == 3);
        CHECK(f2.getDenominator() == 4);
    }
    SUBCASE("Addition") {
        Fraction f1(1, 2);
        Fraction f2(1, 3);
        Fraction f3 = f1 + f2;
        CHECK(f3.getNumerator() == 5);
        CHECK(f3.getDenominator() == 6);
    }
    SUBCASE("Subtraction") {
        Fraction f1(5, 8);
        Fraction f2(1, 4);
        Fraction f3 = f1 - f2;
        CHECK(f3.getNumerator() == 3);
        CHECK(f3.getDenominator() == 8);
    }
    SUBCASE("Multiplication") {
        Fraction f1(3, 4);
        Fraction f2(2, 5);
        Fraction f3 = f1 * f2;
        CHECK(f3.getNumerator() == 3);
        CHECK(f3.getDenominator() == 10);
    }
    SUBCASE("Division") {
        Fraction f1(3, 4);
        Fraction f2(1, 2);
        Fraction f3 = f1 / f2;
        CHECK(f3.getNumerator() == 3);
        CHECK(f3.getDenominator() == 2);
    }
    
    SUBCASE("Equality") {
        Fraction f1(1, 2);
        Fraction f2(2, 4);
        CHECK(f1 == f2);
    }
    SUBCASE("Inequality") {
        Fraction f1(1, 2);
        Fraction f2(3, 4);
        CHECK(f1 != f2);
    }
    
    SUBCASE("Less than") {
        Fraction f1(1, 2);
        Fraction f2(3, 4);
        CHECK(f1 < f2);
    }
    
    SUBCASE("Greater than") {
        Fraction f1(3, 4);
        Fraction f2(1, 2);
        CHECK(f1 > f2);
    }
    SUBCASE("Prefix and Postfix Increment and Decrement Operators") {
    Fraction f1(2, 3);
    
    // Prefix increment
    Fraction& f2 = ++f1;
    CHECK(f2.getNumerator() == 5);
    CHECK(f2.getDenominator() == 3);
    CHECK(f1.getNumerator() == 5);
    CHECK(f1.getDenominator() == 3);
    
    // Postfix increment
    Fraction f3 = f1++;
    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 3);
    CHECK(f1.getNumerator() == 8);
    CHECK(f1.getDenominator() == 3);
    
    // Prefix decrement
    Fraction& f4 = --f1;
    CHECK(f4.getNumerator() == 5);
    CHECK(f4.getDenominator() == 3);
    CHECK(f1.getNumerator() == 5);
    CHECK(f1.getDenominator() == 3);
    
    // Postfix decrement
    Fraction f5 = f1--;
    CHECK(f5.getNumerator() == 5);
    CHECK(f5.getDenominator() == 3);
    CHECK(f1.getNumerator() == 2);
    CHECK(f1.getDenominator() == 3);

    }
    SUBCASE("simplify") {
    Fraction f1(4, 8);
    f1.simplify();
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);

    Fraction f2(-10, 25);
    f2.simplify();
    CHECK(f2.getNumerator() == -2);
    CHECK(f2.getDenominator() == 5);

    Fraction f3(0, 5);
    f3.simplify();
    CHECK(f3.getNumerator() == 0);
    CHECK(f3.getDenominator() == 1);
}
}