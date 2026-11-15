#pragma once
#include "Pair.h"


class Rational : public Pair {
private:
    void Reduce(); 
public:
    Rational();
    Rational(int a, int b);
    Rational(const Rational& other);

 
    void setSecond(int s) override;
    void Init(int f, int s) override;

    Rational& operator=(const Rational& other);
    operator string() const;
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    double value() const;

    
    Rational div(const Rational& other) const;
    bool equal(const Rational& other) const;
    bool great(const Rational& other) const;
    bool less(const Rational& other) const;
};

Rational makeRational(int a, int b); 