#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <vector>
#include "Fonobj.h"
class Game {
private:
	sf::RenderWindow window;
public:
	Game() {
		window.create(sf::VideoMode{ (size_t)WINDOW_WIDTH, (size_t)WINDOW_HEIGHT }, WINDOW_TITLE);
		window.setFramerateLimit(FPS);
	}
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}
	void update() {}
	void checkCollisions() {}
	void draw() {
		window.clear();
		window.display();
	}
	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};