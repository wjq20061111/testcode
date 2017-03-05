#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mycompare(const pair<float, float> &p1, const pair<float, float> &p2)
{
	return p1.second < p2.second;
}

void print(const vector<pair<float, float>> &tab)
{
	for (int i = 0; i < tab.size(); i++)
		cout << tab.at(i).first << " " << tab.at(i).second << "\n";
	cout << "\n";
}

int main()
{
	
	vector<pair<float, float>> tab;
	pair<float, float> tem;
	tem.first=2.0;
	tem.second = 1.0;
	tab.push_back(tem);
	tem.first = 1.0;
	tem.second = 3.0;
	tab.push_back(tem);
	tem.first = 5.0;
	tem.second = 2.0;
	tab.push_back(tem);

	print(tab);
	sort(tab.begin(), tab.end(), mycompare);
	print(tab);

	cout << tab.size() << "\n";
	tab.clear();
	cout << tab.size() << "\n";
	tab.push_back(tem);
	cout << tab.size() << "\n";
	print(tab);
	return 0;
}