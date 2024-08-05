//
// Created by Yousef on 05/11/2023.
//

#include "BigReal.h"
#include <bits/stdc++.h>


struct sum_carry {
    deque<char> sum;
    int carry;
};
sum_carry add_float ( deque < char >a,  deque < char >b,int carry = 0) {
    // add_float implementation
    deque < char >sum;

    int size = max (a.size (), b.size ());
    while (a.size () < size)
    {
        a.push_back ('0');

    }
    while (b.size () < size)
    {
        b.push_back ('0');
    }
    for (int i = size - 1; i >= 0; i--)
    {
        int digit_sum = (a[i] - 48) + (b[i] - 48) + carry;
        carry = digit_sum / 10;
        sum.push_front ((digit_sum % 10) + 48);
    }
    if (carry > 0)
    {
        sum.push_front (carry + 48);
        carry = 0;
    }
    if(sum.size()>size)
    {
        carry=(sum[0]-'0');
        sum.pop_front();
    }
    return {sum, carry};
}
sum_carry subt_float( deque < char >a,  deque < char >b,int carry = 0) {
    // add_float implementation
    deque<char> sum;

    int size = max(a.size(), b.size());
    while (a.size() < size) {
        a.push_back('0');

    }
    while (b.size() < size) {
        b.push_back('0');
    }
    for (int i = size - 1; i >= 0; i--) {
        int digit_sum = (a[i] - '0') - (b[i] - '0') + carry;
        if (digit_sum < 0) {
            digit_sum += 10;
            carry = -1;
        } else { carry = digit_sum / 10; }
        sum.push_front((digit_sum % 10) + '0');
    }
    if (carry > 0) {
        sum.push_front(carry + '0');
        carry = 0;
    }
    if (sum.size() > size) {
        carry = (sum[0] - '0');
        sum.pop_front();
    }
    return {sum, carry};
}

BigReal::BigReal(const string& realNumber)
{
    if (isValid(realNumber))
    {
        bool beforePoint = true;

        for (char i : realNumber)
        {

            if(beforePoint)
            {
                if(i == '.')
                {
                    beforePoint = false;
                    continue;
                }

                this->wholeNumber.push_back(i);
            }

            else
                this->floatNumber.push_back(i);

        }

    }

    else
        cout << "Not Valid Real Number!\n";
}

BigReal::BigReal(const BigReal &anotherReal)
{
    this->wholeNumber = anotherReal.wholeNumber;

    this->floatNumber = anotherReal.floatNumber;
}


int BigReal::sign()
{
    return wholeNumber[0];
}

BigReal BigReal::operator + (BigReal& other) {
    BigReal n;
    deque<char> a;
    deque<char> b;
    deque<char> r1;
    deque<char> r2;

    if (wholeNumber[0] == other.wholeNumber[0]) {
        a = floatNumber;
        b = other.floatNumber;
        sum_carry s;
        s = add_float(a, b);
        r1 = s.sum;
        int c = s.carry;
        a = wholeNumber;
        b = other.wholeNumber;
        a.pop_front();
        b.pop_front();
        int size = max(a.size(), b.size());
        while (a.size() < size) {
            a.push_front('0');

        }
        while (b.size() < size) {
            b.push_front('0');
        }
        s = add_float(a, b,c);
        r2=s.sum;
        if (s.carry!=0)
            r2.push_front((char)s.carry);
        r2.push_front(other.wholeNumber[0]);
        n.floatNumber = r1;
        n.wholeNumber = r2;
        return BigReal(n);
    }else{
        a = floatNumber;
        b = other.floatNumber;
        sum_carry s;
        s = subt_float(a, b);
        r1 = s.sum;
        int c = s.carry;
        a = wholeNumber;
        b = other.wholeNumber;
        a.pop_front();
        b.pop_front();
        int size = max(a.size(), b.size());
        while (a.size() < size) {
            a.push_front('0');

        }
        while (b.size() < size) {
            b.push_front('0');
        }
        s = subt_float(a, b,c);
        r2=s.sum;
        if (s.carry!=0)
            r2.push_front((char)s.carry);
        for (int i=1;i<size;i++) {
            if (wholeNumber[i] > other.wholeNumber[i]) {
                r2.push_front(wholeNumber[0]);
                break;
            }else if (wholeNumber[i] < other.wholeNumber[i]){
                r2.push_front(other.wholeNumber[0]);
                break;
            }
        }

        n.floatNumber = r1;
        n.wholeNumber = r2;
        return BigReal(n);
    }
}
BigReal BigReal::operator - (BigReal& other) {
    deque<char> a;
    deque<char> b;
    deque<char> r1;
    deque<char> r2;
    sum_carry s;
    BigReal n;
    a=wholeNumber;
    b=other.wholeNumber;
    int size = max(a.size(), b.size());


    if ((wholeNumber[0] == other.wholeNumber[0] and wholeNumber[0]=='+')or(wholeNumber[0]=='-' and other.wholeNumber[0]=='+' )){
        a = floatNumber;
        b = other.floatNumber;
        sum_carry s;
        s = subt_float(a, b);
        r1 = s.sum;
        int c = s.carry;
        a = wholeNumber;
        b = other.wholeNumber;
        a.pop_front();
        b.pop_front();
        while (a.size() < size) {
            a.push_front('0');

        }
        while (b.size() < size) {
            b.push_front('0');
        }
        s = subt_float(a, b,c);
        r2=s.sum;
        if (s.carry!=0)
            r2.push_front((char)s.carry);
        for (int i=1;i<size;i++) {
            if (wholeNumber[i] > other.wholeNumber[i]) {
                r2.push_front(wholeNumber[0]);
                break;
            }else if (wholeNumber[i] < other.wholeNumber[i]){
                r2.push_front(other.wholeNumber[0]);
                break;
            }
        }

        n.floatNumber = r1;
        n.wholeNumber = r2;
    } else{
        if ((wholeNumber[0] == '-' and other.wholeNumber[0]=='-')or (wholeNumber[0] == '+' and other.wholeNumber[0]=='-')){
            a = floatNumber;
            b = other.floatNumber;
            sum_carry s;
            s = subt_float(a, b);
            r1 = s.sum;
            int c = s.carry;
            a = wholeNumber;
            b = other.wholeNumber;
            a.pop_front();
            b.pop_front();
            int size = max(a.size(), b.size());
            while (a.size() < size) {
                a.push_front('0');

            }
            while (b.size() < size) {
                b.push_front('0');
            }
            s = subt_float(a, b,c);
            r2=s.sum;
            if (s.carry!=0)
                r2.push_front((char)s.carry);
            for (int i=1;i<size;i++) {
                if (wholeNumber[i] > other.wholeNumber[i]) {
                    r2.push_front(wholeNumber[0]);
                    break;
                }else if (wholeNumber[i] < other.wholeNumber[i]){
                    r2.push_front(other.wholeNumber[0]);
                    break;
                }
            }

            n.floatNumber = r1;
            n.wholeNumber = r2;

        }else{
            sum_carry s;
            s = add_float(a, b);
            r1 = s.sum;
            int c = s.carry;
            a = wholeNumber;
            b = other.wholeNumber;
            a.pop_front();
            b.pop_front();
            int size = max(a.size(), b.size());
            while (a.size() < size) {
                a.push_front('0');

            }
            while (b.size() < size) {
                b.push_front('0');
            }
            s = add_float(a, b,c);
            r2=s.sum;
            if (s.carry!=0)
                r2.push_front((char)s.carry);
            r2.push_front(other.wholeNumber[0]);
            n.floatNumber = r1;
            n.wholeNumber = r2;
            return BigReal(n);
        }
    }

    return BigReal(n);
}

