//
// GraphicFactory.hh for nibbler in /home/marchi_n/rendu/cpp_nibbler/src
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Sun Apr  6 19:09:43 2014 Nans Marchis-Mouren
// Last update Sun Apr  6 20:09:19 2014 Nans Marchis-Mouren
//

#ifndef GRAPHICFACTORY_HH_
# define GRAPHICFACTORY_HH_

# include "../lib/IGraphic.hh"

class	GraphicFactory
{
public:
  GraphicFactory(const char *path);
  ~GraphicFactory();
  
  IGraphic	*getLib() const;
private:
  
  IGraphic	*_lib;

};

#endif /* GRAPHICFACTORY_HH_ */
