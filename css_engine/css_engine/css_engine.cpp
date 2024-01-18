﻿#include <iostream>
#include <string.h>
#include "Sections.h"
#include "Blocks.h"
#include "Attributes.h"
#include "Selectors.h"
#include "CustomString.h"
#include "functions.h"

using namespace std;
int main()
{
    BlockList mainList;
    CustomString command("");
    CustomString buffer("");
    CustomString att("");
    CustomString sel("");
    bool attribute = 0;
    bool commands = 0;


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
                SelectorL.PrintList();

                mainList.AppendNode(Section);

                att.EmptyString();
                sel.EmptyString();
                continue;
                break;
            }

        if (ch != '\t') {
            if (strcmp(sel.str, "????") == 0) {
                commands = 1;
                sel.EmptyString();
            }
            else if (strcmp(command.str, "****") == 0) {
                commands = 0;
                command.EmptyString();
            }

            if (commands == 0 && ch != '\n') {
                if (attribute) {
                    att.PushChar(znak);
                }
                else if(ch != ' ') {
                    sel.PushChar(znak);
                }
            }
            else if(commands == 1) {
                if (ch == '\n' || ch == EOF || ch == '\b') {
                    ParseCommand(&command, &mainList);
                    command.EmptyString();
                }
                else {
                    command.PushChar(znak);
                }
            }
        }
        

    }
    //mainList.PrintList();
    //fclose(fname);
    
}

