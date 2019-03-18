#pragma once

#include <string>

enum
{
	ent_Miner_Bob,

	ent_Elsa,

	ent_Drunker_Master
};

inline std::string GetNameOfEntity(int n)
{
	switch (n)
	{
	case ent_Miner_Bob:

		return "Miner Bob";

	case ent_Elsa:

		return "Elsa";


	case ent_Drunker_Master:

		return "The Drunker Master";

	default:

		return "UNKNOWN!";
	}
}