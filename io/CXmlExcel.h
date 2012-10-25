#ifndef __IO_CXMLEXCEL_H__
#define __IO_CXMLEXCEL_H__
#include "basedef.h"
#include "CTable.h"
#include <string>
namespace BSLib
{
	class CExcelBook;

	typedef CTableCell<std::string> CXmlExcelCell;
	typedef CTableRow<std::string> CExcelTableRow;
	typedef CTable<std::string>	CExcelTable;

	class CXmlExcel
	{
	public:
		CXmlExcel();
		~CXmlExcel();

		bool loadFile(std::string &fileName);
		bool saveFile(std::string &fileName);

		bool clear();
	private:

		std::string m_fileName;
		CExcelBook* m_excelBook;
	};
}
#endif