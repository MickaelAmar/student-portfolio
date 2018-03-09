//
// Resource.hh for ResourceManager.hh in /home/marchi_n/bomber
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Wed May 28 14:46:17 2014 Nans Marchis-Mouren
// Last update Sat Jun 14 16:44:44 2014 Nans Marchis-Mouren
//

#ifndef RESOURCE_MANAGER_HH_
# define RESOURCE_MANAGER_HH_

# include "Mutex.hh"
# include "Map.hh"

class			ResourceManager
{
public:

  ResourceManager();
  ~ResourceManager();

  void		displayMap();
  void		displayVector(std::vector<std::string>);
  const std::vector< std::vector<std::string> >&	getMap() const;
  const std::vector<std::string>&			getRmap() const;
  void		generateRmap();

private:

  IMutex		*_mapMutex;
  Map			*_maps;
 };

#endif /* RESOURCE_MANAGER_HH_ */
