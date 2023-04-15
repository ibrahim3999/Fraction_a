#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel {

    class Fraction {

    private:
        int numerator;
        int denominator;


    public:
        // Constructors
        Fraction(int numerator,int denominator);
        Fraction(const Fraction& other);
        Fraction();

        //Arithmetic
        friend Fraction operator+(const Fraction & a, const Fraction &b){
            int N = a.numerator * b.denominator + b.numerator * a.denominator;
            int D = b.denominator * a.denominator;
            return Fraction(N,D);
        }
        //friend Fraction operator-(const Fraction& a, const Fraction& b);
       // friend Fraction operator*(const Fraction& a, const Fraction& b);
        //friend Fraction operator/(const Fraction& a, const Fraction& b);

        // toString method
        std::string to_string()const;
    };

}
#endif