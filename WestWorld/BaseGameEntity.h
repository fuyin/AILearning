#pragma once

class BaseGameEntity {
private :
	int m_iTemplateID;
	static int m_iNextValidId;

	void SetID(int val);

public:
	BaseGameEntity(int val) {
		SetID(val);
	}

	virtual void Update() = 0;

	int ID()const { return m_iTemplateID; }
};