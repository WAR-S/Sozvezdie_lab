#include <iostream>
struct Cell		
{
  int x, y;
};

int main ()
{
  Cell a;
  Cell b;
  while (true)
{
      std::cout << "Enter first coordinates \n";
      std::cin >> a.x >> a.y;
      if ((a.x || a.y) > 8)
	{
	  std::cout << "desk size 8x8 !\n";
	  return 0;
	}
	std::cout << "Enter second coordinates \n";
      std::cin >> b.x >> b.y;
      if ((b.x || b.y) > 8)
	{
	  std::cout << "desk size 8x8 !\n";
	  return 0;
	    
	}

      if ((a.x - a.y == b.x - b.y || a.x + a.y == b.x + b.y)
	  || ((a.x == b.x) || (a.y == b.y)))
	{
	  std::cout << "YES\n";
	}
      else
	{
	  std::cout << "NO\n";
	}
}
      return 0;
    }

