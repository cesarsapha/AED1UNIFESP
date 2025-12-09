#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

int vis[110];
char dijkstra[110][110];

int x, final ;
void dfs(int);

void dfs(int u)
{

    int i;
    vis[u] = true;

    for (i = 0; i < x; ++i)
        if (dijkstra[u][i])
            if (!vis[i])
                dfs(i), final ++;

}

int main()
{

    int n, y;
    int q, u, v, i;

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &q);
        scanf("%d %d", &x, &y);
        memset(vis, 0, sizeof(vis));
        memset(dijkstra, 0, sizeof(dijkstra));
        for (i = 0; i < y; ++i)
        {
            scanf("%d %d", &u, &v);
            dijkstra[u][v] = dijkstra[v][u] = true;

        }
        final  = 0;
        dfs(q);
        printf("%d\n", final  << 1);

    }
    return 0;
}
