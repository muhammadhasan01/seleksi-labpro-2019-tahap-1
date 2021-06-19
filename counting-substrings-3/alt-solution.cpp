/** START OF HARAM OPTIMIZATION **/
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
/** END OF HARAM OPTIMIZATION **/

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int C = 26;
const int T = 3e2 + 1;

struct Node{
    int cnt = 0;
    int dep;
    Node * next[C] = {
        0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0
    };
    Node * link = 0;
    Node * p;
    char pch;

    Node(){}
    Node(Node * p, char pch, int dep = 0) : p(p), pch(pch), dep(dep) {}
};

vector<Node *> allnodes[T];
struct Trie{
    Node * head;
    
    Trie(){
        head = new Node(0, 0);
    }
    Node * add(string s){
        Node * cur = head;
        int dep = 1;
        for (char &x : s){
            int dig = x - 'a';
            if (!cur->next[dig]){
                cur->next[dig] = new Node(cur, x, dep);
                allnodes[dep].pb(cur->next[dig]);
            }
            cur = cur->next[dig];
            dep++;
        }
        return cur;
    }
};

Node * go(Node * node, char ch);
Node * get_link(Node * node){
    if (!node->link){
        if (node->dep == 0) return node->link = node;
        else if (node->dep == 1) return node->link = node->p;
        return node->link = go(get_link(node->p), node->pch);
    }
    return node->link;
}
Node * go(Node * node, char ch){
    int dig = ch - 'a';
    if (!node->next[dig]){
        if (node->dep == 0) node->next[dig] = node;
        else node->next[dig] = go(get_link(node), ch);
    }
    return node->next[dig];
}

Trie trie;
string s;
int q;

void propagate(){
    for (int i=T-1;i>0;i--){
        for (Node* &x : allnodes[i]){
            Node * link = get_link(x);
            link->cnt += x->cnt;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    cin >> q;
    vector<Node *> vec;
    while (q--){
        string t;
        cin >> t;
        vec.pb(trie.add(t));
    }
    {
        Node * cur = trie.head;
        for (char &x : s){
            cur = go(cur, x);
            cur->cnt++;
        }
    }
    propagate();
    for (Node* &x : vec){
        cout << x->cnt << el;
    }

    return 0;
}