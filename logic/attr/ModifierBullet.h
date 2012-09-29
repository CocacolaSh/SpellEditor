#ifndef __LOGIC_ATTR_MODIFIERBULLET_H__
#define __LOGIC_ATTR_MODIFIERBULLET_H__

namespace SKILLEDITOR
{
	enum EAttrBulletModifierKey
	{
		EAMKBullet_Invalid = -1,
		EAMKBullet_Null,
		EAMKBullet_AtkPlusByAttribute,
		EAMKBullet_AtbPlusBySkill,
		EAMKBullet_PlusAura,
		EAMKBullet_PlusEot,
		EAMKBullet_EotPlus,
		EAMKBullet_AtkSpecialMod,
		EAMKBullet_CriSpecialMod,
		EAMKBullet_ApplyTargetSeq,
		EAMKBullet_ApplySrcSeq,
		EAMKBullet_Count
	};
}
#endif