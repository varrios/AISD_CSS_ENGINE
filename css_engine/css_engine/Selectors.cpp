 #include "Selectors.h";
#include <stdio.h>
#include <string.h>
using namespace std;

SelectorList::SelectorList() {
	head = NULL;
}

void SelectorList::AppendNode(CustomString* name) {
	SelectorNode* newNode = new SelectorNode;
	SelectorNode* lastNode = head;
	newNode->next = NULL;
	newNode->name = new char[strlen(name->str)];
	strcpy(newNode->name, name->str);

	if (head == NULL) {
		head = newNode;
		//cout << "Attribute node appended as head node" << endl;
		return;
	}
	while (lastNode->next != NULL) {
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
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
