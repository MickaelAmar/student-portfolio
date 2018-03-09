//
// main.cpp for main in /home/marchi_n/rendu/cpp_bomberman
// 
// Made by Nans Marchis-Mouren
// Login   <marchi_n@epitech.net>
// 
// Started on  Mon Jun  2 15:01:35 2014 Nans Marchis-Mouren
// Last update Fri Jun 13 15:49:09 2014 Jausselme
//

#include <iostream>
#include "DynEngine.hh"
#include "Mutex.hh"
#include "Thread.hh"
#include "Core.hh"
#include "Map.hh"

int	main()
{
  std::cout << "11111111" << std::endl;
  DynEngine		eng;
  eng.initialize();
  std::cout << "222222222" << std::endl;
  ResourceManager	res;
  std::cout << "3333333333" << std::endl;
  SceneManager		sce;
  std::cout << "444444444" << std::endl;
  std::cout << "55555555555" << std::endl;
  Core			game(&eng, &res, &sce);

  std::cout << "66666666666" << std::endl;
  game.initialize();
  std::cout << "START" << std::endl;
  game.start();
  std::cout << "STOP" << std::endl;
  //res->displayMap();
  return (0);
}
