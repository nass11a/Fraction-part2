#pragma once

#ifndef FRAC_H_
#define FRAC_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


#include <cmath>

using namespace std;  


namespace ariel{



class Fraction {
private:
    int numerator;
    int denominator;
    

   
    
public:

    Fraction(int temp1, int temp2) : numerator(temp1), denominator(temp2) {
        if(denominator==0){
            std::__throw_invalid_argument("denominator iz zero");
        }
        if(denominator < 0){
            numerator=-numerator;
            denominator=-denominator;
        }
    }

    Fraction(float var);
    

    
    
    int getNumerator();
    int getDenominator();
    

    Fraction simplify_fraction();

    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator+(const float& var , const Fraction& frac1);
    friend Fraction operator+(const Fraction& frac1, const float& var);

    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator-(const Fraction& frac1, const float& frac2);
    friend Fraction operator-(const float& frac2,const Fraction& frac1);

    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator*(const float& var, const Fraction& frac);
    friend Fraction operator*( const Fraction& frac,const float& var);
    
    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator/(const Fraction& frac1,const float& var);
    friend Fraction operator/(const float& var,const Fraction& frac1);


    friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
    friend bool operator>=(const Fraction& frac1, const float& var);
    friend bool operator>=(const float& var,const Fraction& frac1);

    friend bool operator==(const Fraction& frac1, const Fraction& frac2);
    friend bool operator==(const Fraction& frac1, const float& var);
    friend bool operator==(const float& var,const Fraction& frac1);

    friend bool operator!=(const Fraction& frac1, const Fraction& frac2);
    friend bool operator!=(const Fraction& frac1, const float& var);
    friend bool operator!=(const float& var,const Fraction& frac1);

    friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
    friend bool operator<=(const Fraction& frac1, const float& var);
    friend bool operator<=(const float& var,const Fraction& frac1);

    friend bool operator<(const Fraction& frac1, const Fraction& frac2);
    friend bool operator<(const Fraction& frac1, const float& var);
    friend bool operator<(const float& var,const Fraction& frac1);

    friend bool operator>(const Fraction& frac1, const Fraction& frac2);
    friend bool operator>(const Fraction& frac1, const float& var);
    friend bool operator>(const float& var,const Fraction& frac1);
    Fraction operator++(int){
        Fraction temp=*this;
        numerator+=denominator;
        return temp;
    }
    Fraction& operator++(){
        numerator+=denominator;
        return *this;

        
    }
    Fraction operator--(int){
        Fraction temp=*this;
        numerator-=denominator;
        return temp;

    }
      Fraction& operator--(){
        numerator-=denominator;
        return *this;

    }
    //friend Fraction operator-(const Fraction& f, int x);


    friend ostream& operator<<(ostream& out,  Fraction frac);
    
     friend istream& operator>>(istream& input, Fraction& frac);
    
};

}

#endif

