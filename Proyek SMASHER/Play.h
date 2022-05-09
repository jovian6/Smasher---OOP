#pragma once
#include"Global.h"
#include"Enemy.h"
#include"Music.h"
#include<time.h>
#include<Windows.h>
class Play
{
protected:
	Enemy** enemy;
	Music sound;
	sf::Texture _backgroundT, _skill1T, _skill2T, _skill3T;
	sf::Sprite _background, _skill1, _skill2, _skill3;
	sf::Text _life, _kill, _text1, _text2, _text3;
	sf::Font _font;
	int banyakEnemy, point, countLife, totalEnemy, countEnemyKill, _level, countEnemy;
	int currentTime, startTime, timeEnemy, currentTime1, startTime1, Skill3Time, enemyUpdateTime;
	bool _over, _win, _s1, _s2, _s3;
public:
	Play(int level = 1)
	{
		_level = level;
		if (_level == 1)
		{
			_backgroundT.loadFromFile("Resources/bg level 1.jpg");
			totalEnemy = 30;
			timeEnemy = 2000;
		}	
		else if(_level == 2)
		{
			_backgroundT.loadFromFile("Resources/bg level 2.jpg");
			totalEnemy = 40;
			timeEnemy = 1500;
		}
		else
		{
			_backgroundT.loadFromFile("Resources/bg level 3.jpg");
			totalEnemy = 50;
			timeEnemy = 1000;
		}
		_background.setTexture(_backgroundT);

		banyakEnemy = 0;
		enemy = new Enemy *[banyakEnemy];

		countLife = 3;
		point = 0;
		countEnemy = 0;
		countEnemyKill = 0;
		_over = false;
		_win = false;
		currentTime = 0;
		startTime = 0;
		startTime1 = 0;
		currentTime1 = 0;
		enemyUpdateTime = 100;

		_font.loadFromFile("Resources/Fonts/Birdthopia.ttf");
		
		_life.setFont(_font);
		_life.setString("LIFE : " + std::to_string(countLife));
		_life.setFillColor(sf::Color::White);
		_life.setCharacterSize(75);
		_life.setOutlineColor(sf::Color::Black);
		_life.setOutlineThickness(5);
		_life.setOrigin(sf::Vector2f(_life.getLocalBounds().width / 2, _life.getLocalBounds().height / 2));
		_life.setPosition(sf::Vector2f(width * 3/4 - _life.getGlobalBounds().width, 800));

		_kill.setFont(_font);
		_kill.setString("KILL : " + std::to_string(point));
		_kill.setFillColor(sf::Color::White);
		_kill.setCharacterSize(75);
		_kill.setOutlineColor(sf::Color::Black);
		_kill.setOutlineThickness(5);
		_kill.setOrigin(sf::Vector2f(_kill.getLocalBounds().width / 2, _kill.getLocalBounds().height / 2));
		_kill.setPosition(sf::Vector2f(width - _kill.getGlobalBounds().width, 800));

		_skill1T.loadFromFile("Resources/heart.png");
		_skill1.setTexture(_skill1T);
		_skill1.setOrigin(sf::Vector2f(_skill1.getLocalBounds().width / 2, _skill1.getLocalBounds().height / 2));
		_skill1.setPosition(sf::Vector2f(100, 800));
		_skill1.setColor(sf::Color(255, 255, 255, 100));

		_text1.setFont(_font);
		_text1.setString("10");
		_text1.setFillColor(sf::Color::White);
		_text1.setCharacterSize(40);
		_text1.setOutlineColor(sf::Color::Black);
		_text1.setOutlineThickness(2.5);
		_text1.setOrigin(sf::Vector2f(_text1.getLocalBounds().width / 2, _text1.getLocalBounds().height / 2));
		_text1.setPosition(sf::Vector2f(100, 860));

		_skill2T.loadFromFile("Resources/lightning.png");
		_skill2.setTexture(_skill2T);
		_skill2.setOrigin(sf::Vector2f(_skill2.getLocalBounds().width / 2, _skill2.getLocalBounds().height / 2));
		_skill2.setPosition(sf::Vector2f(300, 800));
		_skill2.setColor(sf::Color(255, 255, 255, 100));

		_text2.setFont(_font);
		_text2.setString("15");
		_text2.setFillColor(sf::Color::White);
		_text2.setCharacterSize(40);
		_text2.setOutlineColor(sf::Color::Black);
		_text2.setOutlineThickness(2.5);
		_text2.setOrigin(sf::Vector2f(_text2.getLocalBounds().width / 2, _text2.getLocalBounds().height / 2));
		_text2.setPosition(sf::Vector2f(300, 860));

		_skill3T.loadFromFile("Resources/water.png");
		_skill3.setTexture(_skill3T);
		_skill3.setOrigin(sf::Vector2f(_skill3.getLocalBounds().width / 2, _skill3.getLocalBounds().height / 2));
		_skill3.setPosition(sf::Vector2f(500, 800));
		_skill3.setColor(sf::Color(255, 255, 255, 100));

		_text3.setFont(_font);
		_text3.setString("5");
		_text3.setFillColor(sf::Color::White);
		_text3.setCharacterSize(40);
		_text3.setOutlineColor(sf::Color::Black);
		_text3.setOutlineThickness(2.5);
		_text3.setOrigin(sf::Vector2f(_text3.getLocalBounds().width / 2, _text3.getLocalBounds().height / 2));
		_text3.setPosition(sf::Vector2f(500, 860));

		_s1 = false;
		_s2 = false;
		_s3 = false;
	}
	bool getOver()
	{
		return _over;
	}
	bool getWin()
	{
		return _win;
	}
	void Run()
	{
		currentTime1 = GetTickCount();
		if (currentTime1 - startTime1 >= timeEnemy)
		{
			startTime1 = GetTickCount();
			if (countEnemy + 1 <= totalEnemy)
			{
				Enemy** temp;
				temp = new Enemy * [banyakEnemy + 1];
				for (int j = 0; j < banyakEnemy; j++)
				{
					temp[j] = enemy[j];
				}
				int random = rand() % 5;
				if (random == 0)
					temp[banyakEnemy] = new EnemyA();
				else if (random == 1)
					temp[banyakEnemy] = new EnemyB();
				else if (random == 2)
					temp[banyakEnemy] = new EnemyC();
				else if (random == 3)
					temp[banyakEnemy] = new EnemyD();
				else
					temp[banyakEnemy] = new EnemyE();

				delete[]enemy;
				banyakEnemy++;
				countEnemy++;
				enemy = new Enemy * [banyakEnemy];
				enemy = temp;
				temp = NULL;
			}

			for (int i = 0; i < banyakEnemy; i++)
			{
				if (enemy[i]->getType() == 4)
				{
					if (enemy[i]->getShield() == true)
						enemy[i]->setShield(0);
					else
						enemy[i]->setShield(1);
				}
			}
		}

		if (countEnemyKill == totalEnemy)
		{
			if (countLife > 0)
				_win = true;
			_over = true;
		}
	
		currentTime = GetTickCount();
		if (currentTime - startTime >= enemyUpdateTime)
		{
			startTime = GetTickCount();
			for (int i = 0; i < banyakEnemy; i++)
			{
				enemy[i]->Move();
			}
		}
		
		ActiveSkill();

		if (currentTime - Skill3Time >= 5000)
		{
			unskill_3();
		}

		CheckEnemy();

		_life.setString("LIFE : " + std::to_string(countLife));
		_kill.setString("KILL : " + std::to_string(point));
	}
	void CheckOver(bool& over, bool& win)
	{
		over = _over;
		win = _win;
	}
	void PlayPick(sf::RenderWindow& window)
	{
		bool check;
		for (int i = 0; i < banyakEnemy; i++)
		{
			enemy[i]->EnemyPick(check);
			if (check)
			{
				if (enemy[i]->getType() == 1)
					sound.PlayEnemyASound();
				else if (enemy[i]->getType() == 2)
					sound.PlayEnemyBSound();
				else if (enemy[i]->getType() == 3)
					sound.PlayEnemyCSound();
				else if (enemy[i]->getType() == 4)
					sound.PlayEnemyDSound();
				else if (enemy[i]->getType() == 5)
					sound.PlayEnemyESound();
			}
		}

		if (_skill1.getGlobalBounds().left <= mouse_x && _skill1.getGlobalBounds().left + _skill1.getGlobalBounds().width >= mouse_x && _skill1.getGlobalBounds().top <= mouse_y && _skill1.getGlobalBounds().top + _skill1.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			if (_s1 == true)
			{
				skill_1();
				point -= 10;
			}
		}
		if (_skill2.getGlobalBounds().left <= mouse_x && _skill2.getGlobalBounds().left + _skill2.getGlobalBounds().width >= mouse_x && _skill2.getGlobalBounds().top <= mouse_y && _skill2.getGlobalBounds().top + _skill2.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			if (_s2 == true)
			{
				skill_2();
				point -= 15;
			}
		}
		if (_skill3.getGlobalBounds().left <= mouse_x && _skill3.getGlobalBounds().left + _skill3.getGlobalBounds().width >= mouse_x && _skill3.getGlobalBounds().top <= mouse_y && _skill3.getGlobalBounds().top + _skill3.getGlobalBounds().height >= mouse_y)
		{
			sound.PlayClickSound();
			if (_s3 == true)
			{
				skill_3();
				point -= 5;
				Skill3Time = GetTickCount();
			}
		}
	}
	void Draw(sf::RenderWindow& window)
	{
		window.draw(_background);
		window.draw(_life);
		window.draw(_kill);
		window.draw(_skill1);
		window.draw(_skill2);
		window.draw(_skill3);
		window.draw(_text1);
		window.draw(_text2);
		window.draw(_text3);
		for (int i = 0; i < banyakEnemy; i++)
		{
			enemy[i]->Draw(window);
		}
	}
	void KillEnemy(int i)
	{
		Enemy** temp;
		temp = new Enemy * [banyakEnemy - 1];
		for (int j = 0; j < banyakEnemy - 1; j++)
		{
			if (j < i)
			{
				temp[j] = enemy[j];
			}
			else 
			{
				temp[j] = enemy[j + 1];
			}
		}
		delete[]enemy;
		banyakEnemy--;
		enemy = new Enemy * [banyakEnemy];
		for (int j = 0; j <banyakEnemy; j++)
		{
			enemy[j] = temp[j];
		}
		temp = NULL;
	}
	void CheckEnemy() //kalau mati, kalau lewati layar
	{
		for (int i = 0; i < banyakEnemy; i++)
		{
			if (enemy[i]->GetXPosition() >= width)
			{
				countLife--;
				sound.PlayCrashSound();
				if (countLife <= 0)
				{
					_win = false;
					_over = true;
				}
				KillEnemy(i);
				countEnemyKill++;
			}
			if (enemy[i]->getHealth() <= 0)
			{
				KillEnemy(i);
				point++;
				countEnemyKill++;
			}
		}
	}
	void setMouse(int x, int y) 
	{
		mouse_x = x;
		mouse_y = y;
	}
	void skill_1() //life
	{
		//10
		countLife++;
		
		if (countLife > 3)
		{
			countLife = 3;
		}
	}
	void skill_2()//bunuh semua
	{
		//banyakenemy yg keluar di layar
		//15
		countEnemyKill += banyakEnemy;
		point += banyakEnemy;
		banyakEnemy = 0;
	}
	void skill_3() //slow motion
	{
		//5
		enemyUpdateTime = 200;
	}
	void unskill_3()
	{
		enemyUpdateTime = 100;
	}
	void ActiveSkill()
	{
		if(point < 5)
		{
			_s1 = false;
			_s2 = false;
			_s3 = false;
			_skill3.setColor(sf::Color(255, 255, 255, 100));
			_skill2.setColor(sf::Color(255, 255, 255, 100));
			_skill1.setColor(sf::Color(255, 255, 255, 100));
		}
		if(point >= 15)
		{
			_s2 = true;
			_skill2.setColor(sf::Color(255, 255, 255, 255));
		}
		if(point >= 10)
		{
			_s1 = true;
			_skill1.setColor(sf::Color(255, 255, 255, 255));
			if (_s2 == false)
			{
				_skill2.setColor(sf::Color(255, 255, 255, 100));
			}
		}
		if(point >= 5)
		{
			_s3 = true;
			_skill3.setColor(sf::Color(255, 255, 255, 255));
			if (_s2 == false)
			{
				_skill2.setColor(sf::Color(255, 255, 255, 100));
			}
			if (_s1 == false)
			{
				_skill1.setColor(sf::Color(255, 255, 255, 100));
			}
		}
	}
};