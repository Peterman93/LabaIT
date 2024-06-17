#pragma once
#include <string>
#include <vector>
#include <map>
#include <string>

class Game
{
	enum class GameState
	{
		START,
		UPDATE,
		FINISH
	};

public:
	void OnInit();
	void OnInput();
	bool OnUpdate(float deltaTime);
	void OnRender();
	void OnShutdown();

private:
	std::string m_word;
	std::vector<bool> m_guessedLetters;
	GameState m_gameState = GameState::START;
	char m_letter;
	bool m_guessed = false;
	int m_stage = -1;
	std::map<int, std::string> m_drawings = { {0, "  _________\n  |       |\n  |       |\n  |       |\n  |       |\n  |       |\n /|\\     /|\\\n/ | \\   / | \\"},
		{1, "  _________\n  |   |   |\n  |       |\n  |       |\n  |       |\n  |       |\n /|\\     /|\\\n/ | \\   / | \\"},
		{2, "  _________\n  |   |   |\n  |   O   |\n  |       |\n  |       |\n  |       |\n /|\\     /|\\\n/ | \\   / | \\"},
		{3, "  _________\n  |   |   |\n  |   O   |\n  |   |   |\n  |   |   |\n  |       |\n /|\\     /|\\\n/ | \\   / | \\"},
		{4, "  _________\n  |   |   |\n  |   O   |\n  |  /|   |\n  |   |   |\n  |       |\n /|\\     /|\\\n/ | \\   / | \\"},
		{5, "  _________\n  |   |   |\n  |   O   |\n  |  /|\\  |\n  |   |   |\n  |       |\n /|\\     /|\\\n/ | \\   / | \\"},
		{6, "  _________\n  |   |   |\n  |   O   |\n  |  /|\\  |\n  |   |   |\n  |  /    |\n /|\\     /|\\\n/ | \\   / | \\"},
		{7, "  _________\n  |   |   |\n  |   O   |\n  |  /|\\  |\n  |   |   |\n  |  / \\  |\n /|\\     /|\\\n/ | \\   / | \\"} };;
};