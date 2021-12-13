#include <iostream>
#include <SDL.h>
#include <glew.h>
#include <fstream>
#include<string>

#include "Game.h"
#include "Timer.h"
#include "Window.h"


using namespace std;


//Describe the shape by its vertices

int main(int argc, char* argv[])
{
	// Exercice fichier shader separes //

	/*
	string const nomFichier1 = "vert.txt";

	string const nomFichier2 = "frag.txt";

	string ligne;
	string vertShaderSrc, fragShaderSrc;

	ifstream mFlux1;
	mFlux1.open(nomFichier1);
	if (!mFlux1.fail()) {
		while (getline(mFlux1, ligne))
		{
			vertShaderSrc += ligne + "\n";
		}
	mFlux1.close();
	}
	else { cout << "impossible d'ouvrir " << nomFichier1 << " en lecture!" << endl; }
		
	ifstream mFlux2;
	mFlux2.open(nomFichier2);

	if (!mFlux2.fail()) {
		while (getline(mFlux2, ligne))
		{
			fragShaderSrc += ligne + "\n";
		}
		mFlux2.close();
	}else{ cout << "impossible d'ouvrir " << nomFichier2 << " en lecture!" << endl; }

	*/

		////////////INITIALIZE SDL2 (Simple Direct Media Layer v2.)///////////////
	/*
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
			return -1;
		}
	
		cout << "SDL initialization succeeded!";

		///////////SETTING UP SDL/////////////
		//Create a simple window
		int width = 700;
		int height = 700;
		unsigned int center = SDL_WINDOWPOS_CENTERED;
		SDL_Window* Window = SDL_CreateWindow("My window", center, center, width, height, SDL_WINDOW_OPENGL);
		//SDL_WINDOW_OPENGL is a u32 flag !


		//Create an OpenGL compatible context to let glew draw on it
		SDL_GLContext Context = SDL_GL_CreateContext(Window);

		/////////SETTING UP OPENGL WITH GLEW (OpenGL Extension Wrapper)///////////
		//Initialize glew
		glewExperimental = GL_TRUE;
		if (glewInit() == GLEW_OK) {
			cout << "Glew initialized successfully\n";

		}

		// Tell GL to only draw onto a pixel if the shape is closer to the viewer
		glEnable(GL_DEPTH_TEST);  // enable depth-testing
		glDepthFunc(GL_LESS);     // depth-testing interprets a smaller value as "closer"

		//Set the viewing frame through which we will see the objects
		glViewport(0, 0, width, height);
		
		//Put the color you want here for the background
		glClearColor(0.0f, 0.0f, 0.2f, 1.0f);

		//Describe the shape by its vertices

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		//Create an ID to be given at object generation
		unsigned int vbo;


		//Pass how many buffers should be created and the reference of the ID to get the value set
		glGenBuffers(1, &vbo);

		const char* vertexShaderSource = vertShaderSrc.c_str();

		const char* fragmentShaderSource = fragShaderSrc.c_str();


		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);


		//now that we have a vertex shader, let’s put the code text inside
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);


		//aaaaand… Compile !
		glCompileShader(vertexShader);


		//Do the same with the fragment shader !
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();



		//now attach shaders to use to the program
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);

		//and link it 
		glLinkProgram(shaderProgram);

		//now that the program is complete, we can use it 
		glUseProgram(shaderProgram);


		//Create one ID to be given at object generation
		unsigned int vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		//Binds the buffer linked to this ID to the vertex array buffer to be rendered. Put 0 instead of vbo to reset the value.
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		//Finally send the vertices array in the array buffer 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		//Enable my vertex attrib array number 0 (we only have one attribute of position)
		glEnableVertexAttribArray(0);

		

		bool isRunning = true;
		while (isRunning) {
			// Inputs
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					isRunning = false;
					break;
				default:
					break;
				}
			}
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen

			//Shader to use next
			glUseProgram(shaderProgram);

			//VAO to use next
			glBindVertexArray(vao);

			//OMG WE FINALLY DRAW ! We use the GL_TRIANGLES primitive type
			//We draw from vertex 0 and we will be drawing 3 vertices
			glDrawArrays(GL_TRIANGLES, 0, 3);

			SDL_GL_SwapWindow(Window); // Swapbuffer
		}
		
		
		// Quit
		SDL_DestroyWindow(Window);
		SDL_GL_DeleteContext(Context);
		*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 640;

	//Init window
	Window window = Window("Hello SDL");
	if (!window.init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false)) {
		return 1;
	}


	//init game
	Timer timer;
	Game game;

	game.init(SCREEN_WIDTH, SCREEN_HEIGHT);
	game.load();

	//delta time in seconds
	float dt;

	//Game loop
	while (game.isRunning) {
		dt = static_cast<float>(timer.computeDeltaTime()) / 1000.0f;
		window.updateFPSCounter(dt);

		game.handleInputs();
		game.update(dt);

		window.clearBuffer();
		game.render();
		window.swapBuffer();

		//Delay frame if game runs too fast
		timer.delayTime();
	}

	//Exit the game
	game.clean();
	window.clean();
	
	return 0;
}