#include <stdexcept>
#include "add_value_command.h"
#include "command_manager.h"

TAddValueCommand::TAddValueCommand(std::vector<int>& vec, int value) :
  vec(vec), value(value)
{
}

TAddValueCommand::~TAddValueCommand()
{
}

TCommand * TAddValueCommand::Clone()
{
  return new TAddValueCommand(vec, value);
}

void TAddValueCommand::DoExecute()
{
  vec.push_back(value);
}
