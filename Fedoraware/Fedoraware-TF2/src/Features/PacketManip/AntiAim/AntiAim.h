#pragma once
#include "../../Feature.h"
#include "../../Aimbot/AimbotGlobal/AimbotGlobal.h"

class CCAntiAim {
private:
	// utils
	inline void FakeShotAngles(CUserCmd* pCmd);
	inline void Keybinds();

	//	logic
	float EdgeDistance(const float flEdgeRayYaw, CBaseEntity* pEntity);
	inline bool ShouldAntiAim(CBaseEntity* pLocal);

	// angles
	inline float CalculateCustomRealPitch(const float flWishPitch, const bool bFakeDown);
	inline float GetPitch(const int iFake, const int iReal, const float flCurPitch);
	inline float GetYawOffset(const int iIndex, const bool bFake);
	float GetBaseYaw(int iMode, CBaseEntity* pLocal, CUserCmd* pCmd);

	float flBaseYaw = 0.f;
	float flFakeOffset = 0.f;
	float flRealOffset = 0.f;
	bool bInvert = false;
	
public:
	Vec2 vFakeAngles{};
	Vec2 vRealAngles{};
	bool bMovement = false;
	bool bSendingReal = false;	//	for leg jitter

	bool GetEdge(const float flEdgeOrigYaw, CBaseEntity* pEntity);
	void Run(CUserCmd* pCmd, bool* pSendPacket);
};

ADD_FEATURE(CCAntiAim, AntiAim)