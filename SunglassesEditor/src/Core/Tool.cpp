#include "Tool.h"
#include "../../vendor/rlImGui/imgui.h"

#include <iostream>

Tool::Tool(std::string toolName): m_toolName(toolName)
{
}

void Tool::DrawGUI()
{
	ImGui::Begin(m_toolName.c_str());

	ImGui::End();
}

void Tool::ToolGUI()
{
	ImGui::Text(m_toolName.append(" Editor").c_str());
}
