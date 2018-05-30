#include <iostream>

#include "command_manager.h"

TCommandManager* TCommandManager::cm = NULL;

TCommandManager::TCommandManager() : history(), lock(false)
{}

TCommandManager* TCommandManager::GetInstance()
{
  if (cm == NULL)
  {
    cm = new TCommandManager();
  }

  return cm;
}

void TCommandManager::Undo()
{
  if (history.size() <= 1)
  {
    std::cout << "Warning. Command history is empty" << std::endl;
    return;
  }

  lock = true;

  delete history.back();
  history.pop_back();
  for (int i = 0; i < history.size(); ++i)
  {
    history[i]->Execute();
  }

  lock = false;
}

void TCommandManager::SaveCommand(TCommand* command)
{
  if (lock == false)
  {
    history.push_back(command);
  }
}
