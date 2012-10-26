#ifndef __IO_CXMLEXCEL_H__
#define __IO_CXMLEXCEL_H__
#include "basedef.h"
#include "CTable.h"
#include <string>
namespace BSLib
{
	class CExcelBook;

	typedef CTableCell<BSLib::stringc> CXmlExcelCell;
	typedef CTableRow<BSLib::stringc> CExcelTableRow;
	typedef CTable<BSLib::stringc>	CExcelTable;

	class CXmlExcel
	{
	public:
		CXmlExcel();
		~CXmlExcel();

		bool loadFile(BSLib::stringc &fileName);
		bool saveFile(BSLib::stringc &fileName);

		bool clear();
	private:

		BSLib::stringc m_fileName;
		CExcelBook* m_excelBook;
	};
}
#endif