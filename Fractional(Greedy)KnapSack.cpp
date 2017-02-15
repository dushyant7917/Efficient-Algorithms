#include<iostream>
#include<algorithm>

using namespace std;

struct Item
{
  double value;
  double weight;
  double ratio;
  Item(int v, int w)
  {
    value = v; cout << "value: " << value << " ";
    weight = w; cout << "weight: " << weight << " ";
    ratio = v / w; cout << "ratio: " << ratio << endl;
  }
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
      cout << "a[i].weight: " << a[i].weight << " " << "req_W: " << req_W << endl;
      max_P += a[i].value; cout << "max_P: " << max_P << endl;
      cur_W += a[i].weight; cout << "cur_W: " << cur_W << endl;
      req_W = W - cur_W; cout << "req_W: " << req_W << endl;
    }
    else
    {
      cout << "a[i].weight: " << a[i].weight << " " << "req_W: " << req_W << endl;
      cout << "cur_W: " << cur_W << endl;
      max_P += req_W * a[i].ratio;
      cout << "max_P: " << max_P << endl;
      cout << "req_W: " << req_W << endl;
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
  Item obj[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(obj)/sizeof(obj[0]);
  sort(obj, obj + n, cmp);

  cout << "Maximum Profit: " << KnapSack(obj, n, max_w);

  return 0;
}
