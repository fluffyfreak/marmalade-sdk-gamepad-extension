/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "gamepad.h"


// For MIPs (and WP8) platform we do not have asm code for stack switching 
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef     uint32(*gamepadGetNumDevices_t)();
typedef     uint32(*gamepadGetDeviceId_t)(uint32 index);
typedef     uint32(*gamepadGetNumAxes_t)(uint32 index);
typedef     uint32(*gamepadGetNumButtons_t)(uint32 index);
typedef     uint32(*gamepadGetButtons_t)(uint32 index);
typedef      int32(*gamepadGetAxis_t)(uint32 index, uint32 axisIndex);
typedef     uint32(*gamepadIsPointOfViewAvailable_t)(uint32 index);
typedef      int32(*gamepadGetPointOfViewAngle_t)(uint32 index);
typedef       void(*gamepadRegisterCallback_t)(s3eCallback callback, void* userData);
typedef       void(*gamepadUnregisterCallback_t)(s3eCallback callback);
typedef       void(*gamepadUpdate_t)();

/**
 * struct that gets filled in by gamepadRegister
 */
typedef struct gamepadFuncs
{
    gamepadGetNumDevices_t m_gamepadGetNumDevices;
    gamepadGetDeviceId_t m_gamepadGetDeviceId;
    gamepadGetNumAxes_t m_gamepadGetNumAxes;
    gamepadGetNumButtons_t m_gamepadGetNumButtons;
    gamepadGetButtons_t m_gamepadGetButtons;
    gamepadGetAxis_t m_gamepadGetAxis;
    gamepadIsPointOfViewAvailable_t m_gamepadIsPointOfViewAvailable;
    gamepadGetPointOfViewAngle_t m_gamepadGetPointOfViewAngle;
    gamepadRegisterCallback_t m_gamepadRegisterCallback;
    gamepadUnregisterCallback_t m_gamepadUnregisterCallback;
    gamepadUpdate_t m_gamepadUpdate;
} gamepadFuncs;

static gamepadFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xe6a02e94, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: gamepad");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xe6a02e94, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool gamepadAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

uint32 gamepadGetNumDevices()
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[0] func: gamepadGetNumDevices"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    uint32 ret = g_Ext.m_gamepadGetNumDevices();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

uint32 gamepadGetDeviceId(uint32 index)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[1] func: gamepadGetDeviceId"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    uint32 ret = g_Ext.m_gamepadGetDeviceId(index);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

uint32 gamepadGetNumAxes(uint32 index)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[2] func: gamepadGetNumAxes"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    uint32 ret = g_Ext.m_gamepadGetNumAxes(index);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

uint32 gamepadGetNumButtons(uint32 index)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[3] func: gamepadGetNumButtons"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    uint32 ret = g_Ext.m_gamepadGetNumButtons(index);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

uint32 gamepadGetButtons(uint32 index)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[4] func: gamepadGetButtons"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    uint32 ret = g_Ext.m_gamepadGetButtons(index);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int32 gamepadGetAxis(uint32 index, uint32 axisIndex)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[5] func: gamepadGetAxis"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int32 ret = g_Ext.m_gamepadGetAxis(index, axisIndex);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

uint32 gamepadIsPointOfViewAvailable(uint32 index)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[6] func: gamepadIsPointOfViewAvailable"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    uint32 ret = g_Ext.m_gamepadIsPointOfViewAvailable(index);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int32 gamepadGetPointOfViewAngle(uint32 index)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[7] func: gamepadGetPointOfViewAngle"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int32 ret = g_Ext.m_gamepadGetPointOfViewAngle(index);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void gamepadRegisterCallback(s3eCallback callback, void* userData)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[8] func: gamepadRegisterCallback"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_gamepadRegisterCallback(callback, userData);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void gamepadUnregisterCallback(s3eCallback callback)
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[9] func: gamepadUnregisterCallback"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_gamepadUnregisterCallback(callback);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void gamepadUpdate()
{
    IwTrace(GAMEPAD_VERBOSE, ("calling gamepad[10] func: gamepadUpdate"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_gamepadUpdate();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
