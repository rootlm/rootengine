#include <SDL.h>
#include "input.h"

void InitKeys() {
JumpButton = SDL_SCANCODE_Z;
AttackButton = SDL_SCANCODE_X;
SpecialButton = SDL_SCANCODE_C;
StartButton = SDL_SCANCODE_RETURN;

LeftButton = SDL_SCANCODE_LEFT;
RightButton = SDL_SCANCODE_RIGHT;
UpButton = SDL_SCANCODE_UP;
DownButton = SDL_SCANCODE_DOWN;

JumpButtonState = 0;
AttackButtonState = 0;
SpecialButtonState = 0;
StartButtonState = 0;

LeftButtonState = 0;
RightButtonState = 0;
UpButtonState = 0;
DownButtonState = 0;
}

char keyboard_check(char statetocheck) {
	if (statetocheck > 0 && statetocheck != 3) {
	return 1;
	}
else {
return 0;
}

}

char keyboard_check_pressed(char statetocheck) {
	if (statetocheck == 1) {
	return 1;
	}
else {
return 0;
}

}

char keyboard_check_released(char statetocheck) {
	if (statetocheck == 3) {
	return 1;
	}
else {
return 0;
}

}

void UpdateKeys() {
const Uint8 *keyboard = SDL_GetKeyboardState(NULL);

	//If button state is 3 that means it was released on the previous frame so set it to 0!
	if (JumpButtonState == 3) {
	JumpButtonState = 0;
	}

	//If its being pressed state goes up until 2 (1 = pressed 2 = held)
	if(keyboard[JumpButton] == 1)
	{
		if (JumpButtonState < 2) {
		JumpButtonState +=1;
		}
	}
	//release
	else if (JumpButtonState != 0) {
		JumpButtonState = 3;
		}


	if (AttackButtonState == 3) {
	AttackButtonState = 0;
	}

	if(keyboard[AttackButton] == 1)
	{
		if (AttackButtonState < 2) {
		AttackButtonState +=1;
		}
	}
	else if (AttackButtonState != 0) {
		AttackButtonState = 3;
		}


	if (SpecialButtonState == 3) {
	SpecialButtonState = 0;
	}

	if(keyboard[SpecialButton] == 1)
	{
		if (SpecialButtonState < 2) {
		SpecialButtonState +=1;
		}
	}
	else if (SpecialButtonState != 0) {
		SpecialButtonState = 3;
		}


	if (LeftButtonState == 3) {
	LeftButtonState = 0;
	}

	if(keyboard[LeftButton] == 1)
	{
		if (LeftButtonState < 2) {
		LeftButtonState +=1;
		}
	}
	else if (LeftButtonState != 0) {
		LeftButtonState = 3;
		}


	if (RightButtonState == 3) {
	RightButtonState = 0;
	}

	if(keyboard[RightButton] == 1)
	{
		if (RightButtonState < 2) {
		RightButtonState +=1;
		}
	}
	else if (RightButtonState != 0) {
		RightButtonState = 3;
		}


	if (UpButtonState == 3) {
	UpButtonState = 0;
	}

	if(keyboard[UpButton] == 1)
	{
		if (UpButtonState < 2) {
		UpButtonState +=1;
		}
	}
	else if (UpButtonState != 0) {
		UpButtonState = 3;
		}


	if (DownButtonState == 3) {
	DownButtonState = 0;
	}

	if(keyboard[DownButton] == 1)
	{
		if (DownButtonState < 2) {
		DownButtonState +=1;
		}
	}
	else if (DownButtonState != 0) {
		DownButtonState = 3;
		}

}