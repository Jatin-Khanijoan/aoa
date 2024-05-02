#include <stdio.h>
#include <string.h>

int naive_match(char st[], char pat[]);

int main() {
    char txt[100], pat[100];

    printf("Enter the Text: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0';

    printf("Enter the Pattern: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';

    int pos = naive_match(txt, pat);
    if (pos == -1)
        printf("\nNo match found\n");
    else
        printf("Naive String Matching: Match found at position %d\n", pos);

    return 0;
}

int naive_match(char st[], char pat[]) {
    int n = strlen(st);
    int m = strlen(pat);
    int i, j;
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (st[i + j] != pat[j])
                break;
        }
        if (j == m)
            return i + 1;
    }
    return -1;
}
