#ifndef __IO_CTABLE_H__
#define __IO_CTABLE_H__
#include "basedef.h"
#include "../colaString.h"
#include <vector>
#include <hash_map>

namespace BSLib
{
	template <class CELLTYPE>
	class CTableCell
	{
	public:
		CTableCell(){}
		~CTableCell(){}

		CELLTYPE & getValue()const {return m_value;}
		void setValue(CELLTYPE _value){m_value = _value;}

		CELLTYPE &operator = (CELLTYPE &_value)
		{
			m_value = _value;
			return m_value;
		}

		CELLTYPE & operator() ()const
		{
			return m_value;
		}

		template <class ValueType>
		bool getValue(ValueType &_value)const
		{
			_value = m_value;
			return true;
		}
		template <class ValueType>
		bool setValue(ValueType &_value)const
		{
			m_value = _value;
			return true;
		}

		template <class ValueType>
		bool operator()(ValueType &_value)const
		{
			_value = (ValueType)m_value;
			return true;
		}
	private:
		CELLTYPE m_value;
	};


	template <class TYPE, class CELLTYPE = CTableCell<TYPE>, class ROWTYPE = CTableRow<TYPE> >
	class CTable;

	template <class TYPE, class CELLTYPE = CTableCell<TYPE> >
	class CTableRow
	{
	public:
		CTableRow(CTable<TYPE, CELLTYPE, CTableRow> * table, BSLib::s32 columnMax)
			:m_table(table)
		{
			m_cells.resize(columnMax);	
			for (BSLib::s32 i = 0; i < columnMax; ++i)
			{
				m_cells[i] = _createCell();
			}
		}
		~CTableRow()
		{
			_clear();
		}

		CELLTYPE * getColumn(BSLib::s32 index)const
		{
			if (index >= 0 && index < m_cells.size())
			{
				return m_cells[index];
			}
			return NULL;
		}


		CELLTYPE * getColumn(BSLib::stringc &columnName)const
		{
			BSLib::s32 columnIndex = m_table->getColumnIndex(columnName);
			return getColumn(columnIndex);
		}

		CELLTYPE& operator[](BSLib::s32 index)const
		{
			return *(getColumn(index));
		}
		CELLTYPE& operator[](BSLib::stringc &columnName)const
		{
			return *(getColumn(columnName));
		}
		BSLib::s32 columnSize() const {return m_cells.size();}
	protected:
		CELLTYPE *_createCell()
		{
			return m_table->_createCell();
		}

		bool _clear()
		{
			BSLib::s32 columnMax = m_cells.size();
			for (BSLib::s32 i = 0; i < columnMax; ++i)
			{
				delete m_cells[i];
			}
			m_cells.clear();
			return true;
		}

	private:
		CTable<TYPE, CELLTYPE, CTableRow> *m_table;
		std::vector<CELLTYPE *>	m_cells;
	};

	template <class TYPE, class CELLTYPE = CTableCell<TYPE>, class ROWTYPE = CTableRow<TYPE, CELLTYPE> >
	class CTable
	{
	public:
		CTable(BSLib::s32 columnSize)
			:m_columnSize(columnSize)
		{
			m_columnNames.resize(columnSize);
		}
		~CTable()
		{
			clear();
		}
		
		ROWTYPE * getRow(BSLib::s32 index)const
		{
			BSLib::s32 _rowSize = rowSize();
			if (index >= 0 && index < _rowSize)
			{
				return m_rows[index];
			}
			return NULL;
		}

		bool clear()
		{
			BSLib::s32 rowSize = m_rows.size();
			for (BSLib::s32 i = 0; i < rowSize; ++i)
			{
				delete m_rows[i];
			}
			m_rows.clear();
			return true;
		}

		BSLib::s32 rowSize() const {return m_rows.size();}
		BSLib::s32 columnSize() const {return m_columnSize;}

