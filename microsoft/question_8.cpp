#include <bits/stdc++.h>
using namespace std;

void connect(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);

            if (sz)
            {
                curr->nextRight = q.front();
            }
            else
            {
                curr->nextRight = NULL;
            }
        }
    }
}