#ifndef PARENTHESISERROR_H
#define PARENTHESISERROR_H

#include <stdexcept>
using std::runtime_error;

class ParenthesisError: public runtime_error
{
  public: 
    
     ParenthesisError()
             : runtime_error("Parenthesis error") {}

};
#endif

