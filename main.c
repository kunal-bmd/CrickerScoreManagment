#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define BA 11
#define BO 5
char competition[100],venue[100],n1[100],n2[100],no1[100],no2[100],twon[100],e[100],opt,innings1[20][6],innings2[20][6];
int wic=0,s=0,ns=1,bpos=1,s1,s2,w1,w2,x1,x2,f1,f2,n_ball=0,r1,r2;

struct batsmanA{
    char name[100];
    int runs;
    int fours;
    int sixes;
    int balls;
}b1[BA];

struct batsmanB{
    char name[100];
    int runs;
    int fours;
    int sixes;
    int balls;
}b2[BA];

struct bowerA{
    char name[100];
    int runs;
    int wickets;
    int extra;
}bo1[BO];

struct bowlerB{
    char name[100];
    int runs;
    int wickets;
    int extra;
}bo2[BO];

void rules(){
    printf("**TERMINOLOGY FOR OUTCOME ENTRY**\n");
    printf("1. D->Dot ball(0-Runs)\n");
    printf("2. 1->One run\n");
    printf("3. 2->Two runs\n");
    printf("4. 3->Three runs\n");
    printf("5. 4->Four runs(Boundary)\n");
    printf("6. 6->Six runs(Boundary)\n");
    printf("7. w->Wide(1-Run with no ball count)\n");
    printf("8. N->No ball(1-Run with no ball count)\n");
    printf("9. W->Wicket\n");
    printf("10. C->catch out\n");
    printf("========================================================================================================================================\n");
}

