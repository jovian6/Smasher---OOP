#pragma once
#include "Global.h"

class Music
{
public:
	Music() {
		click_buffer.loadFromFile("Resources/Sounds/click.ogg");
		click.setBuffer(click_buffer);

		hover_buffer.loadFromFile("Resources/Sounds/hover.wav");
		hover.setBuffer(hover_buffer);

		crash_buffer.loadFromFile("Resources/Sounds/crash.wav");
		crash.setBuffer(crash_buffer);

		win_buffer.loadFromFile("Resources/Sounds/next_level.wav");
		win.setBuffer(win_buffer);

		enemyHit_buffer.loadFromFile("Resources/Sounds/hit.wav");
		enemyHit.setBuffer(enemyHit_buffer);

		enemyA_buffer.loadFromFile("Resources/Sounds/sound enemy 1.wav");
		enemyA.setBuffer(enemyA_buffer);

		enemyB_buffer.loadFromFile("Resources/Sounds/sound enemy 2.wav");
		enemyB.setBuffer(enemyB_buffer);

		enemyC_buffer.loadFromFile("Resources/Sounds/sound enemy 3.wav");
		enemyC.setBuffer(enemyC_buffer);

		enemyD_buffer.loadFromFile("Resources/Sounds/sound enemy 4.wav");
		enemyD.setBuffer(enemyD_buffer);

		enemyE_buffer.loadFromFile("Resources/Sounds/sound enemy 5.wav");
		enemyE.setBuffer(enemyE_buffer);

		musik.openFromFile("Resources/Sounds/musik.wav");
		musik.setVolume(30);
		musik.setLoop(true);
	}

	void PlayClickSound() 
	{
		click.play();
	}

	void PlayHoverSound()
	{
		hover.play();
	}

	void PlayCrashSound()
	{
		crash.play();
	}

	void PlayWinSound()
	{
		win.play();
	}

	void PlayEnemyHitSound()
	{
		enemyHit.play();
	}

	void PlayEnemyASound()
	{
		enemyA.play();
	}

	void PlayEnemyBSound()
	{
		enemyB.play();
	}

	void PlayEnemyCSound()
	{
		enemyC.play();
	}

	void PlayEnemyDSound()
	{
		enemyD.play();
	}

	void PlayEnemyESound()
	{
		enemyE.play();
	}

	void PlayMusic() {
		musik.play();
	}

	void StopMusic() {
		musik.stop();
	}

	void setVolumeMusic(int n) {
		musik.setVolume(n);
	}

private:
	sf::SoundBuffer click_buffer, hover_buffer, crash_buffer, win_buffer, enemyHit_buffer, enemyA_buffer, enemyB_buffer, enemyC_buffer, enemyD_buffer, enemyE_buffer;
	sf::Sound click, hover, crash, win, enemyHit, enemyA, enemyB, enemyC, enemyD, enemyE;
	sf::Music musik;
};
