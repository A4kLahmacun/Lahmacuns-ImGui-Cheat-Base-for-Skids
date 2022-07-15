#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "../TextEditor/TextEditor.h"
#include <io.h>

void DoStyle()
{
    
    ImGuiStyle& style = ImGui::GetStyle();
 
    style.Colors[ImGuiCol_TitleBgActive] = ImColor(2, 40, 2);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(42, 43, 42);
    style.Colors[ImGuiCol_WindowBg] = ImColor(2, 36, 2);
    style.Colors[ImGuiCol_Tab] = ImColor(2, 36, 2);
    style.Colors[ImGuiCol_TabActive] = ImColor(63, 145, 15);
    style.Colors[ImGuiCol_TabHovered] = ImColor(67, 71, 67);
    style.Colors[ImGuiCol_SliderGrab] = ImColor(67, 71, 67);
   
}

void ui::render() {
    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);



    ImGui::Begin(window_title, &globals.active, window_flags);
    {
       DoStyle();
       
        if (ImGui::BeginTabBar("CheatMenuBase"))
        {
            
            
            
            if (ImGui::BeginTabItem("Tab-1"))
            {
                static bool c1 = false;
                ImGui::BulletText("First Tab LoL");

            
                ImGui::Checkbox("Free Robux Mod", &c1);
               

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Tab-2"))
            {
                
                static TextEditor editor;
               
                    if (ImGui::TreeNode("TextEditor"))
                        
                {
                    //Pro Skid Tip: 
                     //You can remove the Text editor simply by removing the lines of code under this comment
                       
                        editor.Render("##EditorWindow");
                        
                    editor.SetShowWhitespaces(false);
                    editor.SetReadOnly(false);
                    editor.SetPalette(TextEditor::GetDarkPalette());
                    editor.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());

                    ImGui::TreePop();
                    
                }
               
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Tab-3"))
            {

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Tab-4"))
            {

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Tab-5"))
            {

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Tab-6"))
            {

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Style Editor"))
            {
                ImGui::ShowStyleEditor();

                ImGui::EndTabItem();
                              }

                                    ImGui::EndTabBar();
       }
        
    }
    ImGui::End();
}




void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;
	
    // colors
    ImGui::StyleColorsDark();

	if (window_pos.x == 0) {
		RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;

		// init images here
	}
}