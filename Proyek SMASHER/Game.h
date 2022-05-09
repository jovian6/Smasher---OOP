#pragma once
#include "Global.h"
#include "Menu.h"
#include "Music.h"
#include "Play.h"
#include "GameOver.h"
#include "how.h"

class Game
{
public:
	Game() : window(sf::VideoMode(width, height), "SMASHER", sf::Style::Close | sf::Style::Titlebar)
	{
		_menu = true;
		_instruction = false;
		_level1 = false;
		_level2 = false;
		_level3 = false;
		_over1 = false;
		_over2 = false;
		_over3 = false;
		_win = false;
		_check1 = false;
		_how = false;
	}
	void run()
	{
		sound.PlayMusic();
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (_menu)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						menu.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							menu.MenuPick(window, _level1, _exit, _how);
							if (_level1)
							{
								_menu = false;
							}
							if (_how)
							{
								_menu = false;
							}
						}
					}

				}
				if (_how)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						how.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							how.HowPick(window, _menu);
							if (_menu)
							{
								_how = false;
							}
						}
					}
				}
				if (_level1)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						level1.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							level1.PlayPick(window);
						}
					}
				}
				if (_level2)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						level2.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							level2.PlayPick(window);
						}
					}
				}
				if (_level3)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						level3.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							level3.PlayPick(window);
						}
					}
				}
				if (_over1)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						over1.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							over1.GameOverPick(window, _check, _check1);
							if (_check)
							{
								if (_check1)
								{
									_level2 = true;
								}
								else
									_menu = true;
								_over1 = false;
							}
						}
					}
				}
				if (_over2)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						over2.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							over2.GameOverPick(window, _check, _check1);
							if (_check)
							{
								if (_check1)
								{
									_level3 = true;
								}
								else
									_menu = true;
								_over2 = false;
							}
						}
					}
				}
				if (_over3)
				{
					if (event.type == sf::Event::MouseMoved)
					{
						over3.setMouse(event.mouseMove.x, event.mouseMove.y);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							over3.GameOverPick(window, _menu, _check1); 
							if(_menu)
							{
								_over3 = false;
							}
						}
					}
				}
			}
			window.clear();
			if (_menu)
			{
				menu.Draw(window);
			}
			if (_how)
			{
				how.Draw(window);
			}
			if (_level1)
			{
				level1.Run();
				level1.Draw(window);
				level1.CheckOver(_over1, _win);
				if (_over1)
				{
					_level1 = false;
					over1.setWinLose(_win, 1);
					sound.PlayWinSound();
				}
			}
			if (_level2)
			{
				level2.Run();
				level2.Draw(window);
				level2.CheckOver(_over2, _win);
				if (_over2)
				{
					_level2 = false;
					over2.setWinLose(_win, 2);
					sound.PlayWinSound();
				}
			}
			if (_level3)
			{
				level3.Run();
				level3.Draw(window);
				level3.CheckOver(_over3, _win);
				if (_over3)
				{
					_level3 = false;
					over3.setWinLose(_win, 3);
					sound.PlayWinSound();
				}
			}
			if (_over1)
			{
				over1.Draw(window);
			}
			if (_over2)
			{
				over2.Draw(window);
			}
			if (_over3)
			{
				over3.Draw(window);
			}
			window.display();
		}
	}
private:
	sf::RenderWindow window;
	sf::Clock clock;
	Music sound;
	Menu menu;
	Play level1{ 1 }, level2{ 2 }, level3{ 3 };
	GameOver over1, over2, over3;
	How how;
	bool _menu, _instruction, _exit, _how;
	bool _level1, _level2, _level3;
	bool _over1, _over2, _over3;
	bool _win, _check, _check1;
};

