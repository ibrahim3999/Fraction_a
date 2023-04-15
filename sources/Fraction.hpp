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

        friend Fraction operator+(const Fraction & fraction1, const Fraction &fraction2){
            int N = fraction1.numerator * fraction1.denominator + fraction1.numerator * fraction1.denominator;
            int D = fraction1.denominator * fraction1.denominator;
            return Fraction(N,D);
        }
        // int +
        friend Fraction operator+(const int& i, const Fraction& f) {
            int new_numerator = i * f.denominator + f.numerator;
            return Fraction(new_numerator, f.denominator);
        }
        // float +
        friend Fraction operator+(const float& f, const Fraction& frac) {
            int new_numerator = (int)(f * frac.denominator) + frac.numerator;
            return Fraction(new_numerator, frac.denominator);
        }
        //+ float
        friend Fraction operator+( const Fraction& frac,const float& d) {
            int new_numerator = (int)(d * frac.denominator) + frac.numerator;
            return Fraction(new_numerator, frac.denominator);
        }     

        friend Fraction operator-(const Fraction& a, const Fraction& b){
            int N = a.numerator * b.denominator - b.numerator * a.denominator;
            int D = b.denominator * a.denominator;
            return Fraction(N,D);
        }

        friend Fraction operator-( const Fraction& frac,const float& f) {
            int new_numerator = (int)(f * frac.denominator) - frac.numerator;
            return Fraction(new_numerator, frac.denominator);
        }
        
        friend Fraction operator*(const Fraction& a, const Fraction& b){
            int N = a.numerator *  b.numerator ;
            int D = b.denominator * a.denominator;
            return Fraction(N,D);
        }
        friend Fraction operator*(const float & d, const Fraction& f) {
            return Fraction(d * f.numerator, f.denominator);
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

        //increment and decrement
        Fraction & operator++();
       Fraction  operator++(int);
       Fraction & operator--();
        Fraction  operator--(int);
        //output 

        friend std::ostream& operator<<(std::ostream& os, const Fraction& f){
            os << f.numerator << "/" << f.denominator;
            return os;

        }

        int getNumerator() const { return numerator; }
        int getDenominator() const { return denominator; }
        // toString method
        std::string to_string()const;
    
    };
}
#endif