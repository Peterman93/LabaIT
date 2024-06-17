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
	m_guessedLetters.resize(m_word.length());
}

void Game::OnInput()
{
	if (m_gameState == GameState::UPDATE)
	{
		cin >> m_letter;
	}
}

bool Game::OnUpdate(float deltaTime)
{

	if (m_gameState == GameState::FINISH)
	{
		return true;
	}
	m_gameState = GameState::UPDATE;
	m_guessed = false;
	for (int i = 0; i < m_word.length(); ++i)
	{
		if (m_word[i] == m_letter)
		{
			m_guessedLetters[i] = true;
			m_guessed = true;
		}
	}
	if (!m_guessed)
	{
		m_stage++;
		if (m_stage == 7) 
		{
			m_gameState = GameState::FINISH;
			return true;
		}
	}
	auto it = find(m_guessedLetters.begin(), m_guessedLetters.end(), false);
	if (it != m_guessedLetters.end())
	{
		if (!*it)
		{
			return false;
		}

	}
	else
	{
		m_gameState = GameState::FINISH;
		return true;
	}

	return false;
}

void Game::OnRender()
{
	system("cls");

	if (m_gameState == GameState::UPDATE)
	{
		for (int i = 0; i < m_guessedLetters.size(); ++i)
		{
			if (m_guessedLetters[i])
			{
				cout << m_word[i];
			}
			else
			{
				cout << "_";
			}
		}
		cout << endl;
		if (m_guessed)
		{
			cout << "You guessed the letter!";
		}
		if (m_stage == 0)
		{
			cout << endl << m_drawings[m_stage] << endl;
		}
		if (m_letter != 0 && m_stage > 0)
		{
			cout << endl << m_drawings[m_stage] << endl;
			
		}
		cout << "Please guess the letter: " << endl;		
	}

	if (m_gameState == GameState::FINISH && m_stage < 7)
	{
		cout << "You guessed the word!" << endl;
	}
	if (m_gameState == GameState::FINISH && m_stage == 7)
	{
		cout << "You failed to guess the word :(" << endl;
	}
}

void Game::OnShutdown()
{
	m_guessedLetters.clear();

}
