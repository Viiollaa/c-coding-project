#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int duration;
    int wait;
    int waitlist[105];
    int check;
    int earlyfinish;
}task;
typedef struct {
    int totaltask;
    task tasks[105];
}project;
int main()
{
    int numprj;
    if (scanf("%d",&numprj)!=1)return 0;
    for(int g =0; g<numprj; g++){
        project prj;
        scanf("%d",&prj.totaltask);

        for (int i = 1; i<=prj.totaltask;i++){
        prj.tasks[i].check =0;
        prj.tasks[i].earlyfinish = 0;
    }

        for (int i = 1; i <= prj.totaltask;i++){
            scanf("%d %d",&prj.tasks[i].duration, &prj.tasks[i].wait);
            for(int j = 0; j<prj.tasks[i].wait;j++){
                scanf("%d",&prj.tasks[i].waitlist[j]);

                int next = prj.tasks[i].waitlist[j];
                prj.tasks[next].check++;
            }
        }
        int process[105] = {0};
        int maxtime = 0;
        for (int i = 1; i<= prj.totaltask; i++){
            if (prj.tasks[i].check == 0){
                prj.tasks[i].earlyfinish = prj.tasks[i].duration;
            }
        }
        for (int k =0; k<prj.totaltask;k++){
            int now = -1;

            for(int i = 1; i<=prj.totaltask; i++){
                if (prj.tasks[i].check ==0 && !process[i]){
                    now = i;
                    break;
                }
            }
            if (now == -1) break;
            process[now] = 1;

            for (int j = 0; j<prj.tasks[now].wait;j++){
                int next2 = prj.tasks[now].waitlist[j];

                int willend = prj.tasks[now].earlyfinish + prj.tasks[next2].duration;

                if (willend> prj.tasks[next2].earlyfinish){
                    prj.tasks[next2].earlyfinish = willend;
                }
                prj.tasks[next2].check--;
            }
        }

        for (int i = 1; i<=prj.totaltask;i++){
            if (prj.tasks[i].earlyfinish>maxtime){
                maxtime = prj.tasks[i].earlyfinish;
            }
        }

        printf("%d\n",maxtime);
    }

    return 0;
}
