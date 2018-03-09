//
// Map.cpp for bomberman in /home/marchi_n/rendu/cpp_bomberman
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Thu Jun  5 16:34:31 2014 Nans Marchis-Mouren
// Last update Sat Jun 14 17:03:18 2014 Nans Marchis-Mouren
//

#include "Map.hh"

Map::Map(const std::string &filepath)
{
  _filepath = filepath;
  getFile();
}

Map::~Map()
{
}

const std::vector< std::vector<std::string> >&	Map::getMap() const
{
  return (_maps);
}

const std::vector<std::string>&			Map::getRmap() const
{
  return (_rmap);
}

void						Map::getFile()
{
  std::string					map;
  std::string					line;
  std::ifstream					file;
  unsigned char					i = '1';

  while (i <= NB_MAP)
    {
      _filepath += i;
      file.open(_filepath.c_str());
      if (file)
	while (getline(file, line))
	  map += line + "\n";
      else
	std::cout << "FAIL !!!!!!" << std::endl;
      fillMap(map);
	map.clear();
      file.close();
      i += 1;
      _filepath = _filepath.substr(0, _filepath.length()-1);
    }
}

void						Map::fillMap(const std::string &map)
{
  std::vector<std::string>			vec;
  std::string					tmp;
  unsigned int					i = 0;

  while (map[i])
    {
      tmp += map[i++];
      if (map[i] == '\n')
	{
	  vec.push_back(tmp);
	  tmp.clear();
	  i += 1;
	}
    }
  _maps.push_back(vec);
}

void						Map::generateRmap()
{
  Random					rd;
  int						size_x;
  int						size_y;
  int						i = 1;
  int						j = 1;
  std::string					ref = "       BBBWW";

  _rmap.clear();
  size_x = 2 + (rd.randomNb() % (98 - 4 + 1));
  size_y = 2 + (rd.randomNb() % (98 - 4 + 1));
  std::cout << "X ==> " << size_x << "  Y ==> " << size_y << std::endl;
  i = size_y;
  while (i != -2)
    {
      fillX(size_x);
      i -= 1;
    }
  i = 1;
  while (j <= size_y)
    {
      if (i == size_x)
	{
	  i = 1;
	  j += 1;
	}
      _rmap[j][i++] = ref[rd.randomNb() % 12];
    }
  _rmap[1][1] = ' ';
  _rmap[size_y][size_x] = ' ';
  _rmap[_rmap.size() - 1][1] = 'W';
  displayVector(_rmap);
}

void						Map::fillX(int x)
{
  std::string					tmp;

  tmp.assign(x + 2, 'W');
  _rmap.push_back(tmp);
}

void						Map::displayVector(std::vector<std::string> vec)
{
  for (unsigned int i = 0; i < vec.size(); i += 1)
    std::cout << vec[i] << std::endl;
}
