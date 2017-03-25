#ifndef TEXTURE_H
#define TEXTURE_H
#include "../SDLInclude.h"
#include "WindowManager.h"
#include <map>
#include <string>
struct gameReady {
	SDL_Texture* texture;
	int width;
	int height;
};
class TextureManager
{
public:
	static TextureManager* getInstance();
	void addTexture(std::string name, SDL_Texture* mTexture);
	void addTexture(std::string name, std::string filename);
	gameReady getTexture(std::string name);
	std::map<std::string, gameReady> textures;
private:
	static TextureManager* gInstance;
	TextureManager();
	~TextureManager();

	SDL_Renderer* gRenderer;
};
#endif
