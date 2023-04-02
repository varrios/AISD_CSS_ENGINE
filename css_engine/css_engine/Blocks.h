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
	Section *sectionList;
	BlockNode();
	void AppendSection(Section section);
};


class BlockList {
public:
	BlockList();
	void AppendNode(Section section);
	void PrintList();
	BlockNode* head;
	BlockNode* tail;
	int CountSections();
	int CountSelectorsInSection(int section_num);
	
};