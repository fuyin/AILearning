#pragma once

#include <string>

enum message_type
{
	Msg_HiHoneyInHome,
	Msg_StewReady,
};

inline std::string MsgToStr(message_type mes_type)
{
	switch (mes_type)
	{
	case Msg_HiHoneyInHome:
		return "HiHoneyInHome";
		break;
	case Msg_StewReady:
		return "StewReady";
		break;
	default:
		return "not recognized";
		break;
	}
}