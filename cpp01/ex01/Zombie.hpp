#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <ostream>
#include <iostream>

class Zombie
{
  public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
	void baptize(std::string name);

  private:
	std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif