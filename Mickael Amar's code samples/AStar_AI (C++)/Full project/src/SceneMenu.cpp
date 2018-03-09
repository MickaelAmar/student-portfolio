//
// SceneMenu.cpp for SceneMenu in /home/rose_r/cpp_bomberman/src
// 
// Made by ROSE
// Login   <rose_r@epitech.net>
// 
// Started on  Fri Jun 13 15:24:57 2014 ROSE
// Last update Sun Jun 15 18:01:54 2014 ROSE
//

#include "SceneMenu.hh"

SceneMenu::SceneMenu(DynEngine *engine, ResourceManager *resM)
{
  _engine = engine;
  _resM = resM;
  _selection = 0;
  _nextScene = NULL;
}

SceneMenu::~SceneMenu()
{
}

bool		SceneMenu::initialize()
{
  glm::mat4                   projection;

  if (!_shader.load("./lib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./lib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
  _shader.bind();
  _shader.setUniform("view", glm::mat4(1));
  _shader.setUniform("projection", projection);
  drawMenu();
  return true;
}

bool		SceneMenu::tick()
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return false;
      break;
    case SDL_KEYUP:
      {
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  return false;
	if (_selection < 3 && event.key.keysym.sym == SDLK_DOWN)
	  {
	    _ents[1]->translate(glm::vec3(0, 100, 0)); 
	    _ents[2]->translate(glm::vec3(0, 100, 0));
	    _selection++;	    
	    std::cout << "KeyDown" << _selection << std::endl;
	  }
	if (_selection > 0 && event.key.keysym.sym == SDLK_UP)
	  {
	    _ents[1]->translate(glm::vec3(0, -100, 0)); 
	    _ents[2]->translate(glm::vec3(0, -100, 0));
	    _selection--;
	    std::cout << "KeyUp" << _selection << std::endl;
	  }
	if (_selection == 3 && event.key.keysym.sym == SDLK_RETURN)
	  return false;
	if (_selection == 0 && event.key.keysym.sym == SDLK_RETURN)
	  playScene();
      }
      break;
    }
  _engine->updateClock();
  _engine->updateInputs();
  for (size_t i = 0; i < _ents.size(); ++i)
    _ents[i]->update(_engine, _resM);
  return true;
}

void		SceneMenu::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _ents.size(); ++i)
    _ents[i]->draw(_engine, _shader);
  _engine->flush();
}

bool		SceneMenu::drawMenu()
{
  AEntity	*background = new Button(20, 0, 0, 150, 200);
  AEntity	*leftArrow = new Button(148, 216, 1, 33, 38);
  AEntity	*rightArrow = new Button(620, 216, 2, 33, 38);
  AEntity	*play = new Button(200, 200, 3, 400, 60);
  AEntity	*settings = new Button(200, 300, 4, 400, 60);
  AEntity	*credits = new Button(200, 400, 5, 400, 60);
  AEntity	*exit = new Button(200, 500, 6, 400, 60);
  AEntity	*splash = new Button(180, 30, 7, 600, 109);
  AEntity	*bomber = new Button(0, 0, 8, 800, 600);

  if (!background->initialize() || !play->initialize() || !exit->initialize() || !credits->initialize() ||
      !leftArrow->initialize() || !rightArrow->initialize() || !settings->initialize() || !splash->initialize() ||      !bomber->initialize())
    {
      std::cout << "Fail initialization" << std::endl;
      return false;
    }
  _ents.push_back(background);
  _ents.push_back(leftArrow);
  _ents.push_back(rightArrow);
  _ents.push_back(play);
  _ents.push_back(settings);
  _ents.push_back(exit);
  _ents.push_back(credits);
  _ents.push_back(splash);
  _ents.push_back(bomber);
  return true;
}

IScene		*SceneMenu::getScene() const
{
  return _nextScene;
}

void		SceneMenu::playScene()
{
  _nextScene = new SceneMap(_engine, _resM);
}
