#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

/**** 전역 변수 ****/
int turn = 0;
char rulea[100] = {0};
char name[2][10];
char chess[30][30] = {
    {"도움말 : q, 기권 : s"},
    {"                  "},
    {"1   # % & @ $ & % #"}, //(1,A) chess[2][4]  4 6 8 10 12 14 16 18 / 2~9
    {"2   * * * * R * * *"}, // 규칙: 세로축은 +1, 가로축은 2x-190
    {"3   - - - P - - - -"},
    {"4   # - - - - - - -"},
    {"5   - P - # - P - -"},
    {"6   K - - K - - - -"},
    {"7   P P P P # P P P"},
    {"8   R N B Q K B N R"},
    {"                   "},
    {"    A B C D E F G H"} // 97~104
};                          // 맵을 배열에 넣기

/**** 함수 선언 ****/
void playername(void);
void rule();
void map();
int error();
int giveUp(int *);
void printResult(int number);
void getkey(int *);
void movepieces(char, char);
void queen(char, char);
void king(char, char);
void bishop(char, char);
void knight(char, char);
void rook(char, char);
void pawn(char, char);

/***** 코드 시작 *****/
int main() // 메인 함수
{
   int win = 99;
   int *p;
   p = &win;
   playername();
   while (1)
   {
      map();
      getkey(p);
      if (win == 0 || win == 1)
         break;
   }
   printResult(win);
   // error();
   return 0;
}

void playername(void)
{
   int i = 0, j;
   if (name[0][0] == 0)
   {
      while (1)
      {
         printf("player%d : ", i + 1);
         scanf("%s", &name[i]);
         getchar();
         for (j = 0; name[i][j] != 0; j++)
            ;
         if (j <= 10)
            printf("\n");
         else
         {
            printf("!Enter your name under 10 letters!\n");
            continue;
         }
         i++;
         if (i == 2)
            break;
      }
      system("cls");
   }
}

