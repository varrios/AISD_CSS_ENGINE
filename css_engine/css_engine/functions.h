#pragma once
#include "Attributes.h"
#include "Blocks.h"

void DissectAndAppendAttributes(AttributeList* AttL, CustomString* att, const char* delimiter);

void ParseCommand(CustomString* command, BlockList* BList);
void ExecuteCommand(const char* arg1, const char* arg2, const char* arg3, BlockList* BList, CustomString* command);