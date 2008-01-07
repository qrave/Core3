/*
Copyright (C) 2007 <SWGEmu>
 
This File is part of Core3.
 
This program is free software; you can redistribute 
it and/or modify it under the terms of the GNU Lesser 
General Public License as published by the Free Software
Foundation; either version 2 of the License, 
or (at your option) any later version.
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU Lesser General Public License for
more details.
 
You should have received a copy of the GNU Lesser General 
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
Linking Engine3 statically or dynamically with other modules 
is making a combined work based on Engine3. 
Thus, the terms and conditions of the GNU Lesser General Public License 
cover the whole combination.
 
In addition, as a special exception, the copyright holders of Engine3 
give you permission to combine Engine3 program with free software 
programs or libraries that are released under the GNU LGPL and with 
code included in the standard release of Core3 under the GNU LGPL 
license (or modified versions of such code, with unchanged license). 
You may copy and distribute such a system following the terms of the 
GNU LGPL for Engine3 and the licenses of the other code concerned, 
provided that you include the source code of that other code when 
and as the GNU LGPL requires distribution of source code.
 
Note that people who make modified versions of Engine3 are not obligated 
to grant this special exception for their modified versions; 
it is their choice whether to do so. The GNU Lesser General Public License 
gives permission to release a modified version without this exception; 
this exception also makes it possible to release a modified version 
which carries forward this exception.
*/

#ifndef BAZAARMANAGERIMPLEMENTATION_H_
#define BAZAARMANAGERIMPLEMENTATION_H_

#include "engine/engine.h"

#include "BazaarManager.h"

#include "BazaarTerminals.h"
#include "BazaarPlanetManager.h"

#include "../../objects/player/Player.h"

#define ARMOR 				0x00000100
#define BUILDING 			0x00000200
#define ENTITY				0x00000400
#define DATA				0x00000800
#define INSTALLATION		0x00001000
#define MISC				0x00002000
#define TOOL				0x00008000
#define WEAPON				0x00020000
#define COMPONENT			0x00040000
#define WEAPONPOWERUP		0x00080000
#define ARMORPOWERUP		0x00100000
#define JEWELRY				0x00200000
#define RESOURCECONTAINER	0x00400000
#define	DEED				0x00800000
#define CLOTHING			0x01000000
#define SHIPCOMPONENT		0x40000000

class BazaarManagerImplementation : public BazaarManagerServant, public Mutex {
	BazaarPlanetManager* bazaarPlanets[10];
	BazaarTerminals* bazaarTerminals;
	
public:
	BazaarManagerImplementation(ZoneServer* server);
	
	void newBazaarRequest(long bazaarID, Player* player, int planet);
	bool isBazaarTerminal(long objectID);
	
	void addInstantItem(Player* player, long objectid, long bazaarid, string& description, int price);
	void addAuctionItem(Player* player, long objectid, long bazaarid, string& description, int price, int duration);
	void getBazaarData(Player* player, long objectid, int screen, int extent, int category, int count);
};

#endif /*BAZAARMANAGERIMPLEMENTATION_H_*/
