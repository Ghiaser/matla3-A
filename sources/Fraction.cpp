#include "Fraction.hpp"

namespace ariel
{

    int findGCD(int num1, int num2)
    {
        int gcd;
        for(int i=1; i <= num1 && i <= num2; i++)
        {
            if(num1%i==0 && num2%i==0)
                gcd = i;
        }
        return gcd;
    }
    
    Fraction::Fraction(int n,int d):numerator(n),denominator(d){}
    Fraction::Fraction(){}

    /* + */
    Fraction operator+(const Fraction& a, const Fraction& b){

        int gcd = findGCD(a.getD(),b.getD());
        int lcm = (a.getD()*b.getD())/ gcd;                            //finding lcm of the denominators
        
        int sum=(a.getN()*lcm/a.getD()) + (b.getN()*lcm/b.getD());     //finding the sum of the numbers

        int num=sum/findGCD(sum,lcm);                                  //normalizing numerator and denominator of result
        lcm=lcm/findGCD(sum,lcm);
		return Fraction(num, lcm);
    }
    Fraction operator+(const Fraction& a, float b){return Fraction(1,1);}
    Fraction operator+(float a, const Fraction& b){return Fraction(1,1);}

    /* - */
    Fraction operator-(const Fraction& a, const Fraction& b){return Fraction(1,1);}
    Fraction operator-(const Fraction& a, float b){return Fraction(1,1);}
    Fraction operator-(float a, const Fraction& b){return Fraction(1,1);}

    /* * */
    Fraction operator*(const Fraction& a, const Fraction& b){return Fraction(1,1);}
    Fraction operator*(const Fraction& a, float b){return Fraction(1,1);}
    Fraction operator*(float a, const Fraction& b){return Fraction(1,1);}

    /* / */
    Fraction operator/(const Fraction& a, const Fraction& b){return Fraction(1,1);}
    Fraction operator/(const Fraction& a, float b){return Fraction(1,1);}
    Fraction operator/(float a, const Fraction& b){return Fraction(1,1);}
    
    /* > */
    bool operator >(const Fraction& a, const Fraction& b){return true;}
    bool operator >(const Fraction& a, float b){return true;}
    bool operator >(float a, const Fraction& b){return true;}

    /* >= */
    bool operator >=(const Fraction& a, const Fraction& b){return true;}
    bool operator >=(const Fraction& a, float b){return true;}
    bool operator >=(float a, const Fraction& b){return true;}

    /* < */
    bool operator <(const Fraction& a, const Fraction& b){return true;}
    bool operator <(const Fraction& a, float b){return true;}
    bool operator <(float a, const Fraction& b){return true;}

    /* <= */
    bool operator <=(const Fraction& a, const Fraction& b){return true;}
    bool operator <=(const Fraction& a, float b){return true;}
    bool operator <=(float a, const Fraction& b){return true;}
    
    /* == */
    bool operator ==(const Fraction& a, const Fraction& b){return true;}
    bool operator ==(const Fraction& a, float b){return true;}
    bool operator ==(float a, const Fraction& b){return true;}

    // overloaded prefix ++ operator
    Fraction& Fraction::operator++(){return *this;}

    // overloaded postfix ++ operator
    Fraction Fraction::operator++(int){return *this;}

    // overloaded prefix -- operator
    Fraction& Fraction::operator--(){return *this;}

    // overloaded postfix -- operator
    Fraction Fraction::operator--(int){return *this;}

    ostream& operator<<(ostream& output, const Fraction& fracture){
        return output << fracture.numerator << '/' << fracture.denominator;
    }
    istream& operator>>(istream& is, Fraction& fracture){return is;}

    int Fraction::getN() const {return numerator;}
    int Fraction::getD() const{return denominator;}

}