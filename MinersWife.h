#pragma once

#include "pch.h"

#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinersWifeOwnedStates.h"

#include "FSM\StateMachine.h"



class MinersWife : public BaseGameEntity
{
private:

	//an instance of the state machine class
	StateMachine<MinersWife>* m_pStateMachine;

	location_type   m_Location;

	//is she presently cooking?
	bool            m_bCooking;


public:

	MinersWife(int id) :m_Location(shack),
		m_bCooking(false),
		BaseGameEntity(id)

	{
		//set up the state machine
		m_pStateMachine = new StateMachine<MinersWife>(this);

		m_pStateMachine->SetCurrentState(DoHouseWork::Instance());

		m_pStateMachine->SetGlobalState(WifesGlobalState::Instance());
	}

	~MinersWife() { delete m_pStateMachine; }


	//this must be implemented
	void          Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);

	StateMachine<MinersWife>* GetFSM()const { return m_pStateMachine; }

	//----------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(location_type loc) { m_Location = loc; }

	bool          Cooking()const { return m_bCooking; }
	void          SetCooking(bool val) { m_bCooking = val; }

};

