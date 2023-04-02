#include "CustomString.h"
#include <string.h>
#include <iostream>
using namespace std;

class AttributeList;

CustomString::CustomString() {
	str = new char[1];
	str[0] = '\0';
}

CustomString::CustomString(const char* input) {
    if (input == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        str = new char[strlen(input) + 1];
        strcpy(str, input);
        str[strlen(input)] = '\0';
    }
}

CustomString::CustomString(const CustomString& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    str[strlen(other.str)] = '\0';
}

CustomString::CustomString(CustomString&& other) {
    str = other.str;
    other.str = nullptr;
}

CustomString::~CustomString() {
    if (str != nullptr)
        delete[] str;
}

CustomString CustomString::operator +(const char* s1) {
    int length = strlen(this->str) + strlen(s1);
    char* buff = new char[length + 1]; 
    strcpy(buff, this->str);
    strcat(buff,s1);
    buff[length] = '\0';
    CustomString result(buff);
    delete[]buff;
    return result;
}

void CustomString::PushChar (char c) {
    int length = strlen(this->str);
    char* buff = new char[length + 2];
    for (int i = 0; i < length; i++) {
        if(str[i] != '\0')
            buff[i] = str[i];
    }
    buff[length] = c;
    buff[length + 1] = '\0';
    *this = CustomString{ buff };
    delete[]buff;
}

CustomString& CustomString::operator=(const CustomString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

void CustomString::EmptyString() {
        //delete[] str;
        str = new char[1];
        str[0] = '\0';
}

ostream& operator<<(ostream& ostr, CustomString& s)
{
    int i = 0;
    while (s.str[i] != '\0') {
        ostr << s.str[i];
        i++;
    }
    return ostr;
}