void map()
{
   int i, j;
   for (i = 0; i < 12; i++)
   {
      for (j = 0; j < 30; j++)
      {
         printf("%c", chess[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   printf("Turn : %s\n", name[turn % 2]);
}

void getkey(int *p)
{
   int key;
   char locx, locy;
   {
      key = getche();
      if (key == 'q')
      {
         rule();
         return;
      }
      if (key == 's')
      {
         giveUp(p);
         return;
      }
      if (key >= 97 && key <= 104)
      {
         locx = key;
         locy = getche();
         // locy알파벳이면 에러인거 추가
         movepieces(locx, locy);
         system("cls");
         return;
      }
      else
      {
         system("cls");
         printf("\nERROR\n");
      }
   }
}

int giveUp(int *p)
{
   int char_input;
   while (1)
   { // 계속 반복되도록 한 후, switch문을 통해 y나 n가 입력되었을 때 탈출하도록 함.
      system("cls");
      printf("******************************************************************\n");
      printf("\n\n\n\n\n\t기권하시겠습니까?\n");
      printf("\t기권을 하시겠다면 y를, 하지 않으시겠다면 n을 입력해주십시오.\n");
      printf("\n\n\n\n\n\n******************************************************************\n입 력 : ");
      char_input = getche();
      switch (char_input)
      {
      case 'y': // 상대편이 이기게 되므로 win에 상대편 번호 저장.
         if (turn % 2 == 0)
            *p = 1;
         if (turn % 2 == 1)
            *p = 0;
         return 0;
      case 'n': // 기권하지 않으므로 아무것도 하지 않고 함수 탈출함.
         system("cls");
         return 0;
      }
   }
}

void rule()
{
   int k;
   system("cls");
   printf("규칙 \n1. 킹을 이동하는 방법\n킹은 가장 중요한 기물이지만, 가장 약한 기물 중 하나입니다. \n어느 방향이든(위, 아래, 양옆, 대각선) 한 칸씩 이동할 수 있습니다.\n 킹은 스스로 체크 위치로 잡힐 수 있는 위치 이동할 수 없습니다. 킹이 다른 기물에게 공격을 받을 때 이를 \"체크\" 라고 합니다.\n\n");
   printf("2. 퀸을 이동하는 방법\n퀸은 가장 강력한 기물입니다.\n일직선으로 어느 방향이든(앞, 뒤, 옆, 대각선) 원하는 만큼 이동할 수 있습니다.\n단, 본인의 기물을 뚫고 갈 수는 없습니다.\n그리고 다른 기물과 마찬가지로 상대방 기물을 잡게 되면 수가 종료됩니다.\n백퀸이 흑퀸을 잡은 후 흑킹의 이동이 강제되는 상황을 살펴보십시오.\n\n");
   printf("3. 룩을 이동하는 방법\n룩은 원하는 만큼 움직일 수 있지만 앞, 뒤, 혹은 양옆으로만 이동이 가능합니다. \n룩은 둘이 서로를 보호하며 협동할 때 특히 강력해 집니다!\n\n");
   printf("4. 비숍을 이동하는 방법\n비숍은 원하는 만큼 이동할 수 있지만, 대각선으로만 가능합니다. \n각 비숍은 한 개의 색깔(밝은 칸 or 어두운 칸)에서 시작하게 되고 항상 그 색으로만 다닐 수 있습니다. \n 비숍들은 서로의 약점을 보완하기 때문에 협력하기 좋습니다.\n\n");
   printf("5. 나이트를 이동하는 방법\n나이트는 다른 기물과 전혀 다른 방식으로 이동합니다\n한 방향으로 두 칸을 이동하고 그와 90도를 이루는 방향으로 한칸 이동하여 \"L\"자 모양으로 갑니다. \n나이트는 기물 중 유일하게 다른 기물을 뛰어넘을 수 있습니다.\n\n");
   printf("6. 폰을 이동하는 방법\n폰들은 일반 이동과 잡을 때의 이동이 다르다는 점이 특이합니다\n일반 이동은 앞으로 하며, 잡을 때는 대각선으로 갑니다. \n폰은 한 번에 한칸만 앞으로 이동할 수 있지만, 처음으로 움직이는 폰은 두 칸을 이동할 수도 있습니다. \n잡을 때는 대각선으로 한 칸 앞에 있는 상대기물만 잡을 수 있습니다. \n절대 뒤로 이동하거나 뒤로 잡을 수 없습니다. \n폰 바로 앞에 다른 기물이 있을 경우 그것을 뛰어넘거나 잡을 수 없습니다.\n앙파상과 프로모션 규칙이 적용됩니다.\n\n");
   printf("7. 기타\n캐슬링 - 킹과 룩이 동시에 위치를 바꾸는 것으로 이동한 적없는 룩만 가능합니다. \n킹과 룩 사이에 다른 말이 없어야 하며 킹이 공격받거나 경로가 공격 받는다면 규칙이 적용되지 않습니다\n프로모션 - 폰이 상대진영의 끝에 도달하면 킹을 제외한 다른 말로 바꿀 수 있습니다\n앙파상 - 상대 폰이 2칸 이동했을 때 자신의 폰 옆에 위치하였을 때 대각선으로 이동하며 잡을 수 있습니다. \n다음 턴에서는 규칙이 적용되지 않습니다. \n체크메이트 - 킹이 공격 받는 것을 체크라고 합니다. 체크를 당했을 때, 이를 막거나 피할 수 없으면 게임은 패로 끝납니다\n스테일메이트 - 체크메이트가 되지 않았음에도 어떤 수도 둘 것이 없을 경우 무승부로 게임은 끝납니다.\n\n");
   printf("규칙을 다 확인하셨다면 \'w\'키를 입력하세요");
   while (1)
   {
      k = getch();
      if (k == 'k')
      {
         system("cls");
         break;
      }
      if (k == 'w')
      {
         system("cls");
         break;
      }
   }
}

void movepieces(char locx, char locy)
{
   locy -= 48;
   if (chess[locy + 1][2 * locx - 190] == 'R' || chess[locy + 1][2 * locx - 190] == '#')
   {
      rook(locx, locy);
      turn++;
   }

   if (chess[locy + 1][2 * locx - 190] == 'K' || chess[locy + 1][2 * locx - 190] == '$')
   {
      king(locx, locy);
      turn++;
   }
   if (chess[locy + 1][2 * locx - 190] == 'Q' || chess[locy + 1][2 * locx - 190] == '@')
   {
      queen(locx, locy);
      turn++;
   }
   if (chess[locy + 1][2 * locx - 190] == 'N' || chess[locy + 1][2 * locx - 190] == '%')
   {
      knight(locx, locy);
      turn++;
   }
   if (chess[locy + 1][2 * locx - 190] == 'B' || chess[locy + 1][2 * locx - 190] == '&')
   {
      bishop(locx, locy);
      turn++;
   }
}

void rook(char locx, char locy)
{
   int u, d, r, l, i;
   int a = locy + 1;
   int b = 2 * locx - 190;

   if (chess[a][b] == 'R')
   {
      // 말로부터 위의 요소 검사
      for (i = 1; i < a; i++)
      {
         // 같은문자열
         if (chess[a - i][b] >= 66 && chess[a - i][b] <= 82)
         { // 알파벳이면..
            break;
         }
         // 다른 문자열
         if (chess[a - i][b] == '@')
         {
            chess[a - i][b] = '2';
            break;
         }
         else if (chess[a - i][b] == '#')
         {
            chess[a - i][b] = '3';
            break;
         }
         else if (chess[a - i][b] == '$')
         {
            chess[a - i][b] = '4';
            break;
         }
         else if (chess[a - i][b] == '%')
         {
            chess[a - i][b] = '5';
            break;
         }
         else if (chess[a - i][b] == '&')
         {
            chess[a - i][b] = '7';
            break;
         }
         else if (chess[a - i][b] == '*')
         {
            chess[a - i][b] = '8';
            break;
         }
      }
      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a - k][b] == '-')
            chess[a - k][b] = 'o';
      }
      // 아래 요소 검사
      for (i = 1; i < 9 - a; i++)
      {
         if (chess[a + i][b] >= 66 && chess[a + i][b] <= 82)
         {
            break;
         }
         if (chess[a + i][b] == '@')
         {
            chess[a + i][b] = '2';
            break;
         }
         else if (chess[a + i][b] == '#')
         {
            chess[a + i][b] = '3';
            break;
         }
         else if (chess[a + i][b] == '$')
         {
            chess[a + i][b] = '4';
            break;
         }
         else if (chess[a + i][b] == '%')
         {
            chess[a + i][b] = '5';
            break;
         }
         else if (chess[a + i][b] == '&')
         {
            chess[a + i][b] = '7';
            break;
         }
         else if (chess[a + i][b] == '*')
         {
            chess[a + i][b] = '8';
            break;
         }
      }
      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a + k][b] == '-')
            chess[a + k][b] = 'o';
      }
      // 왼쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b - i] >= 66 && chess[a][b - i] <= 82)
         {
            break;
         }
         if (chess[a][b - i] == '@')
         {
            chess[a][b - i] = '2';
            break;
         }
         else if (chess[a][b - i] == '#')
         {
            chess[a][b - i] = '3';
            break;
         }
         else if (chess[a][b - i] == '$')
         {
            chess[a][b - i] = '4';
            break;
         }
         else if (chess[a][b - i] == '%')
         {
            chess[a][b - i] = '5';
            break;
         }
         else if (chess[a][b - i] == '&')
         {
            chess[a][b - i] = '7';
            break;
         }
         else if (chess[a][b - i] == '*')
         {
            chess[a][b - i] = '8';
            break;
         }
      }
      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b - k] == '-')
            chess[a][b - k] = 'o';
      }

      // 오른쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b + i] >= 66 && chess[a][b + i] <= 82)
         {
            break;
         }
         if (chess[a][b + i] == '@')
         {
            chess[a][b + i] = '2';
            break;
         }
         else if (chess[a][b + i] == '#')
         {
            chess[a][b + i] = '3';
            break;
         }
         else if (chess[a][b + i] == '$')
         {
            chess[a][b + i] = '4';
            break;
         }
         else if (chess[a][b + i] == '%')
         {
            chess[a][b + i] = '5';
            break;
         }
         else if (chess[a][b + i] == '&')
         {
            chess[a][b + i] = '7';
            break;
         }
         else if (chess[a][b + i] == '*')
         {
            chess[a][b + i] = '8';
            break;
         }
      }
      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b + k] == '-')
            chess[a][b + k] = 'o';
      }
   }

   if (chess[a][b] == '#')
   {
      // 말로부터 위의 요소 검사
      for (i = 1; i < a; i++)
      {
         // 같은 문자열
         if (chess[a - i][b] == '@')
         {
            break;
         }
         else if (chess[a - i][b] == '#')
         {
            break;
         }
         else if (chess[a - i][b] == '$')
         {
            break;
         }
         else if (chess[a - i][b] == '%')
         {
            break;
         }
         else if (chess[a - i][b] == '&')
         {
            break;
         }
         else if (chess[a - i][b] == '*')
         {
            break;
         }
         if (chess[a - i][b] >= 66 && chess[a - i][b] <= 82)
         { // 알파벳이면..
            chess[a - i][b] += 32;
            break;
         }
      }
      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a - k][b] == '-')
            chess[a - k][b] = 'o';
      }
      // 아래 요소 검사
      for (i = 1; i <= 9 - a; i++)
      {

         if (chess[a + i][b] == '@')
         {
            break;
         }
         else if (chess[a + i][b] == '#')
         {
            break;
         }
         else if (chess[a + i][b] == '$')
         {
            break;
         }
         else if (chess[a + i][b] == '%')
         {
            break;
         }
         else if (chess[a + i][b] == '&')
         {
            break;
         }
         else if (chess[a + i][b] == '*')
         {
            break;
         }
         if (chess[a + i][b] >= 66 && chess[a + i][b] <= 82)
         {
            chess[a + i][b] += 32;
            break;
         }
      }
      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a + k][b] == '-')
            chess[a + k][b] = 'o';
      }
      // 왼쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b - i] == '@')
         {
            break;
         }
         else if (chess[a][b - i] == '#')
         {
            break;
         }
         else if (chess[a][b - i] == '$')
         {
            break;
         }
         else if (chess[a][b - i] == '%')
         {
            break;
         }
         else if (chess[a][b - i] == '&')
         {
            break;
         }
         else if (chess[a][b - i] == '*')
         {
            break;
         }
         if (chess[a][b - i] >= 66 && chess[a][b - i] <= 82)
         {
            chess[a][b - i] += 32;
            break;
         }
      }
      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b - k] == '-')
            chess[a][b - k] = 'o';
      }

      // 오른쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b + i] == '@')
         {
            break;
         }
         else if (chess[a][b + i] == '#')
         {
            break;
         }
         else if (chess[a][b + i] == '$')
         {
            break;
         }
         else if (chess[a][b + i] == '%')
         {
            break;
         }
         else if (chess[a][b + i] == '&')
         {
            break;
         }
         else if (chess[a][b + i] == '*')
         {
            break;
         }
         if (chess[a][b + i] >= 66 && chess[a][b + i] <= 82)
         {
            chess[a][b + i] += 32;
            break;
         }
      }
      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b + k] == '-')
            chess[a][b + k] = 'o';
      }
   }
}

