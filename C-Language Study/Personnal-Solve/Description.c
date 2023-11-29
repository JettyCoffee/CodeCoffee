#include <stdio.h>

struct ListNode *readlist();

struct ListNode *deletem( struct ListNode *L, int m);

int main()
{
    ListNode *readlist;
}

struct ListNode *readlist()
{
    for( int i=0;;i++ )
    {
        int n, *readlist;
        scanf("%d",&n);
        if( n==-1 )
        {
            break;
        }
        *readlist = &n;
    }
}