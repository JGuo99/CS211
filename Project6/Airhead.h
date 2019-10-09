//Includes: Inforamtion for airport classes
#include <cstdio>
#include <cstring>
#include <cstdlib>

class MyNODE{
// data members are almost ALWAYS private
  private:
// the X and Y coordinates for the point
    int airport;
    MyNODE* next;
  public:
// use of class constructors to initialize the variables
    MyNODE(int a, MyNODE* n);
    MyNODE();
    void setNext(MyNODE* n);
    int getkey();
    MyNODE* getNextp();
};

class Mylist{
// data members are almost ALWAYS private
  private:
// the X and Y coordinates for the point
    MyNODE *head;
    int size;
  public:
    void printList();
// use of class constructors to initialize the variables
    Mylist();
    void insert_edge(int key);
    void del_edge(int key);
    int isEmpty();
    void listfree();
    int contains(int key);
    MyNODE * gethead();
};

class Airport{
// data members are almost ALWAYS private
  private:
    Mylist* path;
    bool VISITED;
  public:
    Airport();
    void insert_edge(int key);
    void del_edge(int key);
    void printnetwork();
    void Airport_free();
    int Airport_contains(int key);
    void T_VISITED();
    void F_VISITED();
    bool getVISITED();
    Mylist* getlistp();
};
