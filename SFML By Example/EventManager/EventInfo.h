#ifndef EVENTINFO_H
#define EVENTINFO_H

struct EventInfo
{
	EventInfo() { _code = 0; }
	EventInfo(int event) { _code = event; }
	union
	{
		int _code;
	}
};

#endif
