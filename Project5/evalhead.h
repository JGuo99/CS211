#include "myStack.h"
#include "proj5.h"

using namespace std;

void checkDebug(const int argc, char *argv[]);

bool popAndEval(stack<char> &opStack, stack<int> &valStack);

bool processExpression(Token inputToken, TokenReader *tr);

void printCommands();
