1 Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction 
{
private:
    int numerator;
    int denominator;

    void reduce();
    Fraction(int num, int den) : numerator(num), denominator(den) 
    {
        if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
        reduce();
    }

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num) : numerator(num), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) { reduce(); 

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    Fraction operator-() const;

    std::string dump() const;
};

std::ostream& operator<<(std::ostream& os, const Fraction& frac);

#endif



2 Fraction.cpp

#include "Fraction.h"
#include <cstdlib>
#include <cmath>

void Fraction::reduce() 
{
    int gcd = std::__gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

bool Fraction::operator==(const Fraction& other) const 
{
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Fraction::operator!=(const Fraction& other) const 
{
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const 
{
    return (numerator * other.denominator) < (denominator * other.numerator);
}

bool Fraction::operator>(const Fraction& other) const 
{
    return (numerator * other.denominator) > (denominator * other.numerator);
}

bool Fraction::operator<=(const Fraction& other) const 
{
    return !(numerator * other.denominator) > (denominator * other.numerator);
}

bool Fraction::operator>=(const Fraction& other) const 
{
    return !(numerator * other.denominator) < (denominator * other.numerator);
}

Fraction Fraction::operator+(const Fraction& other) const 
{
    int new_numer = numerator * other.denominator + denominator * other.numerator;
    int new_denom = denominator * other.denominator;
    return Fraction(new_numer, new_denom);
}

Fraction Fraction::operator-(const Fraction& other) const 
{
    int new_numer = numerator * other.denominator - denominator * other.numerator;
    int new_denom = denominator * other.denominator;
    return Fraction(new_numer, new_denom);
}

Fraction Fraction::operator*(const Fraction& other) const 
{
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const 
{
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction& Fraction::operator++() 
{
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int)
