/**
 * Bigint: a class for computing with l-o-n-g integers
 * 
 * Written for the topic COMP2711 Computer Programming 2
 * by Paul Calder
 * on 13 February 2014
 *
 * Simple implementation using a fixed-size array of int for the digits,
 * with the LSD in array element 0.
 */

#include <string>
#include <iostream>
#include "Bigint.h"
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

/**
 * Copy operations.
 */

Bigint::Bigint (const Bigint& other) {
    *this = other;
}

Bigint& Bigint::operator= (const Bigint& other) {
    for (int i = DIGITS-1; i >= 0; --i) {
        digits[i] = other.digits[i];
    }
    return *this;
}

/**
 * Convenience operations for conveting to and from int,
 * which is useful for mixed-mode expressions.
 *
 * Note that there no checks for nonsense values!
 */

Bigint::Bigint (int other) {
    *this = other;
}

Bigint& Bigint::operator= (int other) {
    // assumes non-negative value
    for (int i = 0; i < DIGITS; ++i) {
        digits[i] = other % 10;
        other /= 10;
    }
    return *this;
}

Bigint::operator int () const {
    // no check for overflow
    int result = 0;
    for (int i = DIGITS-1; i >= 0; --i) {
        result *= 10;
        result += digits[i];
    }
    return result;
}

/**
 * Arithmetic operations
 *
 * No attempt to optimise for leading zeros.
 * And don't forget that the MSD is on the _right_!!
 */

Bigint operator+ (const Bigint& n1, const Bigint& n2) {
    // placeholder code: only correct if n2 is 0
    return n1;
}

Bigint operator- (const Bigint& n1, const Bigint& n2) {
    // placeholder code: only correct if n2 is 0
    return n1;
}

Bigint operator* (const Bigint& n1, const Bigint& n2) {
    // placeholder code: only correct if n2 is 1
    return n1;
}

Bigint operator/ (const Bigint& n1, const Bigint& n2) {
    // placeholder code: only correct if n2 is 1
    return n1;
}

/**
 * Basic comparisons
 *
 * Could perhaps use a helper to avoid duplication, but
 * probably not worthwhile.
 */

bool operator== (const Bigint& n1, const Bigint& n2) {
    for (int i = DIGITS-1; i >= 0; --i) {
        if (n1.digits[i] != n2.digits[i]) {
            return false;
        }
    }
    return true;
}

bool operator< (const Bigint& n1, const Bigint& n2) {
    for (int i = DIGITS-1; i >= 0; --i) {
        if (n1.digits[i] != n2.digits[i]) {
            return n1.digits[i] < n2.digits[i];
        }
    }
    return false;
}

/**
 * IO operations.
 *
 * Note that there are no checks for nonsense values!
 */

ostream& operator<< (ostream &out, const Bigint& n) {
   
    string result;
    
#ifdef DEBUG
    cout << "operator>>" << endl;
    cout << setw(4) << "[]" << setw(10) << "n" << endl;
#endif
    for (int i = DIGITS - 1; i >= 0; --i) {
        result.append(1, n.digits[i] + '0');
        
#ifdef DEBUG
        
        cout << setw(4) << i << setw(10) << n.digits[i]  << endl;
#endif
    }
    int suppressedZeros;
    suppressedZeros = result.find_first_not_of('0');
    
    if (suppressedZeros == -1) {
        result = '0';
    } else {
        result.erase(0,suppressedZeros);
    }
    return out << result;
}

istream& operator>> (istream& in, Bigint& n) {
 
    string s;
    if (in >> s) {
        // assumes valid digit string
        n = 0;
        int strSize = s.length();
#ifdef DEBUG
        cout << "operator>>" << endl;
        cout << setw(4) << "[]" << setw(10) << "n" << endl;
#endif
        for (int i = 0; v = strSize - 1; i <= DIGITS - 1; ++i, --v;) {
            if (v >= 0) {
            n.digits[i] = s[v] - '0';
            } else {
                n.digits[i] = 0;
            }
            //s.erase(0, 1);
#ifdef DEBUG
          cout << setw(4) << i << setw(10) << n.digits[i]  << endl;
#endif
        }
    }
    return in;
}


