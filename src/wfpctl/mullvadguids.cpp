#include "stdafx.h"
#include "mullvadguids.h"

//static
const GUID &MullvadGuids::Provider()
{
	static const GUID g =
	{
		0x21e1dab8,
		0xb9db,
		0x43c0,
		{ 0xb3, 0x43, 0xeb, 0x93, 0x65, 0xc7, 0xbd, 0xd2 }
	};

	return g;
}

//static
const GUID &MullvadGuids::SublayerBlocking()
{
	static const GUID g =
	{
		0x11d1a31a,
		0xd7fa,
		0x469b,
		{ 0xbc, 0x21, 0xcc, 0xe9, 0x2e, 0x35, 0xfe, 0x90 }
	};

	return g;
}

//static
const GUID &MullvadGuids::SublayerAllowing()
{
	static const GUID g =
	{
		0x843b74f0,
		0xb499,
		0x499a,
		{ 0xac, 0xe3, 0xf9, 0xee, 0xa2, 0x4, 0x89, 0xc1 }
	};

	return g;
}