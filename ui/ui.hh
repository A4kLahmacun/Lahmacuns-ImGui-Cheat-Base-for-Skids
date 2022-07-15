#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"

namespace ui {
	void init(LPDIRECT3DDEVICE9);
	void render();
	void getx();
}

namespace ui {
	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = "Skid Menu Mod Base ";
}

namespace ui {
	inline ImVec2 screen_res{ 000, 000 };
	inline ImVec2 window_pos{ 0, 0 };
	inline ImVec2 window_size{ 1200, 500 };
	inline DWORD  window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
}