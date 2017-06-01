#pragma once

#include <map>
#include <cassert>
#include <string>

class BaseGameEntity;

class EntityManager
{
private :
	typedef std::map<int, BaseGameEntity*> EntityMap;
public:
	EntityMap m_EntityMap;
private:

	EntityManager(){}
	~EntityManager(){}
	EntityManager& operator=(const EntityManager &);
	EntityManager(const EntityManager&);

public:

	static EntityManager* Instance();

	void RegisterEntity(BaseGameEntity *newEntity);

	void RemoveEntity(BaseGameEntity* pEntity);

	BaseGameEntity* GetEntityFromID(int id) const;

};
