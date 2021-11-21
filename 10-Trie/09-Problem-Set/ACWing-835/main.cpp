/*
 * ACWing 835. Trie字符串统计
 * */
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1e5 + 10;

int tr[MAX_N][26], cnt[MAX_N], idx;
char str[MAX_N];

int n;

void insert(char *s) {
    int p = 0;
    for (int i = 0; i < strlen(s); ++i) {
        int u = s[i] - 'a';
        if (!tr[p][u])
            tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++;
}

int query(char *s) {
    int p = 0;
    for (int i = 0; i < strlen(s); ++i) {
        int u = s[i] - 'a';
        if (!tr[p][u])
            return 0;
        p = tr[p][u];
    }
    return cnt[p];
}

int main() {
    scanf("%d", &n);
    while (n--) {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') {
            insert(str);
        } else if (*op == 'Q') {
            printf("%d\n", query(str));
        }
    }
    return 0;
}
