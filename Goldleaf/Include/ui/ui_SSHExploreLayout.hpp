
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

#pragma once
#include <ui/ui_Includes.hpp>
#include <pu/Plutonium>

namespace ui
{
    class SSHExploreLayout : public pu::ui::Layout
    {
        public:
            SSHExploreLayout();
            PU_SMART_CTOR(SSHExploreLayout)

            void UpdatePaths();
            void UpdateMenu();
            void ssh_Click();
            void path_Click();
            //void fileSelect_Click();
        private:
            std::vector<String> names;
            std::vector<String> paths;
            pu::ui::elm::Menu::Ref pathsMenu;
            std::vector<pu::ui::elm::MenuItem::Ref> pathItems;
    };
}
