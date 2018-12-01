/*
*  Project     Nintendo Extension Controller Library
*  @author     David Madison
*  @link       github.com/dmadison/NintendoExtensionCtrl
*  @license    LGPLv3 - Copyright (c) 2018 David Madison
*
*  This file is part of the Nintendo Extension Controller Library.
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXC_NESMiniController_h
#define NXC_NESMiniController_h

#include "ClassicController.h"

namespace NintendoExtensionCtrl {
	class NESMiniController_Data : protected ClassicController_Data {
	public:
		// The NES Mini controller reports itself as a Classic Controller
		// and functions identically. This class includes data maps for
		// the improperly reporting knockoff NES controllers
		struct Maps : public ClassicController_Data::Maps {
			constexpr static BitMap  Knockoff_DpadUp = { 7, 0 };
			constexpr static BitMap  Knockoff_DpadDown = { 6, 6 };
			constexpr static BitMap  Knockoff_DpadLeft = { 7, 1 };
			constexpr static BitMap  Knockoff_DpadRight = { 6, 7 };

			constexpr static BitMap  Knockoff_ButtonStart = { 6, 2 };
			constexpr static BitMap  Knockoff_ButtonSelect = { 6, 4 };

			constexpr static BitMap  Knockoff_ButtonA = { 7, 4 };
			constexpr static BitMap  Knockoff_ButtonB = { 7, 6 };
		};

		using ClassicController_Data::ClassicController_Data;  // Reuse constructor
		using ClassicController_Data::id;  // Share ID

		boolean dpadUp() const;
		boolean dpadDown() const;
		boolean dpadLeft() const;
		boolean dpadRight() const;

		boolean buttonA() const;
		boolean buttonB() const;

		boolean buttonStart() const;
		boolean buttonSelect() const;

		void printDebug(Print& output = NXC_SERIAL_DEFAULT) const;

		boolean isKnockoff() const;
	};
}

typedef NintendoExtensionCtrl::BuildControllerClass
	<NintendoExtensionCtrl::NESMiniController_Data>	NESMiniController;

#endif
