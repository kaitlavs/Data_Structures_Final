// Kaitlyn Lavan
// Final project 
// 12/7/18

#include "LinkedList.h"
#include "Calculator.h"
#include "ItemType.h"

int main()
{
   Calculator calc;
   string eq;
   float result;

   cout << "Enter an equation in infix notation" << endl;
   getline(cin, eq);

   result = calc.EvaluatePostFix(eq);
  
   cout << endl;
   cout << "The result is: " << result << endl;

return 0;
}
