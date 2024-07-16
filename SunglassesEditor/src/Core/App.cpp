#include "App.h"

//TODO: Fai header file per sto obrobrio
#include "../../vendor/rlImGui/imgui.h"
#include "../../vendor/rlImGui/rlImGui.h"
#include "../../vendor/rlImGui/extras/IconsKenney.h"

#include "SceneManager.h"

App::App(std::string applicationName, int windowWidth, int windowHeigth) : m_isGameRunning(true)
{
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(windowWidth, windowHeigth, applicationName.c_str());
}

void App::Initialize()
{
	//Setuppa l'interfaccia con font
	rlImGuiSetup(true);
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	ImFont* font = io.Fonts->AddFontFromFileTTF("resources/editor-styles/Arvo-Regular.ttf", 20.0f,
		nullptr, io.Fonts->GetGlyphRangesJapanese());
	io.FontDefault = font;


	static const ImWchar icons_ranges[] = { ICON_MIN_KI, ICON_MAX_KI, 0 };
	ImFontConfig icons_config;
	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	icons_config.GlyphMinAdvanceX = 15.0f;
	io.Fonts->AddFontFromFileTTF("resources/editor-styles/kenney-icon-font.ttf", 15.0f, &icons_config, icons_ranges);

	io.FontGlobalScale = 1.0f;
	rlImGuiReloadFonts();

	SetStylePurpleDark();
	ImGuiStyle& style = ImGui::GetStyle();
	style.FrameRounding = 3;
	style.GrabRounding = 3;
	style.GrabMinSize = 12;
}

void App::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(VIOLET);

		//Draw scene TODO: fallo diventare m_game->Run(); dove game sarà una classe del tipo => class MyGame: public Game
		
		if(SceneManager::CurrentScene() !=  nullptr)
		{
			if (m_isGameRunning)
			{
				SceneManager::CurrentScene()->Update();
			}
			SceneManager::CurrentScene()->Draw();
		}

		//Draw Editor GUI
		{
			rlImGuiBegin();

			ImGui::BeginMainMenuBar();
			ImGui::Text("%s Sunglasses Engine ", ICON_KI_FIST_CIRCLE);

			ImGui::SameLine(ImGui::GetWindowWidth()/2 - 10);
			if (ImGui::Button(m_isGameRunning ? ICON_KI_CARET_RIGHT : ICON_KI_PAUSE))
			{
				m_isGameRunning = !m_isGameRunning;
			}

			ImGui::SameLine(ImGui::GetWindowWidth() - 120);
			ImGui::Text(TextFormat("%i - %0.02fms", GetFPS(), GetFrameTime() * 1000));
			ImGui::EndMainMenuBar();
			ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

			/*
			for (std::unique_ptr<Tool>& tool : editorTools) {
				tool->DrawGUI();
			}
			*/

			//ImGui::ShowDemoWindow();

			rlImGuiEnd();
		}

		EndDrawing();
	}
}

void App::Shutdown()
{
	rlImGuiShutdown();
	CloseWindow();
}