#pragma once
#include"Music.h"
#include"Global.h"

class GameOver
{
private:
	sf::Texture _backgroundT, _playT, _exitT;
	sf::Sprite _background;
	sf::Text _text, _win;
	sf::Font _font, _font1;
	bool _winlose;
	Music sound;
public:

	GameOver(int win = 0)
	{
		_font.loadFromFile("Resources/Fonts/Birdthopia.ttf");
		_font1.loadFromFile("Resources/Fonts/Typograph.ttf");
    
		_backgroundT.loadFromFile("Resources/gameover.jpg");
		_background.setTexture(_backgroundT);

		_win.setFont(_font);
		_win.setFillColor(sf::Color::White);
		_win.setCharacterSize(170);
		_win.setOutlineColor(sf::Color::Black);
		_win.setOutlineThickness(10);
		_win.setPosition(sf::Vector2f(width / 2, height * 1/ 4));

		_text.setFont(_font1);
		_text.setFillColor(sf::Color::White);
		_text.setCharacterSize(100);
		_text.setOutlineColor(sf::Color::Black);
		_text.setOutlineThickness(7);
		_text.setPosition(sf::Vector2f(width / 2, height * 3 / 5));
	}

	void setWinLose(bool win, int level)
	{
		if (!win)
		{
			_win.setString("YOU LOSE");
			_text.setString("MAIN MENU");
		}
		else
		{
			_win.setString("YOU WIN");
			_text.setString("NEXT LEVEL");
		}
		if(level==3)
		{
			_text.setString("MAIN MENU");
		}
		_winlose = win;
		_win.setOrigin(sf::Vector2f(_win.getLocalBounds().width / 2, _win.getLocalBounds().height / 2));
		_text.setOrigin(sf::Vector2f(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2));
	}

	bool getWinLose()
	{
		return _winlose;
	}

	void Draw(sf::RenderWindow& window)
	{
		MenuEffect();
		window.draw(_background);
		window.draw(_win);
		window.draw(_text);
	}

	void setMouse(int x, int y)
	{
		mouse_x = x;
		mouse_y = y;
	}

	void GameOverPick(sf::RenderWindow& window, bool& next, bool &menu)
	{
		if (_text.getGlobalBounds().left <= mouse_x && _text.getGlobalBounds().left + _text.getGlobalBounds().width >= mouse_x && _text.getGlobalBounds().top <= mouse_y && _text.getGlobalBounds().top + _text.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			next = true;
			menu = _winlose;
		}
		else
			next = false;
	}

	void MenuEffect()
	{
		if (_text.getGlobalBounds().left <= mouse_x && _text.getGlobalBounds().left + _text.getGlobalBounds().width >= mouse_x && _text.getGlobalBounds().top <= mouse_y && _text.getGlobalBounds().top + _text.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayHoverSound();
			_text.setScale(1.1, 1.1);
		}
		else
		{
			_text.setScale(1, 1);
		}
	}
};