#ifndef __SPELL_EDITOR_REFRECECOUNT_H__
#define __SPELL_EDITOR_REFRECECOUNT_H__
#include "basedef.h"
namespace BSLib
{
	class IReferenceCounted
	{
	public:
		IReferenceCounted():m_debugName(0), m_counts(1)
		{
			//
		}
		virtual ~IReferenceCounted(){}

		void grab(){++m_counts;}
		bool drop()
		{
			//log_process_error(m_counts > 0);
			--m_counts;

			if (m_counts == 0)
			{
				delete this;
				return true;
			}
			return false;
		}

		const c8 * getDebugName()const{return m_debugName;}
		s32 getRefrenceCounts()const{return m_counts;}

	protected:
		void setDebugName(const c8* newName)
		{
			m_debugName = newName;
		}
	private:
		const c8 *			m_debugName;
		mutable s32			m_counts;
	};
}
#endif