#include <stdio.h>

int main() {
    int n = 0;     // 현재 숫자
    int me;        // 내가 말할 개수
    int com;       // 컴퓨터가 말할 개수

    printf("===== 베스킨라빈스 31 =====\n");
    printf("31을 말하면 지는 게임!\n\n");

    while (1) {

        // --- 사용자 턴 ---
        printf("몇 개 말할래? (1~3) : ");
        scanf("%d", &me);

        // 입력 오류 처리
        if (me < 1 || me > 3) {
            printf("1~3 중에서 골라!\n");
            continue;
        }

        // 내가 말하기
        for (int i = 0; i < me; i++) {
            n++;
            printf("너: %d\n", n);
            if (n == 31) {
                printf("\n너가 31 말함! 너 패배!\n");
                return 0;
            }
        }

        // --- 컴퓨터 턴 (필승법: 4의 배수 만들기) ---
        // 목표: 4, 8, 12, 16, 20, 24, 28을 만들기
        com = 4 - (n % 4);
        if (com == 4) com = 1;  // 이미 4의 배수면 1개만 말함

        printf("\n컴퓨터는 %d개 말함.\n", com);

        for (int i = 0; i < com; i++) {
            n++;
            printf("컴퓨터: %d\n", n);
            if (n == 31) {
                printf("\n컴퓨터가 31 말함! 너 승리!!\n");
                return 0;
            }
        }

        printf("\n"); // 턴 구분용 줄바꿈
    }

    return 0;
}

