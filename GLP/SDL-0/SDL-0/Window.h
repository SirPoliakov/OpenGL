#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <glew.h>

#include <string>

class Window {

public:
	Window(const std::string &title);
	~Window();

	bool init(int xPos, int yPos, int width, int height, bool isFullscreen);
	void clearBuffer();
	void swapBuffer();
	void updateFPSCounter(float dt);
	void clean();

private:
	SDL_Window *window;
	SDL_GLContext context;
	const std::string &title;

	double previousSeconds;
	double currentSeconds;
	int frameCount;

	//delete
	Window() = delete;
	//Window(const Window &) = delete;
	Window &operator=(const Window &) = delete;

};

#endif