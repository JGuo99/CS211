//Header File
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//Status
enum STAT{
  waiting,
  called,
  none
};
//Group Structure
typedef struct Group{
  int g_size;
  char* g_name;
  struct Group* nxt;
  enum STAT status;
} Group, *group;
//Seven functions with remove function
void addToList(group* hd, int size, char* name, bool inResturant);
void displayGroupSizeAhead(char* name, group hd);
void displayListInformation(group hd);
void removeGroup(group* hd, int n); //used to remove groups
bool updateStatus(group hd, char* name);
bool doesNameExist(group hd, char* name);
int countGroupsAhead(char* name, group hd);
char* retrieveAndRemove(group* hd, int size);
//base functions
void doAdd(group* hd);
void doCallAhead(group* hd);
void doWaiting(group hd);
void doRetrieve(group* hd);
void doList(group hd);
void doDisplay(group hd);
void clearToEoln();
void printCommands();
int getPosInt();
int getNextNWSChar();
char *getName();
typedef enum {FALSE = 0, TRUE, NO = 0, YES}; boolean;
