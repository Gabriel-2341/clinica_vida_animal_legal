#include <stdio.h>
#include <windows.h>

struct info{
	char nome[20], relat[900];
	int dia, mes, ano, idade;
	char tamanho[20], especie[25];
};
int main() {
	SetConsoleOutputCP(CP_UTF8);
	int cont = 0, resp1 = 'c', resp2;
	char nome[5] = "Nome", esp[] = "Espécie", porte[] = "Porte";
	struct info cliente[1000];
	while(resp1 != 's'){
		int e;
		if(cont == 0){
			printf("Seja bem-vindo ao histórico de consultas!\n");
			printf("--- Novo relatório de consulta ---\n");
			printf("Qual o nome do paciente?\n");
			scanf(" %[^\n]", cliente[0].nome);
			printf("Qual a idade do paciente?\n");
			scanf("%d", &cliente[0].idade);
			printf("Qual a espécie do paciente?\n");
			scanf(" %s", cliente[0].especie);
			printf("Qual o porte do paciente?\n");
			scanf("%s", cliente[0].tamanho);
			printf("Indique a data da consulta: (dd/mm/aaaa)\n");
			scanf("%d/%d/%d", &cliente[0].dia, &cliente[0].mes, &cliente[0].ano);
			printf("Coloque o relatório da consulta (Cite as vacinações e tratamentos anteriores):\n");
			scanf(" %[^\n]", cliente[0].relat);
			cont++;
		}
		printf("Núm. Client.|%-20s|Idade |%-25s|%-20s|Data      |Relatório          \n", nome, esp, porte);
		for(int i = 0; i < cont; i++){
			printf("%-12d|%-20s|%-6d|%-24s|%-20s|%-2d/%-2d/%-4d|%s\n", i+1, cliente[i].nome, cliente[i].idade, cliente[i].especie, cliente[i].tamanho, cliente[i].dia, cliente[i].mes, cliente[i].ano, cliente[i].relat);
		}
		printf("O que você deseja fazer?\n");
		printf("c para criar um novo relatório;\n");
		printf("e para editar um relatório;\n");
		printf("d para deletar um relatório;\n");
		printf("s para sair do programa.\n");
		scanf(" %c", &resp1);
		if(resp1 == 'c'){
			cont++;
			printf("--- Novo relatório de consulta ---\n");
			printf("Qual o nome do paciente?\n");
			scanf(" %[^\n]", cliente[cont-1].nome);
			printf("Qual a idade do paciente?\n");
			scanf("%d", &cliente[cont-1].idade);
			printf("Qual a espécie do paciente?\n");
			scanf(" %s", cliente[0].especie);
			printf("Qual o porte do paciente?\n");
			scanf("%s", cliente[0].tamanho);
			printf("Indique a data da consulta: (dd/mm/aaaa)\n");
			scanf("%d/%d/%d", &cliente[cont-1].dia, &cliente[cont-1].mes, &cliente[cont-1].ano);
			printf("Coloque o relatório da consulta:\n");
			scanf(" %[^\n]", cliente[cont-1].relat);
			printf("Adicionado com sucesso!\n");
		}else if(resp1 == 'e'){
			printf("--- Edição do relatório de consulta ---\n");
			printf("Qual o número do relatório que você deseja editar?\n");
			scanf("%d", &e);
			e--;
			printf("(Caso não queira modificar, copie as informações passadas.)\n");
			printf("Indique o novo nome do paciente:(Antigo: %s)\n", cliente[e].nome);
			scanf(" %[^\n]", cliente[e].nome);
			printf("Indique a nova idade do paciente:(Antigo: %d)\n", cliente[e].idade);
			scanf(" %d", &cliente[e].idade);
			printf("Indique o novo tamanho do paciente:(Antigo: %.2lf)\n", cliente[e].tamanho);
			scanf(" %lf", &cliente[e].tamanho);
			printf("Indique a nova data da consulta: (Antiga: %d/%d/%d)\n", cliente[e].dia, cliente[e].mes, cliente[e].ano);
			scanf("%d/%d/%d", &cliente[e].dia, &cliente[e].mes, &cliente[e].ano);
			printf("Editado com sucesso!\n");
		}else if(resp1 == 'd'){
			printf("--- Deletar uma consulta ---\n");
			printf("Qual é o número do relatório que você quer deletar?\n");
			scanf("%d", &e);
			e--;
			for(int i = e; i < cont; i++){
				cliente[i] = cliente[i+1];
			}
			cont--;
		}else{
			printf("Até mais!");
		}
	}
	return 0;
}