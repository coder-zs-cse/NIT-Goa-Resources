#include <bits/stdc++.h>
using namespace std;
// in a frame or not
bool search(int key, vector<int>& frames)
{
	for (int i = 0; i < frames.size(); i++)
		if (frames[i] == key)
			return true;
	return false;
}
int predict(int pages[], vector<int>& frames, int pageCount, int index)
{
	int res = -1, farthest = index;
	for (int i = 0; i < frames.size(); i++) {
		int j;
		for (j = index; j < pageCount; j++) {
			if (frames[i] == pages[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}
		if (j == pageCount)
			return i;
	}

	return (res == -1) ? 0 : res;
}

void optimalPage(int pages[], int pageCount, int frameNumber)
{
	vector<int> frames;
	int hit = 0;
	for (int i = 0; i < pageCount; i++) {
		if (search(pages[i], frames)) {
			hit++;
			continue;
		}
		if (frames.size() < frameNumber)
			frames.push_back(pages[i]);
		else {
			int j = predict(pages, frames, pageCount, i + 1);
			frames[j] = pages[i];
		}
	}
	cout << "No. of hits = " << hit << endl;
	cout << "No. of misses = " << pageCount - hit << endl;
}

// Driver Function
int main()
{
	int pages[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
	int pageCount = sizeof(pages) / sizeof(pages[0]);
	int frameNumber = 4;
	optimalPage(pages, pageCount, frameNumber);
	return 0;
}

// This code is contributed by Karandeep Singh
