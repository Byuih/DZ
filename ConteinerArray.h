#pragma once
#include <iostream>



#ifndef INTARRAY_H
#define INTARRAY_H

using namespace std;

class ConteinerArray
{
private:
	int m_size{};
	int* m_data{};

public:
	
	ConteinerArray() = default;
	ConteinerArray(int size):
		m_size {size}
	{
		
		try
		{
			if (size < 0)
			{
				throw runtime_error(" Ошибка в переменной size");
			}
		}
		catch (const std::exception&ex)
		{
			cerr << "Exception: " << ex.what() << '\n';
		}
		
		if (size > 0)
			m_data = new int[size] {};
		
	}

	~ConteinerArray()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
	}

	int& operator[](int index)
	{
		try
		{
			if (index<0 && index>m_size)
			{
				throw runtime_error("Ощибка в переменной оператор");
			}
		}
		catch (const std::exception& ex)
		{
			cerr  << "Exception" << ex.what()<< endl;
		}
		
		
		return m_data[index];
	}

	int getSize() const { return m_size; }


	void reallocate(int newsize)
	{
		erase();
		if (newsize <= 0)
			return;
		m_data = new int[newsize];
		m_size = newsize;
	}

	void resize(int newsize)
	{
		if (newsize == m_size)
			return;
		if (newsize <= 0)
		{
			erase();
			return;
		}

		int* data{ new int[newsize] };
		if (m_size > 0)
		{
			int elementsTocopy{ (newsize > m_size) ? m_size : newsize };
			for (int index{ 0 }; index < elementsTocopy; ++index)
				data[index] = m_data[index];
		}
		delete[] m_data;
		m_data = data;
		m_size = newsize;
	}

	ConteinerArray(const ConteinerArray& a)
	{
		reallocate(a.getLength());
		for (int index{ 0 }; index < m_size; ++index)
			m_data[index] = a.m_data[index];
	}

	ConteinerArray& operator=(const ConteinerArray& a)
	{
		if (&a == this)
			return *this;
		reallocate(a.getLength());
		for (int index{ 0 }; index < m_size; ++index)
			m_data[index] = a.m_data[index];
		return *this;
	}

	void insertBEfore(int value, int index)
	{
		try
		{
			if (index < 0 && index > m_size)
			{
				throw runtime_error("Ошибка в функции insertBEfore"); 
			}
		}
		catch (const std::exception& e)
		{
			cerr << "Exception: " << e.what() << '\n';
		}

		int* data{ new int[m_size + 1] };
		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];
		data[index] = value;
		for (int after{ index }; after < m_size; ++after)
			data[after + 1] = m_data[after];

		delete[] m_data;
		m_data = data;
		++m_size;
	}


	void remove(int index)
	{
		try
		{
			if (index<0 && index>m_size)
			{
				throw runtime_error("Ошибка в функции remove");
			}
		}
		catch (const std::exception& ex)
		{
			cerr << "Exception: " << ex.what() << '\n';
		}

		if (m_size == 1)
		{
			erase();
			return;
		}

		int* data{ new int[m_size - 1] };

		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		for (int after{ index + 1 }; after < m_size; ++after)
			data[after - 1] = m_data[after];

		delete[] m_data;
		m_data = data;
		--m_size;


	}

	int getLength() const { return m_size; }
	

};
#endif

