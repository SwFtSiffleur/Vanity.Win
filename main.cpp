#include "core/graphics_api.hpp"
//Include from your source :P (most of these are usless and not needed here - Fienddd xoxox <3
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <ostream>
#include <regex>
#include <sstream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include<iostream>
#include<string.h>
#include<string>
#include <iostream>
#include <sstream>
#include <limits>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
// necessary source files
#include "Vanity/Features.h"
#include "Vanity/RecoilTables.h"

                                    //COLORS TEXT



#define REDT (255, 0, 0),
#define GREENT TextColored(ImColor(0, 255, 0),
#define YELLOWT TextColored(ImColor(255, 255, 0),
#define BLUET TextColored(ImColor(0, 0, 255),
#define CYANT TextColored(ImColor(0, 255, 255),
#define REDT TextColored(ImColor(255, 0, 0),
#define PURPLET TextColored(ImColor(255, 0, 255),
#define WHITET TextColored(ImColor(255, 255, 255),
#define BLACKT TextColored(ImColor(0, 0, 0),



int COLORT;

float COLORTEXT;




//default color TEXT











// Settings / toggles

float game_sensitivity = 0.5;


//bool for randomization
bool random_active = false;

bool show_random = false;
bool randomxy_active = false;

bool show_xycontrol = false;
bool controlxy_active = false;


bool CustomColors = true;
bool redtext = true;
bool greentext = false;
bool bluetext = false;

bool weapon_active = false;
bool ak_active = false;
bool lr_active = false;
bool mp5_active = false;
bool thompson_active = false;
bool custom_active = false;
bool semi_active = false;
bool m249_active = false;
bool python_active = false;
bool m39_active = false;
bool holo_active = false;
bool sniper_active = false;
bool simple_active = false;
bool x16_active = false;
bool silencer_active = false;
bool boost_active = false;
bool compensation_changed = false;
bool empty_active = false;
bool legit_mode = false;
bool choice_one = false;
bool choice_two = false;
int XSCALE = 1;
int YSCALE = 1;
bool show_another_window = false;






float XCONTROL = 1;
float YCONTROL = 1;






bool g_open = true;

const char* Active_Weapon = "NONE";
const char* Active_Scopes = "NONE";
const char* Active_Barrel = "NONE";

static const char* items[]{ "NONE", "HOLO", "8X", "16X", "SIMPLE" };           //combo list





namespace Input
{
	bool WhilePressed(int virtual_key)
	{
		if (GetAsyncKeyState(virtual_key) & 0x8000) return true;
		return false;
	}
	bool IsPressed(int virtual_key)
	{
		if (GetKeyState(virtual_key) & 0x8000) return true;
		return false;
	}
}





bool WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return true;
}


