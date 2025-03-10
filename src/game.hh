#ifndef YCRAFT_GAME_HH
#define YCRAFT_GAME_HH

#include "_components.hh"
#include "blockdefs.hh"
#include "types.hh"
#include "level.hh"
#include "player.hh"
#include "pauseMenu.hh"
#include "ui.hh"
#include "chat.hh"
#include "particles.hh"
#include "inventoryScreen.hh"

class App;
enum class AppState;

enum class GameState {
	Running = 0,
	Paused,
	InChat,
	Inventory
};

class Game {
	public:
		// variables
		Blockdefs              blockdefs;
		FVec2                  camera; // unit: blocks
		Level                  level;
		Player                 player; // unit: blocks
		Vec2                   mousePosition;
		WVec2                  highlightedBlock;
		bool                   blockHighlighted;
		GameState              gameState;
		std::vector <ChatItem> chat;
		UI::Textbox            chatbox;
		size_t                 chatScroll;
		bool                   mouseDown;
		App*                   app;
		CommandsSystem         commands;
		Particles::Manager     particles;
		int 				   heldDownFor;

		Menus::PauseMenu       pauseMenu;
		InventoryScreen        inventoryScreen;
		
		SDL_GameController *   gameController;
		int  		 		   xMovement = 0;
		int  		 		   yMovement = 0;
		int 				   xJoyMouse = 0;
		int 				   yJoyMouse = 0;
		
		// functions
		Game();
		void Init(UVec2 levelSize, bool generate);
		void SpawnPlayer();
		void Deinit();
		void Update(AppState& state);
		void HandleEvent(SDL_Event& event);
		void UpdateCamera();
		void HandleInput(const Uint8* keystate, double delta);
		void Render();
		void GetHighlightedBlock();
		void PlaceBlock();
		void DeleteBlock();
		void AddToChat(std::string message);
};

#endif