int main()
{
    time_t t;
    char opt;
    time(&t);
    printf("========================================================================================================================================\n");
    printf("\t\t\t\t\tCRICKET SCORE MANAGEMENT\n");
    printf("\t\t\t\t\t%s",ctime(&t));
    printf("COMPETITION :");
    scanf("%s",&competition);
    printf("VENUE :");
    scanf("%s",&venue);
    printf("MATCH PLAYED BETWEEN :");
    scanf("%s",&no1);
    printf("VERSUS :");
    scanf("%s",&no2);
    printf("TOSS WON BY :");
    scanf("%s",&twon);
    printf("ELECTED TO(BAT/BOWL) :");
    scanf("%s",&e);
    if((!strcmp(twon,no1) && (!strcmp("BAT",e))) || ((!strcmp(twon,no2)) && (!strcmp("BOWL",e)))){
        strcpy(n1,no1);
        strcpy(n2,no2);
    }
    else{
        strcpy(n1,no2);
        strcpy(n2,no1);
    }
    printf("========================================================================================================================================\n");
    printf("\t\t\tTEAM::%s\n\n",n1);
    printf("BATTING AND BOWLING LINEUP:-\n");
    printf("**REQUIRED 6 BATSMEN**\n");
    printf("**REQUIRED 5 BOWLERS**\n");
    for(int i=0; i<BA; i++){
        printf("BATSMAN %d NAME :",i+1);
        scanf("%s",&b1[i].name);
        if(i>=6){
            strcpy(bo1[i-6].name,b1[i].name);
        }
    }
    printf("========================================================================================================================================\n");
    printf("\t\t\tTEAM::%s\n\n",n2);
    printf("BATTING AND BOWLING LINEUP:-\n");
    printf("**REQUIRED 6 BATSMEN**\n");
    printf("**REQUIRED 5 BOWLERS**\n");
    for(int i=0; i<BA; i++){
        printf("BATSMAN %d NAME :",i+1);
        scanf("%s",&b2[i].name);
        if(i>=6){
            strcpy(bo2[i-6].name,b2[i].name);
        }
    }
    printf("========================================================================================================================================\n");
    rules();
    printf("\t\t\t\tINNINGS 1\n\n");
    printf("OPENING BATSMAN :%s\n",b1[s].name);
    printf("BATSMAN ON THE NON STRIKE :%s\n",b1[ns].name);
    for(int i=0; i<20; i++){
        if(wic==10){
            break;
        }
        printf("BOWLER :%s\n",bo2[i%5].name);
        printf("OVER::%d\n",i+1);
        for(int j=0; j<6; j++){
            if(wic==10){
               break;
            }
            printf("\tBALL %d:",j+1);
            scanf("%s",&opt);
            innings1[i][j]=opt;
            if(bpos==1){
                b1[s].balls+=1;
            }
            else{
                b1[ns].balls+=1;
            }
            switch (opt){
                case 'D':
                break;

                case '1':
                r1+=1;
                bo2[i%5].runs+=1;
                if(bpos==1){
                    b1[s].runs+=1;
                }
                else{
                    b1[ns].runs+=1;
                }
                if(bpos==2){
                   bpos=1;
                }
                else{
                   bpos=2;
                }
                break;

                case '2':
                r1+=2;
                bo2[i%5].runs+=2;
                if(bpos==1){
                    b1[s].runs+=2;
                }
                else{
                    b1[ns].runs+=2;
                }
                break;

                case '3':
                r1+=3;
                bo2[i%5].runs+=3;
                if(bpos==1){
                    b1[s].runs+=3;
                }
                else{
                    b1[ns].runs+=3;
                }
                if(bpos==2){
                   bpos=1;
                }
                else{
                   bpos=2;
                }
                break;

                case '4':
                r1+=4;
                bo2[i%5].runs+=4;
                if(bpos==1){
                    b1[s].runs+=4;
                    b1[s].fours+=1;
                }
                else{
                    b1[ns].runs+=4;
                    b1[ns].fours+=1;
                }
                break;

                case '6':
                r1+=6;
                bo2[i%5].runs+=6;
                if(bpos==1){
                    b1[s].runs+=6;
                    b1[s].sixes+=1;
                }
                else{
                    b1[ns].runs+=6;
                    b1[ns].sixes+=1;
                }
                break;

                case 'w':
                r1+=1;
                bo2[i%5].extra+=1;
                bo2[i%5].runs+=1;
                j--;
                break;

                case 'N':
                r1+=1;
                bo2[i%5].extra+=1;
                bo2[i%5].runs+=1;
                n_ball=1;
                j--;
                break;

                case 'W':
                case 'C':
                if(n_ball==1){
                    n_ball=0;
                    break;
                }
                bo2[i%5].wickets+=1;
                wic++;
                if(wic==10){
                    break;
                }
                int max;
                if(s>ns){
                    max=s;
                }
                else{
                    max=ns;
                }
                if(bpos==1){
                    s=max+1;
                }
                else{
                    ns=max+1;
                }
                printf("HERE COMES %s, THE NEW BATSMAN ON THE FIELD.\n",b1[max+1].name);
                break;

                default:
                printf("INVALID OUTCOME, ENTER THE RIGHT OUTCOME.\n");
                j--;
                if(bpos==1){
                    b1[s].balls-=1;
                }
                else{
                    b1[ns].balls-=1;
                }
                break;
            }
        }
        if(bpos==2){
            bpos=1;
        }
        else{
            bpos=2;
        }
    }
//==========================================================================================================================
    wic=0;ns=1,s=0;bpos=1,n_ball=0;
    printf("========================================================================================================================================\n");
    printf("\t\t\t\tINNINGS 2\n");
    printf("\t\t\tTARGET TO BEAT IN 20 OVERS IS %d\n\n",r1);
    printf("OPENING BATSMAN :%s\n",b2[s].name);
    printf("BATSMAN ON THE NON STRIKE :%s\n",b2[ns].name);
    for(int i=0; i<20; i++){
        if(wic==10 || r2>r1){
            break;
        }
        printf("BOWLER :%s\n",bo1[i%5].name);
        printf("OVER::%d\n",i+1);
        for(int j=0; j<6; j++){
            if(wic==10 || r2>r1){
            break;
            }
            printf("\tBALL %d:",j+1);
            scanf("%s",&opt);
            innings2[i][j]=opt;
            if(bpos==1){
                b2[s].balls+=1;
            }
            else{
                b2[ns].balls+=1;
            }
            switch (opt){
                case 'D':
                break;

                case '1':
                r2+=1;
                bo1[i%5].runs+=1;
                if(bpos==1){
                    b2[s].runs+=1;
                }
                else{
                    b2[ns].runs+=1;
                }
                if(bpos==2){
                   bpos=1;
                }
                else{
                   bpos=2;
                }
                break;

                case '2':
                r2+=2;
                bo1[i%5].runs+=2;
                if(bpos==1){
                    b2[s].runs+=2;
                }
                else{
                    b2[ns].runs+=2;
                }
                break;

                case '3':
                r2+=3;
                bo1[i%5].runs+=3;
                if(bpos==1){
                    b2[s].runs+=3;
                }
                else{
                    b2[ns].runs+=3;
                }
                if(bpos==2){
                   bpos=1;
                }
                else{
                   bpos=2;
                }
                break;

                case '4':
                r2+=4;
                bo1[i%5].runs+=4;
                if(bpos==1){
                    b2[s].runs+=4;
                    b2[s].fours+=1;
                }
                else{
                    b2[ns].runs+=4;
                    b2[ns].fours+=1;
                }
                break;

                case '6':
                r2+=6;
                bo1[i%5].runs+=6;
                if(bpos==1){
                    b2[s].runs+=6;
                    b2[s].sixes+=1;
                }
                else{
                    b2[ns].runs+=6;
                    b2[ns].sixes+=1;
                }
                break;

                case 'w':
                r2+=1;
                bo1[i%5].extra+=1;
                bo1[i%5].runs+=1;
                j--;
                break;

                case 'N':
                r2+=1;
                bo1[i%5].extra+=1;
                bo1[i%5].runs+=1;
                n_ball=1;
                j--;
                break;

                case 'W':
                case 'C':
                if(n_ball==1){
                    n_ball=0;
                    break;
                }
                bo1[i%5].wickets+=1;
                wic++;
                if(wic==10){
                    break;
                }
                int max;
                if(s>ns){
                    max=s;
                }
                else{
                    max=ns;
                }
                if(bpos==1){
                    s=max+1;
                }
                else{
                    ns=max+1;
                }
                printf("HERE COMES %s, THE NEW BATSMAN ON THE FIELD.\n",b2[max+1].name);
                break;

                default:
                printf("INVALID OUTCOME, ENTER THE RIGHT OUTCOME.\n");
                j--;
                if(bpos==1){
                    b2[s].balls-=1;
                }
                else{
                    b2[ns].balls-=1;
                }
                break;
            }
        }
        printf("\nCHASE %d MORE TO WIN.\n",r1-r2);
        if(bpos==2){
            bpos=1;
        }
        else{
            bpos=2;
        }
    }
    printf("========================================================================================================================================\n");
    for(int i=0; i<BA; i++){
        f1+=b1[i].fours;
        s1+=b1[i].sixes;
        f2+=b2[i].fours;
        s2+=b2[i].sixes;
    }
    for(int i=0; i<BO; i++){
        w1+=bo1[i].wickets;
        x1+=bo1[i].extra;
        w2+=bo2[i].wickets;
        x2+=bo2[i].extra;
    }
    printf("========================================================================================================================================\n");
    printf("========================================================================================================================================\n");
    printf("\t\t\t\t\tSCORE CARD\n");
    printf("========================================================================================================================================\n");
    printf("COMPETITION :%s             |    VENUE :%s\n",competition,venue);
    printf("MATCH PLAYED BETWEEN %s     |    VERSUS %s\n",no1,no2);
    printf("TOSS WON BY %s              |    ELECTED TO(BAT/BOWL) :%s\n",twon,e);
    printf("========================================================================================================================================\n");
    printf("\t\t\tTEAM::%s\n\n",n1);
    printf("BALL :: 1 2 3 4 5 6\n");
    for(int j=0; j<20; j++){
        printf("OVER %d :%c %c %c %c %c %c\n",j,innings1[j][0],innings1[j][1],innings1[j][2],innings1[j][3],innings1[j][4],innings1[j][5]);
    }
    printf("========================================================================================================================================\n");
    printf("\nPLAYER NAME\tRUNS\tFOURS\tSIXES\tBALLS\tNRR\n");
    for(int i=0; i<BA; i++){
        if(b1[i].balls!=0){
            printf("%s\t\t%d\t%d\t%d\t%d\t%d\n",b1[i].name,b1[i].runs,b1[i].fours,b1[i].sixes,b1[i].balls,(b1[i].runs/b1[i].balls)*100);
        }
        else{
            printf("%s\t\t%d\t%d\t%d\t%d\t0\n",b1[i].name,b1[i].runs,b1[i].fours,b1[i].sixes,b1[i].balls);
        }
    }
    printf("========================================================================================================================================\n");
    printf("\nPLAYER NAME\tWICKETS\tRUNS\tEXTRAS\tECONOMY\n");
    for(int i=0; i<BO; i++){
        printf("%s\t\t%d\t%d\t%d\t%d\n",bo1[i].name,bo1[i].wickets,bo1[i].runs,bo1[i].extra,(bo1[i].runs/24)*100);
    }
    printf("========================================================================================================================================\n");
    printf("\n");
    printf("TOTAL RUNS :%d\n",r1);
    printf("TOTAL FOURS :%d\n",f1);
    printf("TOTAL SIXES :%d\n",s1);
    printf("TOTAL BOUNDARIES :%d\n",f1+s1);
    printf("TOTAL FALLEN WICKETS :%d\n",w1);
    printf("EXTRAS GIVEN :%d\n",x1);
    printf("========================================================================================================================================\n");
    printf("========================================================================================================================================\n");
    printf("========================================================================================================================================\n");
    printf("\t\t\tTEAM::%s\n\n",n2);
    printf("BALL :: 1 2 3 4 5 6\n");
    for(int j=0; j<20; j++){
        printf("OVER %d :%c %c %c %c %c %c\n",j,innings2[j][0],innings2[j][1],innings2[j][2],innings2[j][3],innings2[j][4],innings2[j][5]);
    }
    printf("========================================================================================================================================\n");
    printf("\nPLAYER NAME\tRUNS\tFOURS\tSIXES\tBALLS\tNRR\n");
    for(int i=0; i<BA; i++){
        if(b2[i].balls!=0){
           printf("%s\t\t%d\t%d\t%d\t%d\t%d\n",b2[i].name,b2[i].runs,b2[i].fours,b2[i].sixes,b2[i].balls,(b2[i].runs/b2[i].balls)*100);
        }
        else{
           printf("%s\t\t%d\t%d\t%d\t%d\t0\n",b2[i].name,b2[i].runs,b2[i].fours,b2[i].sixes,b2[i].balls);
        }
    }
    printf("========================================================================================================================================\n");
    printf("\nPLAYER NAME\tWICKETS\tRUNS\tEXTRAS\tECONOMY\n");
    for(int i=0; i<BO; i++){
        printf("%s\t\t%d\t%d\t%d\t%d\n",bo2[i].name,bo2[i].wickets,bo2[i].runs,bo2[i].extra,(bo2[i].runs/24)*100);
    }
    printf("========================================================================================================================================\n");
    printf("\n");
    printf("TOTAL RUNS :%d\n",r2);
    printf("TOTAL FOURS :%d\n",f2);
    printf("TOTAL SIXES :%d\n",s2);
    printf("TOTAL BOUNDARIES :%d\n",f2+s2);
    printf("TOTAL FALLEN WICKETS :%d\n",w2);
    printf("EXTRAS GIVEN :%d\n",x2);
    printf("========================================================================================================================================\n");
    printf("========================================================================================================================================\n");
    if(r1>r2){
        printf("WINNER:%s , WON BY %d RUNS AND %d WICKETS.\n",n1,r1-r2,11-w1);
    }
    else if(r2>r1){
        printf("WINNER:%s , WON BY %d RUNS AND %d WICKETS.\n",n2,r2-r1,11-w2);
    }
    else{
        printf("DRAW\n");
    }
    printf("========================================================================================================================================\n");
    printf("========================================================================================================================================\n");
}



