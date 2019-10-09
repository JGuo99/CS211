/*
* Source File 2
* This file includes all the seven functions
*/
#include "waitList.h"

// addToList(): This operation is to add a new node to the end of the linked list.
// This is to be used when the a and c commands are given as input.
void addToList(group* hd, int size, char* name, bool inResturant){
  group tmp = (group) malloc (sizeof(Group));
  //get name, size and Status
  tmp -> g_name = (char*) malloc (sizeof(char) * (26));
  strcpy(tmp -> g_name, name);
  tmp -> g_size = size;
  tmp -> status = (inResturant ? waiting : called);
  tmp -> nxt = NULL;
  if((*hd) == NULL || hd == NULL){
    *hd = tmp;
    return;
  }
  while((*hd) -> nxt != NULL){
    (*hd) = (*hd) -> nxt;
  }
  (*hd) -> nxt = tmp;
}

// doesNameExist() : This operation is to return a Boolean value indicating whether a name already
// exists in the linked list. This is to be used when the a, c, w and l commands are given as input.
bool doesNameExist(group hd, char* name){
  while(hd -> nxt != NULL){
    //compare the previous string name
    if(!strcmp(name, hd -> g_name)) return true;
    hd = hd -> nxt;
  } return false;
}

// updateStatus() : This operation is to change the in-restaurant status when a call-ahead group
// arrives at the restaurant. This operation will return a FALSE value if that group is already
// marked as being in the restaurant. This is to be used when the w command is given as input.
bool updateStatus(group hd, char* name){
  while(strcmp(name, hd -> g_name) && hd -> nxt != NULL){
    hd = hd -> nxt;
  }
  //checks if the group is not in waitng then set group in waiting.
  if (!strcmp(hd -> g_name, name) && hd -> status != waiting){
    hd -> status = waiting;
    return true;
  }
  printf("Group '%s' is not found or in restaurant.\n", name);
  return false;
}

// retrieveAndRemove() : This operation is to find the first in-restaurant group that can fit at a
// given table. This operation is to return the name of group. This group is to be removed from the
// linked list. This is to be used when the r command is given as input.
char* retrieveAndRemove(group* hd, int size){
  int cnt = 1;
  group hdptr = *hd;
  group tmp = NULL;
  // find group that fits in table
  while(hdptr != NULL && hdptr -> g_size > size){
    tmp = hdptr;
    hdptr = hdptr -> nxt;
    cnt++;
  }
  // group is removed from list when table found
  if(hdptr != NULL){
    char* g_name = (char*) malloc (sizeof(char) * (strlen(hdptr -> g_name) + 1));
    strcpy(g_name, hdptr -> g_name);
    //remove group
    removeGroup(hd, cnt);
    return g_name;
  } return NULL;
}

// removeGroup() :This operation removes the n-th group from the list. It help support the
// function retrieveAndRemove().
void removeGroup(group* hd, int n){
  int cnt = 0;
  if((*hd) == NULL) return;
  if(n == 1){
    *hd = (*hd) -> nxt;
  } else if(n > 1){
    while (n - 2 > cnt && (*hd) != NULL){
      (*hd) = (*hd) -> nxt;
      cnt++;
    }
    free((*hd) -> nxt);
    (*hd) -> nxt = (*hd) -> nxt -> nxt;
  }
}

// countGroupsAhead() : This operation is to return the number of groups waiting ahead of a
// group with a specific name. This is to be used when the l command is given as input.
int countGroupsAhead(char* name, group hd){
  int cnt = 0;
  while (strcmp(name, hd -> g_name)){
    hd = hd -> nxt;
  }
  while(hd -> nxt != NULL){
    cnt++;
    hd = hd -> nxt;
  } return cnt;
}

// displayGroupSizeAhead() : This operation traverses down the list until a specific group name
// is encountered. As each node is traversed, print out that node’s group size. This command is
// to be used when the l command is given.
void displayGroupSizeAhead(char* name, group hd){
  int cnt = 0;
  printf("First to last in line:\n");
  while(hd != NULL){
    if(!strcmp(hd -> g_name, name)){
      break;
    }
    // Counts the size of the group and then prints out how many groups ahead
    printf("Group size: %d \n", hd -> g_size);
    cnt++;
    hd = hd -> nxt;
  }
  printf("Groups Ahead: %d\n", cnt);
}

// displayListInformation() : This operation to traverse down the entire list from beginning to
// end. As each node is traversed, print out that node’s group name, group size and in-restaurant
// status. This command is to be used when the d command is given as input.
void displayListInformation(group hd){
  int cnt = 0;
  int status;
  // Display each groups name, size, and status
  while(hd != NULL){
    status = hd -> status;
    printf("Name of the Group: %s\n", hd -> g_name);
    printf("Size of the Group: %s\n", hd -> g_size);
    printf("Status of the Group: ");
    switch(status) {
      case 1:
        printf("Called");
        break;
      case 2:
        printf("In-restaurant");
        break;
      default:
        printf("None");
        break;
    }
    hd = hd -> nxt;
    cnt++;
  }
  printf("Total groups waiting: %d\n", cnt);
}
