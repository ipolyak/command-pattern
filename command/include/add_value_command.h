#ifndef ADD_VALUE_COMMAND_H_
#define ADD_VALUE_COMMAND_H_

#include <vector>

#include "command.h"
#include "prototype.h"

class TAddValueCommand : public TCommand
{
public:
  TAddValueCommand(std::vector<int>& vec, int value);

  ~TAddValueCommand();

  virtual TCommand* Clone();

protected:
  virtual void DoExecute();

private:
  std::vector<int>& vec;

  int value;
};

#endif  // ADD_VALUE_COMMAND_H_
