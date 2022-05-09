#pragma once
#include"Global.h"
#include"Music.h"

class Enemy
{
public:
	Enemy()
	{
		_speed = 10;
		_x = 0;
		_y = (rand() % 6 + 1) * 100 - 50;

		_playerSprite[0].setOrigin(sf::Vector2f(_playerSprite[0].getLocalBounds().width / 2, _playerSprite[0].getLocalBounds().height / 2));
		_playerSprite[0].setPosition(_x, _y);
		_playerSprite[0].setScale(0.2, 0.2);

		_playerSprite[1].setOrigin(sf::Vector2f(_playerSprite[1].getLocalBounds().width / 2, _playerSprite[1].getLocalBounds().height / 2));
		_playerSprite[1].setPosition(_x, _y);
		_playerSprite[1].setScale(0.2, 0.2);

		_health = 3;

		index = 0;
	}

	void SetPosition(int x, int y) 
	{
		_x = x;
		_y = y;
	}
	void setSpeed(int speed) 
	{
		_speed = speed;
	}
	int getSpeed() 
	{
		return _speed;
	}
	void moveUp() 
	{
		_playerSprite[0].move(0, -_speed);
		_playerSprite[1].move(0, -_speed);
	}
	void moveDown() 
	{
		_playerSprite[0].move(0, _speed);
		_playerSprite[1].move(0, _speed);
	}
	void moveRight() 
	{
		_playerSprite[0].move(_speed, 0);
		_playerSprite[1].move(_speed, 0);
	}
	int GetXPosition()
	{
		return _playerSprite[0].getPosition().x;
	}
	int GetYPosition() 
	{
		return _playerSprite[0].getPosition().y;
	}
	sf::Sprite getPlayerSprite() 
	{
		return _playerSprite[0];
	}
	void EnemyPick(bool &check)
	{
		check = false;
		if (_playerSprite[0].getGlobalBounds().left <= mouse_x && _playerSprite[0].getGlobalBounds().left + _playerSprite[0].getGlobalBounds().width >= mouse_x && _playerSprite[0].getGlobalBounds().top <= mouse_y && _playerSprite[0].getGlobalBounds().top + _playerSprite[0].getGlobalBounds().height >= mouse_y)
		{
			Hit();
			check = true;
		}
		else if (_playerSprite[1].getGlobalBounds().left <= mouse_x && _playerSprite[1].getGlobalBounds().left + _playerSprite[1].getGlobalBounds().width >= mouse_x && _playerSprite[1].getGlobalBounds().top <= mouse_y && _playerSprite[1].getGlobalBounds().top + _playerSprite[1].getGlobalBounds().height >= mouse_y)
		{
			Hit();
			check = true;
		}
	}
	void SetHealth(int h)
	{
		_health = h;
	}
	int getHealth()
	{
		return _health;
	}
	virtual void Hit()
	{
		_health--;
	}
	void Draw(sf::RenderWindow& window)
	{
		window.draw(_playerSprite[index]);
		if (index == 0)
			index = 1;
		else
			index = 0;
	}
	virtual void Move() {}
	virtual int getType() { return 0; }
	virtual void setShield(int shield) {}
	virtual bool getShield() { return false; }

protected:

	int _x, _y;
	sf::Texture _playerTex[2];
	sf::Sprite _playerSprite[2];
	int _speed;
	int index;
	int _health;
	Music sound;
};
		
//normal
class EnemyA : public Enemy
{
protected:

public:
	EnemyA()
	{
		_playerTex[0].loadFromFile("Resources/Enemy 1.png");
		_playerSprite[0].setTexture(_playerTex[0]);
		_playerTex[1].loadFromFile("Resources/Enemy 1-2.png");
		_playerSprite[1].setTexture(_playerTex[1]);
	}
	void Move()
	{
		moveRight();
	}
	int getType() 
	{ 
		return 1; 
	}
};
//zig-zag
class EnemyB : public Enemy
{
protected:
public:
	EnemyB()
	{
		_playerTex[0].loadFromFile("Resources/Enemy 2.png");
		_playerSprite[0].setTexture(_playerTex[0]);
		_playerTex[1].loadFromFile("Resources/Enemy 2-2.png");
		_playerSprite[1].setTexture(_playerTex[1]);
	}
	void Move()
	{
		moveRight();

		int random = rand() % 2;

		if (random == 0)
		{
			if (GetYPosition() == 0)
				moveDown();
			else
				moveUp();
		}
		else
		{
			if (GetYPosition() == height - 200)
				moveUp();
			else
				moveDown();
		}
	}
	int getType()
	{
		return 2;
	}
};
//super cepat
class EnemyC : public Enemy
{
protected:

public:
	EnemyC()
	{
		_playerTex[0].loadFromFile("Resources/Enemy 3.png");
		_playerSprite[0].setTexture(_playerTex[0]);
		_playerTex[1].loadFromFile("Resources/Enemy 3-2.png");
		_playerSprite[1].setTexture(_playerTex[1]);
	
		_speed = 20;

		_health = 2;
	}
	void Move()
	{
		moveRight();
	}
	int getType()
	{
		return 3;
	}
};
//shield
class EnemyD : public Enemy
{
protected:
	bool _shield;
public:
	EnemyD()
	{
		_playerTex[0].loadFromFile("Resources/Enemy 4.png");
		_playerSprite[0].setTexture(_playerTex[0]);
		_playerTex[1].loadFromFile("Resources/Enemy 4-2.png");
		_playerSprite[1].setTexture(_playerTex[1]);

		_shield = false;

		_health = 2;
	}
	void Move()
	{
		if (_shield)
		{
			_speed = 5;
			_playerSprite[0].setColor(sf::Color(255, 255, 255, 100));
			_playerSprite[1].setColor(sf::Color(255, 255, 255, 100));
		}
		else
		{
			_speed = 10;
			_playerSprite[0].setColor(sf::Color(255, 255, 255, 255));
			_playerSprite[1].setColor(sf::Color(255, 255, 255, 255));
		}
		moveRight();
	}
	void setShield(int shield)
	{
		if (shield == 0)
			_shield = false;
		else
			_shield = true;
	}
	bool getShield()
	{
		return _shield;
	}
	void Hit()
	{
		if (_shield)
		{}
		else
		{
			_health--;
		}
	}
	int getType()
	{
		return 4;
	}
};
//invisible(startnya dari tengah layar)
class EnemyE : public Enemy
{
protected:

public:
	EnemyE()
	{
		_playerTex[0].loadFromFile("Resources/Enemy 5.png");
		_playerSprite[0].setTexture(_playerTex[0]);
		_playerTex[1].loadFromFile("Resources/Enemy 5-2.png");
		_playerSprite[1].setTexture(_playerTex[1]);

		_playerSprite[0].move(width / 2, 0);
		_playerSprite[1].move(width / 2, 0);

		_health = 2;
	}
	void Move()
	{
		moveRight();
	}
	int getType()
	{
		return 5;
	}
};