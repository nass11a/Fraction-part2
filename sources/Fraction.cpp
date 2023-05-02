#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "namespace.hpp"
#include <limits>



using namespace std;
using namespace ariel;


    int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Convert a decimal number to a fraction
// Convert a decimal number to a fraction
Fraction floatToFraction(float f) {
    // Extract the first three numbers after the decimal point
    int num = round(f * 1000);
    int den = 1000;

    // Simplify the fraction by dividing by their GCD
    int div = gcd(num, den);
    num /= div;
    den /= div;

    // Convert the fraction to a string
    return Fraction(num, den);
}

// constructor that takes float
     ariel::Fraction::Fraction(float var){
       Fraction temp=floatToFraction(var);

       this->numerator=temp.numerator;
       this->denominator=temp.denominator;

          if(denominator==0){
            std::__throw_invalid_argument("denominator iz zero");
        }
        if(denominator < 0){
            numerator=-numerator;
            denominator=-denominator;
        }
     } 


////////////////////////////////////////////////////  operator plus ->  + 

////// add two fractions
     Fraction  ariel::operator+(const Fraction& frac1, const Fraction& frac2){
           if(frac1.numerator==std::numeric_limits<int>::max() || frac2.numerator==std::numeric_limits<int>::max() 
       || frac2.denominator==std::numeric_limits<int>::max() || frac1.denominator==std::numeric_limits<int>::max() ){
           throw std::overflow_error("over flow");
      }

        if(frac1.numerator==std::numeric_limits<int>::min() || frac2.numerator==std::numeric_limits<int>::min() 
       || frac2.denominator==std::numeric_limits<int>::min() || frac1.denominator==std::numeric_limits<int>::min() ){
           throw std::overflow_error("over flow");
      }
       
       if(frac1.denominator == frac2.denominator){
       int numerator_sum = frac1.numerator+frac2.numerator;
      
  
       return Fraction(numerator_sum,frac1.denominator).simplify_fraction();
       }
       else{
        int denominator_sum= frac1.denominator *frac2.denominator;
        int frac1_numerator= frac1.numerator * frac2.denominator;
        int frac2_numerator= frac2.numerator * frac1.denominator;
        return Fraction(frac1_numerator+frac2_numerator,denominator_sum).simplify_fraction();
       }
     }

     int ariel::Fraction::getNumerator(){
      return this->numerator;
     }

      int ariel::Fraction::getDenominator(){
      return this->denominator;
     }

////// add fraction + float
    Fraction ariel::operator+(const Fraction& frac1, const float& var){
        Fraction frac2=floatToFraction(var);
          if(frac1.denominator == frac2.denominator){
       int numerator_sum = frac1.numerator+frac2.numerator;
       
  
       return Fraction(numerator_sum,frac1.denominator).simplify_fraction();
       }
       else{
        int denominator_sum= frac1.denominator *frac2.denominator;
        int frac1_numerator= frac1.numerator * frac2.denominator;
        int frac2_numerator= frac2.numerator * frac1.denominator;
        return Fraction(frac1_numerator+frac2_numerator,denominator_sum).simplify_fraction();
       }
     }

////// add  float + fraction
    Fraction ariel::operator+(const float& var , const Fraction& frac1){
         Fraction frac2=floatToFraction(var);
          if(frac1.denominator == frac2.denominator){
       int numerator_sum = frac1.numerator+frac2.numerator;
       
  
       return Fraction(numerator_sum,frac1.denominator).simplify_fraction();
       }
       else{
        int denominator_sum= frac1.denominator *frac2.denominator;
        int frac1_numerator= frac1.numerator * frac2.denominator;
        int frac2_numerator= frac2.numerator * frac1.denominator;
        return Fraction(frac1_numerator+frac2_numerator,denominator_sum).simplify_fraction();
       }
     }

/////////////////////////////////////////////////////// operator -

