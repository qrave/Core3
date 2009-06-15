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

#ifndef CREATUREOBJECTMESSAGE4_H_
#define CREATUREOBJECTMESSAGE4_H_

#include "../../packets/BaseLineMessage.h"

#include "../../objects/tangible/creature/CreatureObject.h"

class CreatureObjectMessage4 : public BaseLineMessage {
public:
	CreatureObjectMessage4(CreatureObject* creo)
			: BaseLineMessage(creo->getObjectID(), 0x4352454F, 4, 0x0E) {
		insertFloat(1); //Unknown MovementRatio?
		insertFloat(1); //Unknown MovementRatio?

		//Encumbrances
		insertInt(3); //List Size
		insertInt(creo->getUpdateCounterEncumbrance()); //Update Counter
		insertInt(creo->getHealthEncumbrance()); //Health Encumbrance
		insertInt(creo->getActionEncumbrance()); //Action Encumbrance
		insertInt(creo->getMindEncumbrance());   //Mind Encumbrance

		// skill mods
		insertSkillMods(creo);

		//
		insertFloat(1); //Unknown AccellerationRatio?
		insertFloat(1); //Unknown AccellerationRatio?

		insertLong(creo->getListeningToID()); //Listening to ID

		insertFloat(creo->getSpeed()); //Speed

		insertFloat(1.00625f); //What is this value?

		insertFloat(creo->getTerrainNegotiation());  //Terrain Negotiation

		insertFloat(creo->getTurnRadius()); //Turn radius

		insertFloat(creo->getAcceleration()); //Acceleration
		insertFloat(creo->getDeceleration()); //Deceleration

		insertInt(0); //Unknown ListSize for ?
		insertInt(0); //Unknown UpdateCounter for ?
		//{
		//insertLong(0); //Unknown
		//}

		setSize();
	}

	// TODO: this needs to be cleaner for dealing with values
	void insertSkillMods(CreatureObject* creo) {
		insertInt(0);
		insertInt(0);

		/*
		String skillmod;
		int value;

		creo->creatureSkillMods.resetIterator();

		insertInt(creo->creatureSkillMods.size());
		insertInt(creo->skillModsCounter);

		while (creo->creatureSkillMods.hasNext()) {
			insertByte(0);

			creo->creatureSkillMods.getNextKeyAndValue(skillmod, value);
			insertAscii(skillmod);
			insertInt(value + creo->creatureSkillModBonus.get(skillmod));

			insertInt(0);
		}*/
	}
};

#endif /*CREATUREOBJECTMESSAGE4_H_*/