void king(char locx, char locy)
{
   int a = locy + 1;
   int b = 2 * locx - 190;
   // 말로부터 위의 요소 검사
   if (chess[a][b] == 'K')
   {
      if (chess[a - 1][b] == '@' || chess[a - 1][b] == '#' || chess[a - 1][b] == '$' || chess[a - 1][b] == '%' || chess[a - 1][b] == '&' || chess[a - 1][b] == '*')
      {
         if (chess[a - 1][b] == '@')
         {
            chess[a - 1][b] = '2';
         }
         else if (chess[a - 1][b] == '#')
         {
            chess[a - 1][b] = '3';
         }
         else if (chess[a - 1][b] == '$')
         {
            chess[a - 1][b] = '4';
         }
         else if (chess[a - 1][b] == '%')
         {
            chess[a - 1][b] = '5';
         }
         else if (chess[a - 1][b] == '&')
         {
            chess[a - 1][b] = '7';
         }
         else if (chess[a - 1][b] == '*')
         {
            chess[a - 1][b] = '8';
         }
      }
      if (chess[a - 1][b] == '-')
         chess[a - 1][b] = 'o';

      // 아래 요소 검사
      if (chess[a + 1][b] == '@' || chess[a + 1][b] == '#' || chess[a + 1][b] == '$' || chess[a + 1][b] == '%' || chess[a + 1][b] == '&' || chess[a + 1][b] == '*')
      {
         if (chess[a + 1][b] == '@')
         {
            chess[a + 1][b] = '2';
         }
         else if (chess[a + 1][b] == '#')
         {
            chess[a + 1][b] = '3';
         }
         else if (chess[a + 1][b] == '$')
         {
            chess[a + 1][b] = '4';
         }
         else if (chess[a + 1][b] == '%')
         {
            chess[a + 1][b] = '5';
         }
         else if (chess[a + 1][b] == '&')
         {
            chess[a + 1][b] = '7';
         }
         else if (chess[a + 1][b] == '*')
         {
            chess[a + 1][b] = '8';
         }
      }
      if (chess[a + 1][b] == '-')
         chess[a + 1][b] = 'o';

      // 왼쪽 요소 검사
      if (chess[a][b - 2] == '@' || chess[a][b - 2] == '#' || chess[a][b - 2] == '$' || chess[a][b - 2] == '%' || chess[a][b - 2] == '&' || chess[a][b - 2] == '*')
      {
         if (chess[a][b - 2] == '@')
         {
            chess[a][b - 2] = '2';
         }
         else if (chess[a][b - 2] == '#')
         {
            chess[a][b - 2] = '3';
         }
         else if (chess[a][b - 2] == '$')
         {
            chess[a][b - 2] = '4';
         }
         else if (chess[a][b - 2] == '%')
         {
            chess[a][b - 2] = '5';
         }
         else if (chess[a][b - 2] == '&')
         {
            chess[a][b - 2] = '7';
         }
         else if (chess[a][b - 2] == '*')
         {
            chess[a][b - 2] = '8';
         }
      }
      if (chess[a][b - 2] == '-')
         chess[a][b - 2] = 'o';

      // 오른쪽 요소 검사
      if (chess[a][b + 2] == '@' || chess[a][b + 2] == '#' || chess[a][b + 2] == '$' || chess[a][b + 2] == '%' || chess[a][b + 2] == '&' || chess[a][b + 2] == '*')
      {
         if (chess[a][b + 2] == '@')
         {
            chess[a][b + 2] = '2';
         }
         else if (chess[a][b + 2] == '#')
         {
            chess[a][b + 2] = '3';
         }
         else if (chess[a][b + 2] == '$')
         {
            chess[a][b + 2] = '4';
         }
         else if (chess[a][b + 2] == '%')
         {
            chess[a][b + 2] = '5';
         }
         else if (chess[a][b + 2] == '&')
         {
            chess[a][b + 2] = '7';
         }
         else if (chess[a][b + 2] == '*')
         {
            chess[a][b + 2] = '8';
         }
      }

      if (chess[a][b + 2] == '-')
         chess[a][b + 2] = 'o';

      // 대각선 요소 검사
      if (chess[a + 1][b + 2] == '@' || chess[a + 1][b + 2] == '#' || chess[a + 1][b + 2] == '$' || chess[a + 1][b + 2] == '%' || chess[a + 1][b + 2] == '&' || chess[a + 1][b + 2] == '*')
      {
         if (chess[a + 1][b + 2] == '@')
         {
            chess[a + 1][b + 2] = '2';
         }
         else if (chess[a + 1][b + 2] == '#')
         {
            chess[a + 1][b + 2] = '3';
         }
         else if (chess[a + 1][b + 2] == '$')
         {
            chess[a + 1][b + 2] = '4';
         }
         else if (chess[a + 1][b + 2] == '%')
         {
            chess[a + 1][b + 2] = '5';
         }
         else if (chess[a + 1][b + 2] == '&')
         {
            chess[a + 1][b + 2] = '7';
         }
         else if (chess[a + 1][b + 2] == '*')
         {
            chess[a + 1][b + 2] = '8';
         }
      }
      if (chess[a + 1][b + 2] == '-')
      {
         chess[a + 1][b + 2] = 'o';
      }

      if (chess[a - 1][b - 2] == '@' || chess[a - 1][b - 2] == '#' || chess[a - 1][b - 2] == '$' || chess[a - 1][b - 2] == '%' || chess[a - 1][b - 2] == '&' || chess[a - 1][b - 2] == '*')
      {
         if (chess[a - 1][b - 2] == '@')
         {
            chess[a - 1][b - 2] = '2';
         }
         else if (chess[a - 1][b - 2] == '#')
         {
            chess[a - 1][b - 2] = '3';
         }
         else if (chess[a - 1][b - 2] == '$')
         {
            chess[a - 1][b - 2] = '4';
         }
         else if (chess[a - 1][b - 2] == '%')
         {
            chess[a - 1][b - 2] = '5';
         }
         else if (chess[a - 1][b - 2] == '&')
         {
            chess[a - 1][b - 2] = '7';
         }
         else if (chess[a - 1][b - 2] == '*')
         {
            chess[a - 1][b - 2] = '8';
         }
      }
      if (chess[a - 1][b - 2] == '-')
      {
         chess[a - 1][b - 2] = 'o';
      }

      if (chess[a - 1][b + 2] == '@' || chess[a - 1][b + 2] == '#' || chess[a - 1][b + 2] == '$' || chess[a - 1][b + 2] == '%' || chess[a - 1][b + 2] == '&' || chess[a - 1][b + 2] == '*')
      {
         if (chess[a - 1][b + 2] == '@')
         {
            chess[a - 1][b + 2] = '2';
         }
         else if (chess[a - 1][b + 2] == '#')
         {
            chess[a - 1][b + 2] = '3';
         }
         else if (chess[a - 1][b + 2] == '$')
         {
            chess[a - 1][b + 2] = '4';
         }
         else if (chess[a - 1][b + 2] == '%')
         {
            chess[a - 1][b + 2] = '5';
         }
         else if (chess[a - 1][b + 2] == '&')
         {
            chess[a - 1][b + 2] = '7';
         }
         else if (chess[a - 1][b + 2] == '*')
         {
            chess[a - 1][b + 2] = '8';
         }
      }
      if (chess[a - 1][b + 2] == '-')
      {
         chess[a - 1][b + 2] = 'o';
      }

      if (chess[a + 1][b - 2] == '@' || chess[a + 1][b - 2] == '#' || chess[a + 1][b - 2] == '$' || chess[a + 1][b - 2] == '%' || chess[a + 1][b - 2] == '&' || chess[a + 1][b - 2] == '*')
      {
         if (chess[a + 1][b - 2] == '@')
         {
            chess[a + 1][b - 2] = '2';
         }
         else if (chess[a + 1][b - 2] == '#')
         {
            chess[a + 1][b - 2] = '3';
         }
         else if (chess[a + 1][b - 2] == '$')
         {
            chess[a + 1][b - 2] = '4';
         }
         else if (chess[a + 1][b - 2] == '%')
         {
            chess[a + 1][b - 2] = '5';
         }
         else if (chess[a + 1][b - 2] == '&')
         {
            chess[a + 1][b - 2] = '7';
         }
         else if (chess[a + 1][b - 2] == '*')
         {
            chess[a + 1][b - 2] = '8';
         }
      }
      if (chess[a + 1][b - 2] == '-')
      {
         chess[a + 1][b - 2] = 'o';
      }

      // 같은 문자일
      // 말로부터 위의 요소 검사
      if (chess[a - 1][b] >= 66 && chess[a - 1][b] <= 82)
      {
         // break;
      }
      // 아래 요소 검사
      if (chess[a + 1][b] >= 66 && chess[a + 1][b] <= 82)
      {
         // break;
      }
      // 왼쪽 요소 검사
      if (chess[a][b - 2] >= 66 && chess[a][b - 2] <= 82)
      {
         // break;
      }
      // 오른쪽 요소 검사
      if (chess[a][b + 2] >= 66 && chess[a][b + 2] <= 82)
      {
         // break;
      }
      // 대각선 요소 검사
      if (chess[a + 1][b + 2] >= 66 && chess[a + 1][b + 2] <= 82)
      {
         // break;
      }
      if (chess[a - 1][b - 2] >= 66 && chess[a - 1][b - 2] <= 82)
      {
         // break;
      }
      if (chess[a - 1][b + 2] >= 66 && chess[a - 1][b + 2] <= 82)
      {
         // break;
      }
      if (chess[a + 1][b - 2] >= 66 && chess[a + 1][b - 2] <= 82)
      {
         // break;
      }
   }

   if (chess[a][b] == '$')
   {
      // 위 요소 검사
      if (chess[a - 1][b] >= 66 && chess[a - 1][b] <= 82)
         chess[a - 1][b] += 32;
      if (chess[a - 1][b] == '-')
         chess[a - 1][b] = 'o';

      // 아래 요소 검사
      if (chess[a + 1][b] >= 66 && chess[a + 1][b] <= 82)
         chess[a + 1][b] += 32;
      if (chess[a + 1][b] == '-')
         chess[a + 1][b] = 'o';

      // 왼쪽 요소 검사
      if (chess[a][b - 2] >= 66 && chess[a][b - 2] <= 82)
         chess[a][b - 2] += 32;
      if (chess[a][b - 2] == '-')
         chess[a][b - 2] = 'o';

      // 오른쪽 요소 검사
      if (chess[a][b + 2] >= 66 && chess[a][b + 2] <= 82)
         chess[a][b + 2] += 32;
      if (chess[a][b + 2] == '-')
         chess[a][b + 2] = 'o';

      // 대각선 요소 검사
      if (chess[a + 1][b + 2] >= 66 && chess[a + 1][b + 2] <= 82)
         chess[a + 1][b + 2] += 32;
      if (chess[a + 1][b + 2] == '-')
         chess[a + 1][b + 2] = 'o';

      if (chess[a - 1][b - 2] >= 66 && chess[a - 1][b - 2] <= 82)
         chess[a - 1][b - 2] += 32;
      if (chess[a - 1][b - 2] == '-')
         chess[a - 1][b - 2] = 'o';

      if (chess[a - 1][b + 2] >= 66 && chess[a - 1][b + 2] <= 82)
         chess[a - 1][b + 2] += 32;
      if (chess[a - 1][b + 2] == '-')
         chess[a - 1][b + 2] = 'o';

      if (chess[a + 1][b - 2] >= 66 && chess[a + 1][b - 2] <= 82)
         chess[a + 1][b - 2] += 32;
      if (chess[a + 1][b - 2] == '-')
         chess[a + 1][b - 2] = 'o';

      // 같은 문자일
      // 말로부터 위의 요소 검사
      if (chess[a - 1][b] == '@' || chess[a - 1][b] == '#' || chess[a - 1][b] == '%' || chess[a - 1][b] == '&' || chess[a - 1][b] == '*')
      {
         // break;
      }
      // 아래 요소 검사
      if (chess[a + 1][b] == '@' || chess[a + 1][b] == '#' || chess[a + 1][b] == '%' || chess[a + 1][b] == '&' || chess[a + 1][b] == '*')
      {
         // break;
      }
      // 왼쪽 요소 검사
      if (chess[a][b - 2] == '@' || chess[a][b - 2] == '#' || chess[a][b - 2] == '%' || chess[a][b - 2] == '&' || chess[a][b - 2] == '*')
      {
         // break;
      }
      // 오른쪽 요소 검사
      if (chess[a][b + 2] == '@' || chess[a][b + 2] == '#' || chess[a][b + 2] == '%' || chess[a][b + 2] == '&' || chess[a][b + 2] == '*')
      {
         // break;
      }
      // 대각선 요소 검사
      if (chess[a + 1][b + 2] == '@' || chess[a + 1][b + 2] == '#' || chess[a + 1][b + 2] == '%' || chess[a + 1][b + 2] == '&' || chess[a + 1][b + 2] == '*')
      {
         // break;
      }
      if (chess[a - 1][b + 2] == '@' || chess[a - 1][b + 2] == '#' || chess[a = 1][b + 2] == '%' || chess[a - 1][b + 2] == '&' || chess[a - 1][b + 2] == '*')
      {
         // break;
      }
      if (chess[a + 1][b - 2] == '@' || chess[a + 1][b - 2] == '#' || chess[a + 1][b - 2] == '%' || chess[a + 1][b - 2] == '&' || chess[a + 1][b - 2] == '*')
      {
         // break;
      }
      if (chess[a - 1][b - 2] == '@' || chess[a - 1][b - 2] == '#' || chess[a - 1][b - 2] == '%' || chess[a - 1][b - 2] == '&' || chess[a - 1][b - 2] == '*')
      {
         // break;
      }
   }

   system("cls");
}

