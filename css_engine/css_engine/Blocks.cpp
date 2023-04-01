#include "Blocks.h"

BlockList::BlockList() {
	head = NULL;
}

void BlockList::AppendNode(Section section) {
	BlockNode* newNode = new BlockNode;
	BlockNode* lastNode = head;
	newNode->next = NULL;
	(newNode->section) = section;

	if (head == NULL) {
		head = newNode;
		cout << "Section node appended as head node" << endl;
		return;
	}
	while (lastNode->next != NULL) {
		lastNode = lastNode->next;
	}
	
	newNode->prev = lastNode;
	lastNode->next = newNode;
	cout << "Section node appended." << endl;
}

void BlockList::PrintList() {
	BlockNode* currentBlockNode = head;
	int counter = 0;
	while (currentBlockNode != NULL) {
		cout << "Node " << counter++ << endl;
		currentBlockNode->section.PrintSection();
		cout << endl;
		currentBlockNode = currentBlockNode->next;
	}
}

BlockNode::BlockNode() {
	holding = 0;
	next = NULL;
	prev = NULL;
}

