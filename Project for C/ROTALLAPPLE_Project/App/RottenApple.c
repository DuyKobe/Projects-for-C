/*
#include<stdio.h> 
#include <assert.h>
#include <time.h>
int rotAllApple(int n, int m, int positions[100][2])
{
    int days = 0;
    int box[n][m];
    int newBOX[n][m];

    // Initialize box, 0 is intact apple, 1 is damaged apple.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            box[i][j] = 0;
        }
    }

    // Initialize Newbox, 0 is intact apple, 1 is damaged apple.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            newBOX[i][j] = 0;
        }
    }

    // Check rotten apple
    for (int i=0; i<n; i++){
         int x = positions[i][0] - 1;
         int y = positions[i][1] - 1;
         if(x>=0 && y>=0){
         box[x][y]= 1;
         }
    }

    // Transmit rotten
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int allRotten = 0;

    // Process the next rotten apple
    while (!allRotten) {
        allRotten = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (box[i][j] == 0) {
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && box[ni][nj] == 1) {
                            newBOX[i][j] = 1;
                            allRotten = 0;
                        }
                    }
                }
            } 
        }
        //Update Box
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (newBOX[i][j] == 1){
                    box[i][j]= 1;
                }
            }
        }

        //Update days
        if(!allRotten){
            days++;
        }  
    }
    return days;
}

int main(){
 clock_t t; 
    t = clock(); 
    // int n = 5;
    // int m = 5;
    // int positions[100][100] = {{2,2},{1,1},{3,3},{4,4},{5,5}};
    // int result = rotAllApple(n,m, positions);
    // printf("%d\n", result);

     // Test case 1
    int test_case_1_n = 2;
    int test_case_1_m = 2;
    int test_case_1_positions[100][2] = {{1, 1}};
    int result_1 = rotAllApple(test_case_1_n, test_case_1_m, test_case_1_positions);
    printf("%d\n", result_1);
    assert(result_1 == 2);

    // Test case 2
    int test_case_2_n = 1;
    int test_case_2_m = 1;
    int test_case_2_positions[100][2] = {{1, 1}};
    int result_2 = rotAllApple(test_case_2_n, test_case_2_m, test_case_2_positions);
    printf("%d\n", result_2);
    assert(result_2 == 0);

    // Test case 3
    int test_case_3_n = 5;
    int test_case_3_m = 5;
    int test_case_3_positions[100][2] = {{2, 2}, {1, 1}, {3, 3}, {4, 4}, {5, 5}};
    int result_3 = rotAllApple(test_case_3_n, test_case_3_m, test_case_3_positions);
    printf("%d\n", result_3);
    assert(result_3 == 4);

    // Test case 4
    int test_case_4_n = 1;
    int test_case_4_m = 7;
    int test_case_4_positions[100][2] = {{1, 3}};
    int result_4 = rotAllApple(test_case_4_n, test_case_4_m, test_case_4_positions);
    printf("%d\n", result_4);
    assert(result_4 == 4);

    // Test case 5
    int test_case_5_n = 3;
    int test_case_5_m = 7;
    int test_case_5_positions[100][2] = {{2, 4}};
    int result_5 = rotAllApple(test_case_5_n, test_case_5_m, test_case_5_positions);
    printf("%d\n", result_5);
    assert(result_5 == 4);

    printf("All test cases passed!\n");
     t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 

            printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#define MAX_N 7
#define MAX_M 7

// Ma trận lưu trạng thái của táo (1: táo hỏng, 0: táo không hỏng)
int grid[MAX_N + 1][MAX_M + 1];

// Mảng đánh dấu ô đã được duyệt
bool visited[MAX_N + 1][MAX_M + 1];

int rotAllApple(const int n, const int m, int positions[][2], int positions_size) {
    int count = 0;
    int days = 0;
    // Khởi tạo ma trận và đánh dấu tất cả là táo đều bìh thường 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] = 0;
            visited[i][j] = false;
        }
    }

    // Đánh dấu các táo bị hỏng theo vị trí được đưa vào
    for (int i = 0; i < positions_size; ++i) {
        int x = positions[i][0]-1;
        int y = positions[i][1]-1;
        grid[x][y] = 1;
    }

    // Duyệt qua từng ô, nếu gặp táo hỏng thì thực hiện DFS
    while (count < (n*m) ){
        days++;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                if (!visited[i][j] && grid[i][j] == days) {
                    dfs(i, j, n, m);
                }
        }
        }
    }
    return days-1 ; // Trừ đi 1 vì ngày đầu tiên không cần làm gì cả
}

// Hàm DFS để lan truyền tác động của táo hỏng
void dfs(int x, int y, const int n, const int m, int pDays, int pCount) {
    visited[x][y] = true;
    pCount++;
   // Transmit rotten
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    // Duyệt qua tất cả các ô lân cận
                    for (int d = 0; d < 4; d++) {
                        int newX = x + dx[d];
                        int newY = y + dy[d];
        
            // Nếu ô lân cận hợp lệ và chưa được duyệt
            if (isValid(newX, newY, n, m) && !visited[newX][newY] && grid[newX][newY] == 0) {
                grid[newX][newY] =pDays+1;
                
                
                //dfs(newX, newY);
            
            }
        }
}

// Hàm kiểm tra xem một ô có nằm trong giới hạn của ma trận hay không
bool isValid(int x, int y, const int n, const int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    clock_t t; 
    t = clock();

     // Test case 1
    const int test_case_1_n = 2;
    const int test_case_1_m = 2;
    int test_case_1_positions[][2] = {{1, 1}};
    int positions_size_1 = sizeof(test_case_1_positions) / sizeof(test_case_1_positions[0]);
    int result_1 = rotAllApple(test_case_1_n, test_case_1_m, test_case_1_positions, positions_size_1); 
    printf("%d\n", result_1);
    assert(result_1 == 2);

    // Test case 2
    const int test_case_2_n = 1;
    const int test_case_2_m = 1;
    int test_case_2_positions[][2] = {{1, 1}};
    int positions_size_2 = sizeof(test_case_2_positions) / sizeof(test_case_2_positions[0]);
    int result_2 = rotAllApple(test_case_2_n, test_case_2_m, test_case_2_positions, positions_size_2);
    printf("%d\n", result_2);
    assert(result_2 == 0);

    // Test case 3
    const int test_case_3_n = 5;
    const int test_case_3_m = 5;
    int test_case_3_positions[][2] = {{2, 2}, {1, 1}, {3, 3}, {4, 4}, {5, 5}};
    int positions_size_3 = sizeof(test_case_3_positions) / sizeof(test_case_3_positions[0]);
    int result_3 = rotAllApple(test_case_3_n, test_case_3_m, test_case_3_positions, positions_size_3);
    printf("%d\n", result_3);
    assert(result_3 == 4);

    // Test case 4
    const int test_case_4_n = 1;
    const int test_case_4_m = 7;
    int test_case_4_positions[][2] = {{1, 3}};
    int positions_size_4 = sizeof(test_case_4_positions) / sizeof(test_case_4_positions[0]);
    int result_4 = rotAllApple(test_case_4_n, test_case_4_m, test_case_4_positions, positions_size_4);
    printf("%d\n", result_4);
    assert(result_4 == 4);

    // Test case 5
    const int test_case_5_n = 3;
    const int test_case_5_m = 7;
    int test_case_5_positions[100][2] = {{2, 4}};
    int positions_size_5 = sizeof(test_case_5_positions) / sizeof(test_case_5_positions[0]);
    int result_5 = rotAllApple(test_case_5_n, test_case_5_m, test_case_5_positions, positions_size_5);
    printf("%d\n", result_5);
    assert(result_5 == 4);

    printf("All test cases passed!\n");
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 

    printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
}
*/
