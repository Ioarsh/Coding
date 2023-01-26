#include<stdio.h>

typedef struct datetime {
    int date;       // 1-31
    int month;      // 1-12
    int year;       // 1970++
    int dayOfWeek;  // 0-6
    int hour;       // 0-23
    int minute;     // 0-59
    int second;     // 0-59      
} datetime_t;

datetime_t createDate(int timestamp){
    int i,n,countday;
    datetime_t info;

    info.date=1;
    info.month=1;
    info.year=1970;
    info.dayOfWeek=0;
    countday=timestamp/(60*60*24);

    for(i=0;i<countday;i++){
        info.date+=1;
        info.dayOfWeek+=1;
        if(info.dayOfWeek>6) info.dayOfWeek=0;
        switch(info.month){
            case 1: if(info.date>31){
                info.month+=1;
                info.date=1;
            }
            break;
            case 2: if(info.year%4==0 && info.year%100!=0) n=29;
                    else if(info.year%400==0) n=29;
                    else n=28;
                    if(info.date>n){
                        info.month+=1;
                        info.date=1;
                    }
                    break;
            case 3: if(info.date>31){
                info.month+=1;
                info.date=1;
            }
            break;
            case 4: if(info.date>30){
                info.month+=1;
                info.date=1;
            }
            break;
            case 5: if(info.date>31){
                info.month+=1;
                info.date=1;
            }
            break;
            case 6: if(info.date>30){
                info.month+=1;
                info.date=1;
            }
            break;
            case 7: if(info.date>31){
                info.month+=1;
                info.date=1;
            }
            break;
            case 8: if(info.date>31){
                info.month+=1;
                info.date=1;
            }
            break;
            case 9: if(info.date>30){
                info.month+=1;
                info.date=1;
            }
            break;
            case 10: if(info.date>31){
                info.month+=1;
                info.date=1;
            }
            break;
            case 11: if(info.date>30){
                info.month+=1;
                info.date=1;
            }
            break;
            case 12: if(info.date>31){
                info.month=1;
                info.date=1;
                info.year+=1;
            }
            break;
        }
    }

    timestamp-=countday*60*60*24;
    info.hour=timestamp/(60*60);
    timestamp-=info.hour*60*60;
    info.minute=timestamp/60;
    timestamp-=info.minute*60;
    info.second=timestamp;
    return(info);

}

int printDate(datetime_t info){
    switch(info.dayOfWeek){
        case 0: printf("Thu "); break;
        case 1: printf("Fri "); break;
        case 2: printf("Sat "); break;
        case 3: printf("Sun "); break;
        case 4: printf("Mon "); break;
        case 5: printf("Tue "); break;
        case 6: printf("Wed "); break;
    }
    printf("%d ",info.date);
    switch(info.month){
        case 1: printf("JAN "); break;
        case 2: printf("FEB "); break;
        case 3: printf("MAR "); break;
        case 4: printf("APR "); break;
        case 5: printf("MAY "); break;
        case 6: printf("JUN "); break;
        case 7: printf("JUL "); break;
        case 8: printf("AUG "); break;
        case 9: printf("SEP "); break;
        case 10: printf("OCT "); break;
        case 11: printf("NOV "); break;
        case 12: printf("DEC "); break;
    }
    printf("%d ",info.year);
    if(info.hour<10) printf("0%d:",info.hour);
    else printf("%d:",info.hour);
    if(info.minute<10) printf("0%d:",info.minute);
    else printf("%d:",info.minute);
    if(info.second<10) printf("0%d",info.second);
    else printf("%d",info.second);
    return 0;
}

int main(void){
    datetime_t inputDate;
    int timestamp;

    scanf("%d", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}