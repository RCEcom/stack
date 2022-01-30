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
	//데이터를 추가하기 위한 노드 생성
	CStackNode<T>* pNewNode = new CStackNode<T>();
	pNewNode->m_Data = data;

	//새로 생성한 노드는 전에 있던 기존 노드를 가리키도록 한다.
	pNewNode->m_pNext = m_pNode;

	//새로 생성한 노드가 대장이 될 수 있도록 한다.(가장 마지막 stack data)
	m_pNode = pNewNode; 
	++m_Count;
}

template<typename T>
inline T CStackList<T>::pop()
{
	//맨 위에 있는 노드의 다음 노드 정보를 가져온다.
	PNODE m_pNext = m_pNode->m_pNext;
	T m_Data = m_pNode->m_Data;
	//마지막 노드를 지운다.
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
	while (pNode) //없을떄까지
	{
		//다음 노드 get
		PNODE pNext = pNode->m_pNext;
		delete(pNode);

		//다음 삭제할 노드 갱신
		pNode = pNext;
	}
}
