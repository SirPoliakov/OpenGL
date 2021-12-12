#include "Window.h"
//#include "GIDebug.hpp"
#include <iostream>

using std::cout;
using std::endl;

Window::Window(const std::string &title) : context(nullptr), title(title), previousSeconds(0), currentSeconds(0), frameCount(0) {}

Window::~Window() {
	SDL_Quit();
}

bool Window::init(int xPos, int yPos, int width, int height, bool isFullscreen) {
	int flags = SDL_WINDOW_OPENGL;

	if (isFullscreen) {
		flags = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL INIT FAILED" << endl;
		return false;
	}

	//SDL Window
	window = SDL_CreateWindow(title.c_str(),xPos, yPos, width, height, flags);
	if (window) {
		cout << "WINDOW_SDL INITIALIAZED" << endl;
	}
	else { cout << "WINDOW SDL INIT FAILED" << endl ; return false; }

	//OpenGL Context

	context = SDL_GL_CreateContext(window);
	if (context) {
		cout << "OPENGL CONTEXT INITIALIAZED" << endl;
	}
	else {
		cout << "OPENGL CONTEXT INIT FAILED" << endl; return false;
	}

	//OpenGL Setup
	glewExperimental = GL_TRUE;
	GLenum InitGLEW(glewInit());
	if (InitGLEW == GLEW_OK) {
		cout << "GLEW INITIALIZED" << endl;
	}
	else {
		cout << "GLEW INIT FAILED" << endl; return false;
	}

	//Size of the viewport
	glViewport(0, 0, width, height);

	//Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//window color
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f);

	return true;
}

void Window::clearBuffer() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffer() {
	SDL_GL_SwapWindow(window);
}

void Window::updateFPSCounter(float dt) {
	double elapsedSeconds;

	currentSeconds += dt;
	elapsedSeconds = currentSeconds - previousSeconds;

	if (elapsedSeconds > 0.25) {
		previousSeconds = currentSeconds;
		char tmp[128];
		double fps = (double)frameCount / elapsedSeconds;
		sprintf_s(tmp, "%s @ fps: %.2f", title.c_str(), fps);
		SDL_SetWindowTitle(window, tmp);
		frameCount = 0;
	}
	frameCount++;
}

void Window::clean() {
	SDL_DestroyWindow(window);
	SDL_GL_DeleteContext(context);
}