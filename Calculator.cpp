#include "Calculator.h"
#include "LinkedList.h"
#include "ItemType.h"
#include "ParenthesisError.h"
#include "OperatorError.h"

Calculator::Calculator()
{
   str = "";
   stack<char> stack1;
   stack<int> stack2;
}

void Calculator::Input(string infixeq)
{
   infixeq = str;  

   EvaluatePostFix(str);
}

float Calculator::EvaluatePostFix(string infixeq)
{
   string postfixStr;
   LinkedList outputList; 
   int listLength, strLength;
   char item;
   float result, finalResult;

   InfixToPostFix(infixeq, outputList);  
    
   outputList.ResetList();
   listLength = outputList.GetLength();
   for(int counter = 1; counter <= listLength; counter++)
   { 
      outputList.GetNextItem(item);
      postfixStr += item;
   }
 
 
   strLength = postfixStr.length();

   for(int i=0;i<strLength;i++)
   {
      int opd1, opd2;
      if (isdigit(postfixStr[i]))
      {
         int b = postfixStr[i] - '0'; 
         stack2.push(b);
      }
      else
      {
         if (!stack2.empty())
            opd2 = stack2.top();
         stack2.pop();

         if (!stack2.empty())
            opd1 = stack2.top();
         stack2.pop();
      
         if (postfixStr[i] == '+')
         {
            result = opd1 + opd2;
            stack2.push(result);
         }
         else if (postfixStr[i] == '-')
         {
            result = opd1 - opd2;
            stack2.push(result);
         }
         else if (postfixStr[i] == '*') 
         {
            result = opd1 * opd2;
            stack2.push(result);
         }
         else if (postfixStr[i] == '/') 
         {
            result = opd1 / opd2;
            stack2.push(result);
         }

      }
   }
   finalResult = stack2.top();
 
   return finalResult;

}

void Calculator::InfixToPostFix(string infixeq, LinkedList& outputList)
{
   int len;
   char c;
   string name;
   stack<char> listStack;

   len = infixeq.length();

   for(int i=0;i<len;i++) 
   {
      if (IsOperand(infixeq[i])) 
      {
          listStack.push(infixeq[i]);
      }
      else if (infixeq[i] == '(')
      {
          stack1.push(infixeq[i]);
      }
      else if (IsOperator(infixeq[i]))
      {
         bool pushed = false;
  
         while (pushed == false)
         {          
            if ((stack1.empty()) || (stack1.top() == '('))
            {    
                stack1.push(infixeq[i]);
                pushed = true;
            }
            else if ((!stack1.empty()) && (infixeq[i] == '*' || infixeq[i] == '/') && (stack1.top() == '+' || stack1.top() == '-'))
            {
               stack1.push(infixeq[i]);
               pushed = true;
            } 
            else
            {  
                listStack.push(stack1.top());
                stack1.pop(); 
            }
         }

      }
      else if (infixeq[i] == ')')
      {
         while (stack1.top() != '(')
         {
            listStack.push(stack1.top());
            stack1.pop();
         }
         stack1.pop();
      } 
   }  
   while (!stack1.empty())
   {
      listStack.push(stack1.top());
      stack1.pop();     
   }

   while (!listStack.empty())
   {
      outputList.InsertItem(listStack.top());
      listStack.pop();
   }
       
   cout << "Postfix Notation: " << endl;
   outputList.PrintList(outputList);
}

bool Calculator::IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C == '$') 
        return true;
    
     return false;
}

bool Calculator::IsOperand(char C)
{
   if(C >= '0' && C <= '9')
      return true;
   if(C >= 'a' && C <= 'z') 
      return true;
   if(C >= 'A' && C <= 'Z')
      return true;
   return false;
}

bool CheckParenthesis(string infixeq)
{
   int len = infixeq.length();
   stack<char> checkStack;
   bool pError = false;

   for(int i=0;i<len;i++)
   {
       if (infixeq[i] == '(')
           checkStack.push(infixeq[i]);

       else if (infixeq[i] = ')')
       {
          while (!checkStack.empty())
             checkStack.pop();  
       }
    
   } 
   if (!checkStack.empty())
     pError = true;
 
   return pError;  
}

bool CheckOperators(string infixeq)
{
   int len = infixeq.length();
   bool error = false;

   for(int i=0;i<len;i++)
   {
      if(infixeq[i] == '/')
      {
         int opd2;
         opd2 = infixeq[i+1];
         if (opd2 == 0)
            error = true;
      }
   }
   return error;
}
