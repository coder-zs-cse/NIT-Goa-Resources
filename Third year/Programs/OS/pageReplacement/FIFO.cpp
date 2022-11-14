#include<bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
	unordered_set<int> pageRecord;
	queue<int> pageQueue;
	int pageFaults = 0;
	for (int i=0; i<n; i++)
	{
		if (pageRecord.size() < capacity)
		{
			if (pageRecord.find(pages[i])==pageRecord.end())
			{
				pageRecord.insert(pages[i]);
				pageFaults++;
				pageQueue.push(pages[i]);
			}
		}
		else
		{
			if (pageRecord.find(pages[i]) == pageRecord.end())
			{
				int val = pageQueue.front();
				pageQueue.pop();
				pageRecord.erase(val);
				pageRecord.insert(pages[i]);
				pageQueue.push(pages[i]);
				pageFaults++;
			}
		}
	}

	return pageFaults;
}

// Driver code
int main()
{
	int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 4;
	cout << pageFaults(pages, n, capacity);
	return 0;
}
