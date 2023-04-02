#include "Blocks.h"
#define T 8

BlockList::BlockList() {
	head = NULL;
	tail = NULL;
}

//void BlockList::AppendNode(Section section) {
//	BlockNode* newNode = new BlockNode;
//	BlockNode* lastNode = head;
//	newNode->next = NULL;
//	(newNode->section) = section;
//
//	if (head == NULL) {
//		head = newNode;
//		tail = newNode;
//		cout << "Section node appended as head node" << endl;
//		return;
//	}
//	while (lastNode->next != NULL) {
//		lastNode = lastNode->next;
//	}
//
//	newNode->prev = lastNode;
//	lastNode->next = newNode;
//	tail = newNode;
//	cout << "Section node appended." << endl;
//}

int BlockList::CountSections() {
	BlockNode* currentBlockNode = head;
	int counter = 0;
	while (currentBlockNode != NULL) {
		counter += currentBlockNode->holding;
		currentBlockNode = currentBlockNode->next;
	}
	return counter;
}

void BlockList::AppendNode(Section section) {
	
	// if list is empty
	if (tail == NULL) {
		//cout << "Created first BlockNode!" << endl;
		BlockNode* newNode = new BlockNode;
		newNode->AppendSection(section);
		newNode->next = NULL;
		newNode->prev = tail;
		head = newNode;
		tail = newNode;
		return;
	}
	else if(tail->holding >= T) {
		//cout << "Created new BlockNode!" << endl;
		BlockNode* newNode = new BlockNode;
		newNode->AppendSection(section);
		tail->next = newNode;
		newNode->next = NULL;
		newNode->prev = tail;
		tail = newNode;
		return;
	}
	else {
		tail->AppendSection(section);
	}
	
	

}

void BlockNode::AppendSection(Section section) {
	for (int i = 0; i < T; i++) {
		if (this->sectionList[i].added == '0') {
			sectionList[i] = section;
			sectionList[i].added = '1';
			this->holding++;
			//cout << "Appended section to SectionList at " << i << "  Currently Node is holding: " << this->holding << " sections." << endl;
			return;
		}
	}
}

//void BlockList::PrintList() {
//	BlockNode* currentBlockNode = head;
//	int counter = 0;
//	while (currentBlockNode != NULL) {
//		cout << "Node " << counter++ << endl;
//		currentBlockNode->section.PrintSection();
//		cout << endl;
//		currentBlockNode = currentBlockNode->next;
//	}
//	cout << "Head: " << endl;
//	this->head->section.PrintSection();
//	cout << "Tail: " << endl;
//	this->tail->section.PrintSection();
//}

void BlockList::PrintList() {
	BlockNode* currentBlockNode = head;
	while (currentBlockNode != NULL) {
		for (int i = 0; i < T; i++) {
			if (currentBlockNode->sectionList[i].added != '0') {
				currentBlockNode->sectionList[i].PrintSection();
				cout << endl;
			}
		}
		currentBlockNode = currentBlockNode->next;
	}
}
BlockNode::BlockNode() {
	deleted = '0';
	sectionList = new Section[T];
	holding = 0;
	next = NULL;
	prev = NULL;
}


int BlockList::CountSelectorsInSection(int section_num) {
	BlockNode* currentBlockNode = head;
	int counter = 0;
	bool flag = 0;
	while (currentBlockNode != NULL) {
		for (int i = 0; i < T; i++) {
			if (flag) {
				break;
			}
			if (currentBlockNode->sectionList[i].added == '1' && currentBlockNode->sectionList[i].deleted == '0') {
				counter++;
			}
			if (counter > section_num || currentBlockNode->sectionList[i].added != '1') {
				return -1;
			}
			if (counter == section_num) {
				flag = 1;
			}
			
		}
		if (flag) {
			break;
		}else
		currentBlockNode = currentBlockNode->next;
	}
	return currentBlockNode->sectionList[(counter-1)%T].SelList.SelCount;
}