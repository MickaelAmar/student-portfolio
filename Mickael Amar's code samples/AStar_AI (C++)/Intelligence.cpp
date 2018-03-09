//
// Intelligence.cpp for Intelligence in /home/mika/AStar_AI
//
// Made by mickael amar
// Login   <amar_e@epitech.net>
// 
// Started on  Sun Jun 15 19:02:37 2014 mickael amar
// Last update Sun Jun 15 22:47:07 2014 mickael amar
//

#include "Intelligence.hh"

Intelligence::Intelligence()
{
  /*
   * W : WALL
   * P : PLAYER
   * B : BOX
   * E : END (SUPPOSELY ENEMY)
   */

  _map.push_back("WWWWWWWWWWWWWWWWWWW");
  _map.push_back("WPW.W.....WBBBBB..W");
  _map.push_back("W...W.W.W.W.W.W.WBW");
  _map.push_back("W.........W..B..BBW");
  _map.push_back("W.W.W.WWW.W.WWWBW.W");
  _map.push_back("W.........WB..BBB.W");
  _map.push_back("WBWWW.W.W.WBWBWWW.W");
  _map.push_back("W......W...B.B...BW");
  _map.push_back("W.WBWWW.W.WWW.WBW.W");
  _map.push_back("W.......W..B...B..W");
  _map.push_back("WWWBWWW.W.W.WBWWW.W");
  _map.push_back("W.....BBB........EW");
  _map.push_back("WWWWWWWWWWWWWWWWWWW");

  _end.x = 17;
  _end.y = 11;

  _start.parent.first  = 1;
  _start.parent.second = 1;
}

Intelligence::~Intelligence()
{
}

void			Intelligence::displayMap()
{
  for (unsigned int i = 0; i < _map.size(); i += 1)
    std::cout << _map[i] << std::endl;
}

int			    Intelligence::getDistance(int x1, int y1, int x2, int y2)
{
  return ((x1 - x2) * (x1 - x2) + ( y1 - y2) * (y1 - y2));
}

bool			Intelligence::inList(std::pair<int,int> n, l_node &l)
{
  l_node::iterator	it = l.find(n);

  if (it == l.end())
    return (false);
  return (true);
}

void			Intelligence::checkAdjacents(std::pair <int,int> &n)
{
  t_node		tmp;

  for (unsigned int i = n.first - 1; i <= n.first + 1; i += 1)
    {
      if ((i < 0) || (i >= _map[0].size()))
        continue;
      for (unsigned int j = n.second - 1; j <= n.second + 1; j += 1)
        {
          if ((j < 0) || (j > _map[0].size()) || ((i == n.first) && (j == n.second)) ||
              (_map[j][i] == 'W' || _map[j][i] == 'B') ||
              ((i == n.first - 1) && (j == n.second - 1)) ||
              ((i == n.first - 1) && (j == n.second + 1)) ||
              ((i == n.first + 1) && (j == n.second + 1)) ||
              ((i == n.first + 1) && (j == n.second - 1)))
            continue;
	  std::pair<int,int> it(i,j);
          if (!inList(it, _closeList))
            {
              tmp._g = _closeList[n]._g + getDistance(i,j,n.first,n.second);
              tmp._h = getDistance(i,j,_end.x,_end.y);
              tmp._g = tmp._g + tmp._h;
              tmp.parent = n;
              if (inList(it, _openList))
                {
                  if (tmp._g < _openList[it]._g)
                    _openList[it]=tmp;
                }
              else
		_openList[std::pair<int,int>(i,j)]=tmp;
            }
        }
    }
}

std::pair<int, int>	Intelligence::getNode(l_node &l)
{
  float			        bf = l.begin()->second._g;
  std::pair<int,int>	bn = l.begin()->first;

  for (l_node::iterator i = l.begin(); i != l.end(); i++)
    {
      if (i->second._g < bf)
        {
          bf = i->second._g;
          bn = i->first;
        }
    }
  return (bn);
}

void			Intelligence::addInList(std::pair<int,int> &p)
{
  t_node		&n = _openList[p];

  _closeList[p] = n;
  if (_openList.erase(p) == 0)
    std::cerr << "Unfindable in list" << std::endl;
}

void			Intelligence::findPath()
{
  t_node		&tmp = _closeList[std::pair<int, int>(_end.x,_end.y)];
  t_point		p;
  std::pair<int,int>	prev;

  p.x = _end.x;
  p.y = _end.y;

  prev.first  = tmp.parent.first;
  prev.second = tmp.parent.second;
  _path.push_front(p);
  while (prev != std::pair<int,int>(_start.parent.first, _start.parent.first))
    {
      p.x = prev.first;
      p.y = prev.second;
      _path.push_front(p);
      tmp = _closeList[tmp.parent];
      prev.first  = tmp.parent.first;
      prev.second = tmp.parent.second;
    }
}

void			Intelligence::fillList()
{
  std::pair <int,int> current;

  current.first  = _start.parent.first;
  current.second = _start.parent.second;

  _openList[current] = _start;
  addInList(current);
  checkAdjacents(current);

  while (!((current.first == _end.x) && (current.second == _end.y))
         && (!_openList.empty()))
    {
      current = getNode(_openList);
      addInList(current);
      checkAdjacents(current);
    }
  if ((current.first == _end.x) && (current.second == _end.y))
    findPath();
  else
    std::cerr << "No path found" << std::endl;

  for (std::list<t_point>::iterator it = _path.begin(); it != _path.end(); it++)
    {
      system("clear");
      displayMap();
      _map[it->y][it->x] = 'Z';
      sleep(1);
    }
}
