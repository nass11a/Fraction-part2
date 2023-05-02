#include<iostream>
#include"doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("check +(Add) between two fractions"){

Fraction a(5,3), b(14,21);

CHECK(a+b==147/63);
//////////
//Fraction c(0,1), d(0,2);

//CHECK_EQ(c+d,Fraction(0/0));
/////////
Fraction e(1,1), f(1,2);

CHECK(e+f==3/2);
/////////
Fraction g(1,1), h(1,1);

CHECK(g+h==2/2);
/////////
Fraction i(2,1), k(2,1);

CHECK(i+k==4/1);
/////////
}


TEST_CASE("check -(Minus) between two fractions"){

Fraction j(5,3), s(14,21);

CHECK(j-s==21/21);
//////////
//Fraction w(0,1), q(0,2);

//CHECK_EQ(w-q,Fraction(0/0));
/////////
Fraction r(1,1), t(1,2);

CHECK(r-t==1/2);
/////////
//Fraction a(1,1), b(1,1);

//CHECK_EQ(a-b,Fraction(0/0));
/////////
//Fraction a(2,1), b(2,1);

//CHECK_EQ(a-b,Fraction(0/0));
/////////
Fraction o(1,2), l(1,3);

CHECK(o-l==4/6);
/////////
}


TEST_CASE("check /(Division) between two fractions"){

Fraction a(5,3), b(14,21);

CHECK(a/b==105/42);
//////////
//Fraction a(0,1), b(0,2);

//CHECK_EQ(a/b,Fraction(0/0));
/////////
Fraction v(1,1), m(1,2);

CHECK(v/m==2/1);
/////////
Fraction k(1,1), e(1,1);

CHECK(k/e==1/1);
/////////
Fraction q(2,1), g(2,1);

CHECK(q/g==2/2);
/////////
Fraction d(1,2), p(1,3);

CHECK(d/p==3/2);
/////////
}


TEST_CASE("check *(Multiply) between two fractions"){

Fraction t(5,3), y(14,21);

CHECK(t/y==70/61);
//////////
Fraction q(0,1), s(0,2);

CHECK(q/s==0/2);
/////////
Fraction l(1,1), m(1,2);

CHECK(l/m==1/2);
/////////
Fraction k(1,1), j(1,1);

CHECK(k/j==1/1);
/////////
Fraction v(2,1), w(2,1);

CHECK(v/w==4/1);
/////////
Fraction g(1,2), i(1,3);

CHECK(g/i==1/6);
/////////
}

TEST_CASE("check Fraction + Number "){

    Fraction a(5,3);

    CHECK(a+2.3==70/61);
/////////
    Fraction e(1, 2);
    CHECK(e + 0.5==1/1);
///////////
    Fraction d(3, 4);
    CHECK(d + 0.25==1/1);
///////////
    Fraction f(3, 5);
    CHECK(f + 0.75==18/5);
//////////
    Fraction k(4, 5);
    CHECK(k + 0.4==10/5);
}

TEST_CASE("check Number * Fraction "){

    Fraction a(5,3);

    CHECK(2.3*a==3833/1000);
/////////
    Fraction e(1, 2);
    CHECK(0.5*e==1/4);
///////////
    Fraction f(3, 4);
    CHECK(0.25*f==3/16);
///////////
    Fraction k(3, 5);
    CHECK(0.75*k==9/20);
//////////
    Fraction q(4, 5);
    CHECK(0.4*q==8/25);
}


TEST_CASE("check ->  Fraction = Fraction , operator , Number "){
    Fraction s(5,3), x(14,21);
    Fraction c = s+x-1;
    CHECK(c==1/6);
    //////////
    Fraction q(5,3), w(14,21);
    Fraction l = q-w-1;
    CHECK(l==-1/2);

    //////////
    Fraction h(2,5), m(1,4);
    Fraction e = h+m-1;
    CHECK(e==-3/20);

    //////////
    Fraction r(2,3), t(3,4);
    Fraction j = r+t-1;
    CHECK(j==5/12);

}

TEST_CASE("check --c and c++"){
    Fraction r(5,3), t(2,3);
    Fraction j = r+t;
    for(int i=0 ;i<5; i++){
        j++;
    }
    CHECK(j==22/3);
    //////////
    Fraction k(5,3), l(2,3);
    Fraction m = k+l;

    for(int i=0 ;i<5; i++){
        --m;
    }
    CHECK(m==8/3);
    /////////

    Fraction q(5,3), g(2,3);
    Fraction s = q+g;


    CHECK(s++==7/3);
    CHECK(s==10/3);

    CHECK(--s==7/3);
    CHECK(s==10/3);

    
}

TEST_CASE("Fraction > , <  , <= , >= ,== ,!= "){
    Fraction m(5,3), l(2,3),k(3,5);
    CHECK(m>=l);
    CHECK(l<m);
    CHECK(l<=m);
    /////////
    CHECK(k>l);
    CHECK(l<k);
    CHECK(l<=k);
    CHECK(k>=l);

    Fraction x(2,3), y(4,6) ,z(1,2);
    CHECK(x==y);
    CHECK(x!=z);
}