////// minus  fraction - fraction
     Fraction ariel::operator-(const Fraction& frac1, const Fraction& frac2){
           if(frac1.numerator==std::numeric_limits<int>::max() || frac2.numerator==std::numeric_limits<int>::max() 
       || frac2.denominator==std::numeric_limits<int>::max() || frac1.denominator==std::numeric_limits<int>::max() ){
          throw std::overflow_error("over flow");
      }

        if(frac1.numerator==std::numeric_limits<int>::min() || frac2.numerator==std::numeric_limits<int>::min() 
       || frac2.denominator==std::numeric_limits<int>::min() || frac1.denominator==std::numeric_limits<int>::min() ){
          throw std::overflow_error("over flow");
      }
      if(frac1.numerator==std::numeric_limits<int>::max()-1 && frac2.numerator==std::numeric_limits<int>::min() + 1  &&
       frac1.denominator==1 && frac2.denominator ==1){
          throw std::overflow_error("over flow");
      }
       
         if(frac1.denominator == frac2.denominator){
       int numerator_sum = frac1.numerator-frac2.numerator;
    
       return Fraction(numerator_sum,frac1.denominator).simplify_fraction();
       }
       else{
        int denominator_sum= frac1.denominator *frac2.denominator;
        int frac1_numerator= frac1.numerator * frac2.denominator;
        int frac2_numerator= frac2.numerator * frac1.denominator;
        return Fraction(frac1_numerator-frac2_numerator,denominator_sum).simplify_fraction();
       }
     }

////// minus  fraction - float
       Fraction ariel::operator-(const Fraction& frac1, const float& var){
        Fraction frac2=floatToFraction(var);
          if(frac1.denominator == frac2.denominator){
       int numerator_sum = frac1.numerator-frac2.numerator;
       
       return Fraction(numerator_sum,frac1.denominator).simplify_fraction();
       }
       else{
        int denominator_sum= frac1.denominator *frac2.denominator;
        int frac1_numerator= frac1.numerator * frac2.denominator;
        int frac2_numerator= frac2.numerator * frac1.denominator;
        return Fraction(frac1_numerator-frac2_numerator,denominator_sum).simplify_fraction();
       }
       }

////// minus  float - fraction
         Fraction ariel::operator-( const float& var, const Fraction& frac1){
          Fraction frac2=floatToFraction(var);
          if(frac1.denominator == frac2.denominator){
       int numerator_sum = frac2.numerator-frac1.numerator;
       
       return Fraction(numerator_sum,frac1.denominator).simplify_fraction();
       }
       else{
        int denominator_sum= frac1.denominator *frac2.denominator;
        int frac1_numerator= frac1.numerator * frac2.denominator;
        int frac2_numerator= frac2.numerator * frac1.denominator;
        return Fraction(frac2_numerator-frac1_numerator,denominator_sum).simplify_fraction();
       }
       }



///////////////////////////////////////// operator *

////// Fraction * Fraction 
     Fraction ariel::operator*(const Fraction& frac1, const Fraction& frac2){
           if(frac1.numerator==std::numeric_limits<int>::max() && frac2.numerator==std::numeric_limits<int>::max() ){
           throw std::overflow_error("over flow");
      }

           if(frac1.numerator==std::numeric_limits<int>::max() && frac1.denominator!=std::numeric_limits<int>::max() ){
           throw std::overflow_error("over flow");
      }

      if(frac2.denominator ==std::numeric_limits<int>::max() && frac1.denominator==std::numeric_limits<int>::max() &&
      frac2.numerator !=std::numeric_limits<int>::max() && frac1.numerator!=std::numeric_limits<int>::max()){
           throw std::overflow_error("over flow");
      }
              

        if(frac1.numerator==std::numeric_limits<int>::min() && frac2.numerator==std::numeric_limits<int>::min() 
       || frac2.denominator==std::numeric_limits<int>::min() && frac1.denominator==std::numeric_limits<int>::min() ){
           throw std::overflow_error("over flow");
      }
       
 
        return Fraction(frac1.numerator*frac2.numerator, frac1.denominator*frac2.denominator).simplify_fraction();
       
     }

////// float * Fraction      
       Fraction ariel::operator*(const float& var, const Fraction& frac1){

        Fraction frac2=floatToFraction(var);
          Fraction temp=frac1*frac2;
        return temp.simplify_fraction();
      }

        Fraction ariel::operator*(const Fraction& frac1,const float& var){
          Fraction frac2=floatToFraction(var);
          Fraction temp=frac1*frac2;
        return temp.simplify_fraction();
      }


////////////////////////////////////// operator /

