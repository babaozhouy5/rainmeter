/*
  Copyright (C) 2013 Rainmeter Team

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef RM_LIBRARY_CONTEXTMENU_H
#define RM_LIBRARY_CONTEXTMENU_H

#include <Windows.h>

class Skin;

// Handles the creation and display of Rainmeter and skin context menus.
class ContextMenu
{
public:
	ContextMenu();

	ContextMenu(const ContextMenu& other) = delete;
	ContextMenu& operator=(ContextMenu other) = delete;

	bool IsMenuActive() { return m_MenuActive; }

	void ShowMenu(POINT pos, Skin* skin);
	void ShowSkinCustomMenu(POINT pos, Skin* skin);

	static void CreateMonitorMenu(HMENU monitorMenu, Skin* skin);

private:
	static void DisplayMenu(POINT pos, HMENU menu, HWND parentWindow);

	static HMENU CreateSkinMenu(Skin* skin, int index, HMENU menu);
	static void AppendSkinCustomMenu(
		Skin* skin, int index, HMENU menu, bool standaloneMenu);
	static void ChangeSkinIndex(HMENU subMenu, int index);
	
	static void CreateAllSkinsMenu(HMENU skinMenu) { CreateSkinsMenuRecursive(skinMenu, 0, false); }
	static int CreateSkinsMenuRecursive(HMENU skinMenu, int index, bool isFavoriteMenu);

	static void CreateLayoutMenu(HMENU layoutMenu);

	static void CreateFavoritesMenu(HMENU favoriteMenu) { CreateSkinsMenuRecursive(favoriteMenu, 0, true); }

	bool m_MenuActive;
};

#endif
