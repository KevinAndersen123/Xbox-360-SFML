#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

/// <summary>
/// @author Kevin Andersen
/// @date 1-10-2018
/// </summary>

#include <SFML/Graphics.hpp>
 /// <summary>
 /// Data to store the current state of the controller
 /// </summary>
struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool RightThumbStickkClick;
	bool DpadUp;
	bool DpadDown;
	bool DpadLeft;
	bool DpadRight;
	bool Start;
	bool Back;
	bool Xbox;
	float RTrigger;
	float LTrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};

/// <summary>
/// Xbox controller calss to query current state of controller
/// to mimic the controller status like XNA
/// </summary>

class Xbox360Controller
{
private:
	//deadzone for the dpad(joystick)
	const int dpadThreshold = 50;

public:
	//newly added for multiple controller support not required in your project
	// number of connected controllers
	static int s_noOfControllers;
	//index count for multiple controllers if connected
	int sf_Joystick_index;
	//the current state of all buttons
	GamePadState m_currentState;
	//the previous state to use check for the moment a button is pressed
	GamePadState m_previousState;

	Xbox360Controller();
	~Xbox360Controller();
	void update();
	bool isConnected();
	bool connect();
};
#endif // !XBOX360CONTROLLER