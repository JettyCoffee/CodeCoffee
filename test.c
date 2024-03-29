#include<stdio.h>
int main()
{
	int n,L;//分别表示内存大小和请求次数
	int ad;
	int now;//用来记录被命中的数据 
	int cnt=0;
	int fake;
	scanf("%d%d",&n,&L);
	if(L<n){
		for(int i=0;i<L;i++){
			scanf("%d",&fake);
			printf("NO\n");
		}
		return 0;
	}
	int save[n];
	for(int i=n-1;i>=0;i--){
		scanf("%d",&save[i]);
		printf("NO\n");
	} 
	for(int k=0;k<L-n;k++){
		scanf("%d",&ad);
		for(int i=0;i<n;i++){//检查是否命中 
			if(ad==save[i]){
				cnt++;//使cnt标记成1 
				printf("YES ");
				printf("%d\n",i+1);
				now=i;
				for(int i=now;i>0;i--){
					save[i]=save[i-1];
				}
				save[0]=ad;
				break;//命中后，跳出大for循环 
			}
		}
	    if(cnt==0){
	    	printf("NO\n");
	    	for(int i=n-1;i>0;i--){
	    		save[i]=save[i-1];
			}
			save[0]=ad;
		}
		cnt=0;

	}
return 0;
}