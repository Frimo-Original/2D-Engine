#pragma once

#include <SFML/Graphics.hpp>
#include <thread>

#include "GameScene.h"

namespace Engine
{
	class Window
	{
	private:
		sf::RenderWindow* window;
		GameScene* scene = NULL;
		std::thread th;

		const int SYSTEM_DELAY = 15;

		bool visible;
		bool isClose;

	public:
		Window(int width, int height, sf::String title = "", bool resizable = true);
		~Window();

		void setGameScene(GameScene* scene);

		void setVisible(bool visible);
		bool getVisible();

		void launch();
		void close();

	private:
		void lifeCycle();
		void draw();
	};
}