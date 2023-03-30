#include "Blocks.h"

BlockList::BlockList() {
	head = NULL;
	tail = NULL;
}

BlockNode::BlockNode() {
	next = NULL;
	prev = NULL;
}