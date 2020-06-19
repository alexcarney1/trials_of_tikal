#include <SFML/Graphics.hpp>
#include "Game.h"
//TODO: watch video end for audio again...
Game game = Game();
sf::Time elapsed_time;
sf::Clock r;
sf::Event event;
int main() {

	while (game.window->isOpen()) {
		while (game.window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				game.window->close();
			}
			if (sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) { game.window->close(); }
			}
		}
	sf::Time delta_time = sf::milliseconds(500);
	elapsed_time += r.restart();
	if (elapsed_time >= delta_time) {
		
		game.Update();
		elapsed_time -= delta_time;
	}
	
	game.Render();
	}







	return 0;
}