void InitUI() {
}
void RenderUI() {














	



	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(15, 15);
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;

	style->Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(1.0f, 0.0f, 0.0f, 0.01f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(1.0f, 0.09f, 0.12f, 0.70f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.8f, 0.2f, 0.2f, .20f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
	style->Colors[ImGuiCol_Separator] = ImVec4(1.0f, 0.00f, 0.00f, 0.50f);


	















	/*


	auto& style = ImGui::GetStyle();
	style.FrameRounding = 4.0f;
	style.WindowBorderSize = 0.0f;
	style.PopupBorderSize = 0.0f;
	style.GrabRounding = 4.0f;

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.73f, 0.75f, 0.74f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.09f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.47f, 0.22f, 0.22f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.34f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.71f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.84f, 0.66f, 0.66f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.47f, 0.22f, 0.22f, 0.65f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.71f, 0.39f, 0.39f, 0.65f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
	colors[ImGuiCol_Header] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.65f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
	colors[ImGuiCol_Tab] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
	colors[ImGuiCol_TabActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);






	*/










































	if (!g_open) {
		std::exit(0);
	}
	if (ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
		auto delta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Left);
		GAPI::DragWindow(delta);
	}
	ImGuiWindowFlags flags = 0;
	flags |= ImGuiWindowFlags_NoResize;
	flags |= ImGuiWindowFlags_NoMove;
	//flags |= ImGuiWindowFlags_NoCollapse;
	flags |= ImGuiWindowFlags_NoNav;
	flags |= ImGuiWindowFlags_NoScrollbar;

	ImGui::SetNextWindowPos({ 0, 0 });
	ImGui::SetNextWindowSize(GAPI::GetWindowSize());
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImVec2 lPos = ImGui::GetCursorPos();
	ImGui::Begin("          VANITY.WIN", (bool*)1, flags); {
		static int currentColumn = 0;;		
		//Using GetAsyncKeyState instead of Input cos im lazy and it doesnt matter, scripts will now toggle off with the same key is pressed again xo 
		if (GetAsyncKeyState(VK_F2) != 0) {
			weapon_active = true;
			ak_active = !ak_active;
			if (ak_active == true)
			{
				lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "AK47";
				Sleep(200);
			}
			else if (ak_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_F3) != 0) {
			weapon_active = true;
			lr_active = !lr_active;
			if (lr_active == true)
			{
				ak_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "LR300";
				Sleep(200);
			}
			else if (lr_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_F4) != 0) {
			weapon_active = true;
			mp5_active = !mp5_active;
			if (mp5_active == true)
			{
				ak_active = false, lr_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "MP5";
				Sleep(200);
			}
			else if (mp5_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_F5) != 0) {
			weapon_active = true;
			thompson_active = !thompson_active;
			if (thompson_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "TOMMY";
				Sleep(200);
			}
			else if (thompson_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_F6) != 0) {
			weapon_active = true;
			custom_active = !custom_active;
			if (custom_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "SMG";
				Sleep(200);
			}
			else if (custom_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}	
		if (GetAsyncKeyState(VK_F7) != 0) {
			weapon_active = true;
			semi_active = !semi_active;
			if (semi_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, custom_active = false; python_active = false; m39_active = false;
				Active_Weapon = "SEMI";
				Sleep(200);
			}
			else if (semi_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_F8) != 0) {
			weapon_active = true;
			m249_active = !m249_active;
			if (m249_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; python_active = false; m39_active = false;
				Active_Weapon = "M249";
				Sleep(200);
			}
			else if (m249_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_F9) != 0) {

			weapon_active = true;
			python_active = !python_active;
			if (python_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; m249_active = false; m39_active = false;
				Active_Weapon = "PYTHON";
				Sleep(200);
			}
			else if (python_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_F10) != 0) {
			weapon_active = true;
			m39_active = !m39_active;
			if (m39_active == true)
			{
				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; m249_active = false; python_active = false;
				Active_Weapon = "M39";
				Sleep(200);
			}
			else if (m39_active == false) {
				Active_Weapon = "NONE"; Active_Scopes = "NONE"; Active_Barrel = "NONE";
				Sleep(200);
			}
		}
		///////Scopes
		if (GetAsyncKeyState(VK_NUMPAD1) != 0) {
			holo_active = !holo_active;
			if (holo_active == true)
			{
				sniper_active = false, simple_active = false; x16_active = false;
				Active_Scopes = "HOLO";
				Sleep(150);
			}
			else if (holo_active == false) {
				Active_Scopes = "NONE";
				Sleep(150);
			}
		}
		if (GetAsyncKeyState(VK_NUMPAD2) != 0) {
			sniper_active = !sniper_active;
			if (sniper_active == true)
			{
				holo_active = false, simple_active = false; x16_active = false;
				Active_Scopes = "8X";
				Sleep(150);
			}
			else if (holo_active == false) {
				Active_Scopes = "NONE";
				Sleep(150);
			}
		}
		if (GetAsyncKeyState(VK_NUMPAD3) != 0) {
			simple_active = !simple_active;
			if (simple_active == true)
			{
				holo_active = false, sniper_active = false; x16_active = false;
				Active_Scopes = "SIMPLE";
				Sleep(150);
			}
			else if (simple_active == false) {
				Active_Scopes = "NONE";
				Sleep(150);
			}
		}
		if (GetAsyncKeyState(VK_NUMPAD4) != 0) {
			x16_active = !x16_active;
			if (x16_active == true)
			{
				holo_active = false, sniper_active = false; simple_active = false;
				Active_Scopes = "16X";
				Sleep(150);
			}
			else if (simple_active == false) {
				Active_Scopes = "NONE";
				Sleep(150);
			}
		}
		/// Barrels
		if (GetAsyncKeyState(VK_NUMPAD5) != 0) {
			silencer_active = !silencer_active;
			if (silencer_active == true)
			{
				Active_Barrel = "SILENCER";
				Sleep(150);
			}
			else if (silencer_active == false) {
				Active_Barrel = "NONE";
				Sleep(150);
			}


		}
		switch (currentColumn) {
			break;

			if (redtext == true) {

				COLORT = 255, 0, 0, 255;

			}
			if (bluetext == true) {


				COLORT = 0, 0, 255, 255;

			}
			if (greentext == true) {

				COLORT = 0, 255, 0, 255;

			}

														// STARTUP PAGE AND USER SETUP
		case 0:

			ImGui::Text("");
			
			ImGui::Text("");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "       Startup Config Page!");
			ImGui::Text("");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "   Enter Your Sensitivity Below!");
			ImGui::Text("");
			ImGui::SameLine(95);
			ImGui::SetNextItemWidth(70);
			ImGui::InputFloat(" ", &game_sensitivity, 0, 2);
			ImGui::Text("");
			


			ImGui::Text("");

			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "        More Coming Soon!!!");

			ImGui::Text("");
			ImGui::Text("");
			ImGui::Text("");



			ImGui::Text("");
			ImGui::Text("");
			ImGui::SameLine(80);
			ImGui::SetNextItemWidth(100);
			
			if (ImGui::Button("LAUNCH SCRIPT")) currentColumn = 1;


			ImGui::Text("");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " DISCORD VANITY#9999 & Monke#4662");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "-----------------------------------");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "        Status: ");
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 255, 0), "Undetected");
			
			
			
			break;
														// BUTTON PAGE WITH SWITCH TO KEYBINDS AND CONFIG
		case 1:
			
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "               GUNS");
			
			// Keybinds
			//AK BUTTON (REPEAT FOR ALL WEAPONS)
			ImGui::Text("");
			ImGui::SameLine(20);
			ImGui::SetNextItemWidth(65);
			if (ImGui::Button("  AK47  ")) {                                                                                   //AK BUTTON

				ak_active = true;
				weapon_active = true;
				lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "AK47";
				Sleep(200);

			}
			ImGui::SameLine(100);
			ImGui::SetNextItemWidth(65);
			if (ImGui::Button(" LR-300 ")) {                                                                                   //LR 300 BUTTON

				lr_active = true;
				weapon_active = true;


				ak_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
				Active_Weapon = "LR300";
				Sleep(200);

			}
			ImGui::SameLine(180);
			ImGui::SetNextItemWidth(65);
			if (ImGui::Button("  M249  ")) {                                                                                   //M249 BUTTON


				m249_active = true;
				weapon_active = true;

				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; python_active = false; m39_active = false;
				Active_Weapon = "M249";
				Sleep(200);



			}
				//SEMI AUTO SHITTER GUNS LOPLOLOLOLXSXSXSCXDXD SHIT FUSHAFKDFKJDSHFSDLFKhsdf
				
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "               SMGS");
				ImGui::Text("");
				ImGui::SameLine(20);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("  MP-5  ")) {                                                                                   //MP5

					weapon_active = true;
					mp5_active = true;

					ak_active = false, lr_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
					Active_Weapon = "MP5";
					Sleep(200);

				}
				ImGui::SameLine(100);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button(" CUSTOM ")) {                                                                                   //CUSTOM

					weapon_active = true;
					custom_active = true;

					ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
					Active_Weapon = "SMG";
					Sleep(200);

				}
				//SMG BUTTONS
				
				ImGui::SameLine(180);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button(" TOMMY  ")) {                                                                                   //TOMMY

					weapon_active = true;
					thompson_active = true;
					
					ak_active = false, lr_active = false, mp5_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
					Active_Weapon = "TOMMY";
					Sleep(200);

				}


				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "               SEMI");
				ImGui::Text("");
				ImGui::SameLine(20);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("   M39  ")) {                                                                                   //M39

					weapon_active = true;
					m39_active = true;
					
					ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; m249_active = false; python_active = false;
					Active_Weapon = "M39";
					Sleep(200);
				}
				ImGui::SameLine(100);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("  SEMI  ")) {                                                                                   //SEMI

					weapon_active = true;
					semi_active = true;
					
					ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, custom_active = false; python_active = false; m39_active = false;
					Active_Weapon = "SEMI";
					Sleep(200);

				}
				//SMG BUTTONS

				ImGui::SameLine(180);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button(" PYTHON ")) {                                                                                   //PYTHON

					weapon_active = true;
					python_active = true;

					ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; m249_active = false; m39_active = false;
					Active_Weapon = "PYTHON";
					Sleep(200);

				}

				ImGui::Separator();
				ImGui::Text("");
				ImGui::SameLine(10);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "            ATTACHMENTS");
				
				ImGui::Text("");
				ImGui::SameLine(20);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("  NONE  ")) {                                                                                   //NO SCOPE MLG OOOOO

					holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
					silencer_active = false;
					Active_Scopes = "NONE";
					Active_Barrel = "NONE";

				}
				ImGui::SameLine(100);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("  HOLO  ")) {                                                                                   //HOLO

					holo_active = true;
					sniper_active = false, simple_active = false; x16_active = false;
					Active_Scopes = "HOLO";
					Sleep(150);
				}
				//SMG BUTTONS

				ImGui::SameLine(180);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("   8X   ")) {                                                                                   //8X

					sniper_active = true;

					holo_active = false, simple_active = false; x16_active = false;
					Active_Scopes = "8X";
					Sleep(150);

				}

				
				ImGui::Text("");
				ImGui::SameLine(20);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("  16-X  "  )) {                                                                                   //16X

					x16_active = true;
					holo_active = false, sniper_active = false; simple_active = false;
					Active_Scopes = "16X";
					Sleep(150);

				}
				ImGui::SameLine(100);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button(" SIMPLE ")) {                                                                                   //SIMPLE
					simple_active = true;
					holo_active = false, sniper_active = false; x16_active = false;
					Active_Scopes = "SIMPLE";
					Sleep(150);

				}
				//SMG BUTTONS

				ImGui::SameLine(180);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button("SUPPRESS")) {                                                                                   //TOGGLE SUPPRESOR

					silencer_active = true;
					Active_Barrel = "SILENCER";
					Sleep(150);
				}

				ImGui::Separator();
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "");

				//RESET BUTTON

				ImGui::SameLine(102);
				ImGui::SetNextItemWidth(65);
				if (ImGui::Button(" RESET ")) {                                                                                   //RESET



					ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
					holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
					silencer_active = false;
					weapon_active = false;



					Active_Weapon = "NONE";

					Active_Scopes = "NONE";
					
					Active_Barrel = "NONE";



				}
				
				//Actives for button page
				ImGui::Text("");
				ImGui::SameLine(65);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Active Weapon:");
				ImGui::SameLine();
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), Active_Weapon);
				ImGui::Text("");
				ImGui::SameLine(65);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Active Scopes:");
				ImGui::SameLine();
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), Active_Scopes);
				ImGui::Text("");
				ImGui::SameLine(65);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Active Barrel:");
				ImGui::SameLine();
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), Active_Barrel);

				ImGui::Text("");
				ImGui::Separator();
			
				ImGui::Text("");

			ImGui::SameLine(30);
			ImGui::SetNextItemWidth(115);
			if (ImGui::Button("  KEYBINDS  ")) currentColumn = 2;
			ImGui::SameLine(140);
			ImGui::SetNextItemWidth(105);
			if (ImGui::Button("   CONFIG   ")) currentColumn = 3;

			break;
																			//KEYBIND PAGE WITH SWITCH TO BUTTON AND CONFIG
		case 2:
			
			//keybind page keybinds

			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "               BINDS");
			ImGui::Text("");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " AK-47  = F2");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "  HOLO     = NUMPAD1");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " LR300  = F3");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "  8X       = NUMPAD2");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " MP5    = F4");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "  HANDMADE = NUMPAD3");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " TOMMY  = F5");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "  16X      = NUMPAD4");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " SMG    = F6");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "  Silence  = NUMPAD5");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " M249   = F8");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " SAR    = F7");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " PYTHON = F9");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), " M39    = F10");

			ImGui::Text("");


			ImGui::Separator();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "");

			//RESET BUTTON
			ImGui::SameLine(105);
			ImGui::SetNextItemWidth(65);
			if (ImGui::Button(" RESET ")) {                                                                                   //RESET



				ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
				holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
				silencer_active = false;
				weapon_active = false;



				Active_Weapon = "NONE";

				Active_Scopes = "NONE";

				Active_Barrel = "NONE";



			}

			//Actives for button page
			ImGui::Text("");
			ImGui::SameLine(65);
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Active Weapon:");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), Active_Weapon);
			ImGui::Text("");
			ImGui::SameLine(65);
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Active Scopes:");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), Active_Scopes);
			ImGui::Text("");
			ImGui::SameLine(65);
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Active Barrel:");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), Active_Barrel);

			ImGui::Text("");
			ImGui::Separator();
			ImGui::Text("");

			ImGui::SameLine(30);
			ImGui::SetNextItemWidth(105);
			if (ImGui::Button("   BUTTONS  ")) currentColumn = 1;
			ImGui::SameLine(140);
			ImGui::SetNextItemWidth(105);
			if (ImGui::Button("   CONFIG   ")) currentColumn = 3;



			break;
																			                       //CONFIG PAGE
		case 3:


			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "           Sensitivity");
			ImGui::Separator();
			ImGui::SetNextItemWidth(235);
			ImGui::SliderFloat("", &game_sensitivity, 0, 2, "% .2f");
			ImGui::Separator();
			ImGui::Text("");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "          Randomization");
			ImGui::Separator();                           //ENABLE/DISABLE RANDOMIZATION
			ImGui::Text("");
			ImGui::SameLine(65);
			ImGui::Checkbox("Enable/Disable", &show_random);
			if (show_random == true)
			{
				ImGui::Text("");

				ImGui::Text("");
				ImGui::SameLine(40);
				ImGui::SliderInt("X", &XSCALE, 1, 25, "% .2f");
				ImGui::Text("");
				ImGui::SameLine(40);
				ImGui::SliderInt("Y", &YSCALE, 1, 25, "% .2f");
				ImGui::Text("");

				randomxy_active = true;

			}
			ImGui::Separator();
			ImGui::Text("");
			ImGui::Text("");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "           X/Y CONTROL");
			ImGui::Separator();                           //ENABLE/DISABLE XY CONTROL
			ImGui::Text("");
			ImGui::SameLine(57);
			ImGui::Checkbox("Enable/DisableXY", &show_xycontrol);
			if (show_xycontrol == true)
			{
				ImGui::Text("");

				

				ImGui::Text("");
				ImGui::SameLine(40);
				ImGui::SliderFloat("X##-", &XCONTROL, 1, 5, "% .2f");
				ImGui::Text("");
				ImGui::SameLine(40);
				ImGui::SliderFloat("Y##-", &YCONTROL, 1, 5, "% .2f");
				ImGui::Text("");


			}
			else {

				XCONTROL = 1;
				YCONTROL = 1;

			}
			
			
			ImGui::Separator();
			ImGui::Text("");
			ImGui::Text("");
			ImGui::ColorPicker3;
			ImGui::ColorPicker4;
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "  MORE FEATURES COMING SOON!!!");
			ImGui::Text("");

			if (show_random == true) {

				randomxy_active = true;

			}
			if (show_random == false) {

				randomxy_active = false;

			}
			if (show_xycontrol == true) {

				controlxy_active = true;

			}
			if (show_xycontrol == false) {

				XCONTROL = 1;
				YCONTROL = 1;
		

			}



			/*
			
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Yellow");       //red

			
			*/
			

			/*
			ImGui::Text("");
			ImGui::TextColored(ImColor(COLORT), "        Custom Colors");
			ImGui::Text("");
			ImGui::SameLine(20);
			if (ImGui::Button("")) {


				redtext = true;
				



			}
			ImGui::SameLine(60);
			if (ImGui::Button("")) {


				
				greentext = true;
				

				


			}
			ImGui::SameLine(100);
			if (ImGui::Button("")) {

			
				bluetext = true;


				


			}

			*/
			ImGui::Text("");
			ImGui::Text("");

			

			ImGui::SameLine(30);
			ImGui::SetNextItemWidth(105);
			if (ImGui::Button("   BUTTONS  ")) currentColumn = 1;
			ImGui::SameLine(140);
			ImGui::SetNextItemWidth(105);
			if (ImGui::Button("  KEYBINDS  ")) currentColumn = 2;


		}


	}	ImGui::End();

}
void GameThread() {
	while (true) {
		printf("tick\n");
		
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

DWORD Init(LPVOID lpParam) {
	std::thread([]() { GameThread(); }).detach();


	GAPI::MakeWindow(
		L" ", // window title
		L" ", // window class
		{ 260, 400 }, // window size
		WndProc,
		InitUI,
		RenderUI
	);

	return 1;
}
double barrel() {
	if (silencer_active) {

		if (m249_active) {
			Multiplyer::Barrel.Suppressor = 0.75;
		}
		else if (custom_active) {
			Multiplyer::Barrel.Suppressor = 0.85;
		}

		if (holo_active) {
			return 0.8;
		}
		else if (simple_active) {
			return 0.8;
		}
		else if (sniper_active) {
			return 1;
		}
		else if (x16_active) {
			return 1.5;
		}
		else {
			return Multiplyer::Barrel.Suppressor;
		}
	}
	else {
		return Multiplyer::Barrel.None;
	}
}
double scope_attatchment_active() {
	if (holo_active) {
		if (thompson_active || custom_active) {
			if (holo_active) {
				return Multiplyer::Scope.Holo + 0.3;
			}
		}
		return Multiplyer::Scope.Holo;
	}
	else if (sniper_active) {
		if (thompson_active || custom_active) {
			if (sniper_active) {
				return Multiplyer::Scope.x8 + 0.75;
			}
		}
		return Multiplyer::Scope.x8;
	}
	else if (simple_active) {
		if (custom_active || thompson_active) {
			if (simple_active) {
				return Multiplyer::Scope.Simple + 0.1;
			}
		}
		return Multiplyer::Scope.Simple;
	}
	else if (x16_active) {
		if (custom_active || thompson_active) {
			if (x16_active) {
				return Multiplyer::Scope.x16 + 1.6;
			}
		}
		return Multiplyer::Scope.x16;
	}
	else
		return Multiplyer::Scope.None;
}
int crouch() {
	if (Input::WhilePressed(VK_CONTROL))
	{
		return Multiplyer::Crouch.none;
	}
	return Multiplyer::Crouch.crouch;
}
double relative_x(int b) {
	if (randomxy_active == false) {






		if (ak_active) {
			return (RecoilData::ak47_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL;
		}
		else if (lr_active) {
			return (RecoilData::lr300_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL;
		}
		else if (mp5_active) {
			return (RecoilData::mp5_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL;
		}
		else if (thompson_active) {
			return (RecoilData::thompson_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL;
		}
		else if (custom_active) {
			return (RecoilData::custom_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL;
		}
		else if (m249_active) {
			return (RecoilData::m249_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL;
		}
		else if (semi_active) {
			return (RecoilData::semi_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL;
		}
		else if (python_active) {
			return (RecoilData::python_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL;
		}
		else if (m39_active) {
			return (RecoilData::m39_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL;
		}
		else
			return 0;






	}
	if (randomxy_active == true) {                                                                 //X RANDOMIZATION ON AND OFF




		if (ak_active) {
			return (RecoilData::ak47_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (lr_active) {
			return (RecoilData::lr300_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (mp5_active) {
			return (RecoilData::mp5_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (thompson_active) {
			return (RecoilData::thompson_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (custom_active) {
			return (RecoilData::custom_t[b].x * scope_attatchment_active() * barrel() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (m249_active) {
			return (RecoilData::m249_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (semi_active) {
			return (RecoilData::semi_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (python_active) {
			return (RecoilData::python_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else if (m39_active) {
			return (RecoilData::m39_t[b].x * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
		}
		else
			return 0;





	}
	
}
double relative_y(int b) {                                                                                       //Y RANDOMIZATION ON AND OFF
	if (randomxy_active == false) {




		if (ak_active) {
			return (RecoilData::ak47_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL;
		}
		else if (lr_active) {
			return (RecoilData::lr300_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL;
		}
		else if (mp5_active) {
			return (RecoilData::mp5_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL;
		}
		else if (thompson_active) {
			return (RecoilData::thompson_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL;
		}
		else if (custom_active) {
			return (RecoilData::custom_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL;
		}
		else if (m249_active) {
			return (RecoilData::m249_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL;
		}
		else if (semi_active) {
			return (RecoilData::semi_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL;
		}
		else if (python_active) {
			return (RecoilData::python_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL;
		}
		else if (m39_active) {
			return (RecoilData::m39_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL;
		}
		else
			return 0;





	}
	if (randomxy_active == true) {



		if (ak_active) {
			return (RecoilData::ak47_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);
		}
		else if (lr_active) {
			return (RecoilData::lr300_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else if (mp5_active) {
			return (RecoilData::mp5_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else if (thompson_active) {
			return (RecoilData::thompson_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else if (custom_active) {
			return (RecoilData::custom_t[b].y * scope_attatchment_active() * barrel() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else if (m249_active) {
			return (RecoilData::m249_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else if (semi_active) {
			return (RecoilData::semi_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else if (python_active) {
			return (RecoilData::python_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else if (m39_active) {
			return (RecoilData::m39_t[b].y * scope_attatchment_active() * barrel() * crouch() / 4) / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
		}
		else
			return 0;



	}
	
}
int weapon_bullet() {
	if (ak_active && !RecoilData::ak47_t.empty()) {
		return static_cast<int>(RecoilData::ak47_t.size() - 1);
	}
	else if (lr_active && !RecoilData::lr300_t.empty()) {
		return static_cast<int>(RecoilData::lr300_t.size() - 1);
	}
	else if (mp5_active && !RecoilData::mp5_t.empty()) {
		return static_cast<int>(RecoilData::mp5_t.size() - 1);
	}
	else if (thompson_active && !RecoilData::thompson_t.empty()) {
		return static_cast<int>(RecoilData::thompson_t.size() - 1);
	}
	else if (custom_active && !RecoilData::custom_t.empty()) {
		return static_cast<int>(RecoilData::custom_t.size() - 1);
	}
	else if (m249_active && !RecoilData::m249_t.empty()) {
		return static_cast<int>(RecoilData::m249_t.size() - 1);
	}
	else if (semi_active && !RecoilData::semi_t.empty()) {
		return static_cast<int>(RecoilData::semi_t.size() - 1);
	}
	else if (python_active && !RecoilData::python_t.empty()) {
		return static_cast<int>(RecoilData::python_t.size() - 1);
	}
	else if (m39_active && !RecoilData::m39_t.empty()) {
		return static_cast<int>(RecoilData::m39_t.size() - 1);
	}
	else {
		return 0;
	}
}
double weapon_control(int b) {

	if (ak_active) {
		return RecoilData::control_ak[b];
	}
	else if (lr_active) {
		return RecoilData::control_lr[b];
	}
	else if (mp5_active) {
		return RecoilData::control_mp5[b];
	}
	else if (thompson_active) {
		return RecoilData::control_thompson[b];
	}
	else if (custom_active) {
		return RecoilData::control_custom[b];
	}
	else if (m249_active) {
		return WeaponData::M249.Delay;
	}
	else if (semi_active) {
		return WeaponData::SEMI.Delay;
	}
	else if (python_active) {
		return WeaponData::PYTHON.Delay;
	}
	else if (m39_active) {
		return WeaponData::M39.Delay;
	}
	else
		return 0;
}
double weapon_delay() {
	if (ak_active) {
		return WeaponData::AK47.Delay;
	}
	else if (lr_active) {
		return WeaponData::LR300.Delay;
	}
	else if (mp5_active) {
		return WeaponData::MP5.Delay;
	}
	else if (thompson_active) {
		return WeaponData::THOMPSON.Delay;
	}
	else if (custom_active) {
		return WeaponData::CUSTOM_SMG.Delay;
	}
	else if (m249_active) {
		return WeaponData::M249.Delay;
	}
	else if (semi_active) {
		return WeaponData::SEMI.Delay;
	}
	else if (python_active) {
		return WeaponData::PYTHON.Delay;
	}
	else if (m39_active) {
		return WeaponData::M39.Delay;
	}
	else
		return 0;
}
void Smoothing(double delay, double animation, int x, int y) {
	int x_ = 0, y_ = 0, t_ = 0;
	for (int i = 1; i <= (int)animation; ++i) {
		int xI = i * x / (int)animation;
		int yI = i * y / (int)animation;
		int tI = i * (int)animation / (int)animation;
		mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
		pQuerySleep((int)tI - (int)t_);
		x_ = xI; y_ = yI; t_ = tI;
	}
	pQuerySleep((int)delay - (int)animation);
}
bool recoil() {
	while (true) {
		if (weapon_active) {
			for (int i = 0; i < weapon_bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000; i++)
			{
				if (!Input::WhilePressed(VK_LBUTTON))
					break;
				Smoothing((float)weapon_delay(), weapon_control(i), (int)relative_x(i), (int)relative_y(i));
			}
			if (legit_mode) {
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
		}
	}
	return false;
}















void pQuerySleep(int ms)
{
	LONGLONG timerResolution;
	LONGLONG wantedTime;
	LONGLONG currentTime;
	QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
	timerResolution /= 1000;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	wantedTime = currentTime / timerResolution + ms;
	currentTime = 0;
	while (currentTime < wantedTime)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		currentTime /= timerResolution;
	}
}


BOOL WINAPI DllMain(
	HINSTANCE hInstDll,
	DWORD dwReason,
	LPVOID lpReserved
) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hInstDll);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Init, NULL, NULL, NULL);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)recoil, 0, 0, 0);
		break;
	default:
		return FALSE;
		break;
	}
	return TRUE;
}