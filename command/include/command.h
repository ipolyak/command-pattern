#ifndef COMMAND_H_
#define COMMAND_H_

#include "prototype.h"

class TCommand : public TCommandPrototype
{
public:
  virtual ~TCommand() = 0;

  virtual TCommand* Clone() = 0;

  void Execute();

protected:
  virtual void DoExecute() = 0;
};

#endif  // COMMAND_H_
