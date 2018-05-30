#include <iostream>

#include "command_manager.h"
#include "command.h"
#include "init_command.h"
#include "add_value_command.h"
#include "set_value_command.h"

void PrintVector(const std::vector<int>& vec)
{
  for (int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

int main(int argc, char* argv)
{
  // Init command must be performed firstly
  std::vector<int> clientBuffer;
  TCommand* initCommand = new TInitCommand(clientBuffer);
  initCommand->Execute();

  // Add elements to clientBuffer
  for (int i = 0; i < 10; ++i)
  {
    TCommand* addValueCommand = new TAddValueCommand(clientBuffer, i);
    addValueCommand->Execute();
  }
  std::cout << "Added 0..9 values. Result: " << std::endl;
  PrintVector(clientBuffer);

  // Set value 100 in pos=4 in clientBuffer
  TCommand* setValueCommand = new TSetValueCommand(clientBuffer, 4, 100);
  setValueCommand->Execute();
  std::cout << "Set value 100 in pos=4. Result: " << std::endl;
  PrintVector(clientBuffer);

  // Undo set value
  std::cout << "Undo setting of value 100. Result: " << std::endl;
  TCommandManager::GetInstance()->Undo();
  PrintVector(clientBuffer);

  // Undo adding of 0..9 elements
  std::cout << "Undo adding of 0..9 elements. Result: " << std::endl;
  for (int i = 0; i < 10; ++i)
  {
    TCommandManager::GetInstance()->Undo();
    PrintVector(clientBuffer);
  }

  // Add elements 10 .. 19 to clientBuffer
  for (int i = 10; i < 20; ++i)
  {
    TCommand* addValueCommand = new TAddValueCommand(clientBuffer, i);
    addValueCommand->Execute();
  }
  std::cout << "Added 10..19 values. Result: " << std::endl;
  PrintVector(clientBuffer);

  system("pause");
  return 0;
}
