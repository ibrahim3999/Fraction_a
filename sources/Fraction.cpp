#include "Fraction.hpp"
#include <stdexcept>
#include <sstream>
using namespace std;
namespace ariel {

        Fraction::Fraction(int numerator, int denominator){
            if(denominator==0){
                throw invalid_argument("Denominator cant be 0 ");
            }
            this->denominator=denominator;
            this->numerator=numerator;

        }
        
        Fraction::Fraction(const Fraction& other){


        }
        Fraction::Fraction(){
            this->denominator=0;
            this->numerator=0;
        }

        std::string Fraction::to_string()const{
            std::stringstream ss;
            ss << numerator << "/" << denominator;
            return ss.str();
        }

    
}