#include "Attributes.h"

AttributeList::AttributeList() {
	head = NULL;
	AttCount = 0;
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
		this->AttCount++;
		//cout << newNode->name << "  " << newNode->value << endl;
		//cout << "Attribute node appended as head node" << endl;
		return;
	}
	while (lastNode->next != NULL) {
		if (strcmp(lastNode->name, name->str) == 0) {
			strcpy(lastNode->value, newNode->value);
			delete newNode;
			return;
		}
		lastNode = lastNode->next;
	}
	if (strcmp(lastNode->name, name->str) == 0) {
		strcpy(lastNode->value, newNode->value);
		delete newNode;
		return;
	}
	lastNode->next = newNode;
	this->AttCount++;
	//cout << "Attribute node appended at the end" << endl;
	//cout << newNode->name  << "  " << newNode->value << endl;
}

void AttributeList::PrintList() {
	AttributeNode* currentAttNode = head;
	while (currentAttNode != nullptr) {
		cout << currentAttNode->name << currentAttNode->value << endl;
		currentAttNode = currentAttNode->next;
	}
}

void AttributeList::DeleteList() {
	AttributeNode* current = head;
	this->AttCount = 0;
	while (current != nullptr) {
		AttributeNode* next = current->next;
		if(current != NULL)
			delete current;
		current = next;
	}

	head = nullptr;
}

bool AttributeList::DeleteNode(const char* name) {
	AttributeNode* nodeToDelete = head;
	while (nodeToDelete != nullptr) {
		if (strcmp(nodeToDelete->name, name) == 0)
			break;
		nodeToDelete = nodeToDelete->next;
	}
	if (nodeToDelete != nullptr) {
		if (nodeToDelete == head) {
			head = head->next;
			this->AttCount--;
			delete nodeToDelete;
			return 1;
		}
		AttributeNode* currentNode = head;
		while (currentNode != nullptr) {
			if (currentNode->next == nodeToDelete) {
				currentNode->next = nodeToDelete->next;
				this->AttCount--;
				delete nodeToDelete;
				return 1;
			}
			currentNode = currentNode->next;
		}
	}
	return 0;
}

