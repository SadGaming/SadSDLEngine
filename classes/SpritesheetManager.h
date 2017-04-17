#ifndef SPRITESHEET_H
#define SPRITESHEET_H
class SpritesheetManager 
{
public:
	static SpritesheetManager* getInstance();
private:
	static SpritesheetManager* gInstance;
	SpritesheetManager();
	~SpritesheetManager();
};
#endif 