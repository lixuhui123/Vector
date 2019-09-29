#pragma once
#include <iostream>
using namespace std;
/* �ֶ�ʵ��vector */
/* 9.27���£�֪�����ӣ�һ���Ǵ���ǧ��֮�У�ʼ������*/
namespace work
{
    template<class T>
    class Vector
    {
		/* ģ����,��������˳���*/
    	T* m_start;/* ָ�����ݶεĿ�ʼ */
    	T* m_finish;/* ָ����Ч���ݶεĽ�β */
    	T* m_endofstorage;/* ָ�������ռ�Ľ�β */
    public:
		//Vector<int>::iterator fi;
		//iterator T*;
    	typedef T* iterator;
		/* ����iterator������ΪT*����,iterator��һ���࣬�˴�ʵ����ΪT*����T*����Ϊiterator  */
    	typedef const T* const_iterator;
    	Vector() :m_start(nullptr), m_finish(nullptr), m_endofstorage(nullptr)
    	{
    		/* �յĹ��� */
    	}
    	Vector(int n, const T& val = T())/* �˴�Ϊʲô��T() */
    	{
			/* �漰��������������� */
             reserve(n);
    		for (int i=0;i<n;++i)
    		{
				m_start[i] = val;
    		}
			m_finish = m_start + n ;
			/* m_endofstorageֻ����reserve����ı� */
    	}
		Vector(T*_statr, T*_end):
			                     m_start(nullptr),
			                     m_finish(nullptr),
			                     m_endofstorage(nullptr)
		{
			/* ��һ�οռ�ȥʵ����vector */
			size_t _size = _end - _statr;
			reserve(_size);
			for (size_t i=0;i<_size;++i)
			{
				m_start[i] = _statr[i];
			}
			m_finish = m_start + _size;
			
		}
		iterator insert(iterator pos,const T & val)
		{
			/* ���ڵ�����ʧЧ������ */
			/* ��λ��ǰ����һ��Ԫ�أ��������ݵ�����ƶ� */
			int tmp = pos - m_start;
			reserve(size() + 1);
			pos = m_start + tmp;
			/*���ϲ������˵�����ʧЧ���� */
			for (size_t i = size() - 1; i >= pos - m_start; --i)
			{
				/* �Լ�ҲҪ�ƶ� */
				m_start[i + 1] = m_start[i];
			}
			*pos = val;
			m_finish++;
			return pos;
		}

		iterator insert(iterator pos, int n, const T &val)
		{
			int tmp = pos - m_start;
			reserve(size() + n);
			pos = m_start + tmp;
			int i;
			for (i = size() - 1; i >= pos - m_start; i--)
			{
				m_start[i + n] = m_start[i];
			}

			for (i = 0; i < n; i++)
			{
				pos[i] = val;
			}

			m_finish += n;

			return pos;
		}
		iterator insert(iterator pos, const T * start, const T * end)
		{
			int tmp = pos - m_start;
			int extsize = end - start;
			reserve(size() + extsize);
			pos = m_start + tmp;

			int i;
			for (i = size() - 1; i >= pos - m_start; i--)
			{
				m_start[i + extsize] = m_start[i];
			}

			for (i = 0; i < extsize; i++)
			{
				pos[i] = start[i];
			}

			m_finish += extsize;

			return pos;

		}
		iterator erase(iterator pos)
		{
			for (int i=pos-m_start;i<size()-1;++i)
			{
				m_start[i] = m_start[i + 1];
			}
			m_finish--;
			return pos;
		}
		iterator erase(iterator start, iterator end)
		{
			int tmp = end - start;
			int n = m_finish - end;
			for (int i = 0; i < n; ++i)
			{
				m_start[start + i] = m_start[end + i];
			}
			m_finish -= tmp;
			return start;
			 
		}
		void push_back(const T & val)
		{
			reserve(size() + 1);
			*m_finish = val;
			m_finish++;
		}
		void pop_back()
		{
			m_finish--;
		}
    	size_t size()
    	{
    		return m_finish - m_start;/* ����Ԫ�صĸ�������Ϊָ������������ */
    	}
    	size_t capacity()
    	{
    		return m_endofstorage - m_start;/* ���������Ĵ�С */
    	}
    	void reserve(size_t isize)
    	{
			/* ��Ҫ�Ǽ��Ϳ����ڴ�ռ� */
    		size_t icapacity=capacity();//null-null=0
    		if (icapacity<isize)
    		{
				/* �Զ�����С���ٿռ� */
    			if (icapacity==0)
    			{
    				icapacity = 1;/* ��֤����*=����һֱΪ0 */
    			}
    			while (icapacity < isize)
    			{
    				icapacity *= 2;
    			}
				//m_endofstorage += icapacity;
    		}
    		
    		T* tmp = new T[icapacity];
			int oldsize = size();
    		m_finish = tmp + oldsize;/* �ƶ�ָ��ָ���,ֻ�����ԭ���Ĵ�С,size()������ */
    		m_endofstorage = tmp + icapacity;/* �ƶ�ָ���ָ��Ψһ�����������Ҫ�ı��С���� */
			/* �������ƶ����¿��ٵĿռ䵱��ȥ */
			 
    		if (m_start!=nullptr)
    		{
    			for (size_t i=0;i< oldsize;++i)
    			{
    				tmp[i] = m_start[i];
    			}
    			
    			delete[] m_start;
    		}
    		m_start = tmp;
    	}
		/*����Ҫ�û��Լ���������������Ϊ���ٿռ���ͷŶ���������������� */
		iterator begin()
		{
			return m_start;
		}
		iterator end()
		{
			return m_finish ;
		}
		void resize(size_t isize,const T& val = T())
		{
			/* �ı�vector��size,��������Ŀռ����� T*/
			reserve(isize);
			for (size_t i=size();i<isize;++i)
			{
				m_start[i] = val;
			}
			m_finish = m_start + isize;
		}
		T & operator[](size_t i)
		{
			return m_start[i];
		}
		Vector operator=(Vector & v)
		{
			if (this!=&v)
			{
				reserve(v.size());
				for (int i=0;i<v.size();++i)
				{
					m_start[i] = v.m_start[i];

				}
				m_finish += v.size();
			}
			return *this;
		}
    };
	
}