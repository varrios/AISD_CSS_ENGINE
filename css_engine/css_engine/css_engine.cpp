﻿#include <iostream>
#include <string.h>
#include "Sections.h"
#include "Blocks.h"
#include "Attributes.h"
#include "Selectors.h"
#include "CustomString.h"
using namespace std;
int main(int argc, char** argv)
{
    BlockList mainList;
    CustomString buffer("");
    CustomString att("");
    CustomString sel("");
    bool attribute = 0;


    FILE* fname{};
    const char* filename = "test_input.txt";
    int ch;

    fname = fopen(filename, "r");
    while ((ch = fgetc(fname)) != EOF) {
        char znak = (char)ch;
        switch (znak) {
        case '{':
            attribute = 1;
            continue;
            break;

        case '}':
            AttributeList AttributeL;
            SelectorList SelectorL;
            

            attribute = 0;
            DissectAndAppendSelectors(&SelectorL, &sel);
            DissectAndAppendAttributes(&AttributeL, &att, ";");

            Section Section(AttributeL, SelectorL);

           

           /* cout << "Zbudowana sekcja: " << endl;
            Section.PrintSection();
            cout << endl;*/

            mainList.AppendNode(Section);

            att.EmptyString();
            sel.EmptyString();
            continue;
            break;
        }
        if (ch != '\n' && ch != ' ') {
            if (attribute) {
                att.PushChar(znak);
            }
            else {
                sel.PushChar(znak);
            }
        }

    }
    mainList.PrintList();
    fclose(fname);
    
}

