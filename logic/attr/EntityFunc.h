#ifndef __LOGIC_ATTR_ENTITYFUNC_H__
#define __LOGIC_ATTR_ENTITYFUNC_H__

namespace SKILLEDITOR
{
	enum EGetCharAttrFunc
	{
		EGCAF_INVALID = 0,
		EGCAF_DEBUFNO = 0x00000003,
		EGCAF_FLAG,
		EGCAF_MOVECONDITION,
		EGCAF_ATTRPERCENT,
		EGCAF_BUFFNO,
		EGCAF_ATTRIBUTEA,
		EGCAF_ATTRIBUTEB,
		EGCAF_ATTRIBUTEC,
		EGCAF_ATTRIBUTED,
		EGCAF_ATTRIBUTEE,
		EGCAF_GETISATT,
		EGCAF_COUNT
	};

	class IFighter;
	typedef BSLib::s32 (* TGetAttr)(IFighter* ,BSLib::s32);
	TGetAttr GetAttrFunc(BSLib::s32 funcType, BSLib::s32 key)
	{
		TGetAttr *getAttrFunc = 0;
Exit0:
		return 0;
	}
	enum EAttrModifyKeyChar
	{
		EAMKCHAR_INVALID = -1,  
		EAMKCHAR_NULL,
		EAMKCHAR_RegisterEvtAddDebuf,					//0x00000001 register events add debuf
		EAMKCHAR_RegisterEvtBulletHurt,				//0x00000002 register events bullet hurt
		EAMKCHAR_RegisterEvtChara,						//0x00000003 ע��ʹ�ü����ǵ��õ������޸�������
		EAMKCHAR_RegisterEvtBulletExploded,			//0x00000004 ע�������ӵ�ʱ���õ��ӵ��޸������� 
		EAMKCHAR_RegisterEvtBulletBeHit,				//0x00000005 ע�ᱻ����ʱ���õ��ӵ��޸������� 
		EAMKCHAR_RegisterEvtBulletBeHurt,				//0x00000006 ע���˺��������õ��ӵ��޸�������
		EAMKCHAR_SetAuraLastTime,						//0x00000007 �ı���������aura/eot����ʱ�� 
		EAMKCHAR_AddAuraLastTime,						//0x00000008 ������������aura/eot����ʱ�� 
		EAMKCHAR_SelfSpurt,							//0x00000009 ����λ�� 
		EAMKCHAR_ChangeFlag,							//0x0000000A �޸�������λ 
		EAMKCHAR_ChangeSpeFlag,						//0x0000000B �޸����������������λ 
		EAMKCHAR_ChangeEmblem,							//0x0000000C �޸�����װ�������б��е����¼��ܼ���
		EAMKCHAR_ChangeEotPower,						//0x0000000D �޸���������EOTЧ����ÿһ����ֵ
		EAMKCHAR_ChangeAttributeA,						//0x0000000E �޸���������Aֵ
		EAMKCHAR_ChangeAttributeB,						//0x0000000F �޸���������Bֵ
		EAMKCHAR_ChangeAttributeC,						//0x00000010 �޸���������Cֵ
		EAMKCHAR_ChangeAttributeD,						//0x00000011 �޸���������Dֵ
		EAMKCHAR_ChangeAttributeE,						//0x00000012 �޸���������Eֵ
		EAMKCHAR_SetSpeAuraLastTime,					//0x00000013 �޸�����ָ��ID aura����ʱ��
		EAMKCHAR_ChangeSpeEmblem,						//0x00000014 �޸�����װ�����������ָ�����¼��ܼ��� 
		EAMKCHAR_AddAttributePercent,					//0x00000015 ��������hp,mp�ٷֱ�
		EAMKCHAR_AddAuraToChar,						//0x00000016 ���������ָ��Aura
		EAMKCHAR_AddEotToChar,							//0x00000017 ���������ָ��EOT
		EAMKCHAR_CharacterIfAction,					//0x00000018 ����������ϵ������ж�ִ�� 
		EAMKCHAR_Count

	};

	enum EAttrModifyKeySkill
	{
		EAMKSKILL_Invalid = -1,
		EAMKSKILL_Count,
	};
	enum EAttrModifyKeyBullet
	{
		EAMKBullet_Invalid = -1,
		EAMKBullet_Count,
	};
	enum EAttrModifyKeyEot
	{
		EAMKEot_Invalid = -1,
		EAMKEot_Count,
	};
	enum EAttrModifyKeyAura
	{
		EAMKAura_Invalid = -1,
		EAMKAura_Count,
	};

	
}
#endif