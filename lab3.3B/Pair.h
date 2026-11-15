#pragma once
#include <iostream>
#include <string>

using namespace std;


class Pair {
private:
    int first;
    int second;

public:
    Pair();
    Pair(int f, int s);
    Pair(const Pair& other);

    int getFirst() const;
    int getSecond() const;

    virtual void setFirst(int f);
    virtual void setSecond(int s);

    virtual void Init(int f, int s);
    void Read();
    void Display() const;

    Pair& operator=(const Pair& other);
    operator string() const;
    Pair& operator++();
    Pair operator++(int);
    Pair& operator--();
    Pair operator--(int);

    friend bool operator>(const Pair& p1, const Pair& p2);
    friend bool operator<(const Pair& p1, const Pair& p2);
    friend bool operator==(const Pair& p1, const Pair& p2);
    friend bool operator!=(const Pair& p1, const Pair& p2);
    friend bool operator>=(const Pair& p1, const Pair& p2);
    friend bool operator<=(const Pair& p1, const Pair& p2);

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};