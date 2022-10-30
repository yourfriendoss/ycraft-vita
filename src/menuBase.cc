#include "menuBase.hh"
#include "constants.hh"

MenuBase::MenuBase():
	mousePosition{0, 0},
	mousePressed(false)
{
	
}

void MenuBase::HandleEvent(SDL_Event& event) {
	switch (event.type) {
		case SDL_MOUSEMOTION: {
			mousePosition.x = event.motion.x;
			mousePosition.y = event.motion.y;
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				mousePressed = true;
			}
			break;
		}
		case SDL_FINGERMOTION: {
			mousePosition.x = event.tfinger.x * APP_SCREEN_SIZE_W;
			mousePosition.y = event.tfinger.y * APP_SCREEN_SIZE_H;
            break;
        }
        case SDL_FINGERDOWN: {
            mousePressed = true; 
			break;
        }
        case SDL_FINGERUP: {
            mousePressed = false;
			break;
        }
		case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				mousePressed = false;
			}
			break;
		}
	}
}

void MenuBase::Reset() {
	mousePosition = {0, 0};
	mousePressed  = false;
}