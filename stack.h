#pragma once
#include <iostream>
#include <assert.h>
#include <cassert>

template<typename T>
struct CStackNode
{
private:
	template<typename T>
	friend class CStackList;
private:
	T m_Data;  
	CStackNode<T>* m_pNext;

public:
	CStackNode() : m_pNext(nullptr), m_Data() {}
	~CStackNode() {}
};

template<typename T>
class CStackList
{
private:
	typedef CStackNode<T> NODE;
	typedef CStackNode<T>* PNODE;
private:
	PNODE m_pNode;
	int m_Count;

public:
	void push(const T& data);
	T pop();
	T top();
	bool empty();
	int size();
	void clear();

public:
	CStackList() : m_pNode(nullptr), m_Count(0)
	{

	}
	~CStackList()
	{
		clear();
	}
};

template<typename T>
inline void CStackList<T>::push(const T& data)
{
	//�����͸� �߰��ϱ� ���� ��� ����
	CStackNode<T>* pNewNode = new CStackNode<T>();
	pNewNode->m_Data = data;

	//���� ������ ���� ���� �ִ� ���� ��带 ����Ű���� �Ѵ�.
	pNewNode->m_pNext = m_pNode;

	//���� ������ ��尡 ������ �� �� �ֵ��� �Ѵ�.(���� ������ stack data)
	m_pNode = pNewNode; 
	++m_Count;
}

template<typename T>
inline T CStackList<T>::pop()
{
	//�� ���� �ִ� ����� ���� ��� ������ �����´�.
	PNODE m_pNext = m_pNode->m_pNext;
	T m_Data = m_pNode->m_Data;
	//������ ��带 �����.
	delete m_pNode;
		
	m_pNode = m_pNext;

	m_Count--;

	return m_Data;
}

template<typename T>
inline T CStackList<T>::top()
{
	if (empty())
	{
		assert(false);
		return m_pNode->m_Data;
	}
}

template<typename T>
inline bool CStackList<T>::empty()
{

	return m_Count == 0; //true
}

template<typename T>
inline int CStackList<T>::size()
{
	return m_Count;
}

template<typename T>
inline void CStackList<T>::clear()
{
	PNODE pNode = m_pNode;
	while (pNode) //����������
	{
		//���� ��� get
		PNODE pNext = pNode->m_pNext;
		delete(pNode);

		//���� ������ ��� ����
		pNode = pNext;
	}
}