void queen(char locx, char locy)
{
   int u, d, r, l, i, j;
   int a = locy + 1;
   int b = 2 * locx - 190;

   if (chess[a][b] == 'Q')
   {
      // 말로부터 위의 요소 검사
      for (i = 1; i < a; i++)
      {
         // 같은문자열
         if (chess[a - i][b] >= 66 && chess[a - i][b] <= 82)
         { // 알파벳이면..
            break;
         }
         // 다른 문자열
         if (chess[a - i][b] == '@')
         {
            chess[a - i][b] = '2';
            break;
         }
         else if (chess[a - i][b] == '#')
         {
            chess[a - i][b] = '3';
            break;
         }
         else if (chess[a - i][b] == '$')
         {
            chess[a - i][b] = '4';
            break;
         }
         else if (chess[a - i][b] == '%')
         {
            chess[a - i][b] = '5';
            break;
         }
         else if (chess[a - i][b] == '&')
         {
            chess[a - i][b] = '7';
            break;
         }
         else if (chess[a - i][b] == '*')
         {
            chess[a - i][b] = '8';
            break;
         }
      }
      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a - k][b] == '-')
            chess[a - k][b] = 'o';
      }
      // 아래 요소 검사
      for (i = 1; i < 9 - a; i++)
      {
         if (chess[a + i][b] >= 66 && chess[a + i][b] <= 82)
         {
            break;
         }
         if (chess[a + i][b] == '@')
         {
            chess[a + i][b] = '2';
            break;
         }
         else if (chess[a + i][b] == '#')
         {
            chess[a + i][b] = '3';
            break;
         }
         else if (chess[a + i][b] == '$')
         {
            chess[a + i][b] = '4';
            break;
         }
         else if (chess[a + i][b] == '%')
         {
            chess[a + i][b] = '5';
            break;
         }
         else if (chess[a + i][b] == '&')
         {
            chess[a + i][b] = '7';
            break;
         }
         else if (chess[a + i][b] == '*')
         {
            chess[a + i][b] = '8';
            break;
         }
      }
      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a + k][b] == '-')
            chess[a + k][b] = 'o';
      }
      // 왼쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b - i] >= 66 && chess[a][b - i] <= 82)
         {
            break;
         }
         if (chess[a][b - i] == '@')
         {
            chess[a][b - i] = '2';
            break;
         }
         else if (chess[a][b - i] == '#')
         {
            chess[a][b - i] = '3';
            break;
         }
         else if (chess[a][b - i] == '$')
         {
            chess[a][b - i] = '4';
            break;
         }
         else if (chess[a][b - i] == '%')
         {
            chess[a][b - i] = '5';
            break;
         }
         else if (chess[a][b - i] == '&')
         {
            chess[a][b - i] = '7';
            break;
         }
         else if (chess[a][b - i] == '*')
         {
            chess[a][b - i] = '8';
            break;
         }
      }
      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b - k] == '-')
            chess[a][b - k] = 'o';
      }

      // 오른쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b + i] >= 66 && chess[a][b + i] <= 82)
         {
            break;
         }
         if (chess[a][b + i] == '@')
         {
            chess[a][b + i] = '2';
            break;
         }
         else if (chess[a][b + i] == '#')
         {
            chess[a][b + i] = '3';
            break;
         }
         else if (chess[a][b + i] == '$')
         {
            chess[a][b + i] = '4';
            break;
         }
         else if (chess[a][b + i] == '%')
         {
            chess[a][b + i] = '5';
            break;
         }
         else if (chess[a][b + i] == '&')
         {
            chess[a][b + i] = '7';
            break;
         }
         else if (chess[a][b + i] == '*')
         {
            chess[a][b + i] = '8';
            break;
         }
      }
      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b + k] == '-')
            chess[a][b + k] = 'o';
      }

      // 대각선 요소 검사
      // 아래, 오른쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] >= 66 && chess[a + i][b + k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '@' || chess[a + i][b + k] == '#' || chess[a + i][b + k] == '$' || chess[a + i][b + k] == '%' || chess[a + i][b + k] == '&' || chess[a + i][b + k] == '*')
         {
            if (chess[a + i][b + k] == '@')
            {
               chess[a + i][b + k] = '2';
               break;
            }
            else if (chess[a + i][b + k] == '#')
            {
               chess[a + i][b + k] = '3';
               break;
            }
            else if (chess[a + i][b + k] == '$')
            {
               chess[a + i][b + k] = '4';
               break;
            }
            else if (chess[a + i][b + k] == '%')
            {
               chess[a + i][b + k] = '5';
               break;
            }
            else if (chess[a + i][b + k] == '&')
            {
               chess[a + i][b + k] = '7';
               break;
            }
            else if (chess[a + i][b + k] == '*')
            {
               chess[a + i][b + k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '-')
         {
            chess[a + i][b + k] = 'o';
            k += 2;
         }
      }

      // 위, 왼쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] >= 66 && chess[a - i][b - k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }

      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '@' || chess[a - i][b - k] == '#' || chess[a - i][b - k] == '$' || chess[a - i][b - k] == '%' || chess[a - i][b - k] == '&' || chess[a - i][b - k] == '*')
         {
            if (chess[a - i][b - k] == '@')
            {
               chess[a - i][b - k] = '2';
               break;
            }
            else if (chess[a - i][b - k] == '#')
            {
               chess[a - i][b - k] = '3';
               break;
            }
            else if (chess[a - i][b - k] == '$')
            {
               chess[a - i][b - k] = '4';
               break;
            }
            else if (chess[a - i][b - k] == '%')
            {
               chess[a - i][b - k] = '5';
               break;
            }
            else if (chess[a - i][b - k] == '&')
            {
               chess[a - k][b - k] = '7';
               break;
            }
            else if (chess[a - i][b - k] == '*')
            {
               chess[a - i][b - k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '-')
         {
            chess[a - i][b - k] = 'o';
            k += 2;
         }
      }
      // i++;

      // 위, 오른쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] >= 66 && chess[a - i][b + k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '@' || chess[a - i][b + k] == '#' || chess[a - i][b + k] == '$' || chess[a - i][b + k] == '%' || chess[a - i][b + k] == '&' || chess[a - i][b + k] == '*')
         {
            if (chess[a - i][b + k] == '@')
            {
               chess[a - i][b + k] = '2';
               break;
            }
            else if (chess[a - i][b + k] == '#')
            {
               chess[a - i][b + k] = '3';
               break;
            }
            else if (chess[a - i][b + k] == '$')
            {
               chess[a - i][b + k] = '4';
               break;
            }
            else if (chess[a - i][b + k] == '%')
            {
               chess[a - i][b + k] = '5';
               break;
            }
            else if (chess[a - i][b + k] == '&')
            {
               chess[a - i][b + k] = '7';
               break;
            }
            else if (chess[a - i][b + k] == '*')
            {
               chess[a - i][b + k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '-')
         {
            chess[a - i][b + k] = 'o';
            k += 2;
         }
      }

      // 아래, 왼쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] >= 66 && chess[a + i][b - k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '@' || chess[a + i][b - k] == '#' || chess[a + i][b - k] == '$' || chess[a + i][b - k] == '%' || chess[a + i][b - k] == '&' || chess[a + i][b - k] == '*')
         {
            if (chess[a + i][b - k] == '@')
            {
               chess[a + i][b - k] = '2';
               break;
            }
            else if (chess[a + i][b - k] == '#')
            {
               chess[a + i][b - k] = '3';
               break;
            }
            else if (chess[a + i][b - k] == '$')
            {
               chess[a + i][b - k] = '4';
               break;
            }
            else if (chess[a + i][b - k] == '%')
            {
               chess[a + i][b - k] = '5';
               break;
            }
            else if (chess[a + i][b - k] == '&')
            {
               chess[a + i][b - k] = '7';
               break;
            }
            else if (chess[a + i][b - k] == '*')
            {
               chess[a + i][b - k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '-')
         {
            chess[a + i][b - k] = 'o';
            k += 2;
         }
      }
   }

   if (chess[a][b] == '@')
   {
      // 말로부터 위의 요소 검사
      for (i = 1; i < a; i++)
      {
         // 같은문자열
         if (chess[a - i][b] == '@')
         {
            break;
         }
         else if (chess[a - i][b] == '#')
         {
            break;
         }
         else if (chess[a - i][b] == '$')
         {
            break;
         }
         else if (chess[a - i][b] == '%')
         {
            break;
         }
         else if (chess[a - i][b] == '&')
         {
            break;
         }
         else if (chess[a - i][b] == '*')
         {
            break;
         }
         // 다른 문자열이면
         if (chess[a - i][b] >= 66 && chess[a - i][b] <= 82)
         { // 알파벳이면..
            chess[a - i][b] += 32;
            break;
         }
      }

      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a - k][b] == '-')
            chess[a - k][b] = 'o';
      }
      // 아래 요소 검사
      for (i = 1; i < 9 - a; i++)
      {
         if (chess[a + i][b] == '@')
         {
            break;
         }
         else if (chess[a + i][b] == '#')
         {
            break;
         }
         else if (chess[a + i][b] == '$')
         {
            break;
         }
         else if (chess[a + i][b] == '%')
         {
            break;
         }
         else if (chess[a + i][b] == '&')
         {
            break;
         }
         else if (chess[a + i][b] == '*')
         {
            break;
         }
         if (chess[a + i][b] >= 66 && chess[a + i][b] <= 82)
         {
            chess[a + i][b] += 32;
            break;
         }
      }

      for (int k = i - 1; k > 0; k--)
      {
         if (chess[a + k][b] == '-')
            chess[a + k][b] = 'o';
      }

      // 왼쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b - i] == '@')
         {
            break;
         }
         else if (chess[a][b - i] == '#')
         {
            break;
         }
         else if (chess[a][b - i] == '$')
         {
            break;
         }
         else if (chess[a][b - i] == '%')
         {
            break;
         }
         else if (chess[a][b - i] == '&')
         {
            break;
         }
         else if (chess[a][b - i] == '*')
         {
            break;
         }
         if (chess[a][b - i] >= 66 && chess[a][b - i] <= 82)
         {
            chess[a][b - i] += 32;
            break;
         }
      }

      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b - k] == '-')
            chess[a][b - k] = 'o';
      }

      // 오른쪽 요소 검사
      for (i = 2; i < 18; i += 2)
      {
         if (chess[a][b + i] == '@')
         {
            break;
         }
         else if (chess[a][b + i] == '#')
         {
            break;
         }
         else if (chess[a][b + i] == '$')
         {
            break;
         }
         else if (chess[a][b + i] == '%')
         {
            break;
         }
         else if (chess[a][b + i] == '&')
         {
            break;
         }
         else if (chess[a][b + i] == '*')
         {
            break;
         }
         if (chess[a][b + i] >= 66 && chess[a][b + i] <= 82)
         {
            chess[a][b + i] += 32;
            break;
         }
      }
      for (int k = i - 2; k > 0; k -= 2)
      {
         if (chess[a][b + k] == '-')
            chess[a][b + k] = 'o';
      }

      // 대각선 요소 검사
      // 아래, 오른쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '*')
         {
            k += 2;
            break;
         }
      }

      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == 'K' || chess[a + i][b + k] == 'Q' || chess[a + i][b + k] == 'B' || chess[a + i][b + k] == 'R' || chess[a + i][b + k] == '&' || chess[a + i][b + k] == 'P')
         {
            if (chess[a + i][b + k] == 'K')
            {
               chess[a + i][b + k] = 'k';
               break;
            }
            else if (chess[a + i][b + k] == 'Q')
            {
               chess[a + i][b + k] = 'q';
               break;
            }
            else if (chess[a + i][b + k] == 'B')
            {
               chess[a + i][b + k] = 'b';
               break;
            }
            else if (chess[a + i][b + k] == 'R')
            {
               chess[a + i][b + k] = 'r';
               break;
            }
            else if (chess[a + i][b + k] == 'N')
            {
               chess[a + i][b + k] = 'n';
               break;
            }
            else if (chess[a + i][b + k] == 'P')
            {
               chess[a + i][b + k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '-')
         {
            chess[a + i][b + k] = 'o';
            k += 2;
         }
      }

      // 위, 왼쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '*')
         {
            k += 2;
            break;
         }
      }

      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == 'K' || chess[a - i][b - k] == 'Q' || chess[a - i][b - k] == 'B' || chess[a - i][b - k] == 'R' || chess[a - i][b - k] == 'N' || chess[a - i][b - k] == 'P')
         {
            if (chess[a - i][b - k] == 'K')
            {
               chess[a - i][b - k] = 'k';
               break;
            }
            else if (chess[a - i][b - k] == 'Q')
            {
               chess[a - i][b - k] = 'q';
               break;
            }
            else if (chess[a - i][b - k] == 'B')
            {
               chess[a - i][b - k] = 'b';
               break;
            }
            else if (chess[a - i][b - k] == 'R')
            {
               chess[a - i][b - k] = 'r';
               break;
            }
            else if (chess[a - i][b - k] == 'N')
            {
               chess[a - k][b - k] = 'n';
               break;
            }
            else if (chess[a - i][b - k] == 'P')
            {
               chess[a - i][b - k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '-')
         {
            chess[a - i][b - k] = 'o';
            k += 2;
         }
      }
      // i++;

      // 위, 오른쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '*')
         {
            k += 2;
            break;
         }
      }
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == 'K' || chess[a - i][b + k] == 'Q' || chess[a - i][b + k] == 'B' || chess[a - i][b + k] == 'R' || chess[a - i][b + k] == 'N' || chess[a - i][b + k] == 'P')
         {
            if (chess[a - i][b + k] == 'K')
            {
               chess[a - i][b + k] = 'k';
               break;
            }
            else if (chess[a - i][b + k] == 'Q')
            {
               chess[a - i][b + k] = 'q';
               break;
            }
            else if (chess[a - i][b + k] == 'B')
            {
               chess[a - i][b + k] = 'b';
               break;
            }
            else if (chess[a - i][b + k] == 'R')
            {
               chess[a - i][b + k] = 'r';
               break;
            }
            else if (chess[a - i][b + k] == 'N')
            {
               chess[a - i][b + k] = 'n';
               break;
            }
            else if (chess[a - i][b + k] == 'P')
            {
               chess[a - i][b + k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '-')
         {
            chess[a - i][b + k] = 'o';
            k += 2;
         }
      }

      // 아래, 왼쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '*')
         {
            k += 2;
            break;
         }
      }
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == 'K' || chess[a + i][b - k] == 'Q' || chess[a + i][b - k] == 'B' || chess[a + i][b - k] == 'R' || chess[a + i][b - k] == 'N' || chess[a + i][b - k] == 'P')
         {
            if (chess[a + i][b - k] == 'K')
            {
               chess[a + i][b - k] = 'k';
               break;
            }
            else if (chess[a + i][b - k] == 'Q')
            {
               chess[a + i][b - k] = 'q';
               break;
            }
            else if (chess[a + i][b - k] == 'B')
            {
               chess[a + i][b - k] = 'b';
               break;
            }
            else if (chess[a + i][b - k] == 'R')
            {
               chess[a + i][b - k] = 'r';
               break;
            }
            else if (chess[a + i][b - k] == 'N')
            {
               chess[a + i][b - k] = 'n';
               break;
            }
            else if (chess[a + i][b - k] == 'P')
            {
               chess[a + i][b - k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '-')
         {
            chess[a + i][b - k] = 'o';
            k += 2;
         }
      }
   }
}

