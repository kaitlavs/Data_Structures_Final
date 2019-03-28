#ifndef OPERATORERROR_H
#define OPERATORERROR_H

#include <stdexcept>
using std::runtime_error;

class OperatorError : public runtime_error
{
   public:

      OperatorError()
            : runtime_error("Operator Error") {}

};

#endif
