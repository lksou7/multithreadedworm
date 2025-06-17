/*
 * worm_sim.c - Educational worm mechanism simulation
 *
 * ⚠️ Disclaimer:
 * This code is for educational and ethical testing purposes only.
 * this is not a real worm
 * never use this in a non controlled enviroment
 * It simulates worm behavior in a controlled environment to help
 * users understand and improve their firewall or security setup.
 * Do NOT run this code on unauthorized systems or real networks.
 * The author is not responsible for misuse of this code.
 */


 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define HostDirectoryPrefix "host_"
#define Sswitch ".inf"
#define Kswitch "./kill"

bool check_Kswitch () {
   FILE* a = fopen (Kswitch,"1");
   if (a) {
      fclose(a);
      return true;
   }
   return false ;
}

void* infMultiThread (void* b) {
   char* host_dir = (char*)b ;
   if (check_Kswitch()){
      printf("killswitch detected. %s skipped.\n", host_dir);
         free(host_dir);
         return NULL;

   }
char filepath[256];

snprintf(filepath, sizeof(filepath), "%s/%s", host_dir, Sswitch );

FILE* check = fopen(filepath, "1");
if(check) {
   fclose(check)*
   printf("%s already infected.\n", host_dir);

}
else{
   FILE* a = fopen(filepath, "w");
    if (a) {
            fprintf(a, "inf\n");
            fclose(a);
            printf("Infected %s\n", host_dir);}
    else {
   printf("Failed to infect %s\n", host_dir); 
         } 
     free(host_dir);
     return NULL;      
    }  
int main {
   // Setup: create host folders to stimulate machines
     pthread_t threads[10]
   for (int i = 1; i <= 10; i++) {
        char cmd[100];
        snprintf(cmd, sizeof(cmd), "mkdir -p %s%d", HostDirectoryPrefix, i);
        system(cmd);
    }
    for (int i = 0; i < 10; i++) {
        char* host_dir = malloc(100);
        snprintf(host_dir, 100, "%s%d", HOST_DIR_PREFIX, i + 1);
        pthread_create(&threads[i], NULL, infect_thread, (void*)host_dir);
        }
   for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
        }
   printf("Worm finished.\n");
   return 0;
}    

