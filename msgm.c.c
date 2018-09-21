#include<stdio.h>
#include<math.h>

int elementos;
int v[105];
int h[105];

int abs(int x){ return x<0?-x:x;}

int max(int a, int b){ return a<b?b:a;}

int altura(int posicao){
	if(posicao > elementos) return 0;
	if(v[posicao]==-1) return h[posicao] = 0;
	if(h[posicao]!=-1) return h[posicao];
	int ans = 1 + max(altura(2*posicao),altura(2*posicao+1));
	return h[posicao] = ans;
}

int balancear(int posicao){
	if(posicao > elementos || v[posicao]==-1) return 1;
	int esquerda = altura(posicao<<1);
	int direita = altura(2*posicao+1);
	if(abs(direita-esquerda)<=1 && balancear(posicao<<1) && balancear(2*posicao+1)) return 1;
	return 0;
}

int main(){
	int testes;
	scanf("%d",&testes);
	while(testes--){
		scanf("%d",&elementos);
		for(int i=1; i<=elementos; i++) h[i] = -1;
            for(int i=1; i<=elementos; i++) scanf("%d",v+i);
                if(elementos<=2) puts("T");
            else{
                int h = altura(1);
                if(balancear(1)){
                    puts("T");
			}
                else puts("F");
		}
	}
	return 0;
}
