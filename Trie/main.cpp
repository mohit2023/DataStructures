#include <iostream>
#include "Trie.cpp"
using namespace std;

int main()
{
    Trie dict;
    dict.insert("apple");
    bool ans=dict.search("apple");
    cout<<ans<<'\n';
    dict.remove("app");
    ans=dict.search("apple");
    cout<<ans<<'\n';
    dict.insert("app");
    ans=dict.search("app");
    cout<<ans<<'\n';
    return 0;
}
