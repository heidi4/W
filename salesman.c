#include <stdio.h>

int matrix[4][4] = {
    {0, 1400, 980, 1330},
    {1400, 0, 2150, 2200},
    {980, 2150, 0, 350},
    {1330, 2200, 350, 0}
};

int visited[4] = {0, 0, 0, 0};
int final_ans = 999999;

void tsp(int current_city, int count, int current_cost) {

    if (count == 4 && matrix[current_city][0] > 0) {
        int total_cost = current_cost + matrix[current_city][0];
        printf("Path found! Total Cost: %d km\n", total_cost);

        if (total_cost < final_ans) {
            final_ans = total_cost;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (visited[i] == 0 && matrix[current_city][i] > 0) {
            
            visited[i] = 1;
            tsp(i, count + 1, current_cost + matrix[current_city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    visited[0] = 1; 
    
    printf("--- Calculating Paths ---\n");
    tsp(0, 1, 0); 
    
    printf("-------------------------\n");
    printf("Minimum Cost: %d km\n", final_ans);
    
    return 0;
}