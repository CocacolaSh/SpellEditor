#ifndef __LOGIC_SKILL_PERIODEFFECTDEF_H__
#define __LOGIC_SKILL_PERIODEFFECTDEF_H__
namespace SKILLEDITOR
{
	class CPeriodEffectEntry
	{
	public:
		virtual ~CPeriodEffectEntry(){}
		virtual BSLib::s32 getID() = 0;
		virtual BSLib::s32 getLevel() = 0;
		virtual bool isGood() = 0;
		virtual bool isUndispeled() = 0;
	};

}
#endif