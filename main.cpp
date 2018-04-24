/**
 * Simple 4-function calculator to demonstrate the use of Bigint
 * 
 * Written for the topic COMP2711 Computer Programming 2
 * by Paul Calder
 * on 13 February 2014
 */

#include <iostream>
#include "Bigint.h"

using namespace std;

int main (int argc, char** argv) {
    Bigint n1, n2;
    char op;

    while (cin >> n1 >> op >> n2) {
        switch (op) {
        case '+' :
            cout << n1 + n2 << endl; break;
        case '-' :
            cout << n1 - n2 << endl; break;
        case '*' :
            cout << n1 * n2 << endl; break;
        case '/' :
            cout << n1 / n2 << endl; break;
        }
    }

    return 0;
}
