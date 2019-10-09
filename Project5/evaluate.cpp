#include <iostream>
#include "evalhead.h"


using namespace std;
bool debugMode = false;

bool isAdditiveOperator(char anOperator);

bool isArithmeticOperator(int top);

bool isMultiplicativeOperator(char anOperator);

void checkDebug(const int argc, char *argv[]) {
    if (argc == 2) {
        if (!strcmp(argv[1], "-d")) {
            debugMode = true;
        }
    }
}

int operators(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 3;
        default:
            return -1;
    }
}
//Pops both operators and value and evaluates it and pushes answer back on to the stack
bool popAndEval(stack<char> &opStack, stack<int> &valStack) {
    const char op = opStack.top();
    if (op == -1) {
        if (debugMode) {
            cout << "ERROR: Empty operator stack!" << endl;
        }
        return false;
    }

    opStack.pop();

    const int val2 = valStack.top();
    if (val2 == -1) {
        if (debugMode) {
            cout << "ERROR: Empty values stack!" << endl;
        }
        return false;
    }

    valStack.pop();

    const int val1 = valStack.top();
    if (val1 == -1) {
        if (debugMode) {
            cout << "ERROR: Empty values stack!" << endl;
        }
        return false;
    }

    valStack.pop();
    //this does the math.
    int ans = 0;
    if (op == '+') {
        ans = val1 + val2;
    } else if (op == '-') {
        ans = val1 - val2;
    } else if (op == '*') {
        ans = val1 * val2;
    } else if (op == '/') {
        ans = val1 / val2;
    } else {
        if (debugMode) {
            cout << "ERROR: Operator can't be evaluate!" << endl;
        }
        return false;
    }

    valStack.push(ans);
    return true;
}

bool processExpression(Token inputToken, TokenReader *tr) {
    stack<char> opStack;
    stack<int> valStack;

    /* Loop until the expression reaches its end */
    while (!inputToken.equalsType(EOLN)) {
        if (inputToken.equalsType(VALUE)) { // The expression contains a VALUE
            if (debugMode)
                cout << "Value: " << inputToken.getValue() << endl;

            valStack.push(inputToken.getValue());
        } else if (inputToken.equalsType(OPERATOR)) { // The expression contains an OPERATOR
            if (debugMode) {
                cout << "Operator: " << inputToken.getOperator() << endl;
            }

            if (inputToken.getOperator() == '(') { // Operator is "("
                opStack.push(inputToken.getOperator());
            }

            else if (isAdditiveOperator(inputToken.getOperator())) { // Operator is "+" or "-"
                while (!opStack.isEmpty() && isArithmeticOperator(opStack.top())) {
                    if (!popAndEval(opStack, valStack)) {
                        return false;
                    }
                }

                opStack.push(inputToken.getOperator());
            }

            else if (isMultiplicativeOperator(inputToken.getOperator())) { // Operator is "*" or "/"
                while (!opStack.isEmpty() && isMultiplicativeOperator(opStack.top())) {
                    if (!popAndEval(opStack, valStack)) {
                        return false;
                    }
                }

                opStack.push(inputToken.getOperator());
            }

            else if (inputToken.getOperator() == ')') { // Operator is ")"
                while (!opStack.isEmpty() && opStack.top() != '(') {
                    if (!popAndEval(opStack, valStack)) {
                        return false;
                    }
                }

                if (opStack.isEmpty()) {
                    if (debugMode) {
                        cout << "ERROR: Operator stack is empty!" << endl;
                    }
                    return false;
                } else {
                    opStack.pop();
                }
            }
        }

        /* get next token from input */
        inputToken = tr->getNextToken();
    }

    /* The expression has reached its end */

    while (!opStack.isEmpty()) {
        if (!popAndEval(opStack, valStack)) {
            return false;
        }
    }

    const int answer = valStack.top();
    if (answer == -1) {
        if (debugMode) {
            cout << "ERROR: Values stack is empty when getting the result!" << endl;
        }
        return false;
    }

    cout << "The expression evaluates to: " << answer << endl;

    valStack.pop();
    if (!valStack.isEmpty()) {
        if (debugMode) {
            cout << "ERROR: Values stack is not empty after evaluating the expression!" << endl;
        }
        return false;
    }

    cout << endl;
    return true;
}

bool isMultiplicativeOperator(char anOperator) {
    return anOperator == '*' or anOperator == '/';
}

bool isArithmeticOperator(int top) {
    return top == '+' or top == '-' or top == '*' or top == '/';
}

bool isAdditiveOperator(char anOperator) {
    return anOperator == '+' or anOperator == '-';
}

void printCommands() {
    printf("The commands for this program are:\n\n");
    printf("q - to quit the program\n");
    printf("? - to list the accepted commands\n");
    printf("or any infix mathematical expression using operators of (), *, /, +, -\n");
}

int main(int argc, char *argv[]) {
    checkDebug(argc, argv);

    Token inputToken;
    TokenReader tr;

    cout << "Starting Expression Evaluation Program" << endl << endl;
    printCommands();

    cout << "Enter Expression: ";
    inputToken = tr.getNextToken();
    while (inputToken.equalsType(QUIT) == false) {
        /* check first Token on Line of input */
        if (inputToken.equalsType(HELP)) {
            printCommands();
            tr.clearToEoln();
        } else if (inputToken.equalsType(ERROR)) {
            cout << "Invalid Input - For a list of valid commands, type ?" << endl;
            tr.clearToEoln();
        } else if (inputToken.equalsType(EOLN)) {
            cout << "Blank Line - Do Nothing" << endl;
        } else {
            if (!processExpression(inputToken, &tr)) {
                cout << "Invalid infix expression!" << endl;
            }
        }

        cout << endl << "Enter Expression: ";
        inputToken = tr.getNextToken();
    }

    cout << "Quitting Program" << endl;
    return 0;
}
