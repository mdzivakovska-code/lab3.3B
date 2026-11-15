#include "Pair.h"
#include <iostream>
#include <sstream>

using namespace std;

Pair::Pair() : first(0), second(0) {}


Pair::Pair(int f, int s) {
    setFirst(f);
    setSecond(s);; }
Pair::Pair(const Pair& other) : first(other.first), second(other.second) {}

int Pair::getFirst() const { return first; }
int Pair::getSecond() const { return second; }

void Pair::setFirst(int f) { first = f; }
void Pair::setSecond(int s) { second = s; }

void Pair::Init(int f, int s) {
    setFirst(f);
    setSecond(s);
}

void Pair::Read() {
    int f, s;
    cout << "¬вед≥ть first: "; cin >> f;
    cout << "¬вед≥ть second: "; cin >> s;
    Init(f, s); 
}

void Pair::Display() const { cout << "(" << first << ", " << second << ")" << endl; }

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) { first = other.first; second = other.second; }
    return *this;
}

Pair::operator string() const {
    stringstream ss;
    ss << "(" << first << ", " << second << ")";
    return ss.str();
}

Pair& Pair::operator++() { ++first; ++second; return *this; }
Pair Pair::operator++(int) { Pair temp(*this); ++(*this); return temp; }
Pair& Pair::operator--() { --first; --second; return *this; }
Pair Pair::operator--(int) { Pair temp(*this); --(*this); return temp; }

bool operator>(const Pair& p1, const Pair& p2) {
    return (p1.first > p2.first) || ((p1.first == p2.first) && (p1.second > p2.second));
}
bool operator<(const Pair& p1, const Pair& p2) { return p2 > p1; }
bool operator==(const Pair& p1, const Pair& p2) { return (p1.first == p2.first) && (p1.second == p2.second); }
bool operator!=(const Pair& p1, const Pair& p2) { return !(p1 == p2); }
bool operator>=(const Pair& p1, const Pair& p2) { return (p1 > p2) || (p1 == p2); }
bool operator<=(const Pair& p1, const Pair& p2) { return (p1 < p2) || (p1 == p2); }

istream& operator>>(istream& in, Pair& p) {
    int f, s;
    in >> f >> s;
    p.setFirst(f);
    p.setSecond(s);
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}