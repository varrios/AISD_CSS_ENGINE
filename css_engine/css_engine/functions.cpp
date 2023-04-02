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
	 else if (arg2[0] == 'S' && arg3[0] == '?') {
		 int AttCount = BList->CountSelectorsInSection(atoi(arg1));
		 if (AttCount != -1) {
			 cout << command->str << " == " << AttCount << endl;
		 }
	 }
 }