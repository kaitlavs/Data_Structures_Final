#ifndef CALCULATOR_H
#define CALCULATOR_H

using namespace std;
#include "LinkedList.h"
#include "ItemType.h"
#include <iostream>
#include <stack>

class Calculator
{
public:
  Calculator();
  void Input(string infixeq);
  float EvaluatePostFix(string postfixeq);
private:
  string str;
  stack<char> stack1;
  stack<int> stack2;
  void InfixToPostFix(string infixeq, LinkedList& outputList);
  bool IsOperator(char C);
  bool IsOperand(char C);
  bool CheckParenthesis(string infixeq);
  bool CheckOperator(string infixeq);
};

#endif
