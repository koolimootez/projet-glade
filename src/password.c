#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "password.h"

void generate_password(char password []){
    int password_length = 12;
    char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM[]{};':\"<>,.?";
    srand(time(NULL));
    for(int i = 0; i < password_length; i++) {
       password[i] = list[rand() % (sizeof list - 1)];
    }
}