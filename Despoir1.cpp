#include "pch.h"
#include <iostream>

#include "misc\ConsoleUtils.h"

#include "EntityManager.h"
#include "EntityNames.h"

#include "Miner.h"
#include "MinersWife.h"

#include "MessageDispatcher.h"


int main()
{
    std::cout << "Hello World!\n"; 

	Miner* Bob = new Miner(ent_Miner_Bob);
	MinersWife* Elsa = new MinersWife(ent_Elsa);

	//register them with the entity manager
	EntityMgr->RegisterEntity(Bob);
	EntityMgr->RegisterEntity(Elsa);

	for (int i = 0; i < 30; ++i)
	{
		Bob->Update();
		Elsa->Update();

		//dispatch any delayed messages
		Dispatch->DispatchDelayedMessages();

		Sleep(800);
	}

	delete Bob;

	PressAnyKeyToContinue();
}
