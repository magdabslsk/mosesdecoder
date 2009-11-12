/*
 *  Cube.cpp
 *  moses-chart
 *
 *  Created by Hieu Hoang on 18/08/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Cube.h"

using namespace std;

namespace MosesChart
{
Cube::~Cube()
{
	assert(m_sortedByScore.size() == 0);

	UniqueCubeEntry::iterator iter;
	for (iter = m_uniqueEntry.begin(); iter != m_uniqueEntry.end(); ++iter)
	{
		QueueEntry *entry = *iter;
		delete entry;
	}
	m_uniqueEntry.clear();
	
	//assert(m_uniqueEntry.size() == 0);
}

bool Cube::Add(QueueEntry *queueEntry)
{
	pair<UniqueCubeEntry::iterator, bool> inserted = m_uniqueEntry.insert(queueEntry);
	
	if (inserted.second)
	{ // inserted
		m_sortedByScore.push(queueEntry);
	}
	else
	{ // already there
		//cerr << "already there\n";
		delete queueEntry;
	}
	
	//assert(m_uniqueEntry.size() == m_sortedByScore.size());
	
	return inserted.second;
}

QueueEntry *Cube::Pop()
{
	QueueEntry *entry = m_sortedByScore.top();
	m_sortedByScore.pop();

	return entry;
}
	
}

