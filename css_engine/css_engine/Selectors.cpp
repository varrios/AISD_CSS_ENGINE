 #include "Selectors.h";
#include <stdio.h>
#include <string.h>
using namespace std;

SelectorList::SelectorList() {
	head = NULL;
	SelCount = 0;
}

void SelectorList::AppendNode(CustomString* name) {
	SelectorNode* newNode = new SelectorNode;
	SelectorNode* lastNode = head;
	newNode->next = NULL;
	newNode->name = new char[strlen(name->str)];
	strcpy(newNode->name, name->str);

	if (head == NULL) {
		head = newNode;
		SelCount++;
		//cout << "Attribute node appended as head node" << endl;
		return;
	}
	while (lastNode->next != NULL) {
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
	SelCount++;
	//cout << "Attribute node appended at the end" << endl;
	//cout << newNode->name << "<- name" << endl;
}

void SelectorList::PrintList() {
	SelectorNode* currentSelNode = head;
	while (currentSelNode != nullptr) {
		cout << currentSelNode->name << endl;
		currentSelNode = currentSelNode->next;
	}
}


void DissectAndAppendSelectors(SelectorList* SelectorL, CustomString* selectors) {
	char* token = strtok(selectors->str, ",");
	while (token != NULL) {
		CustomString name("");
		name = token;
		token = strtok(NULL, ",");
		SelectorL->AppendNode(&name);
	}
}

void SelectorList::DeleteList() {
	SelectorNode* current = head;
	this->SelCount = 0;
	while (current != nullptr) {
		SelectorNode* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}