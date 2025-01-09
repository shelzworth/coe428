#include <stdio.h>
#include <stdbool.h>


typedef struct state_Machine 
{
    char name;
    int number; 
    struct state_Machine *next_state_0;
    struct state_Machine *next_state_1;
    bool reachable;
    bool deleted;
} fsm;

fsm states[8];

void init_states() 
{
    // State A
    states[0].name = 'A';
    states[0].number = 0;
    states[0].next_state_0 = &states[1]; //B
    states[0].next_state_1 = &states[6]; //G

    // State B
    states[1].name = 'B';
    states[1].number = 1;
    states[1].next_state_0 = &states[5]; //F
    states[1].next_state_1 = &states[7]; //H

    // State C
    states[2].name = 'C';
    states[2].number = 2;
    states[2].next_state_0 = &states[5]; //F
    states[2].next_state_1 = &states[1]; //B

    // State D
    states[3].name = 'D';
    states[3].number = 3;
    states[3].next_state_0 = &states[3]; //D
    states[3].next_state_1 = &states[2]; //C

    // State E
    states[4].name = 'E';
    states[4].number = 4;
    states[4].next_state_0 = &states[3]; //D
    states[4].next_state_1 = &states[0]; //A

    // State F
    states[5].name = 'F';
    states[5].number = 5;
    states[5].next_state_0 = &states[4]; //E
    states[5].next_state_1 = &states[0]; //A

    // State G
    states[6].name = 'G';
    states[6].number = 6;
    states[6].next_state_0 = &states[7]; //H
    states[6].next_state_1 = &states[4]; //E

   // State H
states[7].name = 'H';
states[7].number = 7;
states[7].next_state_0 = &states[6]; //G
states[7].next_state_1 = &states[3]; //D
}

void print()
{
    printf("Current State: D\n"); 
    for (int i = 0; i < 8; i++) 
    {
        printf("%c %c %c\n", states[i].name, states[i].next_state_0->name, states[i].next_state_1->name);
    }
}

void identify_garbage() 
{
    bool all_reachable = true;
    printf("Garbage: ");
    for (int i = 0; i < 8; i++) 
    {
        if (!states[i].reachable) 
        {
            all_reachable = false;
            printf("%c ", states[i].name);
        }
    }
    if (all_reachable) 
    {
        printf("No garbage\n");
    }
    printf("\n");
}
void dfs(fsm *current_state) 
{
    current_state->reachable = true; 
    //recursive calls
    if (current_state->next_state_0 && !current_state->next_state_0->reachable) 
    {
        dfs(current_state->next_state_0);
    }
    if (current_state->next_state_1 && !current_state->next_state_1->reachable) 
    {
        dfs(current_state->next_state_1);
    }
}
void delete_state(char state_name) 
{
    for (int i = 0; i < 8; i++) 
    {
        if (states[i].name == state_name) 
        {
            states[i].deleted = true;
            break;
        }
    }
}

void delete_unreachable_states() 
{
    states[3].reachable = true; // Starting state is D
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < 8; i++) 
        {
            if (states[i].reachable) 
            {
                if (states[i].next_state_0 && !states[i].next_state_0->reachable) 
                {
                    states[i].next_state_0->reachable = true;
                    changed = true;
                }
                if (states[i].next_state_1 && !states[i].next_state_1->reachable) 
                {
                    states[i].next_state_1->reachable = true;
                    changed = true;
                }
            }
        }
    } while (changed);

    bool has_unreachable = false;
    for (int i = 0; i < 8; i++) 
    {
        if (!states[i].reachable && !states[i].deleted) 
        {
            states[i].deleted = true;
            has_unreachable = true;
        }
    }

    if (!has_unreachable) 
    {
        printf("No unreachable, undeleted states found.\n");
    }
}

int main() 
{
    char input[3]; 
    init_states();
    printf("Enter an argument (0/1), (e)xit (p)rint, (c)hange(0/1), (g)arbage, (d)elete.\n");
    printf("Starting State: D\n");
    printf("Current State: D\n"); 
    for (int i = 0; i < 8; i++) 
    {
        printf("%c %c %c\n", states[i].name, states[i].next_state_0->name, states[i].next_state_1->name);
    }

    while (1) 
    {
        scanf("%s", input);
        //0 state
        if (input[0] == '0') 
        {
            printf("%c\n", states[3].next_state_0->name);
            states[3] = *states[3].next_state_0;
        }
        //1 state
        if (input[0] == '1') 
        {
            printf("%c\n", states[3].next_state_1->name);
            states[3] = *states[3].next_state_1;
        }
        //exit
        if (input[0] == 'e') 
        {
            break;
        }
        //print
        if (input[0] == 'p') 
        {
            print();
        }
        //change
        if (input[0] == 'c') 
        {
            int state_index = input[2] - 'A';
            if (input[4] >= 'A' && input[4] <= 'H') 
            {
                if (input[6] == '0')
                {
                    states[state_index].next_state_0 = &states[input[4] - 'A'];
                }
                else if (input[6] == '1')
                {
                    states[state_index].next_state_1 = &states[input[4] - 'A'];
                }
            }
        }
        //garbage
        if (input[0] == 'g') 
        {
            for(int i = 0; i<8; i++)
            {
                states[i].reachable = false;
            }
            identify_garbage(3);
        }
        //delete
        if (input[0] == 'd') 
        {
            if (input[1] == '\0') 
            {
                delete_unreachable_states();
            } 
            else 
            {
                char state_name = input[1];
                delete_state(state_name);
            }
        }
    }
    return 0;
}