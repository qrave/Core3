/*
 *	server/zone/objects/player/PlayerCreature.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLAYERCREATURE_H_
#define PLAYERCREATURE_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneClientSession;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerObject;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObject;

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class Container;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tool {

class CraftingTool;

} // namespace tool
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tool;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerDisconnectEvent;

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerRecoveryEvent;

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;

namespace server {
namespace chat {
namespace room {

class ChatRoom;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class WeaponObject;

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

namespace server {
namespace zone {
namespace objects {
namespace group {

class GroupObject;

} // namespace group
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::group;

namespace server {
namespace zone {
namespace objects {
namespace waypoint {

class WaypointObject;

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

namespace server {
namespace zone {
namespace objects {
namespace area {

class ActiveArea;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace professions {

class SkillBox;

} // namespace professions
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::professions;

namespace server {
namespace zone {
namespace packets {

class MessageCallback;

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;

namespace server {
namespace zone {
namespace objects {
namespace structure {

class StructureObject;

} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure;

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureFlag.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/LastMovementUpdatesBuffer.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "system/util/VectorMap.h"

#include "engine/util/QuadTreeEntry.h"

#include "engine/util/Vector3.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/lua/LuaObject.h"

#include "system/lang/ref/Reference.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature : public CreatureObject {
public:
	static const int ONLINE = 1;

	static const int OFFLINE = 2;

	static const int LINKDEAD = 3;

	static const int LOGGINGIN = 4;

	static const int LOGGINGOUT = 5;

	static const int LOADING = 6;

	PlayerCreature();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void notifyLoadFromDatabase();

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void reload(ZoneClientSession* client);

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void insertToBuilding(BuildingObject* building);

	void removeFromBuilding(BuildingObject* building);

	void updateToDatabase();

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose = true);

	void sendBadgesResponseTo(PlayerCreature* player);

	void unloadSpawnedChildren();

	bool isAggressiveTo(PlayerCreature* object);

	void sendExecuteConsoleCommand(const String& command);

	bool isAttackableBy(CreatureObject* object);

	int canAddObject(SceneObject* object, int containmentType, String& errorDescription);

	int notifyObjectInserted(SceneObject* object);

	int notifyObjectRemoved(SceneObject* object);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	void setCombatState();

	void setBadge(unsigned int badge);

	void awardBadge(unsigned int badge);

	int getNumBadges();

	int getBadgeTypeCount(byte type);

	bool isFirstIncapacitationExpired();

	void resetIncapacitationCounter();

	void resetFirstIncapacitationTime();

	void updateIncapacitationCounter();

	bool isFirstIncapacitation();

	byte getIncapacitationCounter();

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String getLastNpcConvStr();

	String getLastNpcConvMessStr();

	String getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	int countLastNpcConvOptions();

	void clearLastNpcConvOptions();

	void setSpawnedBlueFrog();

	bool hasSpawnedBlueFrog();

	void addToConsentList(const String& name);

	bool hasInConsentList(const String& name);

	void removeFromConsentList(const String& name);

	String getConsentName(int i);

	int getConsentListSize();

	void addToDuelList(PlayerCreature* targetPlayer);

	void removeFromDuelList(PlayerCreature* targetPlayer);

	PlayerCreature* getDuelListObject(int index);

	bool requestedDuelTo(PlayerCreature* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	void notifySceneReady();

	SortedVector<unsigned long long>* getPersistentMessages();

	void addPersistentMessage(unsigned long long id);

	void dropPersistentMessage(unsigned long long id);

	PlayerObject* getPlayerObject();

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	unsigned int getAccountID();

	ZoneClientSession* getClient();

	byte getRaceID();

	unsigned long long getSavedParentID();

	int getSavedZoneID();

	String getFirstName();

	String getLastName();

	void setSavedParentID(unsigned long long id);

	void setSavedZoneID(int id);

	void setSkillPoints(int points);

	void addSkillPoints(int points);

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setConversatingCreature(CreatureObject* creature);

	void setClientLastMovementStamp(unsigned int stamp);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void setAccountID(unsigned int id);

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	int getSkillPoints();

	unsigned int getNewSuiBoxID(unsigned int type);

	bool hasSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void removeSuiBox(unsigned int boxID, bool closeWindowToClient = false);

	void removeSuiBoxType(unsigned int windowType);

	bool hasSuiBoxWindowType(unsigned int windowType);

	void closeSuiWindowType(unsigned int windowType);

	SuiBox* getSuiBoxFromWindowType(unsigned int windowType);

	void addSuiBox(SuiBox* sui);

	int getLotsRemaining();

	void setLotsRemaining(int lots);

	int getFactionStatus();

	UnicodeString getBiography();

	unsigned int getClientLastMovementStamp();

	void setSurveyTool(SurveyTool* tool);

	SurveyTool* getSurveyTool();

	void clearTradeContainer();

	void setTeachingOrLearning(bool value);

	bool isTeachingOrLearning();

	WaypointObject* getSurveyWaypoint();

	CreatureObject* getConversatingCreature();

	int getCenteredBonus();

	void setCenteredBonus(int bonus);

	TradeContainer* getTradeContainer();

	bool hasBadge(unsigned int badge);

	CraftingTool* getLastCraftingToolUsed();

	void setLastCraftingToolUsed(CraftingTool* tool);

	bool isInvisible();

	LastMovementUpdatesBuffer* getLastMovementUpdates();

	void setInvisible(bool invis);

	BuildingObject* getDeclaredResidence();

	void setDeclaredResidence(BuildingObject* residence);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PlayerCreature(DummyConstructorParameter* param);

	virtual ~PlayerCreature();

	String _return_getConsentName;
	String _return_getFirstName;
	String _return_getLastName;
	String _return_getLastNpcConvMessStr;
	String _return_getLastNpcConvOption;
	String _return_getLastNpcConvStr;

	UnicodeString _return_getBiography;

	friend class PlayerCreatureHelper;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreatureImplementation : public CreatureObjectImplementation {
protected:
	ManagedReference<ZoneClientSession* > owner;

	int savedZoneID;

	unsigned long long savedParentID;

	int onlineStatus;

	ManagedWeakReference<BuildingObject* > declaredResidence;

	Time logoutTimeStamp;

	unsigned int clientLastMovementStamp;

	unsigned int accountID;

	bool invisible;

	unsigned int suiBoxNextID;

	String raceFile;

	byte raceID;

	String startingLocation;

	String startingProfession;

	UnicodeString biography;

	int lotsRemaining;

	PlayerDisconnectEvent* disconnectEvent;

	PlayerRecoveryEvent* recoveryEvent;

	int skillPoints;

	bool teachingOrLearning;

	Badges badges;

	SortedVector<ManagedReference<ChatRoom* > > chatRooms;

	byte incapacitationCounter;

	VectorMap<unsigned int, ManagedReference<SuiBox* > > suiBoxes;

	int pvpRating;

	int factionStatus;

	SortedVector<unsigned long long> persistentMessages;

	SortedVector<ManagedReference<PlayerCreature* > > duelList;

	ManagedWeakReference<SurveyTool* > surveyTool;

	ManagedReference<CraftingTool* > lastCraftingToolUsed;

	bool spawnedBlueFrog;

	SortedVector<String> consentList;

	String lastNpcConvoMessage;

	String lastNpcConvo;

	Vector<String> lastNpcConvoOptions;

	ManagedWeakReference<CreatureObject* > conversatingCreature;

	int centeredBonus;

	TradeContainer tradeContainer;

	LastMovementUpdatesBuffer lastMovementUpdates;

public:
	static const int ONLINE = 1;

	static const int OFFLINE = 2;

	static const int LINKDEAD = 3;

	static const int LOGGINGIN = 4;

	static const int LOGGINGOUT = 5;

	static const int LOADING = 6;

	PlayerCreatureImplementation();

	PlayerCreatureImplementation(DummyConstructorParameter* param);

	void finalize();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void notifyLoadFromDatabase();

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void reload(ZoneClientSession* client);

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void insertToBuilding(BuildingObject* building);

	void removeFromBuilding(BuildingObject* building);

	void updateToDatabase();

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose = true);

	void sendBadgesResponseTo(PlayerCreature* player);

	void unloadSpawnedChildren();

	bool isAggressiveTo(PlayerCreature* object);

	void sendExecuteConsoleCommand(const String& command);

	bool isAttackableBy(CreatureObject* object);

	int canAddObject(SceneObject* object, int containmentType, String& errorDescription);

	int notifyObjectInserted(SceneObject* object);

	int notifyObjectRemoved(SceneObject* object);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	void setCombatState();

	void setBadge(unsigned int badge);

	void awardBadge(unsigned int badge);

	int getNumBadges();

	int getBadgeTypeCount(byte type);

	bool isFirstIncapacitationExpired();

	void resetIncapacitationCounter();

	void resetFirstIncapacitationTime();

	void updateIncapacitationCounter();

	bool isFirstIncapacitation();

	byte getIncapacitationCounter();

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String getLastNpcConvStr();

	String getLastNpcConvMessStr();

	String getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	int countLastNpcConvOptions();

	void clearLastNpcConvOptions();

	void setSpawnedBlueFrog();

	bool hasSpawnedBlueFrog();

	void addToConsentList(const String& name);

	bool hasInConsentList(const String& name);

	void removeFromConsentList(const String& name);

	String getConsentName(int i);

	int getConsentListSize();

	void addToDuelList(PlayerCreature* targetPlayer);

	void removeFromDuelList(PlayerCreature* targetPlayer);

	PlayerCreature* getDuelListObject(int index);

	bool requestedDuelTo(PlayerCreature* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	void notifySceneReady();

	SortedVector<unsigned long long>* getPersistentMessages();

	void addPersistentMessage(unsigned long long id);

	void dropPersistentMessage(unsigned long long id);

	PlayerObject* getPlayerObject();

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	unsigned int getAccountID();

	ZoneClientSession* getClient();

	byte getRaceID();

	unsigned long long getSavedParentID();

	int getSavedZoneID();

	String getFirstName();

	String getLastName();

	void setSavedParentID(unsigned long long id);

	void setSavedZoneID(int id);

	void setSkillPoints(int points);

	void addSkillPoints(int points);

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setConversatingCreature(CreatureObject* creature);

	void setClientLastMovementStamp(unsigned int stamp);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void setAccountID(unsigned int id);

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	int getSkillPoints();

	unsigned int getNewSuiBoxID(unsigned int type);

	bool hasSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void removeSuiBox(unsigned int boxID, bool closeWindowToClient = false);

	void removeSuiBoxType(unsigned int windowType);

	bool hasSuiBoxWindowType(unsigned int windowType);

	void closeSuiWindowType(unsigned int windowType);

	SuiBox* getSuiBoxFromWindowType(unsigned int windowType);

	void addSuiBox(SuiBox* sui);

	int getLotsRemaining();

	void setLotsRemaining(int lots);

	int getFactionStatus();

	UnicodeString getBiography();

	unsigned int getClientLastMovementStamp();

	void setSurveyTool(SurveyTool* tool);

	SurveyTool* getSurveyTool();

	void clearTradeContainer();

	void setTeachingOrLearning(bool value);

	bool isTeachingOrLearning();

	WaypointObject* getSurveyWaypoint();

	CreatureObject* getConversatingCreature();

	int getCenteredBonus();

	void setCenteredBonus(int bonus);

	TradeContainer* getTradeContainer();

	bool hasBadge(unsigned int badge);

	CraftingTool* getLastCraftingToolUsed();

	void setLastCraftingToolUsed(CraftingTool* tool);

	bool isInvisible();

	LastMovementUpdatesBuffer* getLastMovementUpdates();

	void setInvisible(bool invis);

	BuildingObject* getDeclaredResidence();

	void setDeclaredResidence(BuildingObject* residence);

	PlayerCreature* _this;

	operator const PlayerCreature*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~PlayerCreatureImplementation();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class PlayerCreature;
};

class PlayerCreatureAdapter : public CreatureObjectAdapter {
public:
	PlayerCreatureAdapter(PlayerCreatureImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializeTransientMembers();

	void notifyLoadFromDatabase();

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void reload(ZoneClientSession* client);

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void insertToBuilding(BuildingObject* building);

	void removeFromBuilding(BuildingObject* building);

	void updateToDatabase();

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose);

	void sendBadgesResponseTo(PlayerCreature* player);

	void unloadSpawnedChildren();

	bool isAggressiveTo(PlayerCreature* object);

	void sendExecuteConsoleCommand(const String& command);

	bool isAttackableBy(CreatureObject* object);

	int canAddObject(SceneObject* object, int containmentType, String& errorDescription);

	int notifyObjectInserted(SceneObject* object);

	int notifyObjectRemoved(SceneObject* object);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	void setCombatState();

	void setBadge(unsigned int badge);

	void awardBadge(unsigned int badge);

	int getNumBadges();

	int getBadgeTypeCount(byte type);

	bool isFirstIncapacitationExpired();

	void resetIncapacitationCounter();

	void resetFirstIncapacitationTime();

	void updateIncapacitationCounter();

	bool isFirstIncapacitation();

	byte getIncapacitationCounter();

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String getLastNpcConvStr();

	String getLastNpcConvMessStr();

	String getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	int countLastNpcConvOptions();

	void clearLastNpcConvOptions();

	void setSpawnedBlueFrog();

	bool hasSpawnedBlueFrog();

	void addToConsentList(const String& name);

	bool hasInConsentList(const String& name);

	void removeFromConsentList(const String& name);

	String getConsentName(int i);

	int getConsentListSize();

	void addToDuelList(PlayerCreature* targetPlayer);

	void removeFromDuelList(PlayerCreature* targetPlayer);

	PlayerCreature* getDuelListObject(int index);

	bool requestedDuelTo(PlayerCreature* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	void notifySceneReady();

	void addPersistentMessage(unsigned long long id);

	void dropPersistentMessage(unsigned long long id);

	PlayerObject* getPlayerObject();

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	unsigned int getAccountID();

	ZoneClientSession* getClient();

	byte getRaceID();

	unsigned long long getSavedParentID();

	int getSavedZoneID();

	String getFirstName();

	String getLastName();

	void setSavedParentID(unsigned long long id);

	void setSavedZoneID(int id);

	void setSkillPoints(int points);

	void addSkillPoints(int points);

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setConversatingCreature(CreatureObject* creature);

	void setClientLastMovementStamp(unsigned int stamp);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void setAccountID(unsigned int id);

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	int getSkillPoints();

	unsigned int getNewSuiBoxID(unsigned int type);

	bool hasSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void removeSuiBox(unsigned int boxID, bool closeWindowToClient);

	void removeSuiBoxType(unsigned int windowType);

	bool hasSuiBoxWindowType(unsigned int windowType);

	void closeSuiWindowType(unsigned int windowType);

	SuiBox* getSuiBoxFromWindowType(unsigned int windowType);

	void addSuiBox(SuiBox* sui);

	int getLotsRemaining();

	void setLotsRemaining(int lots);

	int getFactionStatus();

	UnicodeString getBiography();

	unsigned int getClientLastMovementStamp();

	void setSurveyTool(SurveyTool* tool);

	SurveyTool* getSurveyTool();

	void setTeachingOrLearning(bool value);

	WaypointObject* getSurveyWaypoint();

	CreatureObject* getConversatingCreature();

	int getCenteredBonus();

	void setCenteredBonus(int bonus);

	bool hasBadge(unsigned int badge);

	CraftingTool* getLastCraftingToolUsed();

	void setLastCraftingToolUsed(CraftingTool* tool);

	bool isInvisible();

	void setInvisible(bool invis);

	BuildingObject* getDeclaredResidence();

	void setDeclaredResidence(BuildingObject* residence);

protected:
	String _param0_sendExecuteConsoleCommand__String_;
	String _param2_canAddObject__SceneObject_int_String_;
	String _param0_setLastNpcConvStr__String_;
	String _param0_setLastNpcConvMessStr__String_;
	String _param0_addLastNpcConvOptions__String_;
	String _param0_addToConsentList__String_;
	String _param0_hasInConsentList__String_;
	String _param0_removeFromConsentList__String_;
	UnicodeString _param0_setBiography__UnicodeString_;
};

class PlayerCreatureHelper : public DistributedObjectClassHelper, public Singleton<PlayerCreatureHelper> {
	static PlayerCreatureHelper* staticInitializer;

public:
	PlayerCreatureHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerCreatureHelper>;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#endif /*PLAYERCREATURE_H_*/
