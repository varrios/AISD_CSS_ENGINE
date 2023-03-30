#include "Sections.h"

Section::Section(AttributeList AttListA, SelectorList SelListA) {
	this->AttList = AttListA;
	this->SelList = SelListA;
}

Section::Section() {
}

void Section::PrintSection() {
	this->SelList.PrintList();
	this->AttList.PrintList();
}

