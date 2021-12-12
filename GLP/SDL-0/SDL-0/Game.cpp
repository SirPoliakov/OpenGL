#include "Game.h"

Game::Game() : isRunning(false), windowWidth(0), windowHeight(0){}

Game::~Game(){}

void Game::init(int screenWidth, int screenHeight) {
	windowWidth = screenWidth;
	windowHeight = screenHeight;
	isRunning = true;
}

void Game::load() {
	GLfloat points[] = { 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f };

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	const char* vertexShader =
		"#version 460\n"
		"out vec4 color;"
		"void main () {"
		" color = vec4 (0.8, 0.5, 0.0, 1.0);"
		"}";

	GLuint vs = GLCreat
}

void Game::handleInputs() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				isRunning = false;
			}
			break;

		default: 
			break;
		}
	}
}

void Game::update(float dt) {

}

void Game::render() {

}

void Game::clean() {

}