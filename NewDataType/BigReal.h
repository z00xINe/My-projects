//
// Created by Yousef on 05/11/2023.
//

#ifndef UNTITLED5_BIGREAL_H
#define UNTITLED5_BIGREAL_H
#include <bits/stdc++.h>

using namespace std;


class BigReal {
private:

    deque<char> wholeNumber;
    deque<char> floatNumber;

    bool isValid(string realNumber)
    {
        bool isFloatPoint = false;

        if (realNumber[0] == '+' || realNumber[0] == '-')
        {
            if (realNumber[1] == '0' && realNumber[2] != '.')
                return false;

            for (int i = 1; i < realNumber.size(); ++i)
            {
                if (realNumber[i] == '+' || realNumber[i] == '-')
                    return false;

                else {
                    if (realNumber[i] == '.' && !isFloatPoint)
                        isFloatPoint = true;

                    else if (realNumber[i] != '.')
                        continue;

                    else
                        return false;

                }

            }
            return true;
        }

        else
            return false;
    }

//    int sumFloat(deque<char> other)
//    {
//        int smallestSize;
//
//        if(other.size() > floatNumber.size())
//        {
//            smallestSize = floatNumber.size();
//
//            for (int i = 0; i < other.size() - smallestSize; ++i)
//                floatNumber.push_back('0');
//
//        }
//        else
//        {
//            smallestSize = other.size();
//
//            for (int i = 0; i < floatNumber.size() - smallestSize; ++i)
//                other.push_back('0');
//        }
//
//        bool isCarried = false;
//
//        for (int i = other.size() - 1; i >= 0; --i)
//        {
//            char tempSum;
//
//            if (isCarried)
//            {
//                tempSum = (floatNumber[i] + other[i] + '1') - 48;
//                isCarried = false;
//            }
//
//            else
//                tempSum = (floatNumber[i] + other[i]) - 48;
//
//            if (tempSum > 57)
//            {
//                floatNumber[i] = 48 + (tempSum - 58);
//                isCarried = true;
//
//                if (i == 0)
//                    return 1;
//
//            }
//
//            else
//                floatNumber[i] = tempSum;
//
//        }
//
//        return 0;
//
//    }
//
//    void sumWhole(deque<char> other, int carry)
//    {
//
//        int smallestSize;
//
//        if(other.size() > floatNumber.size())
//        {
//            smallestSize = floatNumber.size();
//
//            for (int i = 0; i < other.size() - smallestSize; ++i)
//                floatNumber.push_front('0');
//
//        }
//
//        else
//        {
//            smallestSize = other.size();
//
//            for (int i = 0; i < floatNumber.size() - smallestSize; ++i)
//                other.push_front('0');
//        }
//
//        bool isCarried = false;
//        char tempSum;
//
//        if (carry == 1)
//        {
//            tempSum = (floatNumber[other.size() - 1] + other[other.size() - 1] + '1') - 48;
//            isCarried = false;
//        }
//
//        else
//            tempSum = (floatNumber[other.size() - 1] + other[other.size() - 1]) - 48;
//
//        if (tempSum > 57)
//        {
//            floatNumber[other.size() - 1] = 48 + (tempSum - 58);
//            isCarried = true;
//        }
//
//        else
//            floatNumber[other.size() - 1] = tempSum;
//
//        for (int i = other.size() - 2; i > 0; --i)
//        {
//            char tempSum;
//
//            if (isCarried)
//            {
//                tempSum = (floatNumber[i] + other[i] + '1') - 48;
//
//                isCarried = false;
//            }
//
//            else
//                tempSum = (floatNumber[i] + other[i]) - 48;
//
//            if (tempSum > 57)
//            {
//                floatNumber[i] = 48 + (tempSum - 58);
//                isCarried = true;
//            }
//
//            else
//                floatNumber[i] = tempSum;
//
//        }
//    }

public:

    BigReal(const BigReal &anotherReal);
    explicit BigReal(const string& realNumber = "+0.0");
    int size();
    int sign();
    BigReal operator + (BigReal& other);
    BigReal operator - (BigReal& other);
    bool operator < (BigReal anotherReal);
    bool operator > (BigReal anotherReal);
    bool operator == (const BigReal& anotherReal);
    friend ostream& operator << (ostream& out, const BigReal& num);

};


#endif //UNTITLED5_BIGREAL_H
