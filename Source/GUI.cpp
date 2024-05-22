#include "GUI.hpp"
#include <string>

void GUI::AddScore()
{
	m_score += 100;
}

void GUI::AddLives()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	/*m_Lives.push_back(Lives(p_screen, 0, (float)p_screen.GetWindowHeight() - 25));*/
	//	int Index = (int)m_Lives.size() - 1;
	//	if (i == 1 || i == 2)
	//	{
	//		m_Lives[Index].SetX(m_Lives[(long long)Index - 1].GetX() + 40);
	//	}
	//}
}

void GUI::DeleteLives()
{
	m_Lives.pop_back();
}

void GUI::Update()
{

}

void GUI::Draw()
{
	//p_screen.DrawText((int)m_scoreX, (int)m_scoreY, color, "Score: " + std::to_string(GetScore()));
	/*for (int i = 0; i < m_Lives.size(); i++)
	{
		m_Lives[i].Draw();
	}*/
}

int GUI::GetScore()
{
	return m_score;
}

int GUI::GetLives()
{
	return (int)m_Lives.size();
}
