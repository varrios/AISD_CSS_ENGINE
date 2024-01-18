#include "Blocks.h"
#include "functions.h"
#define T 8

BlockList::BlockList() {
	head = NULL;
	tail = NULL;
}

BlockNode::BlockNode() {
	reached_max = '0';
	added = 0;
	sectionList = new Section[T];
	holding = 0;
	next = NULL;
	prev = NULL;
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
	int tail_dead = 0;
	if (tail != NULL) {
		for (int i = 0; i < T; i++) {
			if (tail->sectionList[i].deleted == '1')
				tail_dead++;

		}
	}
	// if list is empty
	if (tail == NULL) {
		//cout << "Created first BlockNode!" << endl;
		BlockNode* newNode = new BlockNode;
		newNode->added++;
		newNode->AppendSection(section);
		++newNode->holding;
		//section.PrintSection();
		/*cout << endl;*/
		newNode->next = NULL;
		newNode->prev = tail;
		head = newNode;
		tail = newNode;
		return;
	}
<<<<<<< HEAD
	else if(tail->added >= T) {
=======
	else if(tail->holding+tail_dead >= T) {
>>>>>>> 6836d6598cbe574742ca87fc5c0ac05497bc21c0
		tail->reached_max = '1';
		//cout << "Created new BlockNode!" << endl;
		BlockNode* newNode = new BlockNode;
		newNode->AppendSection(section);
<<<<<<< HEAD
		newNode->added++;
=======
		++newNode->holding;
		//section.PrintSection();
>>>>>>> 6836d6598cbe574742ca87fc5c0ac05497bc21c0
		tail->next = newNode;
		newNode->next = NULL;
		newNode->prev = tail;
		tail = newNode;
		return;
	}
	else {
		//section.PrintSection();
		//cout << endl;
		tail->AppendSection(section);
		tail->holding++;
	}
	
	

}

void BlockNode::AppendSection(Section section) {
	for (int i = 0; i < T; i++) {
		if (this->sectionList[i].added == '0') {
			sectionList[i] = section;
			sectionList[i].added = '1';
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
	int counter = 0;
	BlockNode* currentBlockNode = head;
	while (currentBlockNode != NULL) {
		for (int i = 0; i < T; i++) {
			if (currentBlockNode->sectionList[i].deleted != '1') {
				currentBlockNode->sectionList[i].SelList.PrintList();
				//counter++;
				cout << endl;
			}
		}
		currentBlockNode = currentBlockNode->next;
	}
	//cout << counter;
}


Section* BlockList::FindSection(int section_num) {
	BlockNode* currentBlockNode = head;
	int counter = 0;
	int how_many_live_sections = 0;
	while (currentBlockNode != NULL) {
		for (int i = 0; i < T; i++) {
			if (currentBlockNode->sectionList[i].added == '1' && currentBlockNode->sectionList[i].deleted == '0') {
				how_many_live_sections++;
			}
			if (how_many_live_sections == section_num) {
				return &(currentBlockNode->sectionList[i]);
			}
		}
		currentBlockNode = currentBlockNode->next;
	}
	return nullptr;
}

int BlockList::CountSelectorsInSection(int section_num) {
	Section *found_section = this->FindSection(section_num);
	if (found_section != nullptr) {
		return found_section->SelList.SelCount;
	}
	return -1;
}


int BlockList::CountAttributesInSection(int section_num) {
	Section* found_section = this->FindSection(section_num);
	if (found_section != nullptr) {
		return found_section->AttList.AttCount;
	}
	return -1;
}


char* BlockList::SelectorNameInSection(int section_num, int selector_num) {
	Section* found_section = this->FindSection(section_num);
	if (found_section == nullptr) {
		return NULL;
	}
	SelectorNode* currentSelNode = found_section->SelList.head;
	int index = 1;
	while (currentSelNode != NULL) {
		if (index == selector_num) {
			return currentSelNode->name;
		}
		index++;
		currentSelNode = currentSelNode->next;
	}
	return NULL;
}

char* BlockList::GetAttributeValueInSection(int section_num, const char* attribute_name) {
	Section* foundSection = this->FindSection(section_num);
	if (foundSection != NULL) {
		AttributeNode* currentAttNode = foundSection->AttList.head;
		while (currentAttNode != NULL) {
			if (strcmp(currentAttNode->name, attribute_name) == 0) {
				return currentAttNode->value;
			}
			currentAttNode = currentAttNode->next;
		}
	}
	return NULL;
}


int BlockList::CountAttributesByName(const char* name) {
	BlockNode* currentBlockNode = head;
	int counter = 0;
	while (currentBlockNode != NULL) {
		for (int i = 0; i < T; i++) {
			AttributeNode* current_AttNode = currentBlockNode->sectionList[i].AttList.head;
			if (currentBlockNode->sectionList[i].deleted == '0' && currentBlockNode->sectionList[i].added == '1') {
				while (current_AttNode != nullptr) {
					if (strcmp(current_AttNode->name, name) == 0)
						counter++;
					current_AttNode = current_AttNode->next;
				}
			}
		}
		currentBlockNode = currentBlockNode->next;
	}
	return counter;
	
}


int BlockList::CountSelectorsByName(const char* name) {
	BlockNode* currentBlockNode = head;
	int counter = 0;
	while (currentBlockNode != NULL) {
		for (int i = 0; i < T; i++) {
			Section current_sec = currentBlockNode->sectionList[i];
			if (current_sec.deleted == '0' && current_sec.added == '1') {
				SelectorNode *current_SelNode = current_sec.SelList.head;
				while (current_SelNode != nullptr) {
					if (strcmp(current_SelNode->name, name) == 0)
						counter++;
					current_SelNode = current_SelNode->next;
				}
			}
		}
		currentBlockNode = currentBlockNode->next;
	}
	return counter;

}

char* BlockList::GetLastAttributeValue(const char* attribute_name, const char* selector_name) {
	struct BlockNode* currentBlockNode = tail;

	while (currentBlockNode != NULL) {
		for (int i = T - 1; i >= 0; i--) {
			if (currentBlockNode->sectionList[i].added == '1' && currentBlockNode->sectionList[i].deleted == '0') {
				SelectorNode* current_SelNode = currentBlockNode->sectionList[i].SelList.head;
				while (current_SelNode != nullptr) {
					if (strcmp(current_SelNode->name, selector_name) == 0) {
						AttributeNode* current_AttNode = currentBlockNode->sectionList[i].AttList.head;
						while (current_AttNode != nullptr) {
							if (strcmp(current_AttNode->name, attribute_name) == 0)
								return current_AttNode->value;
							current_AttNode = current_AttNode->next;
						}
					}
						
					current_SelNode = current_SelNode->next;
				}
			}
		}
		currentBlockNode = currentBlockNode->prev;
	}
	return nullptr;
}

bool BlockList::DeleteSection(int section_num) {
	if (section_num <= 0 || section_num > this->CountSections()) {
		return 0;
	}
	BlockNode* currentBlockNode = head;
	int index = 0;
	int counter = 0;
	int flag = 0;
	int how_many_live_sections = 0;
	while (currentBlockNode != NULL) {
		for (int i = 0; i < T; i++) {
			if (currentBlockNode->sectionList[i].added == '1' && currentBlockNode->sectionList[i].deleted == '0' && flag == 0) {
				how_many_live_sections++;
			}
			if (how_many_live_sections == section_num && flag != 1) {
				flag = 1;
				index = i;
			}
		}
		if (flag)
			break;
		currentBlockNode = currentBlockNode->next;
	}
	if (currentBlockNode != NULL) {
		//currentBlockNode->sectionList[index].AttList.DeleteList();
		//currentBlockNode->sectionList[index].SelList.DeleteList();
		currentBlockNode->sectionList[index].deleted = '1';
		currentBlockNode->holding--;
		if ((currentBlockNode->holding) <= 0) {
			if (currentBlockNode == head) {
				head = currentBlockNode->next;
			}
			if (currentBlockNode == tail) {
				tail = currentBlockNode->prev;
			}
			if (currentBlockNode->prev != NULL) {
				currentBlockNode->prev->next = currentBlockNode->next;
			}
			if (currentBlockNode->next != NULL) {
				currentBlockNode->next->prev = currentBlockNode->prev;
			}
			if (currentBlockNode != NULL) {
				delete currentBlockNode;
				return 1;
			}
		}
		return 1;
	}
	return 0;
	
} 

bool BlockList::DeleteAttribute(int section_num ,const char* name) {
	if (section_num <= 0) {
		return 0;
	}
	Section* section = this->FindSection(section_num);
	if (section != nullptr) {
		bool wynik_usuwania_att = section->AttList.DeleteNode(name);
		if (wynik_usuwania_att == 0)
			return 0;
		if (section->AttList.AttCount <= 0) {
			if(this->DeleteSection(section_num) == true);
				return 1;
		}
		if (wynik_usuwania_att == 1)
			return 1;
	}
	return 0;
}
