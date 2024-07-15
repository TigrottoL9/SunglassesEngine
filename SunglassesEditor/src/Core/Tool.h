#pragma once
#include <raylib.h>
#include <string>
class Tool
{
public:
	Tool(std::string toolName);
	~Tool() = default;
	void DrawGUI();

protected:
	std::string m_toolName;

	virtual void ToolGUI();
};

