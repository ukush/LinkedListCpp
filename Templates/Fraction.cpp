#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
{
}

Fraction::~Fraction()
{
}

const bool Fraction::operator>(const Fraction& rhs)
{
	// cross multiply the fractions
	int tn = numerator * rhs.denominator;
	int tn2 = rhs.numerator * denominator;

	return (tn > tn2);


}


