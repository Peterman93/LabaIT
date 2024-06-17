#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

void Game::OnInit()
{
	m_guessedLetters.clear();
	srand(time(NULL));
	int randomIndex = rand() % 5;

	string word;
	int count = 0;
	ifstream wordsPool("wordsPool.txt");
	while (getline(wordsPool, word))
	{
		if (count == randomIndex)
		{
			m_word = word;
		}
		count++;
	}
	wordsPool.close();

	for (int i = 0; i < m_word.length(); ++i)
	{
		cout << "_";
	}
	cout << endl << endl << "Please guess the letter: " << endl;
}

void Game::OnInput()
{
	char letter;
	cin >> letter;
}

bool Game::OnUpdate(float deltaTime)
{




	return false;
}

void Game::OnRender()
{

}

void Game::OnShutdown()
{
	m_guessedLetters.clear();

}
