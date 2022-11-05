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
			#if defined(PLATFORM_VITA)
				if(event.tfinger.touchId != 0) return;
			#endif
			mousePosition.x = event.tfinger.x * APP_SCREEN_SIZE_W;
			mousePosition.y = event.tfinger.y * APP_SCREEN_SIZE_H;
            break;
        }
        case SDL_FINGERDOWN: {
			#if defined(PLATFORM_VITA)
				if(event.tfinger.touchId != 0) return;
			#endif
            mousePressed = true; 
			break;
        }
        case SDL_FINGERUP: {
			#if defined(PLATFORM_VITA)
				if(event.tfinger.touchId != 0) return;
			#endif
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