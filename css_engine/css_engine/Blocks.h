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
	int CountAttributesInSection(int section_num);
	char* SelectorNameInSection(int section_num, int selector_num);
	char* GetAttributeValueInSection(int section_num, const char* attribute_name);
	int CountAttributesByName(const char* name);
	int CountSelectorsByName(const char* name);
	char* GetLastAttributeValue(const char* attribute_name, const char* selector_name);
	Section *FindSection(int section_num);
	
};