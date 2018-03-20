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
#define N 26
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(x) x.size()

struct Trie{
  struct Trie *child[N]; // reference to a to z alphabets(N=26)
  bool is_EOW; // flag for indicating end of word or not
};

Trie* get_node(){
  Trie* ptr = new Trie;

  ptr->is_EOW=false;

  fr(i,0,N) ptr->child[i]=NULL;

  return ptr;
}

// inserts a word in the trie data structure
void insert(Trie*& root,string word){
  if(root==NULL) root=get_node();

  Trie* ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) ptr->child[pos]=get_node();
    ptr=ptr->child[pos];
  }

  ptr->is_EOW=true;
}

// checks if the word is present as complete word
bool complete_search(Trie* root,string word){
  Trie* ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) return false;
    ptr=ptr->child[pos];
  }

  return (ptr!=NULL && ptr->is_EOW==true);
}

// checks if the word is present as complete word or prefix of some other word
bool prefix_search(Trie* root,string word){
  Trie* ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'a';
    if(ptr->child[pos]==NULL) return false;
    ptr=ptr->child[pos];
  }

  return (ptr!=NULL);
}

bool has_child(Trie* node){
  fr(i,0,26) if(node->child[i]!=NULL) return true;
  return false;
}

// delets a word from the true data structure
bool delete_word(Trie*& root,string word,ll ind){
  if(root==NULL) return false;

  if(word[ind]!='\0'){
    ll pos=word[ind]-'a';
    if(root!=NULL && root->child[pos]!=NULL && delete_word(root->child[pos],word,ind+1) && !root->is_EOW){
      if(!has_child(root)){
        delete root;
        root=NULL;
        return true;
      }
      else return false;
    }
  }

  if(word[ind]=='\0' && root->is_EOW){
    if(!has_child(root)){
      delete root;
      root=NULL;
      return true;
    }
    else{
      root->is_EOW=false;
      return false;
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string list[5]={"a","abc","abccd","egh","eghik"};

  Trie* root=NULL;

  fr(i,0,5) insert(root,list[i]);

  fr(i,0,5){
    if(complete_search(root,list[i])){
      cout<<list[i]<<" is found as complete word\n";
    }
  }
  cout<<"\n";

  string new_words[3]={"ab","eghi","a"};

  fr(i,0,3){
    if(complete_search(root,new_words[i])){
      cout<<new_words[i]<<" is found as complete word\n";
    }
  }
  cout<<"\n";

  fr(i,0,3){
    if(prefix_search(root,new_words[i])){
      cout<<new_words[i]<<" is found as prefix\n";
    }
  }
  cout<<"\n";

  delete_word(root,"abc",0);

  if(prefix_search(root,"abc")) cout<<"abc is found as prefix\n";
  else cout<<"abc not found as prefix\n";

  if(complete_search(root,"abc")) cout<<"abc is found as complete word\n";
  else cout<<"abc not found as complete word\n";

  if(prefix_search(root,"abccd")) cout<<"abccd is found as prefix\n";
  else cout<<"abccd not found as prefix\n";

  if(complete_search(root,"abccd")) cout<<"abccd is found as complete word\n";
  else cout<<"abccd not found as complete word\n";

  return 0;
}
