#include "ModifierChar.h"
#include "basedef.h"
#include "CCharacterEntity.h"
#include "ModifierFunc.h"
namespace SKILLEDITOR
{
	//
	bool RegisterEvtAddDebuf(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletHurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtChara(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletExploded(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletBeHit(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletBeHurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool SetAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}

	bool SelfSpurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeFlag(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeSpeFlag(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeEmblem(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeEotPower(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeA(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeB(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeC(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeD(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeE(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool SetSpeAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeSpeEmblem(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddAttributePercent(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddAuraToChar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddEotToChar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool CharacterIfAction(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	TAttrModifierFunc AttrCharModifierFunc[EAMKCHAR_Count] = 
	{
		NULL,
		RegisterEvtAddDebuf,					//0x00000001 register events add debuf
		RegisterEvtBulletHurt,				//0x00000002 register events bullet hurt
		RegisterEvtChara,						//0x00000003 ע��ʹ�ü����ǵ��õ������޸�������
		RegisterEvtBulletExploded,			//0x00000004 ע�������ӵ�ʱ���õ��ӵ��޸������� 
		RegisterEvtBulletBeHit,				//0x00000005 ע�ᱻ����ʱ���õ��ӵ��޸������� 
		RegisterEvtBulletBeHurt,				//0x00000006 ע���˺��������õ��ӵ��޸�������
		SetAuraLastTime,						//0x00000007 �ı���������aura/eot����ʱ�� 
		AddAuraLastTime,						//0x00000008 ������������aura/eot����ʱ�� 
		SelfSpurt,							//0x00000009 ����λ�� 
		ChangeFlag,							//0x0000000A �޸�������λ 
		ChangeSpeFlag,						//0x0000000B �޸����������������λ 
		ChangeEmblem,							//0x0000000C �޸�����װ�������б��е����¼��ܼ���
		ChangeEotPower,						//0x0000000D �޸���������EOTЧ����ÿһ����ֵ
		ChangeAttributeA,						//0x0000000E �޸���������Aֵ
		ChangeAttributeB,						//0x0000000F �޸���������Bֵ
		ChangeAttributeC,						//0x00000010 �޸���������Cֵ
		ChangeAttributeD,						//0x00000011 �޸���������Dֵ
		ChangeAttributeE,						//0x00000012 �޸���������Eֵ
		SetSpeAuraLastTime,					//0x00000013 �޸�����ָ��ID aura����ʱ��
		ChangeSpeEmblem,						//0x00000014 �޸�����װ�����������ָ�����¼��ܼ��� 
		AddAttributePercent,					//0x00000015 ��������hp,mp�ٷֱ�
		AddAuraToChar,						//0x00000016 ���������ָ��Aura
		AddEotToChar,							//0x00000017 ���������ָ��EOT
		CharacterIfAction,					//0x00000018 ����������ϵ������ж�ִ�� 
	};
}