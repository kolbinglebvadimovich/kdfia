#include <numeric>
#include <stdexcept>

class Fraction 
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) 
    {
        if (denominator == 0) 
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    ~Fraction() = default;
    Fraction(const Fraction& other) = default;

    void reduce() 
    {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    bool operator==(const Fraction& other) const 
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    Fraction operator/(const Fraction& other) const 
    {
        if (other.numerator == 0) 
        {
            throw std::invalid_argument("Division by zero");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator<=(const Fraction& other) const 
    {
        return (numerator * other.denominator) <= (denominator * other.numerator);
    }

    Fraction operator++(int) 
    {
        return Fraction(numerator + 1, denominator);
    }

    Fraction operator--(int) 
    {
        return Fraction(numerator - 1, denominator);
    }

    Fraction operator-(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator - denominator * other.numerator,
                         denominator * other.denominator);
    }

    void dump() const 
    {
        std::cout << numerator << '/' << denominator << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) 
    {
        os << frac.numerator << '/' << frac.denominator;
        return os;
    }
};
