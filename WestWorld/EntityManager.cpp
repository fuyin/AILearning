#include "EntityManager.h"
#include "BaseGameEntity.h"


EntityManager* EntityManager::Instance()
{
	static EntityManager *newEntityManager = new EntityManager();
	return newEntityManager;
}

void EntityManager::RegisterEntity(BaseGameEntity *newEntity)
{
	m_EntityMap.insert(std::make_pair(newEntity->ID(), newEntity));
}

void EntityManager::RemoveEntity(BaseGameEntity* pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}

BaseGameEntity* EntityManager::GetEntityFromID(int id) const
{
	EntityMap::const_iterator iter = m_EntityMap.find(id);
	assert((iter != m_EntityMap.end()) && "<EntityManager::GetEntityFromId>: invalid id");

	return iter->second;
}