#include <iostream>
#include "Rational.h"
#include"Windows.h"
#pragma pack(push, 1)
class RationalPacked : public Pair {};
#pragma pack(pop)

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    cout << "--- Демонстрація роботи програми ---" << endl;

    cout << "\n[1] Ініціалізація та виведення через геттери/сеттери:" << endl;
    Rational r_set;
   
    r_set.setFirst(6);
    r_set.setSecond(8);

   
    cout << "Об'єкт задано через сеттери (6 та 8): "
        << r_set.getFirst() << "/" << r_set.getSecond() << endl;

    Rational r2(2, 4);
    Rational r4 = makeRational(3, 5);

    cout << "\nr2 (2/4 скорочено через Init): " << string(r2) << endl;
    cout << "Унарна операція value() для r4: " << r4.value() << endl;

  
    Rational arr[3] = { Rational(1, 2), Rational(1, 3), Rational(1, 4) };
    cout << "\n[2] Масив об'єктів:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << arr[i].getFirst() << "/" << arr[i].getSecond() << endl;
    }

    Rational r5 = r4.div(r2);
    cout << "\n[3] Метод div(): " << string(r4) << " / " << string(r2) << " = " << string(r5) << endl;

    cout << "\n[4] Порівняння (методи класу):" << endl;
    cout << string(r4) << " equal " << string(r2) << " : " << (r4.equal(r2) ? "Так" : "Ні") << endl;
    cout << string(r4) << " great " << string(r2) << " : " << (r4.great(r2) ? "Так" : "Ні") << endl;
    cout << string(r4) << " less " << string(r2) << " : " << (r4.less(r2) ? "Так" : "Ні") << endl;

    cout << "\n[5] Розміри класів[cite: 2]:" << endl;
    cout << "Розмір базового класу Pair: " << sizeof(Pair) << " байт" << endl;
    cout << "Розмір класу Rational: " << sizeof(Rational) << " байт" << endl;
    cout << "Розмір класу Rational в режимі #pragma pack(1): " << sizeof(RationalPacked) << " байт" << endl;

    return 0;
}