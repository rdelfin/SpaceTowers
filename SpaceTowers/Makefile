cc=g++
CXXFLAGS =-std=c++0x

all: Game

Game: BaseGame.o Button.o Character.o CharacterInfo.o CharacterList.o ComputerPlayer.o GameLevelState.o GameObject.o GameRectangle.o GameState.o GameTime.o HumanPlayer.o Level.o MainMenuState.o MathHelper.o PauseMenu.o PlanetButton.o PlanetMenuState.o Player.o Projectile.o SpaceMarine.o Sprite.o SuperSpaceMarine.o Tower.o Utility.o Vector2.o
	g++ -std=c++0x Game.cpp BaseGame.o Button.o Character.o CharacterInfo.o CharacterList.o ComputerPlayer.o GameLevelState.o GameObject.o GameRectangle.o GameState.o GameTime.o HumanPlayer.o Level.o MainMenuState.o MathHelper.o PauseMenu.o PlanetButton.o PlanetMenuState.o Player.o Projectile.o SpaceMarine.o Sprite.o SuperSpaceMarine.o Tower.o Utility.o Vector2.o -o SpaceTowers `pkg-config --libs allegro-5.0 allegro_main-5.0 allegro_audio-5 allegro_acodec-5.0 allegro_font-5 allegro_ttf-5 allegro_color-5.0 allegro_image-5 allegro_dialog-5 allegro_primitives-5.0`

clean:
	rm -f *.o
	rm -f SpaceTowers