bool BigReal::operator < (BigReal anotherReal)
{
    if (this->sign() == '+' && anotherReal.sign() == '-')
        return false;
    else if (this->sign() == '-' && anotherReal.sign() == '+')
        return true;

    if (this->wholeNumber.size() != anotherReal.wholeNumber.size())
    {
        return (this->sign() == '+' && this->wholeNumber.size() < anotherReal.wholeNumber.size()) ||
               (this->sign() == '-' && this->wholeNumber.size() > anotherReal.wholeNumber.size());
    }

    for (int i = 0; i < this->wholeNumber.size(); ++i)
    {
        if (this->wholeNumber[i] < anotherReal.wholeNumber[i])
            return (this->sign() == '+');

        if (this->wholeNumber[i] > anotherReal.wholeNumber[i])
            return (this->sign() == '-');
    }

    for (int i = 0; i < this->floatNumber.size(); ++i)
    {
        if (this->floatNumber[i] < anotherReal.floatNumber[i])
            return (this->sign() == '+');

        if (this->floatNumber[i] > anotherReal.floatNumber[i])
            return (this->sign() == '-');
    }

    return false;
}

bool BigReal::operator > (BigReal anotherReal)
{
    if (this->sign() == '+' && anotherReal.sign() == '-')
        return true;
    else if (this->sign() == '-' && anotherReal.sign() == '+')
        return false;

    if (this->wholeNumber.size() != anotherReal.wholeNumber.size())
    {
        return (this->sign() == '+' && this->wholeNumber.size() > anotherReal.wholeNumber.size()) ||
               (this->sign() == '-' && this->wholeNumber.size() < anotherReal.wholeNumber.size());
    }

    for (int i = 0; i < this->wholeNumber.size(); ++i)
    {
        if (this->wholeNumber[i] > anotherReal.wholeNumber[i])
            return (this->sign() == '+');

        if (this->wholeNumber[i] < anotherReal.wholeNumber[i])
            return (this->sign() == '-');
    }

    for (int i = 0; i < this->floatNumber.size(); ++i)
    {
        if (this->floatNumber[i] > anotherReal.floatNumber[i])
            return (this->sign() == '+');

        if (this->floatNumber[i] < anotherReal.floatNumber[i])
            return (this->sign() == '-');
    }

    return false;
}

bool BigReal::operator == (const BigReal& anotherReal)
{
    if (wholeNumber==anotherReal.wholeNumber and floatNumber==anotherReal.floatNumber )
    {
        return true;
    }
    else
        return false;
}

ostream& operator << (ostream& out, const BigReal& num)
{
    for (char i : num.wholeNumber)
    {
        out << i;
    }
    out << ".";
    for (char i : num.floatNumber)
        out << i;

    return out;
}

int BigReal::size()
{
    return wholeNumber.size() + floatNumber.size() + 1;
}