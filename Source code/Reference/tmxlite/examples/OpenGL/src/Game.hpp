//Matt Marchant 2016
http://trederia.blogspot.com


#ifndef OGL_GAME_HPP_
#define OGL_GAME_HPP_

#include <SDL2/SDL.h>
#include <glm/matrix.hpp>

#include <MapLayer.hpp>

#include <memory>
#include <vector>

class Game final
{
public:
	Game();
	~Game();
	
	void run(SDL_Window*);
	
private:

	void doEvents();
	void update(float);
	void draw(SDL_Window*);
	
	std::vector<std::unique_ptr<MapLayer>> m_mapLayers;
	void loadMap();
	
	glm::mat4 m_projectionMatrix;
	
	unsigned m_shader;
	std::vector<unsigned> m_tileTextures;
	void initGLStuff(const tmx::Map&);
	void loadShader();
	void loadTexture(const std::string&);

};

#endif //OGL_GAME_HPP_
