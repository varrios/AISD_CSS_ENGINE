//
// Created by lucja on 30.03.2023.
//

#ifndef AISD_CSS_ENGINE_CPP_CUSTOMSTRING_H
#define AISD_CSS_ENGINE_CPP_CUSTOMSTRING_H
#include <string.h>
#include <iostream>
#include "Attributes.h"

class AttributeList;

using namespace std;
class CustomString
{
public:
    char* str;
    CustomString();
    CustomString(const char* input);
    CustomString(const CustomString& other); // konstruktor kopiujacy
    CustomString(CustomString&& other); //konstruktor przenoszacy
    ~CustomString();
    void PushChar(char c);
    void EmptyString();
    CustomString& operator=(const CustomString& rhs);
    CustomString operator +(const char* s1);

};

ostream& operator <<(ostream& ostr, CustomString& s);

#endif //AISD_CSS_ENGINE_CPP_CUSTOMSTRING_H