		virtual void setColumnName(BSLib::s32 index, BSLib::stringc & name)
		{
			m_columnNames[index] = name;
			m_columnNameHash[name] = index;
		}
		BSLib::s32 getColumnIndex(const BSLib::stringc name) const
		{
			std::hash_map<BSLib::stringc, BSLib::s32>::iterator begIter = m_columnNameHash.find(name);
			if (begIter == m_columnNameHash.end())
			{
				return -1;
			}
			return begIter->second;
		}
		BSLib::stringc & getColumnName(BSLib::s32 index) const
		{
			return m_columnNames[index];
		}
		bool appendRow(BSLib::s32 rowNum = 1)
		{
			for(BSLib::s32 i = 0; i < rowNum; ++i)
			{
				ROWTYPE* row = _createRow();
				if (row == NULL)
				{
					return false;
				}
				m_rows.push_back(row);
			}
			return true;
		}

		bool removeRow(BSLib::s32 startIndex, BSLib::s32 num = 1)
		{
			if (startIndex < 0 || startIndex >= rowSize() || startIndex + num > rowSize())
			{
				return false;
			}

			std::vector<ROWTYPE *>::iterator begIter = m_rows.at(startIndex);
			std::vector<ROWTYPE *>::iterator endIter = m_rows.at(startIndex + num);

			while(begIter != endIter)
			{
				std::vector<ROWTYPE *>::iterator currentIter = begIter++;
				if (*currentIter != NULL)
				{
					delete (*currentIter);
					m_rows.erase(currentIter);
				}
			}
			return true;
		}
		ROWTYPE& operator[](BSLib::s32 index)
		{
			return *(m_rows[index]);
		}

		template <class VALUETYPE>
		bool getColumnValue(BSLib::s32 rowIndex, BSLib::s32 columnIndex, VALUETYPE& value)const
		{
			if (rowIndex <0 || rowIndex >= rowSize() ||
				columnIndex < 0 || columnIndex >= columnSize())
			{
				return false;
			}

			ROWTYPE *row = m_rows[rowIndex];
			if (row == NULL)
			{
				return false;
			}
			CELLTYPE *cell = row->getColumn(columnIndex);
			if (cell == NULL)
			{
				return false;
			}
			cell->getValue(value);
			return true;
		}

		template <class VALUETYPE>
		bool getColumnValue(BSLib::s32 rowIndex, BSLib::stringc& columnName, VALUETYPE& value)const
		{
			BSLib::s32 columnIndex = getColumnIndex(columnName);
			return getColumnValue(rowIndex, columnIndex, value);
		}

		template <class VALUETYPE>
		bool setColumnValue(BSLib::s32 rowIndex, BSLib::s32 columnIndex, VALUETYPE value)const
		{
			if (rowIndex <0 || rowIndex >= rowSize() ||
				columnIndex < 0 || columnIndex >= columnSize())
			{
				return false;
			}

			ROWTYPE *row = m_rows[rowIndex];
			if (row == NULL)
			{
				return false;
			}
			CELLTYPE *cell = row->getColumn(columnIndex);
			if (cell == NULL)
			{
				return false;
			}
			cell->setValue(value);
			return true;
		}

		template <class VALUETYPE>
		bool setColumnValue(BSLib::s32 rowIndex, BSLib::stringc& columnName, VALUETYPE& value)const
		{
			BSLib::s32 columnIndex = getColumnIndex(columnName);
			return setColumnValue(rowIndex, columnIndex, value);
		}

		template <class VALUETYPE>
		bool operator() (BSLib::s32 rowIndex, BSLib::stringc& columnName, VALUETYPE& value)const
		{
			return getColumnValue(rowIndex, columnName, value);
		}
		template <class VALUETYPE>
		bool operator() (BSLib::s32 rowIndex, BSLib::s32 columnIndex, VALUETYPE& value)const
		{
			return getColumnValue(rowIndex, columnIndex, value);
		}

	protected:
		virtual CELLTYPE *_createCell()
		{
			return new CELLTYPE();
		}

		virtual ROWTYPE *_createRow()
		{
			return new ROWTYPE(this, m_columnSize);
		}
	private:
		BSLib::s32 m_columnSize;
		std::vector< ROWTYPE *> m_rows;
		stdext::hash_map< BSLib::stringc, BSLib::s32, stdext::hash_compare<BSLib::stringc, std::less<BSLib::stringc> > > m_columnNameHash;
		std::vector< BSLib::stringc> m_columnNames;

		friend class CTableRow<TYPE, CELLTYPE>;
	};
}
#endif