#pragma once
#include "CustomString.h"

class CustomString;

struct AttributeNode {
	char* name;
	char* value;
	AttributeNode *next;
};



class AttributeList {
public:
	int AttCount;
	AttributeNode *head;
	AttributeList();
	void AppendNode(CustomString* name, CustomString* value);
	void PrintList();
};

void DissectAndAppendAttributes(AttributeList* AttL, CustomString* att, const char* delimiter);
