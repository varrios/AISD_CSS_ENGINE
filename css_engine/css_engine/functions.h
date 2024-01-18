#pragma once
#include "Attributes.h"
#include "Blocks.h"

void DissectAndAppendAttributes(AttributeList* AttL, CustomString* att, const char* delimiter);

void ParseCommand(CustomString* command, BlockList* BList);
void ExecuteCommand(char* arg1, char* arg2, char* arg3, BlockList* BList, CustomString* command);

bool checkInteger(const char* arr);
void trim(char* str);