void knight(char locx, char locy)
{
   int a = locy + 1;
   int b = 2 * locx - 190;
   if (chess[a][b] == 'N')
   {
      // 상단 오른쪽
      if (chess[a - 2][b + 2] == '@')
      {
         chess[a - 2][b + 2] = '2';
      }
      else if (chess[a - 2][b + 2] == '#')
      {
         chess[a - 2][b + 2] = '3';
      }
      else if (chess[a - 2][b + 2] == '$')
      {
         chess[a - 2][b + 2] = '4';
      }
      else if (chess[a - 2][b + 2] == '%')
      {
         chess[a - 2][b + 2] = '5';
      }
      else if (chess[a - 2][b + 2] == '&')
      {
         chess[a - 2][b + 2] = '7';
      }
      else if (chess[a - 2][b + 2] == '*')
      {
         chess[a - 2][b + 2] = '8';
      }
      if (chess[a - 2][b + 2] == '-')
         chess[a - 2][b + 2] = 'o';
      // 상단 왼쪽
      if (chess[a - 2][b - 2] == 'K')
      {
         chess[a - 2][b - 2] = '2';
      }
      else if (chess[a - 2][b - 2] == '#')
      {
         chess[a - 2][b - 2] = '3';
      }
      else if (chess[a - 2][b - 2] == '$')
      {
         chess[a - 2][b - 2] = '4';
      }
      else if (chess[a - 2][b - 2] == '%')
      {
         chess[a - 2][b - 2] = '5';
      }
      else if (chess[a - 2][b - 2] == '&')
      {
         chess[a - 2][b - 2] = '7';
      }
      else if (chess[a - 2][b - 2] == '*')
      {
         chess[a - 2][b - 2] = '8';
      }
      if (chess[a - 2][b - 2] == '-')
         chess[a - 2][b - 2] = 'o';
      // 하단 오른쪽
      if (chess[a + 2][b + 2] == '@')
      {
         chess[a + 2][b + 2] = '2';
      }
      else if (chess[a + 2][b + 2] == '#')
      {
         chess[a + 2][b + 2] = '3';
      }
      else if (chess[a + 2][b + 2] == '$')
      {
         chess[a + 2][b + 2] = '4';
      }
      else if (chess[a + 2][b + 2] == '%')
      {
         chess[a + 2][b + 2] = '5';
      }
      else if (chess[a + 2][b + 2] == '&')
      {
         chess[a + 2][b + 2] = '7';
      }
      else if (chess[a + 2][b + 2] == '*')
      {
         chess[a + 2][b + 2] = '8';
      }
      if (chess[a + 2][b + 2] == '-')
         chess[a + 2][b + 2] = 'o';
      // 하단왼쪽
      if (chess[a + 2][b - 2] == '@')
      {
         chess[a + 2][b - 2] = '2';
      }
      else if (chess[a + 2][b - 2] == '#')
      {
         chess[a + 2][b - 2] = '3';
      }
      else if (chess[a + 2][b - 2] == '$')
      {
         chess[a + 2][b - 2] = '4';
      }
      else if (chess[a + 2][b - 2] == '%')
      {
         chess[a + 2][b - 2] = '5';
      }
      else if (chess[a + 2][b - 2] == '&')
      {
         chess[a + 2][b - 2] = '7';
      }
      else if (chess[a + 2][b - 2] == '*')
      {
         chess[a + 2][b - 2] = '8';
      }
      if (chess[a + 2][b - 2] == '-')
         chess[a + 2][b - 2] = 'o';
   }
   if (chess[a][b] == '%')
   {
      if (chess[a - 2][b + 2] >= 66 && chess[a - 2][b + 2] <= 82)
         chess[a - 2][b + 2] += 32;
      if (chess[a - 2][b + 2] == '-')
         chess[a - 2][b + 2] = 'o';
      if (chess[a - 2][b - 2] >= 66 && chess[a - 2][b - 2] <= 82)
         chess[a - 2][b - 2] += 32;
      if (chess[a - 2][b - 2] == '-')
         chess[a - 2][b - 2] = 'o';
      if (chess[a + 2][b + 2] >= 66 && chess[a + 2][b + 2] <= 82)
         chess[a + 2][b + 2] += 32;
      if (chess[a + 2][b + 2] == '-')
         chess[a + 2][b + 2] = 'o';
      if (chess[a + 2][b - 2] >= 66 && chess[a + 2][b - 2] <= 82)
         chess[a + 2][b - 2] += 32;
      if (chess[a + 2][b - 2] == '-')
         chess[a + 2][b - 2] = 'o';
   }
}

