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
        friend Fraction operator-(const Fraction& a, const Fraction& b){
            int N = a.numerator * b.denominator - b.numerator * a.denominator;
            int D = b.denominator * a.denominator;
            return Fraction(N,D);
        }
        friend Fraction operator*(const Fraction& a, const Fraction& b){
            int N = a.numerator *  b.numerator ;
            int D = b.denominator * a.denominator;
            return Fraction(N,D);
        }
        friend Fraction operator/(const Fraction& a, const Fraction& b){
            int N = a.numerator *  b.denominator ;
            int D = a.denominator * b.numerator;
            return Fraction(N,D);
        }

        // Comparison operators
        friend bool operator==(const Fraction& a, const Fraction& b){
            return (a.numerator * b.denominator == b.numerator * a.denominator);
        }
        friend bool operator!=(const Fraction& a, const Fraction& b){
            return !(a==b);
        }
        friend bool operator>(const Fraction& a, const Fraction& b){
            return (a.numerator * b.denominator > b.numerator * a.denominator);
        }
        friend bool operator>=(const Fraction& a, const Fraction& b){
            return (a>b || a==b);
        }
        friend bool operator<(const Fraction& a, const Fraction& b){
            return (a.numerator * b.denominator < b.numerator * a.denominator);
        }
        friend bool operator<=(const Fraction& a, const Fraction& b){
            return (a==b || a<b);
        }

        //output 
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f){
            os << f.numerator << "/" << f.denominator;
            return os;

        }

        // toString method
        std::string to_string()const;
    };

}
#endif