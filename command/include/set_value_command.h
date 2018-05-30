#ifndef SET_VALUE_COMMAND_H_
#define SET_VALUE_COMMAND_H_

#include <vector>

#include "command.h"
#include "prototype.h"

class TSetValueCommand : public TCommand
{
public:
  TSetValueCommand(std::vector<int>& vec, int pos, int newValue);

  ~TSetValueCommand();

  virtual TCommand* Clone();

protected:
  virtual void DoExecute();

private:
  std::vector<int>& vec;

  int pos;

  int newValue;
};

#endif  // SET_VALUE_COMMAND_H_
