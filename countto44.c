#include <stdio.h>

int AI(int,int);
void main(){
    int i=0,n=0,rem=44,c=1;
    printf("Willkommen im Spiel Kamerad!\n");
    while (c == 1){
        while (rem >= 0)
        {
            printf("Es ist deine Runde!\t");
            printf("Noch Verfuegbare Staedte:%d\n",rem);
            printf("Wie viele willst du Eleminieren?:\n");
            scanf("%d",&n);
            if(n>4){
                printf("FALSCH!!!Erlaubt: nur 1-4!\n");
                continue;
            }
            rem=rem-n;
            if (rem<=0){
                printf("Keine Chance du hast gegen den Feind verloren.\n\n");
                break;
            }
            printf("Noch Verfuegbare Staedte:%d\n",rem);
            i=AI(n,rem);
            printf("DER FEIND VERNICHTET = %d\n",i);
            printf("Noch Verfuegbare Staedte:%d\n",(rem=rem-i));
            if (rem<=0){
                printf("DU HAST DIESEN KRIEG FUER DEIN LAND ENTSCHIEDEN.\n\n");
                break;
            }
        }
        printf("Willst du nochmal Kaempfen?(1(JA)/0(NEIN))\n");
        scanf("%d", &c);
        rem=21;
    }
}
int AI(int n,int rem){
    int turn;
    if (rem>4 && n%4==0){
        turn = 4;
    }
    else if(rem>4) {
        turn = 4-(n%4);
    }
    else if (rem<=0){
        turn=0;
    }
    else if (rem==1){
        turn=1;
    }
    else if (rem<=4){
        turn=rem-1;
    }
    return turn;
}
