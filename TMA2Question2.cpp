//Regan Setter
//Student ID 3505894
//Computer Science 206
//February 10th, 2021

//Write a program in which you create a Hen class. Inside this class, nest a Nest class. Inside Nest, place an Egg class. Each class should have a display() member function. For each class, create a constructor and a destructor that prints an appropriate message when it is called. In main(), create an instance of each class using new and call the display() function for each one. After calling display(), free the storage using delete.

//Test: Objects created statically called the constructor in the order hen, nest and egg and called the destructor in the order egg, nest and hen. 
//Where's Objects created dynammically called the constructor in the order hen, nest and egg and called the destructor in the order hen, nest and egg.
//As statically created objects are destructed when the program ends and the object created dynammically destructed when they are deleted using delete.

#include <iostream>
#include <fstream>

using namespace std;

class Hen
{
  std::string namehen;
public:
  class Nest
  {
    std::string namenest;
  public:
    class Egg
    {
      std::string nameegg;
    public:
      void displayegg ();
        Egg (std::string nameegg);
       ~Egg ();
    };

    void displaynest ();
    Nest (std::string namenest);
    ~Nest ();
  };

  void displayhen ();
  Hen (std::string namehen);
  ~Hen ();
};

void Hen::Nest::Egg::displayegg ()
{
  std::cout << nameegg << '\n';
}

Hen::Nest::Egg::Egg (std::string in): nameegg (std::move (in))
{
  std::cout << "constructor called : egg\n";
}

Hen::Nest::Egg::~Egg ()
{
  std::cout << "Destructor called /Egg destroyed\n";
}

void Hen::Nest::displaynest ()
{
  std::cout << namenest << '\n';
}

Hen::Nest::Nest (std::string in):namenest (std::move (in))
{
  std::cout << "constructor called : nest\n";
}

void Hen::displayhen ()
{
  std::cout << namehen << '\n';
}

Hen::Hen (std::string in):namehen (std::move (in))
{
  std::cout << "constructor called : hen\n";
}

Hen::~Hen ()
{
  std::cout << "destructor called / Hen destroyed\n";
}

Hen::Nest::~Nest ()
{
  std::cout << "destructor called /Nest destroyed\n";
}


int main()
{
  {
    Hen
      hen
    {
    "Big Bird"};
    Hen::Nest nest
    {
    "Nest"};
    Hen::Nest::Egg egg
    {
    "Eggbert"};
    hen.displayhen ();
    nest.displaynest ();
    egg.displayegg ();
  }
  std::cout << "\n--------------------\n\n";
  {
    Hen *
    hen = new Hen { "Big Bird" };
    Hen::Nest * nest = new Hen::Nest
    {
    "Nest"};
    Hen::Nest::Egg * egg = new Hen::Nest::Egg
    {
    "Eggbert"};
    hen->displayhen ();
    nest->displaynest ();
    egg->displayegg ();
    delete
      hen;
    delete
      nest;
    delete
      egg;
  }
}
