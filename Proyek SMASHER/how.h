#pragma once
#include"Music.h"
#include"Global.h"

class How
{
private:
	sf::Texture _backgroundT, _backT;
	sf::Sprite _background, _back;
	Music sound;
public:
	How()
	{
		_backgroundT.loadFromFile("Resources/howtoplay.jpg");
		_background.setTexture(_backgroundT);

		_backT.loadFromFile("Resources/back1.png");
		_back.setTexture(_backT);
		_back.setOrigin(sf::Vector2f(_back.getLocalBounds().width / 2, _back.getLocalBounds().height / 2));
		_back.setPosition((width - 50), 50);
	}

	void Draw(sf::RenderWindow& window)
	{
		HowEffect();
		window.draw(_background);
		window.draw(_back);
	}

	void setMouse(int x, int y)
	{
		mouse_x = x;
		mouse_y = y;
	}

	void HowPick(sf::RenderWindow& window, bool& menu)
	{
		if (_back.getGlobalBounds().left <= mouse_x && _back.getGlobalBounds().left + _back.getGlobalBounds().width >= mouse_x && _back.getGlobalBounds().top <= mouse_y && _back.getGlobalBounds().top + _back.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			menu = true;
		}
	}

	void HowEffect()
	{
		if (_back.getGlobalBounds().left <= mouse_x && _back.getGlobalBounds().left + _back.getGlobalBounds().width >= mouse_x && _back.getGlobalBounds().top <= mouse_y && _back.getGlobalBounds().top + _back.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayHoverSound();
			_back.setScale(1.1, 1.1);
		}
		else
		{
			_back.setScale(1, 1);
		}
	}
};