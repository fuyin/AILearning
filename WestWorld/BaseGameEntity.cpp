#include "BaseGameEntity.h"
#include "stdafx.h"
#include <cassert>
int BaseGameEntity::m_iNextValidId = 0;

void BaseGameEntity::SetID(int val)
{
	assert((val >= m_iNextValidId) && "<BaseGameEntity::SetID>: invalid ID");

	m_iTemplateID = val;
	m_iNextValidId = m_iTemplateID + 1;
}

