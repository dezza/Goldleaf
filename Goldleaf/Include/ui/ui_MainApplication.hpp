
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
#include <ui/ui_AboutLayout.hpp>
#ifdef ENABLE_acc
#include <ui/ui_AccountLayout.hpp>
#endif
#ifdef ENABLE_nfp
#include <ui/ui_AmiiboDumpLayout.hpp>
#endif
#include <ui/ui_ContentInformationLayout.hpp>
#include <ui/ui_ContentManagerLayout.hpp>
#include <ui/ui_CopyLayout.hpp>
#include <ui/ui_ExploreMenuLayout.hpp>
#include <ui/ui_FileContentLayout.hpp>
#include <ui/ui_InstallLayout.hpp>
#include <ui/ui_MainMenuLayout.hpp>
#include <ui/ui_MemoryLayout.hpp>
#include <ui/ui_PartitionBrowserLayout.hpp>
#include <ui/ui_PCExploreLayout.hpp>
#include <ui/ui_SettingsLayout.hpp>
#include <ui/ui_StorageContentsLayout.hpp>
#include <ui/ui_UnusedTicketsLayout.hpp>
#ifdef ENABLE_dump
#include <ui/ui_TitleDumperLayout.hpp>
#endif
#ifdef ENABLE_net
#include <ui/ui_UpdateLayout.hpp>
#endif
#include <ui/ui_WebBrowserLayout.hpp>

#include <ui/ui_ClickableImage.hpp>

namespace ui
{
    class MainApplication : public pu::ui::Application
    {
        public:
            using Application::Application;
            PU_SMART_CTOR(MainApplication)

            void OnLoad() override;

            void ShowNotification(String Text);
            void UpdateValues();
            void ReturnToMainMenu();
            void LoadMenuData(String Name, std::string ImageName, String TempHead, bool CommonIcon = true);
            void LoadMenuHead(String Head);
            void UnloadMenuData();
            void browser_Input(u64 down, u64 up, u64 held);
            void exploreMenu_Input(u64 down, u64 up, u64 held);
            void pcExplore_Input(u64 down, u64 up, u64 held);
            void fileContent_Input(u64 down, u64 up, u64 held);
            void contentInformation_Input(u64 down, u64 up, u64 held);
            void storageContents_Input(u64 down, u64 up, u64 held);
            void contentManager_Input(u64 down, u64 up, u64 held);
            void unusedTickets_Input(u64 down, u64 up, u64 held);
#ifdef ENABLE_acc
            void account_Input(u64 down, u64 up, u64 held);
#endif
#ifdef ENABLE_nfp
            void amiibo_Input(u64 down, u64 up, u64 held);
#endif
            void settings_Input(u64 down, u64 up, u64 held);
            void memory_Input(u64 down, u64 up, u64 held);
            void webBrowser_Input(u64 down, u64 up, u64 held);
            void about_Input(u64 down, u64 up, u64 held);
#ifdef ENABLE_acc
            void userImage_OnClick();
#endif
            void helpImage_OnClick();
#ifdef ENABLE_acc
            void ReloadUser(AccountUid User);
#endif
            void OnInput(u64 down, u64 up, u64 held);
            MainMenuLayout::Ref &GetMainMenuLayout();
            PartitionBrowserLayout::Ref &GetBrowserLayout();
            FileContentLayout::Ref &GetFileContentLayout();
            CopyLayout::Ref &GetCopyLayout();
            ExploreMenuLayout::Ref &GetExploreMenuLayout();
            PCExploreLayout::Ref &GetPCExploreLayout();
            InstallLayout::Ref &GetInstallLayout();
            ContentInformationLayout::Ref &GetContentInformationLayout();
            StorageContentsLayout::Ref &GetStorageContentsLayout();
            ContentManagerLayout::Ref &GetContentManagerLayout();
#ifdef ENABLE_dump
            TitleDumperLayout::Ref &GetTitleDumperLayout();
#endif
            UnusedTicketsLayout::Ref &GetUnusedTicketsLayout();
#ifdef ENABLE_acc
            AccountLayout::Ref &GetAccountLayout();
#endif
#ifdef ENABLE_nfp
            AmiiboDumpLayout::Ref &GetAmiiboDumpLayout();
#endif
            SettingsLayout::Ref &GetSettingsLayout();
            MemoryLayout::Ref &GetMemoryLayout();
#ifdef ENABLE_net
            UpdateLayout::Ref &GetUpdateLayout();
#endif
            WebBrowserLayout::Ref &GetWebBrowserLayout();
            AboutLayout::Ref &GetAboutLayout();
            
        private:
            u32 preblv;
            bool preisch;
            bool hasusb;
            u32 connstate;
#ifdef ENABLE_acc
            AccountUid seluser;
#endif
            String pretime;
            bool vfirst;
            MainMenuLayout::Ref mainMenu;
            PartitionBrowserLayout::Ref browser;
            FileContentLayout::Ref fileContent;
            CopyLayout::Ref copy;
            ExploreMenuLayout::Ref exploreMenu;
            PCExploreLayout::Ref pcExplore;
#ifdef ENABLE_nsp
            InstallLayout::Ref nspInstall;
#endif
            ContentInformationLayout::Ref contentInformation;
            StorageContentsLayout::Ref storageContents;
            ContentManagerLayout::Ref contentManager;
#ifdef ENABLE_dump
            TitleDumperLayout::Ref titleDump;
#endif
            UnusedTicketsLayout::Ref unusedTickets;
#ifdef ENABLE_acc
            AccountLayout::Ref account;
#endif
#ifdef ENABLE_nfp
            AmiiboDumpLayout::Ref amiibo;
#endif
            SettingsLayout::Ref settings;
            MemoryLayout::Ref memory;
#ifdef ENABLE_net
            UpdateLayout::Ref update;
#endif
            WebBrowserLayout::Ref webBrowser;
            AboutLayout::Ref about;
            pu::ui::elm::Image::Ref baseImage;
            pu::ui::elm::TextBlock::Ref timeText;
            pu::ui::elm::TextBlock::Ref batteryText;
            pu::ui::elm::Image::Ref batteryImage;
            pu::ui::elm::Image::Ref batteryChargeImage;
            pu::ui::elm::Image::Ref menuBanner;
            pu::ui::elm::Image::Ref menuImage;
            pu::ui::elm::Image::Ref usbImage;
            pu::ui::elm::Image::Ref connImage;
            pu::ui::elm::TextBlock::Ref ipText;
            pu::ui::elm::TextBlock::Ref menuNameText;
            pu::ui::elm::TextBlock::Ref menuHeadText;
            ClickableImage::Ref userImage;
            ClickableImage::Ref helpImage;
            pu::ui::extras::Toast::Ref toast;
            std::chrono::time_point<std::chrono::steady_clock> start;
    };

    static const ColorScheme DefaultLight = { { 124, 199, 239, 255 }, { 196, 224, 239, 255 }, { 168, 214, 237, 255 }, { 15, 15, 15, 255 } };
    static const ColorScheme DefaultDark = { { 29, 81, 114, 255 }, { 37, 104, 145, 255 }, { 45, 124, 173, 255 }, { 225, 225, 225, 255 } };

    void UpdateClipboard(String Path);

    void ApplyRandomScheme();
}
