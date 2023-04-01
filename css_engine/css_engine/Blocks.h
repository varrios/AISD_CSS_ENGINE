#pragma once
#include "Attributes.h"
#include "Selectors.h"
#include "Sections.h"

class Section;

struct BlockNode {
	char deleted;
	int holding;
	BlockNode* next;
	BlockNode* prev;
	Section section;
	Section *sectionList;
	BlockNode();
	void AppendSection(Section section);
};


class BlockList {
public:
	BlockList();
	void AppendNode(Section section);
	void AppendNode2(Section section);
	void PrintList();
	void PrintList2();
	BlockNode* head;
	BlockNode* tail;
	
};