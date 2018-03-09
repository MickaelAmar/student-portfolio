//
// Map.hh for bomberman in /home/marchi_n/rendu/cpp_bomberman
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Thu Jun  5 16:29:50 2014 Nans Marchis-Mouren
// Last update Sat Jun 14 17:19:35 2014 Jausselme
//

#ifndef MAP_HH_
# define MAP_HH_

# include <string>
# include <vector>
# include <iostream>
# include <fstream>
# include "Random.hh"

# define NB_MAP	'6'

class							Map
{
public:
  Map(const std::string&);
  ~Map();

  const std::vector< std::vector<std::string> >&	getMap() const;
  const	std::vector<std::string>&			getRmap() const;
  void							generateRmap();

private:
  std::vector< std::vector<std::string> >		_maps;
  std::string						_filepath;
  std::vector<std::string>				_rmap;

  void							getFile();
  void							fillMap(const std::string&);
  void							fillX(int);
  void							generateMap();
  void							displayVector(std::vector<std::string>);
};

#endif /* MAP_HH_ */
