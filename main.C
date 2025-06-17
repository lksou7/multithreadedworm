/*
 * worm_sim.c - Educational worm mechanism simulation
 *
 * ⚠️ Disclaimer:
 * This code is for educational and ethical testing purposes only.
 * It simulates worm behavior in a controlled environment to help
 * users understand and improve their firewall or security setup.
 *
 * Do NOT run this code on unauthorized systems or real networks.
 * The author is not responsible for misuse of this code.
 */


 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
 


 for (int i = 0; i < MAX_HOSTS; i++) {
        char* host_dir = malloc(100);
        snprintf(host_dir, 100, "%s%d", HOST_DIR_PREFIX, i + 1);
        pthread_create(&threads[i], NULL, infect_thread, (void*)host_dir);
    }


       free(host_dir); 
    return NULL;
