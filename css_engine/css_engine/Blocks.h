#pragma once
#include "Attributes.h"
#include "Selectors.h"
#include "Sections.h"
#define T 5

class Section;

struct BlockNode {
	BlockNode* next;
	BlockNode* prev;
	Section SectionList[T];
	
	BlockNode();
};


class BlockList {
public:
	BlockList();
	void AppendNode(AttributeList* AttList, SelectorList* SelList);
	BlockNode* head;
	BlockNode* tail;
	BlockNode content;
	
};