#ifndef INIT_COMMAND_H_
#define INIT_COMMAND_H_

#include <vector>

#include "command.h"
#include "prototype.h"

class TInitCommand : public TCommand
{
public:
  TInitCommand(std::vector<int>& vec);

  ~TInitCommand();

  virtual TCommand* Clone();

protected:
  virtual void DoExecute();

private:
  std::vector<int>& vec;
};

#endif  // INIT_COMMAND_H_
