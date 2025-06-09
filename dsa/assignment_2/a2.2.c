#include <stdio.h>
#include <stdlib.h>

struct TrieNode {
    struct TrieNode *children[2];
    int count;
};

typedef struct TrieNode* Trie;


Trie create_trienode(){
    Trie node = (Trie)malloc(sizeof(struct TrieNode));
    node->children[0] = NULL;
    node->children[1] = NULL;
    node->count = 0;
    return node;
}

void insert(Trie root, int x) {
    Trie node = root;
    for (int i = 15; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (node->children[bit]==NULL) {
            node->children[bit] = create_trienode();
        }
        node = node->children[bit];
        node->count++;
    }
}

int trie_search(Trie root, int x, int limit) {
    int ans = 0;
    Trie node = root;
    for (int i = 15; i >= 0 && node; i--) {
        int bit = (x >> i) & 1;
        int limitBit = (limit >> i) & 1;
        if (limitBit==1) {
            if (node->children[bit]) {
                ans += node->children[bit]->count;
            }
            node = node->children[bit ^ 1];
        } else {
            node = node->children[bit];
        }
    }
    return ans;
}

int count_pairs(int *nums, int n, int low, int high) {
    Trie root = trie_node_init();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += trie_search(root, nums[i], high + 1) - trie_search(root, nums[i], low);
        trie_insert(root, nums[i]);
    }
    return ans;
}

int main() {
    int nums[] = {2,3,5,7,11};
    int n = sizeof(nums) / sizeof(nums[0]);
    int low = 7, high = 13;

    int result = count_pairs(nums, n, low, high);
    int a = n*(n-1);
    a = a/2;
    result = a - result;
    printf("%d\n",result);

    return 0;
}
