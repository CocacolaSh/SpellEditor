#include "CXmlExcel.h"
#include "irrXML.h"
#include <vector>
#include <hash_map>
#include "Process_error.h"
#include <string>
#include <sstream>
#include <ostream>


namespace BSLib
{

	bool CXmlExcelCell::setBoolean(bool &_value)
	{
		std::ostringstream ss;
		ss << _value;
		m_value = ss.str().c_str();
		return true;
	}
	bool CXmlExcelCell::setInt(BSLib::s32 &_value)
	{
		m_value = BSLib::stringc(_value);
		return true;
	}
	bool CXmlExcelCell::setUInt(BSLib::u32 & _value)
	{
		m_value = BSLib::stringc(_value);
		return true;
	}
	bool CXmlExcelCell::setInt64(BSLib::s64 &_value)
	{
		std::ostringstream ss;
		ss << _value;
		m_value = ss.str().c_str();
		return true;
	}
	bool CXmlExcelCell::setUInt64(BSLib::u64 & _value)
	{
		std::ostringstream ss;
		ss << _value;
		m_value = ss.str().c_str();
		return true;
	}
	bool CXmlExcelCell::setFloat(BSLib::f32 &_value)
	{
		std::ostringstream ss;
		ss << _value;
		m_value = ss.str().c_str();
		return true;
	}
	bool CXmlExcelCell::setDouble(BSLib::f64 &_value)
	{
		std::ostringstream ss;
		ss << _value;
		m_value = ss.str().c_str();
		return true;
	}
	bool CXmlExcelCell::setString(BSLib::stringc &_value)
	{
		std::ostringstream ss;
		ss << _value;
		m_value = ss.str().c_str();
		return true;
	}
	bool CXmlExcelCell::getBoolean(bool &_value)
	{
		_value = atoi(m_value.c_str());
		return true;
	}
	bool CXmlExcelCell::getInt(BSLib::s32 &_value)
	{
		_value = atoi(m_value.c_str());
		return true;
	}
	bool CXmlExcelCell::getUInt(BSLib::u32 & _value)
	{
		_value = atoi(m_value.c_str());
		return true;
	}
	bool CXmlExcelCell::getInt64(BSLib::s64 &_value)
	{
		_value = atol(m_value.c_str());
		return true;
	}
	bool CXmlExcelCell::getUInt64(BSLib::u64 & _value)
	{
		_value = atol(m_value.c_str());
		return true;
	}
	bool CXmlExcelCell::getFloat(BSLib::f32 &_value)
	{
		_value = atof(m_value.c_str());
		return true;
	}
	bool CXmlExcelCell::getDouble(BSLib::f64 &_value)
	{
		_value = atof(m_value.c_str());
		return true;
	}
	bool CXmlExcelCell::getString(BSLib::stringc &_value)
	{
		_value = m_value;
		return true;
	}

