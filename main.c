#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool pour_water(int times,int V_A,int V_B,int V_C,
                int NOW_V_A,int NOW_V_B,int NOW_V_C,
                int target_V_A,int target_V_B,int target_V_C);
int main() {
    int times, V_A, V_B, V_C,NOW_V_A, NOW_V_B, NOW_V_C,
            target_V_A, target_V_B, target_V_C=0;
    scanf("%d %d %d %d %d %d %d %d %d %d",&times, &V_A, &V_B, &V_C,&NOW_V_A,
          &NOW_V_B, &NOW_V_C,
          &target_V_A, &target_V_B, &target_V_C);
    if (pour_water(times, V_A, V_B, V_C,NOW_V_A, NOW_V_B, NOW_V_C,
                   target_V_A, target_V_B, target_V_C))
    {
        printf("%s\n","Yes");
    } else{
        printf("%s\n","No");
    }
    return 0;
}
bool pour_water(int times,int V_A,int V_B,int V_C,
                int NOW_V_A,int NOW_V_B,int NOW_V_C,
                int target_V_A,int target_V_B,int target_V_C){
    int decide[12]={0};
    if (NOW_V_A==target_V_A && NOW_V_B==target_V_B && NOW_V_C==target_V_C){
        return true;
    }
    else {
        if (times > 0) {
            if (NOW_V_A + NOW_V_B >= V_A) {
                if (pour_water(times - 1, V_A, V_B, V_C, V_A, 0, NOW_V_C,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[0] = 1;
                }
            } else if (NOW_V_A + NOW_V_B < V_A) {
                if (pour_water(times - 1, V_A, V_B, V_C, NOW_V_A + NOW_V_B, 0, NOW_V_C,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[1] = 1;
                }
            } else if (NOW_V_A + NOW_V_B >= V_B) {
                if (pour_water(times - 1, V_A, V_B, V_C, 0, V_B, NOW_V_C,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[2] = 1;
                }
            } else if (NOW_V_A + NOW_V_B < V_B) {
                if (pour_water(times - 1, V_A, V_B, V_C, 0, NOW_V_A + NOW_V_B, NOW_V_C,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[3] = 1;
                }
            }
                //-----------------------------------------------------------------------------------
            else if (NOW_V_C + NOW_V_B >= V_C) {
                if (pour_water(times - 1, V_A, V_B, V_C, NOW_V_A, 0, V_C,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[4] = 1;
                }
            } else if (NOW_V_C + NOW_V_B < V_C) {
                if (pour_water(times - 1, V_A, V_B, V_C, NOW_V_A, 0, NOW_V_C + NOW_V_B,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[5] = 1;
                }
            } else if (NOW_V_C + NOW_V_B >= V_B) {
                if (pour_water(times - 1, V_A, V_B, V_C, NOW_V_A, V_B, 0,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[6] = 1;
                }
            } else if (NOW_V_C + NOW_V_B < V_B) {
                if (pour_water(times - 1, V_A, V_B, V_C, NOW_V_A, NOW_V_C + NOW_V_B, 0,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[7] = 1;
                }
            }
                //---------------------------------------------------------------------------
            else if (NOW_V_C + NOW_V_A >= V_C) {
                if (pour_water(times - 1, V_A, V_B, V_C, 0, NOW_V_B, V_C,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[8] = 1;
                }
            } else if (NOW_V_C + NOW_V_A < V_C) {
                if (pour_water(times - 1, V_A, V_B, V_C, 0, NOW_V_B, NOW_V_C + NOW_V_A,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[9] = 1;
                }
            } else if (NOW_V_C + NOW_V_A >= V_A) {
                if (pour_water(times - 1, V_A, V_B, V_C, V_A, NOW_V_B, 0,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[10] = 1;
                }
            } else if (NOW_V_C + NOW_V_A < V_A) {
                if (pour_water(times - 1, V_A, V_B, V_C, NOW_V_C + NOW_V_A, NOW_V_B, 0,
                               target_V_A, target_V_B, target_V_C)) {
                    decide[11] = 1;
                }
            }
            for (int i = 0; i < 12; i++) {
                if (decide[i] == 1) {
                    return true;
                }
            }
            return false;
        } else if (times == 0) {
            if (NOW_V_A == target_V_A && NOW_V_B == target_V_B && NOW_V_C == target_V_C) {
                return true;
            } else {
                return false;
            }
        } else if (times < 0) {
            return false;
        }
    }
}