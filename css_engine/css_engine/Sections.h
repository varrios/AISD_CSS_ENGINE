#pragma once
#include "Attributes.h"
#include "Selectors.h"
class Section {
public:
	char added;
	char deleted;
	AttributeList AttList;
	SelectorList SelList;
	Section(AttributeList AttList, SelectorList SelList);
	Section();
	void PrintSection();
};