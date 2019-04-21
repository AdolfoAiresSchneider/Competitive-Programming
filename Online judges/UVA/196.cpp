#include<bits/stdc++.h>
using namespace std;

char formula[1000][18279][100];
int dp[1000][18279];
bool MenusUm[1000][18279];
 
int f(int r, int c) 
{
	
  register int i,q,w,soma = 0;;
  if (MenusUm[r][c])  return dp[r][c];
  
  for (i = 0; formula[r][c][i]; i++) 
    if (formula[r][c][i] == '+' || formula[r][c][i] == '=')  formula[r][c][i] = ' ';
  
  istringstream fluxo(formula[r][c]);
  string STR;
  
  while (fluxo >> STR) 
  {
    q = w = 0;
    for (i = 0; STR[i] ; i++) 
    {
      if (isdigit(STR[i]))  q = q * 10 + (STR[i] - '0');
      else  w = w * 26 + ( STR[i] - 'A' + 1 );
    }
    soma += f(q, w);
  }
  MenusUm[r][c] = true;
  return dp[r][c] = soma;
}
 
int main()
{	
  //freopen("in","r",stdin);
  register int casos,i,j, R, C;;
  
  scanf("%d", &casos);
  while (casos--)
  {
    scanf("%d%d", &C, &R);
    for (i = 1; i <= R; i++) 
    {
      for (j = 1; j <= C; j++) 
      {
        scanf("%s", formula[i][j]);
        MenusUm[i][j] = false;
        
        if (isdigit(formula[i][j][0])) 
        {
          MenusUm[i][j] = true;
          dp[i][j] = atoi(formula[i][j]);
        }
      }
    }
    
    for (i = 1; i <= R; i++ ) 
      for (j = 1; j<= C; j++ ) 
        printf("%d%s", f(i, j), j == C ? "\n" : " ");
  }
}
