#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <glew.h>
#include <vector>
#include <memory>

using std::vector;

class Game {

public:
	Game();
	virtual ~Game();

	void init(int screenWidth, int screenHeight);
	void load();
	void handleInputs();
	void update(float dt);
	void render();
	void clean();

	bool isRunning;
	int windowWidth, windowHeight;

private:
	GLuint shaderProgram;
	GLuint vao;
};

#endif