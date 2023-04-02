#include <iostream>
#include <string.h>
#include "Sections.h"
#include "Blocks.h"
#include "Attributes.h"
#include "Selectors.h"
#include "CustomString.h"
#include "functions.h"

using namespace std;
int main(int argc, char** argv)
{
    BlockList mainList;
    CustomString command("");
    CustomString buffer("");
    CustomString att("");
    CustomString sel("");
    bool attribute = 0;
    bool commands = 0;
    bool load = 1;


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

                mainList.AppendNode(Section);

                att.EmptyString();
                sel.EmptyString();
                continue;
                break;
            }

        if (ch != ' ') {
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
                else {
                    sel.PushChar(znak);
                }
            }
            else if(commands == 1) {
                if (ch == '\n' || ch == EOF) {
                    ParseCommand(&command, &mainList);
                }
                else {
                    command.PushChar(znak);
                }
            }
        }
        

    }
    //mainList.PrintList();
    fclose(fname);
    
}

