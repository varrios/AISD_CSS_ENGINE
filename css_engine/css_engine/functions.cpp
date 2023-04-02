#include "functions.h"

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

 void ParseCommand(CustomString* command, BlockList* BList) {
		 int index = 1;
		 CustomString buf1("");
		 CustomString buf2("");
		 CustomString buf3("");
		 for (int i = 0; i < strlen(command->str); i++) {
			 if (command->str[i] == ',')
				 index++;
			 else {
				 if (index == 1) {
					 buf1.PushChar(command->str[i]);
				 }
				 if (index == 2) {
					 buf2.PushChar(command->str[i]);
				 }
				 if (index == 3) {
					 buf3.PushChar(command->str[i]);
				 }
			 }
			 
		 }
		 ExecuteCommand(buf1.str, buf2.str, buf3.str, BList, command);
		 command->EmptyString(); 
 }


 void ExecuteCommand(const char* arg1, const char* arg2, const char* arg3, BlockList* BList, CustomString* command){
	 if(arg1[0] == '?' && strlen(arg2) == 0 && strlen(arg3) == 0)
		 cout << "? == " << BList->CountSections() << endl;
	 else if (arg2[0] == 'S' && arg3[0] == '?' && checkInteger(arg1)) {
		 int SelCount = BList->CountSelectorsInSection(atoi(arg1));
		 if (SelCount != -1) {
			 cout << command->str << " == " << SelCount << endl;
		 }
		 return;
	 }
	 else if (arg2[0] == 'A' && arg3[0] == '?' && checkInteger(arg1)) {
		 int AttCount = BList->CountAttributesInSection(atoi(arg1));
		 if (AttCount != -1) {
			 cout << command->str << " == " << AttCount << endl;
		 }
		 return;
	 }
	 else if (arg2[0] == 'S' && checkInteger(arg1) && checkInteger(arg3)) { //ostatni
		 char* FoundSel = BList->SelectorNameInSection(atoi(arg1), atoi(arg3));
		 if (FoundSel != NULL) {
			 cout << command->str << " == " << FoundSel << endl;
		 }
		 return;
	 }
	 else if (arg2[0] == 'A' && checkInteger(arg1) && (checkInteger(arg3) == 0)) { //ostatni
		 char* FoundVal = BList->GetAttributeValueInSection(atoi(arg1), arg3);
		 if (FoundVal != NULL) {
			 cout << command->str << " == " << FoundVal << endl;
		 }
		 return;
	 }
	 else if (arg2[0] == 'A' && (checkInteger(arg1) == 0) && arg3[0] == '?') { //ostatni
		 int FoundVal = BList->CountAttributesByName(arg1);
		 cout << command->str << " == " << FoundVal << endl;
		 return;
	 }
	 else if (arg2[0] == 'S' && (checkInteger(arg1) == 0) && arg3[0] == '?') { //ostatni
		 int FoundVal = BList->CountSelectorsByName(arg1);
		 cout << command->str << " == " << FoundVal << endl;
		 return;
	 }
	 else if (arg2[0] == 'E' && (checkInteger(arg1) == 0) && (checkInteger(arg3) == 0)) { //ostatni
		 char* FoundVal = BList->GetLastAttributeValue(arg3,arg1);
		 if(FoundVal != nullptr)
			cout << command->str << " == " << FoundVal << endl;
		 return;
	 }
 }

 bool checkInteger(const char* arr) {
	 int i = 0;
	 while (arr[i] != '\0') {
		 if (arr[i] < '0' || arr[i] > '9') return 0;
		 i++;
	 }
	 return 1;
 }