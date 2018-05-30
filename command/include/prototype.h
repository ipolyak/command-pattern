#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

class TCommand;

class TCommandPrototype
{
public:
  virtual ~TCommandPrototype() = 0;

  virtual TCommand* Clone() = 0;
};

#endif  // PROTOTYPE_H_
