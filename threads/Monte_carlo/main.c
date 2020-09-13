#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define total_check_point 50
#define min -1
#define max 1

int num_points_in_cir=0;
bool check(float, float);
typedef struct{
float x;
float y;
} point;
void *create_random_num(void *);
void *count_num(void *);
pthread_t thread1, thread2;
int main(){
	for(int i=0; i<=total_check_point; i++)
	{
	pthread_create(&thread1, NULL, create_random_num, NULL);
    pthread_create(&thread2, NULL, count_num, &thread1);
    //usleep(10);
	}
    printf("%d", 4*(num_points_in_cir)/total_check_point);
    return 0;
}
void *create_random_num(void* i){
    pthread_detach(pthread_self());
    srand((unsigned int)clock());
    point* A = (point*)malloc(sizeof(point));
    float scalex = rand() / (float)RAND_MAX;
    float scaley = rand() / (float)RAND_MAX;
    A->x = min + scalex*(max - min);
    A->y = min + scaley*(max - min);

    pthread_exit(A);

}
void *count_num(void *thread123){
    point* B = (point*)malloc(sizeof(point));
    pthread_t* threadphu = (pthread_t*)thread123;

    pthread_join(*threadphu, (void **)&B);
    if(check(B->x, B->y)) num_points_in_cir++;
    pthread_exit(NULL);
}
bool check(float x, float y){
    if(sqrt(pow(x, 2)+pow(y, 2))<=1) return 1;
    else return 0;
}