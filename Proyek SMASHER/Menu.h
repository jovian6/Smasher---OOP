#pragma once
#include"Music.h"
#include"Global.h"

class Menu
{
private:
	sf::Texture _backgroundT, _playT, _exitT, _howT;
	sf::Sprite _background, _play, _exit, _how;
	sf::Text _title;
	sf::Font _font;
	Music sound;
public:
	
	Menu()
	{
		_font.loadFromFile("Resources/Fonts/Birdthopia.ttf");

		_backgroundT.loadFromFile("Resources/menu1.jpg");
		_background.setTexture(_backgroundT);
		
		_playT.loadFromFile("Resources/play.png");
		_play.setTexture(_playT);
		_play.setOrigin(sf::Vector2f(_play.getLocalBounds().width / 2, _play.getLocalBounds().height / 2));
		_play.setPosition(sf::Vector2f(width / 2, height * 3 / 4));

		_exitT.loadFromFile("Resources/exit.png");
		_exit.setTexture(_exitT);
		_exit.setOrigin(sf::Vector2f(_exit.getLocalBounds().width / 2, _exit.getLocalBounds().height / 2));
		_exit.setPosition(sf::Vector2f((width - 50), 50));

		_howT.loadFromFile("Resources/howto1.png");
		_how.setTexture(_howT);
		_how.setOrigin(sf::Vector2f(_how.getLocalBounds().width / 2, _how.getLocalBounds().height / 2));
		_how.setPosition(sf::Vector2f((width - 150), 50));

		_title.setFont(_font);
		_title.setString("SMASHER");
		_title.setFillColor(sf::Color::White);
		_title.setCharacterSize(170);
		_title.setOutlineColor(sf::Color::Black);
		_title.setOutlineThickness(10);
		_title.setOrigin(sf::Vector2f(_title.getLocalBounds().width / 2, _title.getLocalBounds().height / 2));
		_title.setPosition(sf::Vector2f(width / 2, 100));

	}

	void Draw(sf::RenderWindow& window)
	{
		MenuEffect();
		window.draw(_background);
		window.draw(_exit);
		window.draw(_title);
		window.draw(_play);
		window.draw(_how);
	}

	void setMouse(int x, int y) 
	{
		mouse_x = x;
		mouse_y = y;
	}

	void MenuPick(sf::RenderWindow& window, bool& play, bool &exit, bool& how)
	{
		if (_play.getGlobalBounds().left <= mouse_x && _play.getGlobalBounds().left + _play.getGlobalBounds().width >= mouse_x && _play.getGlobalBounds().top <= mouse_y && _play.getGlobalBounds().top + _play.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			play = true;
		}
		if (_exit.getGlobalBounds().left <= mouse_x && _exit.getGlobalBounds().left + _exit.getGlobalBounds().width  >= mouse_x && _exit.getGlobalBounds().top  <= mouse_y && _exit.getGlobalBounds().top + _exit.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			exit = true;
			window.close();
		}
		if (_how.getGlobalBounds().left <= mouse_x && _how.getGlobalBounds().left + _how.getGlobalBounds().width >= mouse_x && _how.getGlobalBounds().top <= mouse_y && _how.getGlobalBounds().top + _how.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			how = true;
		}
	}

	void MenuEffect() 
	{
		if (_play.getGlobalBounds().left <= mouse_x && _play.getGlobalBounds().left + _play.getGlobalBounds().width >= mouse_x && _play.getGlobalBounds().top <= mouse_y && _play.getGlobalBounds().top + _play.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayHoverSound();
			_play.setScale(1.1, 1.1);
		}
		else
		{
			_play.setScale(1, 1);
		}
		if (_exit.getGlobalBounds().left <= mouse_x && _exit.getGlobalBounds().left + _exit.getGlobalBounds().width >= mouse_x && _exit.getGlobalBounds().top <= mouse_y && _exit.getGlobalBounds().top + _exit.getGlobalBounds().height >= mouse_y)
		{	
			sound.PlayHoverSound();
			_exit.setScale(1.1, 1.1);
		}
		else
		{
			_exit.setScale(1, 1);
		}
		if (_how.getGlobalBounds().left <= mouse_x && _how.getGlobalBounds().left + _how.getGlobalBounds().width >= mouse_x && _how.getGlobalBounds().top <= mouse_y && _how.getGlobalBounds().top + _how.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayHoverSound();
			_how.setScale(1.1, 1.1);
		}
		else
		{
			_how.setScale(1, 1);
		}
	}
};