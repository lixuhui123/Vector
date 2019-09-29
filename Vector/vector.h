#pragma once
#include <iostream>
using namespace std;
/* 手动实现vector */
/* 9.27更新，知道分子，一无是处，千里之行，始于足下*/
namespace work
{
    template<class T>
    class Vector
    {
		/* 模板类,容器就是顺序表*/
    	T* m_start;/* 指向数据段的开始 */
    	T* m_finish;/* 指向有效数据段的结尾 */
    	T* m_endofstorage;/* 指向容量空间的结尾 */
    public:
		//Vector<int>::iterator fi;
		//iterator T*;
    	typedef T* iterator;
		/* 定义iterator迭代器为T*类型,iterator是一种类，此处实例化为T*，将T*命名为iterator  */
    	typedef const T* const_iterator;
    	Vector() :m_start(nullptr), m_finish(nullptr), m_endofstorage(nullptr)
    	{
    		/* 空的构造 */
    	}
    	Vector(int n, const T& val = T())/* 此处为什么是T() */
    	{
			/* 涉及到容量方面的问题 */
             reserve(n);
    		for (int i=0;i<n;++i)
    		{
				m_start[i] = val;
    		}
			m_finish = m_start + n ;
			/* m_endofstorage只会在reserve里面改变 */
    	}
		Vector(T*_statr, T*_end):
			                     m_start(nullptr),
			                     m_finish(nullptr),
			                     m_endofstorage(nullptr)
		{
			/* 用一段空间去实例化vector */
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
			/* 存在迭代器失效的问题 */
			/* 往位置前插入一个元素，存在数据的向后移动 */
			int tmp = pos - m_start;
			reserve(size() + 1);
			pos = m_start + tmp;
			/*以上步骤解决了迭代器失效问题 */
			for (size_t i = size() - 1; i >= pos - m_start; --i)
			{
				/* 自己也要移动 */
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
    		return m_finish - m_start;/* 返回元素的个数，因为指定了数据类型 */
    	}
    	size_t capacity()
    	{
    		return m_endofstorage - m_start;/* 返回容量的大小 */
    	}
    	void reserve(size_t isize)
    	{
			/* 主要是检测和开辟内存空间 */
    		size_t icapacity=capacity();//null-null=0
    		if (icapacity<isize)
    		{
				/* 以二倍大小开辟空间 */
    			if (icapacity==0)
    			{
    				icapacity = 1;/* 保证后面*=不会一直为0 */
    			}
    			while (icapacity < isize)
    			{
    				icapacity *= 2;
    			}
				//m_endofstorage += icapacity;
    		}
    		
    		T* tmp = new T[icapacity];
			int oldsize = size();
    		m_finish = tmp + oldsize;/* 移动指针指向的,只会加上原来的大小,size()有问题 */
    		m_endofstorage = tmp + icapacity;/* 移动指针的指向，唯一在这个函数中要改变大小的量 */
			/* 将数据移动到新开辟的空间当中去 */
			 
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
		/*不需要用户自己定义析构函数因为开辟空间和释放都在析构里面完成了 */
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
			/* 改变vector的size,并将多余的空间填上 T*/
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