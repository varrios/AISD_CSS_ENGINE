#include "Sections.h"

Section::Section(AttributeList AttListA, SelectorList SelListA) {
	this->AttList = AttListA;
	this->SelList = SelListA;
}

Section::Section() {
	added = '0';
}

void Section::PrintSection() {
	this->SelList.PrintList();
	this->AttList.PrintList();
}

