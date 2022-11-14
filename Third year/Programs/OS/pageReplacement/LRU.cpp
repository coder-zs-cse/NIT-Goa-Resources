#include<bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
	
	unordered_set<int> pageRecords;
	unordered_map<int, int> pageLastUsed;
	int pageFaults = 0;
	for (int i=0; i<n; i++)
	{
		if (pageRecords.size() < capacity)
		{
			if (pageRecords.find(pages[i])==pageRecords.end())
			{
				pageRecords.insert(pages[i]);
				pageFaults++;
			}
			pageLastUsed[pages[i]] = i;
		}
		else
		{
			if (pageRecords.find(pages[i]) == pageRecords.end())
			{
				int lru = INT_MAX, val;
				for (auto it=pageRecords.begin(); it!=pageRecords.end(); it++)
				{
					if (pageLastUsed[*it] < lru)
					{
						lru = pageLastUsed[*it];
						val = *it;
					}
				}
				pageRecords.erase(val);
				pageRecords.insert(pages[i]);
				pageFaults++;
			}
			pageLastUsed[pages[i]] = i;
		}
	}

	return pageFaults;
}

// Driver code
int main()
{
	int pages[] = {0 ,4, 1 ,4, 2 ,4 ,3 ,4 ,2 ,4 ,0, 4 ,1 ,4, 2, 4, 3, 4};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 3;
	cout << pageFaults(pages, n, capacity);
	return 0;
}
