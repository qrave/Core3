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

#ifndef TANGIBLEOBJECTIMPLEMENTATION_H_
#define TANGIBLEOBJECTIMPLEMENTATION_H_

#include "TangibleObject.h"
#include "CustomizationVariables.h"
#include "FactionPointsList.h"

class CreatureObject;
class TangibleObjectImplementation : public TangibleObjectServant {
protected:
	CustomizationVariables* customizationString;
	FactionPointsList* factionPointsList;

	Vector<ManagedReference<TangibleObject> > defenderList;

	uint32 pvpStatusBitmask;
	uint32 faction;

	uint32 updateCounterMovement;
	uint32 updateCounterDefenders;

	uint32 optionsBitmask;
	uint32 objectCount;

	float conditionDamage;
	uint32 conditionMax;

	uint8 unknownByte;

public:
	//Game Object Types
	// Generic
	static const int MISC = 0x2000;
	static const int AMMUNITION = 0x2001;
	static const int CHEMICAL = 0x2002;
	static const int CONTAINER = 0x2005;
	static const int CRAFTINGSTATION = 0x2006;
	static const int ELECTRONICS = 0x2008;
	static const int FLORA = 0x2009;
	static const int FOOD = 0x200A;
	static const int FURNITURE = 0x200B;
	static const int INSTRUMENT = 0x200C;
	static const int PHARMACEUTICAL = 0x200D;
	static const int SIGN = 0x200F;
	static const int COUNTER = 0x2010;
	static const int FACTORYCRATE = 0x2011;
	static const int TRAVELTICKET = 0x2012;
	static const int GENERICITEM = 0x2013;
	static const int TRAP = 0x2014;
	static const int WEARABLECONTAINER = 0x2015;
	static const int FISHINGPOLE = 0x2016;
	static const int FISHINGBAIT = 0x2017;
	static const int DRINK = 0x2018;
	static const int FIREWORK = 0x2019;
	static const int ITEM = 0x201A;
	static const int PETMEDECINE = 0x201B;
	static const int FIREWORKSHOW = 0x201C;
	static const int CLOTHINGATTACHMENT = 0x201D;
	static const int LIVESAMPLE = 0x201E;
	static const int ARMORATTACHMENT = 0x201F;
	static const int COMMUNITYCRAFTINGPROJECT = 0x2020;
	static const int CRYSTAL = 0x2021;
	static const int DROIDPROGRAMMINGCHIP = 0x2022;
	static const int ASTEROID = 0x2023;
	static const int PILOTCHAIR = 0x2024;
	static const int OPERATIONSCHAIR = 0x2025;
	static const int TURRETACCESSLADDER = 0x2026;
	static const int CONTAINER2 = 0x2027;
	static const int CAMOKIT = 0x2028;

public:
	TangibleObjectImplementation(uint64 objectid, int type);
	~TangibleObjectImplementation();

	//Saving and loading
	//virtual void serialize(String& str);
	//virtual void deserialize(const String& str);

	//Sending data to client
	//virtual void sendTo(Player* player, bool doclose = true);
	//virtual void sendDestroyTo(Player* player);
	//virtual void sendRadialResponseTo(Player* player);

	//General actions.
	virtual void converseStart(PlayerObject* player);
	virtual void converseRespond(PlayerObject* player);
	virtual void converseResponse(PlayerObject* player);
	virtual void converseStop(PlayerObject* player);
	virtual void loot(PlayerObject* player, bool lootall = true);

	//Object orientation and position.
	virtual void rotate(PlayerObject* player, const String& direction, uint32 degrees = 90);
	virtual void move(PlayerObject* player, const String& direction, uint32 distance = 10);

	//Event handlers.
	virtual void onEquip(CreatureObject* creature);
	virtual void onUnequip(CreatureObject* creature);

	//Setters
	inline void setFactionPointsList(FactionPointsList* fplist) {
		factionPointsList = fplist;
	}

	inline void setOptionsBitmask(uint32 bitmask) {
		optionsBitmask = bitmask;
	}

	inline void setObjectCount(uint32 count) {
		objectCount = count;
	}

	inline void setConditionDamage(float damage) {
		conditionDamage = damage;
	}

	inline void setConditionMax(float max) {
		conditionMax = max;
	}

	//Getters
	inline void getCustomizationString(String& appearance) {
		customizationString->toString(appearance);
	}

	inline uint32 getPvpStatusBitmask() {
		return pvpStatusBitmask;
	}

	inline FactionPointsList* getFactionPointsList() {
		return factionPointsList;
	}

	inline uint32 getFaction() {
		return faction;
	}

	inline uint32 getOptionsBitmask() {
		return optionsBitmask;
	}

	//TODO: This could probably be more accurately named. It represents the value of the number overlaying items in inventory.
	inline uint32 getObjectCount() {
		return objectCount;
	}

	inline float getConditionDamage() {
		return conditionDamage;
	}

	inline float getConditionMax() {
		return conditionMax;
	}

	inline uint32 getMovementUpdateCounter() {
		return updateCounterMovement;
	}

	//TODO: Figure out if this byte has any significance.
	inline uint8 getUnknownByte() {
		return unknownByte;
	}

	inline uint32 getNewMovementUpdateCounter(uint8 count) {
		return (updateCounterMovement += count);
	}

	inline uint32 getNewDefenderUpdateCounter(uint8 count) {
		return (updateCounterDefenders += count);
	}


};

#endif /*TANGIBLEOBJECTIMPLEMENTATION_H_*/
