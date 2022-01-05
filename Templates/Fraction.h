#pragma once
class Fraction
{

private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator);
	~Fraction();

	const bool operator>(const Fraction& rhs);
};

