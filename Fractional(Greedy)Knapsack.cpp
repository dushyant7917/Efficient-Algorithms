#include<iostream>
#include<algorithm>

using namespace std;

struct Item
{
  double value;
  double weight;
  double ratio;
};

bool cmp(struct Item a, struct Item b)
{
  return (a.ratio > b.ratio);
}

double KnapSack(struct Item a[], int n, int W)
{
  double max_P = 0.0;
  double cur_W = 0.0;
  double req_W = W;

  for(int i = 0; i < n; i++)
  {
    if(a[i].weight <= req_W)
    {
      max_P += a[i].value;
      cur_W += a[i].weight;
      req_W = W - cur_W;
    }
    else
    {
      max_P += req_W * a[i].ratio;
      break;
    }
  }

  return max_P;
}

int main()
{
  int max_w;
  cout << "Enter max weight: ";
  cin >> max_w;
  int n;
  cout << "\nEnter number of items: ";
  cin >> n;
  Item obj[n];
  for(int i = 0; i < n; i++)
  {
    cout << "\nEnter value and weight pairs respectively: ";
    cin >> obj[i].value >> obj[i].weight;
    obj[i].ratio = obj[i].value / obj[i].weight;
  }

  sort(obj, obj + n, cmp);

  cout << "Maximum Profit: " << KnapSack(obj, n, max_w);

  return 0;
}
