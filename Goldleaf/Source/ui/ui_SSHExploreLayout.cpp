/*

    Goldleaf - Multipurpose homebrew tool for Nintendo Switch
    Copyright (C) 2018-2020  XorTroll

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <ui/ui_SSHExploreLayout.hpp>
#include <ui/ui_MainApplication.hpp>

extern ui::MainApplication::Ref global_app;
extern cfg::Settings global_settings;

namespace ui
{
    SSHExploreLayout::SSHExploreLayout() : pu::ui::Layout()
    {
        this->pathsMenu = pu::ui::elm::Menu::New(0, 160, 1280, global_settings.custom_scheme.Base, global_settings.menu_item_size, (560 / global_settings.menu_item_size));
        this->pathsMenu->SetOnFocusColor(global_settings.custom_scheme.BaseFocus);
        global_settings.ApplyScrollBarColor(this->pathsMenu);
        this->Add(this->pathsMenu);
    }

    void SSHExploreLayout::ssh_Click()
    {
    }

    void SSHExploreLayout::UpdateMenu()
    {
        //this->mountsMenu->Clear();
        auto DirMenuItem = pu::ui::elm::MenuItem::New("dir");
        DirMenuItem->SetIcon(global_settings.PathForResource("/FileSystem/Directory.png"));
        DirMenuItem->SetColor(global_settings.custom_scheme.Text);
        DirMenuItem->AddOnClick(std::bind(&SSHExploreLayout::ssh_Click, this));
        this->pathsMenu->AddItem(DirMenuItem);
        auto FileMenuItem = pu::ui::elm::MenuItem::New("dir");
        FileMenuItem->SetIcon(global_settings.PathForResource("/FileSystem/File.png"));
        FileMenuItem->SetColor(global_settings.custom_scheme.Text);
        FileMenuItem->AddOnClick(std::bind(&SSHExploreLayout::ssh_Click, this));
        this->pathsMenu->AddItem(FileMenuItem);
    }
}
