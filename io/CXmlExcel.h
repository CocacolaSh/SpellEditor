#ifndef __IO_CXMLEXCEL_H__
#define __IO_CXMLEXCEL_H__
#include "basedef.h"
#include "CTable.h"
#include <string>
namespace BSLib
{

	class CXmlExcelCell
	{
	public:
		CXmlExcelCell(){}
		~CXmlExcelCell(){}

		bool getBoolean(bool &_value);
		bool getInt(BSLib::s32 &_value);
		bool getUInt(BSLib::u32 & _value);
		bool getInt64(BSLib::s64 &_value);
		bool getUInt64(BSLib::u64 & _value);
		bool getFloat(BSLib::f32 &_value);
		bool getDouble(BSLib::f64 &_value);
		bool getString(BSLib::stringc &_value);

		bool getBoolean()
		{
			bool _value;
			getBoolean(_value);
			return _value;
		}
		BSLib::s32 getInt()
		{
			BSLib::s32 _value;
			getInt(_value);
			return _value;
		}
		BSLib::u32 getUInt()
		{
			BSLib::u32 _value;
			getUInt(_value);
			return _value;
		}
		BSLib::s64 getInt64()
		{
			BSLib::s64 _value;
			getInt64(_value);
			return _value;
		}
		BSLib::u64 getUInt64()
		{
			BSLib::u64 _value;
			getUInt64(_value);
			return _value;
		}
		BSLib::f32 getFloat()
		{
			BSLib::f32 _value;
			getFloat(_value);
			return _value;
		}
		BSLib::f64 getDouble()
		{
			BSLib::f64 _value;
			getDouble(_value);
			return _value;
		}
		BSLib::stringc & getString()
		{
			return m_value;
		}

		bool setBoolean(bool &_value);
		bool setInt(BSLib::s32 &_value);
		bool setUInt(BSLib::u32 & _value);
		bool setInt64(BSLib::s64 &_value);
		bool setUInt64(BSLib::u64 & _value);
		bool setFloat(BSLib::f32 &_value);
		bool setDouble(BSLib::f64 &_value);
		bool setString(BSLib::stringc &_value);


		CXmlExcelCell &operator = (bool &_value);
		CXmlExcelCell &operator = (BSLib::s32 &_value);
		CXmlExcelCell &operator = (BSLib::u32 &_value);
		CXmlExcelCell &operator = (BSLib::s64 &_value);
		CXmlExcelCell &operator = (BSLib::u64 &_value);
		CXmlExcelCell &operator = (BSLib::f32 &_value);
		CXmlExcelCell &operator = (BSLib::f64 &_value);
		CXmlExcelCell &operator = (BSLib::stringc &_value);

		template <class TYPE>
		bool getValue(TYPE & _value);
		template <class TYPE>
		bool operator()(TYPE & _value)
		{
			return getValue(_value);
		}

		template <class TYPE>
		bool setValue(TYPE & _value);
	protected:
		BSLib::stringc m_value;
	};

	template <> bool CXmlExcelCell::getValue(bool &_value);
	template <> bool CXmlExcelCell::getValue(BSLib::s32 &_value);
	template <> bool CXmlExcelCell::getValue(BSLib::u32 &_value);
	template <> bool CXmlExcelCell::getValue(BSLib::s64 &_value);
	template <> bool CXmlExcelCell::getValue(BSLib::u64 &_value);
	template <> bool CXmlExcelCell::getValue(BSLib::f32 &_value);
	template <> bool CXmlExcelCell::getValue(BSLib::f64 &_value);
	template <> bool CXmlExcelCell::getValue(BSLib::stringc &_value);

	class CExcelBook;

	typedef CXmlExcelCell CXmlExcelTableCell;
	typedef CTableRow<BSLib::stringc, CXmlExcelTableCell> CExcelTableRow;
	typedef CTable<BSLib::stringc, CXmlExcelTableCell, CExcelTableRow>	CExcelTable;

	class CXmlExcel
	{
	public:
		CXmlExcel();
		~CXmlExcel();

		bool loadFile(BSLib::stringc &fileName);
		bool saveFile(BSLib::stringc &fileName);

		CExcelTable* getTable(BSLib::s32 index)const;

		bool clear();
	private:

		BSLib::stringc m_fileName;
		CExcelBook* m_excelBook;
	};
}
#endif