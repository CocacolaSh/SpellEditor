#include "CXmlExcel.h"
#include "irrXML.h"
#include <vector>
#include <hash_map>
#include "Process_error.h"
#include <string>

namespace BSLib
{
	
	bool CXmlExcel::saveFile(BSLib::stringc &fileName)
	{
		return false;
	}

	bool CXmlExcel::clear()
	{
		return false;
	}
	struct SNodeAttr
	{
		BSLib::stringc m_name;
		BSLib::stringc m_value;

		SNodeAttr(BSLib::stringc name = "", BSLib::stringc _value = "")
		{
			m_name = name;
			m_value = _value;
		}
		SNodeAttr(const SNodeAttr &rNodeAttr)
		{
			m_name = rNodeAttr.m_name;
			m_value = rNodeAttr.m_value;
		}
	};
	struct SNode
	{
		SNode()
		{
			m_name = "";
			m_value = "";
		}
		BSLib::stringc m_name;
		BSLib::stringc m_value;
		std::vector<SNodeAttr> m_nodeAttr;
		std::vector<SNode*> m_subNodes;

		bool loadFile(IrrXMLReader *xmlReader);
	};

	bool SNode::loadFile(IrrXMLReader *xmlReader)
	{
		LOG_PROCESS_ERROR(xmlReader);
		
		do 
		{
			EXML_NODE exmlNode = xmlReader->getNodeType();
			switch(exmlNode)
			{
			case EXN_ELEMENT:
				{
					if (m_name != "")
					{
						//sub node
						SNode *pSubNode = new SNode();
						pSubNode->loadFile(xmlReader);
						m_subNodes.push_back(pSubNode);
					
					}
					else
					{
						m_name = xmlReader->getNodeName();
						m_value = xmlReader->getNodeData();

						BSLib::s32 attCnt = xmlReader->getAttributeCount();
						for (BSLib::s32 i = 0; i < attCnt; i++)
						{
							m_nodeAttr.push_back(SNodeAttr(xmlReader->getAttributeName(i),
								xmlReader->getAttributeValue(i)));
						}
					}
					
				}
				break;
			case EXN_TEXT:
				{
					if (xmlReader->isEmptyElement())
					{
						return true;
					}
				
				}
				break;
			case EXN_ELEMENT_END:
				{
					if (m_name == xmlReader->getNodeName())
					{
						return true;
					}
				}
				break;
			
			default:
				{
					BSLib::s64 i = 0;
					i++;
				}
				break;
			}
		} while (xmlReader->read());
		return true;
Exit0:
		return false;
	}
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
		BSLib::stringc m_name;
		CExcelRow*  m_headerRow;
		std::vector<CColumn> m_columns;
		std::vector<SNodeAttr> m_tableAttrs;
		SNode m_workSheetOptions;
	};

	class CExcelBook
	{
	public:
		CExcelBook();
		~CExcelBook(){}

		bool loadFile(BSLib::stringc &fileName);
	private:
		std::vector<SNodeAttr>					m_attrs;
		SNode									m_styles;
		SNode									m_documentProperties;
		SNode									m_excelWorkbook;
		std::vector<CExcelSheet *>				m_excelSheets;
		stdext::hash_map<BSLib::stringc, BSLib::s32>	m_hashMap;
	};
	CExcelBook::CExcelBook()
	{
		m_attrs.clear();
	}

	bool CExcelBook::loadFile(BSLib::stringc &fileName)
	{
		LOG_PROCESS_ERROR(fileName != "");
		IrrXMLReader* xmlReader = createIrrXMLReader(fileName.c_str());
		LOG_PROCESS_ERROR(xmlReader);

		while (xmlReader->read())
		{
			switch (xmlReader->getNodeType())
			{
			case EXN_ELEMENT:
				{
					if (!strcmp("Workbook", xmlReader->getNodeName()))
					{
						BSLib::s32 attrCount = xmlReader->getAttributeCount();
						for (BSLib::s32 i = 0; i < attrCount; ++i)
						{
							m_attrs.push_back(SNodeAttr(xmlReader->getAttributeName(i), 
								xmlReader->getAttributeValue(i)));
						}
					}
					if (!strcmp("DocumentProperties", xmlReader->getNodeName()))
					{
						m_documentProperties.loadFile(xmlReader);
					}
					if (!strcmp("ExcelWorkbook", xmlReader->getNodeName()))
					{
						m_excelWorkbook.loadFile(xmlReader);
					}
					if (!strcmp("Styles", xmlReader->getNodeName()))
					{
						m_styles.loadFile(xmlReader);
					}
				}
				break;
			case EXN_TEXT:
				break;
			default:
				break;
			}
		}
		return true;
Exit0:
		return false;
	}


	CXmlExcel::CXmlExcel()
	{
		m_excelBook = new CExcelBook();
	}
	CXmlExcel::~CXmlExcel()
	{
		//
	}
	bool CXmlExcel::loadFile(BSLib::stringc &fileName)
	{
		m_fileName = fileName;
		m_excelBook->loadFile(m_fileName);
		return false;
	}
}