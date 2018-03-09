//
// IGraphic.hh for nibbler in /home/marchi_n/rendu/cpp_nibbler/lib
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Sun Apr  6 17:43:57 2014 Nans Marchis-Mouren
// Last update Sun Apr  6 22:48:04 2014 Jausselme
//

#ifndef IGRAPHIC_HH_
# define IGRAPHIC_HH_

# include <vector>
# include "../src/Food.hh"
# include "../src/nibbler.h"

class	IGraphic
{
public:
  virtual ~IGraphic() {};
  
  virtual void		windowInit(int, int) = 0;
  virtual eEvent	getEvent() const = 0;
  virtual void		refresh(std::vector<t_snake>, int, int) = 0;
};

#endif /* IGRAPHIC_HH_ */
