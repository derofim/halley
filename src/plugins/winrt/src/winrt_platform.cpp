#include "winrt_system.h"
#ifdef WINDOWS_STORE

#include "winrt_platform.h"
#include "winrt_http.h"
#include "xbl_manager.h"
using namespace Halley;


WinRTPlatform::WinRTPlatform(WinRTSystem* system)
	: system(system)
{
}

void WinRTPlatform::init()
{
	xbl = std::make_shared<XBLManager>();
	xbl->init();
}

void WinRTPlatform::deInit()
{
	xbl.reset();
}

void WinRTPlatform::update() {}

std::unique_ptr<HTTPRequest> WinRTPlatform::makeHTTPRequest(const String& method, const String& url)
{
	return std::make_unique<WinRTHTTPRequest>(method, url);
}

bool WinRTPlatform::canProvideAuthToken() const
{
	return true;
}

Future<AuthTokenResult> WinRTPlatform::getAuthToken(const AuthTokenParameters& parameters)
{
	return xbl->getAuthToken(parameters);
}

bool WinRTPlatform::canProvideCloudSave() const
{
	return false;
}

std::shared_ptr<ISaveData> WinRTPlatform::getCloudSaveContainer(const String& containerName)
{
	return xbl->getSaveContainer(containerName);
}

#endif
