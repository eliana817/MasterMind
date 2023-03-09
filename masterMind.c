#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int ReponseGen(int table[4]);
int display(int table[4], char secret[4]);
int reponse(char answer[4]);
void rangement(int r, int tab[4]);
int displayTwo(int tab[4], int res[4]);
int compare(char letr, char secret[4], int result[4], int index);
int displayFinal(int tab[4], char answer[4]);

//10 rounds 

int main(){

    srand(time( NULL )); 

    int table[4];

    ReponseGen(table); //generate table with 4 random numbers and display

    ///////////////////////////////

    char secret[4];
    display(table, secret); //replace numbers with letters and put the result in secret


    ///////////////////////////////
    
    for(int time = 0; time <= 10; time++){
        char answer[4]; //Take input from user (letters) and store the answers  
        reponse(answer);

        int result[4];
        char letr;
        int r;
        int tab[4] = {3, 3, 3, 3}; //table that contains the result of the compare function
        for(int a = 0; a < 4; a++){
            letr = answer[a];
            compare(letr, secret, result, a);
            //printf("%i -- ", result[a]);
            r = result[a];
            rangement(r, tab); //put random value in random location of the table without overwriting pre-existing values
        }

        displayFinal(tab, answer);

        int correct = 0; //check for number of 2s in the tab table, basically checks if there are 4 correct answers
        for(int r = 0; r < 4; r++){
            if(tab[r] == 2){
                correct += 1;
            }
        }

        if(correct == 4){
            printf("\nYou have guessed the correct combination");
            return 1;
        }

    }
    ///////////////////////////////

    printf("\nYou have used up all 10 guesses");
    return 1;

}

int ReponseGen(int table[4]){ //Secret
    int l[6] = {1, 2, 3, 4, 5, 6};
    int random = rand() % 6;
    //printf("|");
    for(int i = 0; i < 4; i++){
        while(l[random] == 0){
            random = rand() % 6;
        }
        table[i] = l[random];
        l[random] = 0; //replace value by 0 when it has already been taken
        //printf(" %i |", table[i]); //display the table with the numbers
    }
}

int display(int table[4], char secret[4]){
    char letters[6] = {'p', 'b', 'm', 'y', 'o', 'g'};
    printf("\n|");
    for(int h = 0; h < 4; h++){
        secret[h] = letters[table[h] - 1];
        printf(" %c |", secret[h]); //print to verify that thecode works
    }
    return 1;
}

int reponse(char answer[4]){

    char letters[6] = {'p', 'b', 'm', 'y', 'o', 'g'};

    printf("\n");
    for(int k = 0; k < 4; k++){
        printf("\nEnter a letter (p, b, m, y, o, g): ");
        scanf(" %c", &answer[k]);
        while(answer[k] != 'p' && answer[k] != 'b' && answer[k] != 'm' && answer[k] != 'y' && answer[k] != 'o' && answer[k] != 'g'){
            printf("\nBe sure to enter a letter among p, b, m, y, o or g: ");
            scanf(" %c", &answer[k]);
        }
    }
    return 1;
}

void rangement(int r, int tab[4]){

    int index;
    index = rand() % 4; 

    while(tab[index] != 3){
        index = rand() % 4;
    }

    tab[index] = r;

    //printf("%i %i - ", tab[index], index); //verify the values are not overwriting each other
}

int displayTwo(int tab[4], int res[4]){
    char replace[3] = {'.', 'R', 'W'};
    printf("\n");
    for(int u = 0; u < 4; u++){
        res[u] = replace[tab[u]];
    }
    return 1;
}

int compare(char letr, char secret[4], int result[4], int index){
    for(int j = 0; j < 4; j++){
        if(letr == secret[j] && index == j){
            result[index] = 2;
            return 1;
        }else if (letr == secret[j] && index != j){
            result[index] = 1;
            return 1;
        }else{
            result[index] = 0;
        }
    }
}

int displayFinal(int tab[4], char answer[4]){
    int res[4];
    displayTwo(tab, res);

    for(int i = 0; i < 45; i++){
        printf("-");
    }

    printf("|##|\n");

    for(int s = 0; s < 45; s++){
        printf(" ");
    }

    printf("|%c%c|\n", res[0], res[1]);

    for(int p = 0; p < 19; p++){
        printf(" ");
    }

    for(int e = 0; e < 4; e++){
        printf("%c ", answer[e]);
    }

    for(int p = 0; p < 18; p++){
        printf(" ");
    }

    printf("|%c%c|\n", res[2], res[3]);

    for(int i = 0; i < 45; i++){
        printf("-");
    }

    printf("|##|\n");

}