////// Fraction / Fraction 
     Fraction ariel::operator/(const Fraction& frac1, const Fraction& frac2){
       if(frac2.denominator ==0 || frac1.denominator ==0){
         std::__throw_invalid_argument("denominator iz zero");
       }
            if(frac1.numerator==std::numeric_limits<int>::max() && frac2.numerator==std::numeric_limits<int>::max() ){
           throw std::overflow_error("over flow");
      }

           if(frac1.numerator==std::numeric_limits<int>::max() && frac1.denominator!=std::numeric_limits<int>::max() ){
           throw std::overflow_error("over flow");
      }

      if(frac2.denominator ==std::numeric_limits<int>::max() && frac1.denominator==std::numeric_limits<int>::max() &&
      frac2.numerator !=std::numeric_limits<int>::max() && frac1.numerator!=std::numeric_limits<int>::max()){
           throw std::overflow_error("over flow");
      }
              

        if(frac1.numerator==std::numeric_limits<int>::min() && frac2.numerator==std::numeric_limits<int>::min() 
       || frac2.denominator==std::numeric_limits<int>::min() && frac1.denominator==std::numeric_limits<int>::min() ){
           throw std::overflow_error("over flow");
      }
       
       int final_denominator= frac1.denominator *frac2.numerator;
       int final_numerator= frac1.numerator * frac2.denominator;

       if(final_denominator == 0){
       throw std::runtime_error("denominator is zero");
       }
       return Fraction(final_numerator,final_denominator).simplify_fraction();
     }


////// Fraction / float 
     Fraction ariel::operator/(const Fraction& frac1,const float& var){
       if(frac1.denominator ==0){
        throw std::runtime_error("denominator iz zero");
       }
       Fraction temp=floatToFraction(var);
      int final_denominator= frac1.denominator *temp.numerator;
      int final_numerator=frac1.numerator * temp.denominator;

       if(final_denominator == 0){
        throw std::runtime_error("denominator is zero");
       }
      return Fraction(final_numerator,final_denominator).simplify_fraction();
     }

////// float / Fraction 
      Fraction ariel::operator/(const float& var,const Fraction& frac1){
         if( frac1.denominator ==0){
         throw std::runtime_error("denominator iz zero");
       }
       Fraction temp=floatToFraction(var);
      int final_numerator= frac1.denominator *temp.numerator;
      int final_denominator=frac1.numerator * temp.denominator;

       if(final_denominator == 0){
        throw std::runtime_error("denominator iz zero");
       }
      return Fraction(final_numerator,final_denominator).simplify_fraction();
     }
    


//////////////////////////////////////////////////////// copmrasion equalty operators ->  == != >= <=

/////////////// fraction >= fraction
      bool ariel::operator>=(const Fraction& frac1, const Fraction& frac2){
         int denom1=frac1.denominator;
      int denom2=frac2.denominator;
       if(denom1 < 0 ){
        denom1=-denom1;
       }
         if(denom2 < 0){
        denom2=-denom2;
       }
         int f_1=frac1.numerator*denom2;
        int f_2=frac2.numerator*denom1;
        return f_1>=f_2;
      }

/////////////// fraction >= float
     bool ariel::operator>=(const Fraction& frac1, const float& var){
      Fraction temp=floatToFraction(var);
    
        return frac1>=temp;
     }

/////////////// float >= fraction
     bool ariel::operator>=(const float& var,const Fraction& frac1){
           Fraction temp=floatToFraction(var);
    
        return temp>=frac1;
     }


/////////////// fraction == fraction
     bool ariel::operator==(const Fraction& frac1, const Fraction& frac2){
       float denom1=frac1.denominator;
      float denom2=frac2.denominator;
       if(denom1 < 0){
        denom1=-denom1;
       }
         if(denom2 < 0){
        denom2=-denom2;
       }

        float f_1=frac1.numerator*denom2;
        float f_2=frac2.numerator*denom1;

       float num1 = f_1;
      std::string numStr1 = std::to_string(num1); // Convert integer to string
      std::string firstThreeDigitsStr1 = numStr1.substr(0, 3); // Extract first three characters
      float firstThreeDigits1 = std::stoi(firstThreeDigitsStr1); // Convert substring back to integer

       float num2 = f_2;
      std::string numStr2 = std::to_string(num2); // Convert integer to string
      std::string firstThreeDigitsStr2 = numStr2.substr(0, 3); // Extract first three characters
      float firstThreeDigits2 = std::stoi(firstThreeDigitsStr2); // Convert substring back to integer

        return firstThreeDigits1==firstThreeDigits2;
     }

/////////////// fraction == float     
      bool ariel::operator==(const Fraction& frac1, const float& var){
         Fraction temp=floatToFraction(var);

           return temp==frac1;
      }

