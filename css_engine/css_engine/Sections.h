#pragma once
#include "Attributes.h"
#include "Selectors.h"
class Section {
public:
	AttributeList AttList;
	SelectorList SelList;
	Section(AttributeList AttList, SelectorList SelList);
	Section();
	void PrintSection();
};