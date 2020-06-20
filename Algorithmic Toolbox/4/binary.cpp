#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(vector<int> &a, int x)
{
  int left = 0, right = (int)a.size()-1;
  if (right < left)
  {
    return left - 1;
  }
  int mid = 0;
  while (left <= right)
  {
    mid = left + (right - left) / 2;
    if (x == a[mid])
    {
      return mid;
    }
    else if (x <= a[mid])
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return -1;
  //write your code here
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

void FindinFirst(vector<int> First, int n, vector<int> Second, int k) {
	for (int i = 0; i < k; i++)
		std::cout << binary_search(First, Second[i]) << " ";
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  FindinFirst(a,n,b,m);
  
}
