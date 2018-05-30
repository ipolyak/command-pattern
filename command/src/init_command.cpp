#include <stdexcept>
#include "init_command.h"
#include "command_manager.h"

TInitCommand::TInitCommand(std::vector<int>& vec) : vec(vec)
{
}

TInitCommand::~TInitCommand()
{
}

TCommand* TInitCommand::Clone()
{
  return new TInitCommand(vec);
}

void TInitCommand::DoExecute()
{
  vec.clear();
}
