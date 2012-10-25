#include "CXmlExcel.h"
#include <vector>
#include <hash_map>

namespace BSLib
{
	CXmlExcel::CXmlExcel()
	{
		//
	}
	CXmlExcel::~CXmlExcel()
	{
		//
	}
	
	struct SNodeAttr
	{
		std::string m_name;
		std::string m_value;
	};
	struct SNode
	{
		std::string m_name;
		std::string m_value;
		std::vector<SNodeAttr> m_nodeAttr;
		std::vector<SNode*> m_subNodes;
	};

	class CExcelRow : public CExcelTableRow
	{
	public:
		CExcelRow(CExcelTable* table, BSLib::s32 columnSize):CExcelTableRow(table, columnSize){}
		~CExcelRow(){}
	private:
		std::vector<SNodeAttr>					m_attrs;
	};
	class CExcelCell : public CXmlExcelCell
	{
	public:
		CExcelCell(){}
		~CExcelCell(){}
	private:
		std::vector<SNodeAttr>					m_attrs;
		std::vector<SNodeAttr>					m_dataAttrs;
	};

	class CColumn
	{
	public:
		CColumn(){}
		~CColumn(){}
	private:
		std::vector<SNodeAttr>					m_attrs;
		bool									m_isValid;
	};

	class CExcelSheet : public CExcelTable
	{
	public:
		CExcelSheet(BSLib::s32 columnSize):CExcelTable(columnSize){}
		~CExcelSheet(){}
	private:
		std::string m_name;
		CExcelRow*  m_headerRow;
		std::vector<CColumn> m_columns;
		std::vector<SNodeAttr> m_tableAttrs;
		SNode m_workSheetOptions;
	};

	class CExcelBook
	{
	public:
		CExcelBook(){}
		~CExcelBook(){}
	private:
		std::vector<SNodeAttr>					m_attrs;
		SNode									m_styles;
		SNode									m_ocumentProperties;
		SNode									m_excelWorkbook;
		std::vector<CExcelSheet *>				m_excelSheets;
		stdext::hash_map<std::string, BSLib::s32>	m_hashMap;
	};
}