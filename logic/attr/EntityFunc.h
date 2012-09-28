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

	enum EModifyCharAttrKey
	{
		EMAKCHAR_INVALID = -1,  
		EMAKCHAR_NULL,
		EMAKCHAR_RegisterEvtAddDebuf,					//0x00000001 register events add debuf
		EMAKCHAR_RegisterEvtBulletHurt,				//0x00000002 register events bullet hurt
		EMAKCHAR_RegisterEvtChara,						//0x00000003 ע��ʹ�ü����ǵ��õ������޸�������
		EMAKCHAR_RegisterEvtBulletExploded,			//0x00000004 ע�������ӵ�ʱ���õ��ӵ��޸������� 
		EMAKCHAR_RegisterEvtBulletBeHit,				//0x00000005 ע�ᱻ����ʱ���õ��ӵ��޸������� 
		EMAKCHAR_RegisterEvtBulletBeHurt,				//0x00000006 ע���˺��������õ��ӵ��޸�������
		EMAKCHAR_SetAuraLastTime,						//0x00000007 �ı���������aura/eot����ʱ�� 
		EMAKCHAR_AddAuraLastTime,						//0x00000008 ������������aura/eot����ʱ�� 
		EMAKCHAR_SelfSpurt,							//0x00000009 ����λ�� 
		EMAKCHAR_ChangeFlag,							//0x0000000A �޸�������λ 
		EMAKCHAR_ChangeSpeFlag,						//0x0000000B �޸����������������λ 
		EMAKCHAR_ChangeEmblem,							//0x0000000C �޸�����װ�������б��е����¼��ܼ���
		EMAKCHAR_ChangeEotPower,						//0x0000000D �޸���������EOTЧ����ÿһ����ֵ
		EMAKCHAR_ChangeAttributeA,						//0x0000000E �޸���������Aֵ
		EMAKCHAR_ChangeAttributeB,						//0x0000000F �޸���������Bֵ
		EMAKCHAR_ChangeAttributeC,						//0x00000010 �޸���������Cֵ
		EMAKCHAR_ChangeAttributeD,						//0x00000011 �޸���������Dֵ
		EMAKCHAR_ChangeAttributeE,						//0x00000012 �޸���������Eֵ
		EMAKCHAR_SetSpeAuraLastTime,					//0x00000013 �޸�����ָ��ID aura����ʱ��
		EMAKCHAR_ChangeSpeEmblem,						//0x00000014 �޸�����װ�����������ָ�����¼��ܼ��� 
		EMAKCHAR_AddAttributePercent,					//0x00000015 ��������hp,mp�ٷֱ�
		EMAKCHAR_AddAuraToChar,						//0x00000016 ���������ָ��Aura
		EMAKCHAR_AddEotToChar,							//0x00000017 ���������ָ��EOT
		EMAKCHAR_CharacterIfAction,					//0x00000018 ����������ϵ������ж�ִ�� 
		EMAKCHAR_Count

	};
}
#endif