/////////////// float == fraction      
      bool ariel::operator==(const float& var,const Fraction& frac1){
        Fraction temp=floatToFraction(var);

           return temp==frac1;
      }

/////////////// fraction != fraction      
     bool ariel::operator!=(const Fraction& frac1, const Fraction& frac2){
       int denom1=frac1.denominator;
      int denom2=frac2.denominator;
       if(denom1 < 0){
        denom1=-denom1;
       }
         if(denom2 < 0){
        denom2=-denom2;
       }
        int f_1=frac1.numerator*denom2;
        int f_2=frac2.numerator*denom1;

        return f_1!=f_2;
     }

 
/////////////// fraction != float     
     bool ariel::operator!=(const Fraction& frac1, const float& var){
        Fraction temp=floatToFraction(var);

        return frac1!=temp;
     }


/////////////// float != fraction
     bool ariel::operator!=(const float& var,const Fraction& frac1){
         Fraction temp=floatToFraction(var);

        return frac1!=temp;
     }

 ///////////////  fraction <=  fraction  
      bool ariel::operator<=(const Fraction& frac1, const Fraction& frac2){
         int denom1=frac1.denominator;
      int denom2=frac2.denominator;
       if(denom1 < 0){
        denom1=-denom1;
       }
         if(denom2 < 0){
        denom2=-denom2;
       }
        int f_1=frac1.numerator*denom2;
        int f_2=frac2.numerator*denom1;

        return f_1<=f_2;
      }

 ///////////////  fraction <=  float       
      bool ariel::operator<=(const Fraction& frac1, const float& var){
         Fraction temp=floatToFraction(var);

        return frac1<=temp;
      }

 ///////////////  float <=  fraction  
      bool ariel::operator<=(const float& var,const Fraction& frac1){
          Fraction temp=floatToFraction(var);

        return temp<=frac1;
      }

 ///////////////  fraction <  fraction        
     bool ariel::operator<(const Fraction& frac1, const Fraction& frac2){
      int denom1=frac1.denominator;
      int denom2=frac2.denominator;
       if(denom1 < 0){
        denom1=-denom1;
       }
         if(denom2 < 0){
        denom2=-denom2;
       }
        int f_1=frac1.numerator*denom2;
        int f_2=frac2.numerator*denom1;
        
        return f_1<f_2;
     }

   ///////////////  fraction <  float     
      bool ariel::operator<(const Fraction& frac1, const float& var){
           Fraction temp=floatToFraction(var);

        return frac1<temp;
      }

   ///////////////  float < fraction      
      bool ariel::operator<(const float& var,const Fraction& frac1){
         Fraction temp=floatToFraction(var);

        return temp<frac1;
      }

    ///////////////  fraction >  fraction         
      bool ariel::operator>(const Fraction& frac1, const Fraction& frac2){
        int denom1=frac1.denominator;
        int denom2=frac2.denominator;
        int numer1=frac1.numerator;
        int numer2=frac2.numerator;

        int f_1=numer1 * denom2;
        int f_2=numer2 * denom1;

    

        return f_1>f_2;
      }
 ///////////////  fraction >  float     
     bool ariel::operator>(const Fraction& frac1, const float& var){
         Fraction temp=floatToFraction(var);

        return frac1>temp;
     }

 ///////////////  float >  fraction           
     bool ariel::operator>(const float& var,const Fraction& frac1){
       Fraction temp=floatToFraction(var);

        return temp>frac1;
     }

 ///////////////  operator>>       
   istream& ariel::operator>>(istream& input, Fraction& frac){
    int numerator = 0;
    int denominator = 0;

    input >> numerator;
    input >> denominator;

    if (input.fail()) {
        throw std::invalid_argument("Invalid fraction input");
    }

    frac = Fraction(numerator, denominator);

    return input;
}


/////////// operator<<
    ostream& ariel::operator<<(ostream& out,  Fraction frac){
          Fraction temp =frac.simplify_fraction();
         out << temp.numerator << "/" << temp.denominator ;
         return out;
    }

     
    
/////// used to simplify fractions to thier bases
     Fraction ariel::Fraction::simplify_fraction() {
      int num=this->numerator;
      int den=this->denominator;
    // Get the greatest common divisor of the numerator and denominator
    int gcd = __gcd(num, den);

    // Keep dividing the numerator and denominator by their GCD until they can no longer be divided
    while (gcd != 1) {
        num /= gcd;
        den /= gcd;
        gcd = __gcd(num, den);
    }
    return Fraction(num,den);
}
