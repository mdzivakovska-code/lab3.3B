#include "Rational.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int temp = b; b = a % b; a = temp;
    }
    return a;
}

void Rational::Reduce() {
    int a = getFirst();
    int b = getSecond();
    int g = gcd(a, b);
    a /= g; b /= g;
    if (b < 0) { a = -a; b = -b; }
    Pair::setFirst(a);
    Pair::setSecond(b);
}

void Rational::setSecond(int s) {
    if (s == 0) {
        cerr << "Помилка: знаменник не може бути нулем!" << endl;
        exit(1);
    }
    Pair::setSecond(s);
    Reduce(); 
}

void Rational::Init(int f, int s) {
    setFirst(f);
    setSecond(s);
}


Rational::Rational() : Pair() {
    setFirst(0);
    setSecond(1);
}

Rational::Rational(int a, int b) : Pair() {
    setFirst(a);
    setSecond(b);
}

Rational::Rational(const Rational& other) : Pair(other) {}

Rational& Rational::operator=(const Rational& other) {
    if (this != &other) { Pair::operator=(other); }
    return *this;
}

Rational::operator string() const {
    stringstream ss;
    ss << getFirst() << "/" << getSecond();
    return ss.str();
}

Rational& Rational::operator++() {
    Pair::setFirst(getFirst() + getSecond());
    Reduce();
    return *this;
}
Rational Rational::operator++(int) { Rational temp(*this); ++(*this); return temp; }
Rational& Rational::operator--() {
    Pair::setFirst(getFirst() - getSecond());
    Reduce();
    return *this;
}
Rational Rational::operator--(int) { Rational temp(*this); --(*this); return temp; }

double Rational::value() const { return 1.0 * getFirst() / getSecond(); }

Rational Rational::div(const Rational& other) const {
    if (other.getFirst() == 0) {
        cerr << "Помилка: ділення на нуль!" << endl;
        exit(1);
    }
    return Rational(getFirst() * other.getSecond(), getSecond() * other.getFirst());
}

bool Rational::equal(const Rational& other) const {
    return (getFirst() * other.getSecond()) == (other.getFirst() * getSecond());
}

bool Rational::great(const Rational& other) const {
    return (getFirst() * other.getSecond()) > (other.getFirst() * getSecond());
}

bool Rational::less(const Rational& other) const {
    return (getFirst() * other.getSecond()) < (other.getFirst() * getSecond());
}

Rational makeRational(int a, int b) {
    if (b == 0) {
        cerr << "Помилка параметрів makeRational: знаменник дорівнює 0!" << endl;
        exit(1);
    }
    return Rational(a, b);
}