#include <stdexcept>
#include "set_value_command.h"
#include "command_manager.h"

TSetValueCommand::TSetValueCommand(std::vector<int>& vec, int pos,
  int newValue) :
  vec(vec), pos(pos), newValue(newValue)
{
  if (vec.size() <= pos)
  {
    throw std::runtime_error("Out of range");
  }
}

TSetValueCommand::~TSetValueCommand()
{
}

TCommand * TSetValueCommand::Clone()
{
  return new TSetValueCommand(vec, pos, newValue);
}

void TSetValueCommand::DoExecute()
{
  vec[pos] = newValue;
}
