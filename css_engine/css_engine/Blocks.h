#pragma once
#include "Attributes.h"
#include "Selectors.h"
#include "Sections.h"
#define T 5

class Section;

struct BlockNode {
	int holding;
	BlockNode* next;
	BlockNode* prev;
	Section section;
	//Section SectionList[T];
	BlockNode();
};


class BlockList {
public:
	BlockList();
	void AppendNode(Section section);
	void PrintList();
	BlockNode* head;
	
};