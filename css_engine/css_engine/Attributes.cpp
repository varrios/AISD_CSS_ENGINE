#include "Attributes.h"

AttributeList::AttributeList() {
	head = NULL;
}

void AttributeList::AppendNode(CustomString* name, CustomString* value) {
	AttributeNode* newNode = new AttributeNode;
	AttributeNode* lastNode = head;
	newNode->next = NULL;
	newNode->name = new char[strlen(name->str)];
	newNode->value = new char[strlen(value->str)];
	strcpy(newNode->name, name->str);
	strcpy(newNode->value, value->str);

	if (head == NULL) {
		head = newNode;
		//cout << newNode->name << "  " << newNode->value << endl;
		//cout << "Attribute node appended as head node" << endl;
		return;
	}
	while (lastNode->next != NULL) {
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
	//cout << "Attribute node appended at the end" << endl;
	//cout << newNode->name  << "  " << newNode->value << endl;
}

void AttributeList::PrintList() {
	AttributeNode* current = head;
	while (current != nullptr) {
		cout << current->name << current->value << endl;
		current = current->next;
	}
}

void DissectAndAppendAttributes(AttributeList* AttL, CustomString* att, const char* delimiter) {
	char* token = strtok(att->str, ";");
	while (token != NULL) {
		CustomString name("");
		CustomString value("");
		bool flag = 0;
		for (int i = 0; i < strlen(token); i++) {
			if (token[i] == ':') {
				flag = 1;
				continue;
			}
			if (flag) {
				value.PushChar(token[i]);
			}
			else {
				name.PushChar(token[i]);
			}

		}
		token = strtok(NULL, ";");
		AttL->AppendNode(&name, &value);
	}
}