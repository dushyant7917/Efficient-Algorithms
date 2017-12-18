#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

struct Trie{
  struct Trie *child[26]; // reference to a to z alphabets
  bool is_EOW; // flag for indicating end of word or not
};

struct Trie *get_node(){
  struct Trie *ptr = new Trie;

  ptr->is_EOW=false;

  fr(i,0,26) ptr->child[i]=NULL;

  return ptr;
}

void insert(struct Trie *root,string word){
  struct Trie *ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) ptr->child[pos]=get_node();
    ptr=ptr->child[pos];
  }

  ptr->is_EOW=true;
}

bool search(struct Trie *root,string word){
  struct Trie *ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) return false;
    ptr=ptr->child[pos];
  }

  return (ptr!=NULL && ptr->is_EOW==true);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string list[5]={"a","abc","abccd","egh","eghik"};

  struct Trie *root=get_node();

  fr(i,0,5) insert(root,list[i]);

  fr(i,0,5) cout<<search(root,list[i])<<"\n";

  string new_words[2]={"abcd","eghdsd"};

  fr(i,0,2) cout<<search(root,new_words[i])<<"\n";

  return 0;
}
