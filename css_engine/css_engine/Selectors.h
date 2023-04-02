#pragma once
#include "CustomString.h"
struct SelectorNode {
    char* name;
    SelectorNode* next;
};

class SelectorList {
public:
    int SelCount;
    SelectorNode* head;
    void AppendNode(CustomString* name);
    void PrintList();
    SelectorList();
};

void DissectAndAppendSelectors(SelectorList* SelectorL, CustomString* selectors);