void bishop(char locx, char locy)
{
   int a = locy + 1;
   int b = 2 * locx - 190;
   int u, d, r, l, i, j;

   if (chess[a][b] == 'B')
   {
      // 대각선 요소 검사
      // 아래, 오른쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] >= 66 && chess[a + i][b + k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '@' || chess[a + i][b + k] == '#' || chess[a + i][b + k] == '$' || chess[a + i][b + k] == '%' || chess[a + i][b + k] == '&' || chess[a + i][b + k] == '*')
         {
            if (chess[a + i][b + k] == '@')
            {
               chess[a + i][b + k] = '2';
               break;
            }
            else if (chess[a + i][b + k] == '#')
            {
               chess[a + i][b + k] = '3';
               break;
            }
            else if (chess[a + i][b + k] == '$')
            {
               chess[a + i][b + k] = '4';
               break;
            }
            else if (chess[a + i][b + k] == '%')
            {
               chess[a + i][b + k] = '5';
               break;
            }
            else if (chess[a + i][b + k] == '&')
            {
               chess[a + i][b + k] = '7';
               break;
            }
            else if (chess[a + i][b + k] == '*')
            {
               chess[a + i][b + k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '-')
         {
            chess[a + i][b + k] = 'o';
            k += 2;
         }
      }

      // 위, 왼쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] >= 66 && chess[a - i][b - k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }

      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '@' || chess[a - i][b - k] == '#' || chess[a - i][b - k] == '$' || chess[a - i][b - k] == '%' || chess[a - i][b - k] == '&' || chess[a - i][b - k] == '*')
         {
            if (chess[a - i][b - k] == '@')
            {
               chess[a - i][b - k] = '2';
               break;
            }
            else if (chess[a - i][b - k] == '#')
            {
               chess[a - i][b - k] = '3';
               break;
            }
            else if (chess[a - i][b - k] == '$')
            {
               chess[a - i][b - k] = '4';
               break;
            }
            else if (chess[a - i][b - k] == '%')
            {
               chess[a - i][b - k] = '5';
               break;
            }
            else if (chess[a - i][b - k] == '&')
            {
               chess[a - k][b - k] = '7';
               break;
            }
            else if (chess[a - i][b - k] == '*')
            {
               chess[a - i][b - k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '-')
         {
            chess[a - i][b - k] = 'o';
            k += 2;
         }
      }
      // i++;

      // 위, 오른쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] >= 66 && chess[a - i][b + k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '@' || chess[a - i][b + k] == '#' || chess[a - i][b + k] == '$' || chess[a - i][b + k] == '%' || chess[a - i][b + k] == '&' || chess[a - i][b + k] == '*')
         {
            if (chess[a - i][b + k] == '@')
            {
               chess[a - i][b + k] = '2';
               break;
            }
            else if (chess[a - i][b + k] == '#')
            {
               chess[a - i][b + k] = '3';
               break;
            }
            else if (chess[a - i][b + k] == '$')
            {
               chess[a - i][b + k] = '4';
               break;
            }
            else if (chess[a - i][b + k] == '%')
            {
               chess[a - i][b + k] = '5';
               break;
            }
            else if (chess[a - i][b + k] == '&')
            {
               chess[a - i][b + k] = '7';
               break;
            }
            else if (chess[a - i][b + k] == '*')
            {
               chess[a - i][b + k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '-')
         {
            chess[a - i][b + k] = 'o';
            k += 2;
         }
      }

      // 아래, 왼쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] >= 66 && chess[a + i][b - k] <= 82)
         { // 알파벳이면..
            k += 2;
            break;
         }
      }
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '@' || chess[a + i][b - k] == '#' || chess[a + i][b - k] == '$' || chess[a + i][b - k] == '%' || chess[a + i][b - k] == '&' || chess[a + i][b - k] == '*')
         {
            if (chess[a + i][b - k] == '@')
            {
               chess[a + i][b - k] = '2';
               break;
            }
            else if (chess[a + i][b - k] == '#')
            {
               chess[a + i][b - k] = '3';
               break;
            }
            else if (chess[a + i][b - k] == '$')
            {
               chess[a + i][b - k] = '4';
               break;
            }
            else if (chess[a + i][b - k] == '%')
            {
               chess[a + i][b - k] = '5';
               break;
            }
            else if (chess[a + i][b - k] == '&')
            {
               chess[a + i][b - k] = '7';
               break;
            }
            else if (chess[a + i][b - k] == '*')
            {
               chess[a + i][b - k] = '8';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '-')
         {
            chess[a + i][b - k] = 'o';
            k += 2;
         }
      }
   }

   if (chess[a][b] == '&')
   {
      // 대각선 요소 검사
      // 아래, 오른쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b + k] == '*')
         {
            k += 2;
            break;
         }
      }

      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == 'K' || chess[a + i][b + k] == 'Q' || chess[a + i][b + k] == 'B' || chess[a + i][b + k] == 'R' || chess[a + i][b + k] == '&' || chess[a + i][b + k] == 'P')
         {
            if (chess[a + i][b + k] == 'K')
            {
               chess[a + i][b + k] = 'k';
               break;
            }
            else if (chess[a + i][b + k] == 'Q')
            {
               chess[a + i][b + k] = 'q';
               break;
            }
            else if (chess[a + i][b + k] == 'B')
            {
               chess[a + i][b + k] = 'b';
               break;
            }
            else if (chess[a + i][b + k] == 'R')
            {
               chess[a + i][b + k] = 'r';
               break;
            }
            else if (chess[a + i][b + k] == 'N')
            {
               chess[a + i][b + k] = 'n';
               break;
            }
            else if (chess[a + i][b + k] == 'P')
            {
               chess[a + i][b + k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b + k] == '-')
         {
            chess[a + i][b + k] = 'o';
            k += 2;
         }
      }

      // 위, 왼쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b - k] == '*')
         {
            k += 2;
            break;
         }
      }

      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == 'K' || chess[a - i][b - k] == 'Q' || chess[a - i][b - k] == 'B' || chess[a - i][b - k] == 'R' || chess[a - i][b - k] == 'N' || chess[a - i][b - k] == 'P')
         {
            if (chess[a - i][b - k] == 'K')
            {
               chess[a - i][b - k] = 'k';
               break;
            }
            else if (chess[a - i][b - k] == 'Q')
            {
               chess[a - i][b - k] = 'q';
               break;
            }
            else if (chess[a - i][b - k] == 'B')
            {
               chess[a - i][b - k] = 'b';
               break;
            }
            else if (chess[a - i][b - k] == 'R')
            {
               chess[a - i][b - k] = 'r';
               break;
            }
            else if (chess[a - i][b - k] == 'N')
            {
               chess[a - k][b - k] = 'n';
               break;
            }
            else if (chess[a - i][b - k] == 'P')
            {
               chess[a - i][b - k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b - k] == '-')
         {
            chess[a - i][b - k] = 'o';
            k += 2;
         }
      }
      // i++;

      // 위, 오른쪽
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a - i][b + k] == '*')
         {
            k += 2;
            break;
         }
      }
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == 'K' || chess[a - i][b + k] == 'Q' || chess[a - i][b + k] == 'B' || chess[a - i][b + k] == 'R' || chess[a - i][b + k] == 'N' || chess[a - i][b + k] == 'P')
         {
            if (chess[a - i][b + k] == 'K')
            {
               chess[a - i][b + k] = 'k';
               break;
            }
            else if (chess[a - i][b + k] == 'Q')
            {
               chess[a - i][b + k] = 'q';
               break;
            }
            else if (chess[a - i][b + k] == 'B')
            {
               chess[a - i][b + k] = 'b';
               break;
            }
            else if (chess[a - i][b + k] == 'R')
            {
               chess[a - i][b + k] = 'r';
               break;
            }
            else if (chess[a - i][b + k] == 'N')
            {
               chess[a - i][b + k] = 'n';
               break;
            }
            else if (chess[a - i][b + k] == 'P')
            {
               chess[a - i][b + k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < a; i++)
      {
         static int k = 2;
         if (chess[a - i][b + k] == '-')
         {
            chess[a - i][b + k] = 'o';
            k += 2;
         }
      }

      // 아래, 왼쪽
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '@')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '#')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '$')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '%')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '&')
         {
            k += 2;
            break;
         }
         else if (chess[a + i][b - k] == '*')
         {
            k += 2;
            break;
         }
      }
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == 'K' || chess[a + i][b - k] == 'Q' || chess[a + i][b - k] == 'B' || chess[a + i][b - k] == 'R' || chess[a + i][b - k] == 'N' || chess[a + i][b - k] == 'P')
         {
            if (chess[a + i][b - k] == 'K')
            {
               chess[a + i][b - k] = 'k';
               break;
            }
            else if (chess[a + i][b - k] == 'Q')
            {
               chess[a + i][b - k] = 'q';
               break;
            }
            else if (chess[a + i][b - k] == 'B')
            {
               chess[a + i][b - k] = 'b';
               break;
            }
            else if (chess[a + i][b - k] == 'R')
            {
               chess[a + i][b - k] = 'r';
               break;
            }
            else if (chess[a + i][b - k] == 'N')
            {
               chess[a + i][b - k] = 'n';
               break;
            }
            else if (chess[a + i][b - k] == 'P')
            {
               chess[a + i][b - k] = 'p';
               break;
            }
            // k+=2;
         }
         k += 2;
      }

      // for (int k=i-1; k > 0; k--){
      // for (int k=k-2; k > 0; k-=2){
      for (i = 1; i < 9 - a; i++)
      {
         static int k = 2;
         if (chess[a + i][b - k] == '-')
         {
            chess[a + i][b - k] = 'o';
            k += 2;
         }
      }
   }
}

/*int check()
{
   int i,j;
   for (i=2;i<=9;i++)
      for (j=4;j<=18;j+=2)
      {
         movepieces(i-1,(j+190)/2);
      }
   for (i=2;i<=9;i++)
      for (j=4;j<=18;j+=2)
      {
         if (chess[i][j]=='k' || chess[i][j]=='4')
            printf("CHECK\n");
      }
}
*/
void printResult(int number)
{
   system("cls");
   while (1)
   {
      printf("******************************************************************\n");
      printf("\n\n\n\n\n\tC o n g r a t u r a t i o n ! !\n\n");
      printf("\tP l a y e r     %s    W i n ! !", name[number]);
      printf("\n\n\n\n\n\n******************************************************************");
      getch();
      break;
   }
}
