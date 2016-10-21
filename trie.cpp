
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node {
    int status;
    int pref_count;
    struct node *child[26];
};
struct node *root = NULL;
void init() {
    struct node *head = (struct node *)calloc(sizeof(struct node),1);
    head->pref_count = 0;
    head->status = 0;
    root = head;
}
void insert(string s) {
    struct node *current = root;
    current->pref_count++;
    for (int i = 0; i < s.length(); i++) {
        int let = (int) s[i] - 'a';
        if (current->child[let] == NULL) {
            current->child[let] = (struct node *)calloc(sizeof(struct node),1);
        }
        current->child[let]->pref_count++;
        current = current->child[let];
    }
    current->status = 1;
}
int search(string s) {
    struct node *current = root;
    for (int i = 0; i < s.length(); i++) {
        int let = (int) s[i] - 'a';
        if (current->child[let] == NULL) {
            return false;
        }
        current = current->child[let];
    }   
    return current->pref_count;
}
int main() {
    init();
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }
    string s1;
    cin >> s1;
    int val = search(s1);
    cout << val << endl;
    return 0;
}