	CXmlExcelCell &CXmlExcelCell::operator = (bool &_value)
	{
		setBoolean(_value);
		return *this;
	}
	CXmlExcelCell & CXmlExcelCell::operator = (BSLib::s32 &_value)
	{
		setInt(_value);
		return *this;
	}
	CXmlExcelCell & CXmlExcelCell::operator = (BSLib::u32 &_value)
	{
		setUInt(_value);
		return *this;
	}
	CXmlExcelCell & CXmlExcelCell::operator = (BSLib::s64 &_value)
	{
		setInt64(_value);
		return *this;
	}
	CXmlExcelCell & CXmlExcelCell::operator = (BSLib::u64 &_value)
	{
		setUInt64(_value);
		return *this;
	}
	CXmlExcelCell & CXmlExcelCell::operator = (BSLib::f32 &_value)
	{
		setFloat(_value);
		return *this;
	}
	CXmlExcelCell & CXmlExcelCell::operator = (BSLib::f64 &_value)
	{
		setDouble(_value);
		return *this;
	}
	CXmlExcelCell & CXmlExcelCell::operator = (BSLib::stringc &_value)
	{
		setString(_value);
		return *this;
	}
	template <> bool CXmlExcelCell::getValue(bool &_value)
	{
		return getBoolean(_value);
	}
	template <> bool CXmlExcelCell::getValue(BSLib::s32 &_value)
	{
		return getInt(_value);
	}
	template <> bool CXmlExcelCell::getValue(BSLib::u32 &_value)
	{
		return getUInt(_value);
	}
	template <> bool CXmlExcelCell::getValue(BSLib::s64 &_value)
	{
		return getInt64(_value);
	}
	template <> bool CXmlExcelCell::getValue(BSLib::u64 &_value)
	{
		return getUInt64(_value);
	}
	template <> bool CXmlExcelCell::getValue(BSLib::f32 &_value)
	{
		return getFloat(_value);
	}
	template <> bool CXmlExcelCell::getValue(BSLib::f64 &_value)
	{
		return getDouble(_value);
	}
	template <> bool CXmlExcelCell::getValue(BSLib::stringc &_value)
	{
		return getString(_value);
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
	
	class CExcelCell : public CXmlExcelCell
	{
	public:
		CExcelCell(){}
		~CExcelCell(){}
		bool loadFile(IrrXMLReader *xmlReader)
		{
			BSLib::s32 attrCount = xmlReader->getAttributeCount();
			for (BSLib::s32 i = 0; i < attrCount; ++i)
			{
				m_attrs.push_back(SNodeAttr(xmlReader->getAttributeName(i), 
					xmlReader->getAttributeValue(i)));
			}
			BSLib::stringc name = "";
			while (xmlReader->read())
			{
				switch (xmlReader->getNodeType())
				{
				case EXN_ELEMENT:
					{
						name = xmlReader->getNodeName();
						if (!strcmp("Data", name.c_str()))
						{
							BSLib::s32 attrCount = xmlReader->getAttributeCount();
							for (BSLib::s32 i = 0; i < attrCount; ++i)
							{
								m_dataAttrs.push_back(SNodeAttr(xmlReader->getAttributeName(i), 
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
						if (name == "Data")
						{
							CXmlExcelCell::m_value = xmlReader->getNodeData();
						}
					}
					break;
				case EXN_ELEMENT_END:
					{
						if (name == xmlReader->getNodeName())
						{
							return true;
						}
					}
					break;
				default:
					break;
				}
			}
			return true;
Exit0:
			return false;
		}
	private:
		std::vector<SNodeAttr>					m_attrs;
		std::vector<SNodeAttr>					m_dataAttrs;
	};

	class CExcelRow : public CExcelTableRow
	{
	public:
		CExcelRow(CExcelTable* table, BSLib::s32 columnSize):CExcelTableRow(table, columnSize){}
		~CExcelRow(){}
		bool setCell(BSLib::s32 index, BSLib::stringc &_value)
		{
			LOG_PROCESS_ERROR(index >= 0 && index < CExcelTableRow::m_cells.size());

			CXmlExcelCell *pCell = (CXmlExcelCell *)CExcelTableRow::m_cells[index];
			LOG_PROCESS_ERROR(pCell);
			pCell->setValue(_value);

			return true;
Exit0:
			return false;
		}
		BSLib::stringc & getCell(BSLib::s32 index)
		{
			static BSLib::stringc temp = "";
			LOG_PROCESS_ERROR(index >= 0 && index < CExcelTableRow::m_cells.size());

			CXmlExcelCell *pCell = (CXmlExcelCell *)CExcelTableRow::m_cells[index];
			LOG_PROCESS_ERROR(pCell);
			return pCell->getString();
Exit0:
			return temp;
		}

		bool loadFile(IrrXMLReader *xmlReader)
		{
			BSLib::stringc name = "";
			LOG_PROCESS_ERROR(xmlReader);

			BSLib::s32 attrCount = xmlReader->getAttributeCount();
			for (BSLib::s32 i = 0; i < attrCount; ++i)
			{
				m_attrs.push_back(SNodeAttr(xmlReader->getAttributeName(i), 
					xmlReader->getAttributeValue(i)));
			}
			name = xmlReader->getNodeName();
			BSLib::s32 columnCnt = 0;
			while (xmlReader->read())
			{
				switch (xmlReader->getNodeType())
				{
				case EXN_ELEMENT:
					{
						if (!strcmp("Cell", xmlReader->getNodeName()))
						{
							BSLib::s32 cellIndex = xmlReader->getAttributeValueAsInt("ss:Index");
							if (cellIndex > columnCnt)
							{
								columnCnt = cellIndex - 1;
							}

							LOG_PROCESS_ERROR(columnCnt < CExcelTableRow::m_cells.size());
							CExcelCell *pCell = (CExcelCell *)(CExcelTableRow::m_cells[columnCnt]);
							if (pCell == NULL)
							{
								pCell = (CExcelCell*)(CExcelTableRow::_createCell());
								LOG_PROCESS_ERROR(pCell);

								CExcelTableRow::m_cells[columnCnt] = pCell;
							}
							pCell->loadFile(xmlReader);
							++columnCnt;
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
						if (name == xmlReader->getNodeName())
						{
							return true;
						}
					}
					break;
				default:
					break;
				}
			}
			return true;
Exit0:
			return false;
		}
	private:
		std::vector<SNodeAttr>					m_attrs;
	};
	class CColumn
	{
	public:
		CColumn(){}
		~CColumn(){}
		bool loadFile(IrrXMLReader *xmlReader)
		{
			LOG_PROCESS_ERROR(xmlReader);

			BSLib::s32 attrCount = xmlReader->getAttributeCount();
			for (BSLib::s32 i = 0; i < attrCount; ++i)
			{
				m_attrs.push_back(SNodeAttr(xmlReader->getAttributeName(i), 
					xmlReader->getAttributeValue(i)));
			}
			return true;
Exit0:
			return false;
		}
	private:
		std::vector<SNodeAttr>					m_attrs;
		bool									m_isValid;
	};

	class CExcelSheet : public CExcelTable
	{
	public:
		CExcelSheet(BSLib::stringc &sheetName, BSLib::s32 columnSize):m_name(sheetName), CExcelTable(columnSize)
		{
			m_columns.resize(columnSize);
			m_headerRow = NULL;
		}
		~CExcelSheet(){}
		virtual CTableRow<BSLib::stringc, CXmlExcelTableCell> *_createRow()
		{
			return new CExcelRow(this, CExcelTable::columnSize());
		}

		bool loadFile(IrrXMLReader *xmlReader)
		{
			LOG_PROCESS_ERROR(xmlReader);
			BSLib::s32 attrCount = xmlReader->getAttributeCount();
			for (BSLib::s32 i = 0; i < attrCount; ++i)
			{
				m_tableAttrs.push_back(SNodeAttr(xmlReader->getAttributeName(i), 
					xmlReader->getAttributeValue(i)));
			}

			BSLib::s32 columnCnt = 0;
			BSLib::s32 rowCnt = 0;
			BSLib::s32 rowBaseIndex = 0;
			while (xmlReader->read())
			{
				switch (xmlReader->getNodeType())
				{
				case EXN_ELEMENT:
					{
						if (!strcmp("Column", xmlReader->getNodeName()))
						{
							BSLib::s32 columnIndex = xmlReader->getAttributeValueAsInt("ss:Index");
							if (columnIndex > columnCnt + 1)
							{
								columnCnt = columnIndex - 1;
							}

							if (columnCnt >= m_columns.size())
							{
								LOG_PROCESS_ERROR(false);
							}
							
							m_columns[columnCnt].loadFile(xmlReader);
							++columnCnt;
						}
						if (!strcmp("Row", xmlReader->getNodeName()))
						{
							BSLib::s32 rowIndex = xmlReader->getAttributeValueAsInt("ss:Index");
							if (m_headerRow == NULL)
							{
								if (rowIndex > 0)
								{
									rowBaseIndex = rowIndex - 1;
								}

								bool bRet = CExcelTable::appendRow(1);
								LOG_PROCESS_ERROR(bRet);

								m_headerRow = (CExcelRow*)(CExcelTable::getRow(0));
								LOG_PROCESS_ERROR(m_headerRow);

								/*m_headerRow = (CExcelRow*)(_createRow());
								LOG_PROCESS_ERROR(m_headerRow);*/


								m_headerRow->loadFile(xmlReader);

								for (BSLib::s32 i = 0; i < m_headerRow->columnSize(); i++)
								{
									CExcelTable::setColumnName(i, m_headerRow->getCell(i));
								}
								rowBaseIndex++;
							}else
							{
								if (rowIndex >= rowCnt + rowBaseIndex + 1)
								{
									bool bRet = CExcelTable::appendRow(rowIndex - rowCnt - rowBaseIndex);
									LOG_PROCESS_ERROR(bRet);

									rowCnt = rowIndex - 1 - rowBaseIndex;
								}else{
									bool bRet = CExcelTable::appendRow(1);
									LOG_PROCESS_ERROR(bRet);
								}

								CExcelRow *pRow = (CExcelRow*)(CExcelTable::getRow(rowCnt + 1));
								LOG_PROCESS_ERROR(pRow);
								
								pRow->loadFile(xmlReader);
								++rowCnt;
							}
							
							
						}

						if (!strcmp("WorksheetOptions", xmlReader->getNodeName()))
						{
							m_workSheetOptions.loadFile(xmlReader);
						}
					}
					break;
				case EXN_ELEMENT_END:
					{
						if (!strcmp("Worksheet", xmlReader->getNodeName()))
						{
							return true;
						}
					}
					break;
				default:
					break;
				}
			}
			return true;
Exit0:
			return false;
		}

		virtual CXmlExcelCell * _createCell()
		{
			return new CExcelCell();
		}
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
		~CExcelBook()
		{
			clear();
		}

		bool loadFile(BSLib::stringc &fileName);
		bool saveFile(BSLib::stringc &fileName);

		CExcelSheet* addSheet(BSLib::stringc &sheetName, BSLib::s32 columnMax)
		{
			CExcelSheet* pSheet = new CExcelSheet(sheetName, columnMax);
			return pSheet;
		}

		bool clear()
		{
			std::vector<CExcelSheet *>::iterator begIter = m_excelSheets.begin();
			std::vector<CExcelSheet *>::iterator endIter = m_excelSheets.end();
			std::vector<CExcelSheet *>::iterator tempIter;
			while(begIter != endIter)
			{
				tempIter = begIter++;
				SAFE_DELETE(*tempIter);
				m_excelSheets.erase(tempIter);
			}
			return true;
		}
		CExcelTable* getTable(BSLib::s32 index)const
		{
			LOG_PROCESS_ERROR(index >=0 && index < m_excelSheets.size());
			return m_excelSheets[index];
Exit0:
			return NULL;
		}
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

	bool CExcelBook::saveFile(BSLib::stringc &fileName)
	{
		return true;
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
					if (!strcmp("Worksheet", xmlReader->getNodeName()))
					{
						BSLib::stringc sheetName = xmlReader->getAttributeValue("ss:Name");
						//BSLib::s32 attrCount = xmlReader->getAttributeCount();
						//std::vector<SNodeAttr>					sheetAttrs;
						//for (BSLib::s32 i = 0; i < attrCount; ++i)
						//{
						//	sheetAttrs.push_back(SNodeAttr(xmlReader->getAttributeName(i), 
						//		xmlReader->getAttributeValue(i)));
						//}

Repeat:
						if (false == xmlReader->read() || xmlReader->getNodeType() != EXN_ELEMENT
							|| strcmp("Table", xmlReader->getNodeName()))
						{
							goto Repeat;
						}

						BSLib::s32 columnMax = xmlReader->getAttributeValueAsInt("ss:ExpandedColumnCount");

						CExcelSheet* pSheet = addSheet(sheetName, columnMax);
						//pSheet->
						pSheet->loadFile(xmlReader);

						m_excelSheets.push_back(pSheet);
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
		clear();
	}
	bool CXmlExcel::saveFile(BSLib::stringc &fileName)
	{
		m_fileName = fileName;

		return m_excelBook->saveFile(m_fileName);
	}

	bool CXmlExcel::clear()
	{
		delete m_excelBook;
		m_excelBook = false;
		return false;
	}
	bool CXmlExcel::loadFile(BSLib::stringc &fileName)
	{
		m_fileName = fileName;
		
		return m_excelBook->loadFile(m_fileName);
	}

	CExcelTable* CXmlExcel::getTable(BSLib::s32 index)const
	{
		LOG_PROCESS_ERROR(m_excelBook);

		return m_excelBook->getTable(index);
Exit0:
		return NULL;
	}
}