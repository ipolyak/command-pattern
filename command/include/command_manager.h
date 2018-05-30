#ifndef COMMAND_MANAGER_H_
#define COMMAND_MANAGER_H_

#include <vector>

#include "command.h"
#include "prototype.h"

class TCommandManager
{
public:
  static TCommandManager* GetInstance();

  void Undo();

  void SaveCommand(TCommand* command);
private:
  static TCommandManager* cm;

  std::vector<TCommand*> history;

  bool lock;

  TCommandManager();
};

#endif  // COMMAND_MANAGER_H_
