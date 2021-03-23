//@author Kevin Andersen
//@date 1-10-2018
//SFML game to display the current state of the 360 controller.
#include "Game.h"   // include Game header file
int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(800), static_cast<int>(600)), "Xbox360Controller", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// load the font file & setup the message
{
	/*if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}*/	

	if (!bgControllerTexture.loadFromFile("ASSETS/IMAGES/Controller.jpg"))
	{
		std::cout << "Error, cannot load photo" << std::endl;
	}

	bgController.setTexture(bgControllerTexture);
	bgController.setPosition(0, 0);

}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{

}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();
	window.draw(bgController);
	window.display();


}