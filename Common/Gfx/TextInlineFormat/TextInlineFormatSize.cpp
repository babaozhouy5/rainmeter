/*
  Copyright (C) 2015 Brian Ferguson

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

#include "StdAfx.h"
#include "TextInlineFormatSize.h"

namespace Gfx {

TextInlineFormat_Size::TextInlineFormat_Size(const std::wstring& pattern, FLOAT size) :
	TextInlineFormat(pattern),
	m_Size(size)
{
}

TextInlineFormat_Size::~TextInlineFormat_Size()
{
}

void TextInlineFormat_Size::ApplyInlineFormat(IDWriteTextLayout* layout)
{
	if (!layout) return;

	for (const auto& range : GetRanges())
	{
		if (range.length <= 0) continue;

		layout->SetFontSize(m_Size * (4.0f / 3.0f), range);
	}
}

bool TextInlineFormat_Size::CompareAndUpdateProperties(const std::wstring& pattern, FLOAT size)
{
	if (_wcsicmp(GetPattern().c_str(), pattern.c_str()) != 0 || m_Size != size)
	{
		SetPattern(pattern);
		m_Size = size;
		return true;
	}

	return false;
}

}  // namespace Gfx
