#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strArr[5] = { "(2,1)", "(4, 2)", "(2, 7)", "(5, 9)", "(7, 5)" };
	const int n = 5;
	const int nn = n * 2;
	//string strArr[2] = { "(2,1)", "(3, 1)" };
	string str;
	int store_num[nn];
	int k = 0;
	int p = 0;
	int c = 0;
	string temp;
	int parent[n];
	int child[n];
	
	for (int i = 0; i < n; i++)
	{
		temp = strArr[i];
		for (int j = 0; j < temp.size(); j++)
		{
			if (isdigit(temp[j]))
			{
				str = temp[j];
				store_num[k] = stoul(str, 0, 10);
				//cout << store_num[k];
				k = k + 1;
			}
		}
		
	}
	//cout << endl << "Parents ";
	int ss = size(store_num);
	for (int i = 0; i < ss; i+=2)
	{
		parent[p] = store_num[i];
		//cout << parent[p];
		p = p + 1;
		
	}
	//cout << endl << "Childs";
	for (int i = 1; i < ss; i += 2)
	{
		child[c] = store_num[i];
		//cout << child[c];
		c = c + 1;
		
	}
	
	int search_root[n];
	bool root = true;
	//int k;
	for (int i = 0; i < n; i++) // search a root value; if no root, then, no binary tree; return false
	{
		for (int j = 0; j < n; j++)
		{
			if (parent[j] == child[i])
			{
				search_root[i] = 0;
			}
			else { search_root[i] = 1; }
			
		}
		//cout << search_root[i];
		
	}

	for (int i = 0; i < n; i++)
	{
		if (search_root[i] == 0)
		{
			
			root = true;
			break;
		}
		else { root = false; }

	}

	if (root == false)
	{
		cout << endl << "false";
	}
	else { cout << endl << "true"; }
}