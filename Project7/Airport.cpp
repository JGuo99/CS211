#include "Airhead.h"
// use of class constructors to initialize the variables
MyNODE::MyNODE(int a,MyNODE* nxtNODE){
  airport = a;
  next = nxtNODE;
}

MyNODE::MyNODE(){
  airport = 0;
  next = NULL;
}

void MyNODE::setNext(MyNODE* nxtNODE){
  next = nxtNODE;
}

int MyNODE::getkey(){
  return airport;
}

MyNODE* MyNODE:: getNextp(){
  return next;
}

Mylist::Mylist(){
  size = 0;
  head = NULL;
}

int Mylist::isEmpty(){
  if (this->head){
    return 0;
  }
  else{
    return 1;
  }
}

void Mylist::insert_edge(int key) {
  MyNODE* tmp = new MyNODE(key, NULL);
  if (size==0){
     head = tmp; size = 1;
  }
  else {
    MyNODE*p = head;
    while (p) {
      if (p->getNextp() == NULL) {
        p->setNext(tmp); size++;
        break;
      }
      p = p->getNextp();
    }
  }
//printf("size is currently %d\n", this->size);
}

void Mylist::del_edge(int key){
  if (this->head == NULL || size == 0) { //printf("list is empty\n");
    return;
}
  MyNODE*c = head;
  MyNODE*p = NULL;
  while (c!=NULL && c->getkey()!=key) {
  //printf("current key is %d \n", c->getkey());
    p = c;
    c = c->getNextp();
  }
  if (c==NULL){
    return;
  }
  if (p==NULL){
    head = c->getNextp();
  }
  else{
    p->setNext(c->getNextp());
  }
  free(c);
  size--;
//printf("size is currently %d\n", this->size);
}

void Mylist::listfree() {
  MyNODE*c = head;
  MyNODE*n = NULL;
  while(c) {
    size--;
    n = c->getNextp();
    delete c;
    c = n;
  }
//printf("size is currently %d\n", this->size);
  head = NULL;
}

void Mylist::printList() {
  if (this->head == NULL ||size==0) {
    printf("list is empty\n"); return;
  }
  MyNODE*p = head;
  while(p) {
    printf("%d ", p->getkey());
    p = p->getNextp();
  }
  printf("\n");
  return;
}

MyNODE* Mylist::gethead() {
  return head;
}

int Mylist::contains(int key) {
//if (this->head == NULL || size == 0) {
  //   printf("list is empty\n"); return 0;
  // }
  MyNODE*p = head;
//if (!p) {
  //   printf("head is NULL \n");
  // }
  while(p) {
//printf("%d ", p->getkey());
    if (p->getkey() == key) {
      return 1;
    }
    p = p->getNextp();
  }
  return 0;
}

Airport::Airport() {
  this->path=new Mylist;
  VISITED = 0;
}

void Airport::insert_edge(int key) {
  if (key == path->contains(key)) {
    printf("This flight path already exists\n");
    return;
  }
  path->insert_edge(key);
}

void Airport::del_edge(int key) {
  path->del_edge(key);
}

void Airport::printnetwork() {
  path->printList();
}

void Airport::Airport_free() {
  path->listfree();
  delete path;
  path = NULL;
}

int Airport::Airport_contains(int key) {
  return path->contains(key);
}

void Airport::T_VISITED() {
  this->VISITED = true;
}

void Airport::F_VISITED() {
  this->VISITED = false;
}

bool Airport::getVISITED() {
  return VISITED;
}

Mylist* Airport::getlistp() {
  return path;
}
