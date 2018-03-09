//
// Intelligence.hh for Intelligence in /home/mika/AStar_AI
// 
// Made by mickael amar
// Login   <amar_e@epitech.net>
// 
// Started on  Fri Jun 13 18:15:32 2014 mickael amar
// Last update Sun Jun 15 19:41:31 2014 mickael amar
//

#ifndef INTELLIGENCE_HH_
# define INTELLIGENCE_HH_

# include <utility>
# include <map>
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <list>

typedef	struct	s_node
{
  int		_g;
  int		_h;
  int		_f;
  std::pair<int,int> parent;
}		t_node;

typedef struct	s_point
{
  int		x;
  int		y;
}		t_point;

typedef std::map< std::pair<int,int>, t_node> l_node;

class			Intelligence
{
private:
  l_node		_openList;
  l_node		_closeList;
  std::list<t_point>	_path;

  t_node		_start;
  t_point		_end;
  std::vector<std::string>	_map;

public:
  Intelligence();
  ~Intelligence();

  int			getDistance(int, int, int, int);
  void			checkAdjacents(std::pair<int,int>&);
  bool			inList(std::pair<int,int>, l_node&);
  std::pair<int,int>	getNode(l_node&);
  void			addInList(std::pair<int, int>&);
  void			findPath();
  void			displayMap();
  void			fillList();
};

#endif /* !INTELLIGENCE_HH_ */
