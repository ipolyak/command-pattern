#include <stdexcept>

#include "command_manager.h"
#include "command.h"

TCommand::~TCommand() {}

void TCommand::Execute()
{
  TCommandManager::GetInstance()->SaveCommand(Clone());
  DoExecute();
}
