/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _SOCKET_MODULE_H_
#define _SOCKET_MODULE_H_

#include "socket_binding.h"

#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDE_SOCKET_API EXPORT
#elif defined(OS_WIN32)
# ifdef TIDE_SOCKET_API_EXPORT
#  define TIDE_SOCKET_API __declspec(dllexport)
# else
#  define TIDE_SOCKET_API __declspec(dllimport)
# endif
# define EXPORT __declspec(dllexport)
#endif


namespace ti 
{
	class TIDE_SOCKET_API SocketModule : public tide::Module
	{
		TIDE_MODULE_CLASS(SocketModule)

	public:
		static std::string GetRootCertPath();

	private:
		AutoPtr<SocketBinding> socketBinding;
	};

}
#endif
