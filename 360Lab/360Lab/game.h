// Game class declaration
#pragma once
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 
#include "SFML/OpenGL.hpp" 
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML\Audio.hpp"
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

class Game
{
	// private data members

	sf::RenderWindow window;


public:
	sf::Sprite bgController;
	sf::Texture bgControllerTexture;

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
};