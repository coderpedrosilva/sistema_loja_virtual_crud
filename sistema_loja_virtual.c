#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct{
    int codigo;
    char nome[30];
    float preco;
    int quantidade;
    int existe;
    int selecionado;
} Produto;

void infoProduto(Produto prod);
void infoProdutoCarrinho(Produto prod);
void menu();
void cadastrarProduto();
void listarProdutos();
void alterarProduto();
void excluirProduto();
void comprarProdutos();
void visualizarCarrinho();
void alterarCarrinho();
void fecharPedido();

static int contador_produto = 0;
static Produto produtos[50];

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    menu();

    return 0;
}

void infoProduto(Produto prod){
    if(prod.existe != 0){
    printf("Código: %d \nNome: %s \nPreço: %.2f\n",
    prod.codigo, strtok(prod.nome, "\n"), prod.preco);
    printf("\n==============================\n\n");
    }
}

void infoProdutoCarrinho(Produto prod){
    if(prod.selecionado > 0){
    printf("Código: %d \nNome: %s \nPreço: %.2f\nQuantidade %d\n",
    prod.codigo, strtok(prod.nome, "\n"), prod.preco, prod.quantidade);
    printf("\n==============================\n\n");
    }
}

void menu(){
    printf("\n\n==============================\n");
	printf("======== Bem-vindo(a) ========\n");
	printf("======== LOJA VIRTUAL ========\n");
	printf("==============================\n");

    printf("\n  Selecione uma opção abaixo: \n");

    printf("\n========== Produtos ==========\n\n");
    printf("1 - Cadastrar produtos\n");
    printf("2 - Listar produtos\n");
    printf("3 - Alterar produto\n");
    printf("4 - Excluir produto\n");

    printf("\n========== Compras ===========\n\n");
    printf("5 - Comprar produto\n");
    printf("6 - Visualizar carrinho\n");
    printf("7 - Alterar carrinho\n");
    printf("8 - Fechar pedido\n");

    printf("\n=========== Sair =============\n\n");
    printf("9 - Sair do sistema\n\n");

    int opcao;
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            system("@cls||clear");
            cadastrarProduto();
            break;
        case 2:
            system("@cls||clear");
            listarProdutos();
            break;
        case 3:
            system("@cls||clear");
            alterarProduto();
            break;
        case 4:
            system("@cls||clear");
            excluirProduto();
        case 5:
            system("@cls||clear");
            comprarProdutos();
        case 6:
            system("@cls||clear");
            visualizarCarrinho();
        case 7:
            system("@cls||clear");
            alterarCarrinho();
        case 8:
            system("@cls||clear");
            fecharPedido();
        case 9:
            system("@cls||clear");
            printf("\n\nVolte sempre!\n");
            Sleep(2000);
            exit(0);
        default:
            system("@cls||clear");
            printf("\n\nOpção iválida.\n");
            Sleep(2000);
            system("@cls||clear");
            menu();
            break;
    }
}

void cadastrarProduto(Produto prod){

    printf("\n\n==============================\n");
	printf("==== CADASTRO DE PRODUTOS ====\n");
	printf("==============================\n");

    printf("\nInforme o nome do produto: \n");
    fgets(produtos[contador_produto].nome, 30, stdin);

    printf("\nInforme o preço do produto: \n");
    scanf("%f", &produtos[contador_produto].preco);

    system("@cls||clear");

    printf("\n\n==============================\n");
	printf("==== CADASTRO DE PRODUTOS ====\n");
	printf("==============================\n");

    printf("\nO produto %s foi cadastrado com sucesso!\n", strtok(produtos[contador_produto].nome, "\n"));

    produtos[contador_produto].codigo = (contador_produto + 1);

    produtos[contador_produto].existe = 1;

    contador_produto++;

    Sleep(2000);
    system("@cls||clear");
    menu();
}

void listarProdutos(Produto prod){
    if(contador_produto > 0 && prod.existe > 0){
        printf("\n\n==============================\n");
		printf("====== LISTA DE PRODUTOS =====\n");
		printf("==============================\n\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
        }
        system("pause");
        system("@cls||clear");
        menu();
    }else{
        printf("\n\n==============================\n");
		printf("====== LISTA DE PRODUTOS =====\n");
		printf("==============================\n");
        printf("\nNão temos produtos cadastrados\n");
        Sleep(2000);
        system("@cls||clear");
        menu();
    }
}

void alterarProduto(Produto prod){
    char nome[50];
    int codigo, escolha;

    if(contador_produto > 0 && prod.existe > 1){
        printf("\n\n==============================\n");
		printf("====== ALTERAR PRODUTO =======\n");
		printf("==============================\n\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
        }
    }else{
        printf("\n\n==============================\n");
		printf("====== ALTERAR PRODUTO =======\n");
		printf("==============================\n");
        printf("\nNão temos produtos cadastrados\n");
        Sleep(2000);
        system("@cls||clear");
        menu();
    }

        printf("Codigo do produto a ser alterado:\n");
        scanf("%i", &codigo);
        getchar();

        for(int i = 0; i < contador_produto; i++){
            if(codigo == produtos[i].codigo){

                printf("\nNovo nome: \n");
                fgets(nome, 50, stdin);

                nome[strlen(nome)-1] = '\0';
                strcpy(produtos[i].nome, nome);

                printf("\nNovo preco: \n");
                scanf("%f", &produtos[i].preco);
            }
        }
        system("@cls||clear");
        printf("\n\n==============================\n");
		printf("====== ALTERAR PRODUTO =======\n");
		printf("==============================\n");
        printf("\nProduto alterado com sucesso!\n");
        Sleep(2000);
        system("@cls||clear");
        menu();
}

void excluirProduto(){

     Produto aux;
     int codigo;

     if(contador_produto > 0 && contador_produto > 0){
        printf("\n\n==============================\n");
		printf("====== EXCLUIR PRODUTO =======\n");
		printf("==============================\n\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
        }
    }else{
        printf("\n\n==============================\n");
		printf("====== EXCLUIR PRODUTO =======\n");
		printf("==============================\n");
        printf("\nNão temos produtos cadastrados\n");
        Sleep(2000);
        system("@cls||clear");
        menu();
    }

    printf("Digite o codigo do produto a ser excluído:\n");
    scanf("%i", &codigo);
    getchar();

    for(int i = 0; i < contador_produto; i++){
        if(produtos[i].codigo == codigo){
            strcpy(produtos[i].nome,"");
            produtos[i].preco = 0;
            produtos[i].quantidade = 0;
            produtos[i].existe = 0;
            produtos[i].selecionado = 0;
            produtos[i].codigo = 0;
        }
    }
    system("@cls||clear");
    printf("\n\n==============================\n");
    printf("====== EXCLUIR PRODUTO =======\n");
    printf("==============================\n");
    printf("\nProduto excluído com sucesso");
    Sleep(2000);
    system("@cls||clear");
    menu();
}

void comprarProdutos(Produto prod){
    if(contador_produto > 0 && prod.existe > 0){

        printf("\n\n==============================\n");
        printf("====== COMPRAR PRODUTOS ======\n");
        printf("==============================\n\n");
		for(int i = 0; i < contador_produto; i++){
			infoProduto(produtos[i]);
		}

        printf("Informe o código do produto que deseja adicionar ao carrinho\n");
		int codigo = 0;
		scanf("%d", &codigo);
		getchar();

        int i;
		for(i = 0; i < contador_produto; i++){
			if(produtos[i].codigo == codigo){
            produtos[i].selecionado = 1;

            if(produtos[i].quantidade > 0){
                system("@cls||clear");
                printf("\n\n==============================\n");
                printf("====== COMPRAR PRODUTOS ======\n");
                printf("==============================\n");
                printf("\nProduto %s já está no carrinho, \nfoi adicionada mais uma unidade!\n",strtok(produtos[i].nome, "\n"));
                produtos[i].quantidade++;
            Sleep(3000);
            system("@cls||clear");
            menu();
            }else{
               printf("\nInforme a quantidade desejada do produto: \n");
               scanf("%d", &produtos[i].quantidade);

                system("@cls||clear");
                printf("\n\n==============================\n");
                printf("====== COMPRAR PRODUTOS ======\n");
                printf("==============================\n");
                printf("\nO produto %s foi adicionado ao carrinho!\n", strtok(produtos[i].nome, "\n"));
            }
            Sleep(2000);
            system("@cls||clear");
            menu();
        	}
        }

    }else{
        printf("\n\n==============================\n");
        printf("====== COMPRAR PRODUTOS ======\n");
        printf("==============================\n");
        printf("\nAinda não existem produtos para vender\n");
        Sleep(2000);
        system("@cls||clear");
        menu();
    }
}

void visualizarCarrinho(Produto prod){
    if(contador_produto > 0 && prod.selecionado > 0){
        printf("\n\n==============================\n");
        printf("===== CARRINHO DE COMPRAS ====\n");
        printf("==============================\n\n");
        for(int i = 0; i < contador_produto; i++){
            infoProdutoCarrinho(produtos[i]);
        }
        system("pause");
        system("@cls||clear");
        menu();
    }else{
        printf("\n\n==============================\n");
        printf("===== CARRINHO DE COMPRAS ====\n");
        printf("==============================\n");
        printf("\nNão temos produtos no carrinho\n");
        Sleep(2000);
        system("@cls||clear");
        menu();
    }
}

void alterarCarrinho(Produto prod){

    int codigo;
    int resposta;

    if(contador_produto > 0 && prod.selecionado > 0){
		printf("\n\n==============================\n");
        printf("====== ALTERAR CARRINHO ======\n");
        printf("==============================\n\n");
        for(int i = 0; i < contador_produto; i++){
            infoProdutoCarrinho(produtos[i]);
        }

        printf("Escolha uma opção:\n\n");
        printf("1 - Alterar quantidade do produto\n");
        printf("2 - Remover produto do carrinho\n");
        scanf("%d", &resposta);
        getchar();

            if(resposta == 1){

            codigo = 0;
            printf("\nCódigo do produto a ser alterado:\n");
            scanf("%i", &codigo);
            getchar();

            for(int i = 0; i < contador_produto; i++){
                if(codigo == produtos[i].codigo){

            printf("\nNova quantidade: \n");
            scanf("%d", &produtos[i].quantidade);
                }
            }

            system("@cls||clear");
            printf("\n\n==============================\n");
            printf("====== ALTERAR CARRINHO ======\n");
            printf("==============================\n");
            printf("\nQuantidade alterada com sucesso!\n");
            Sleep(2000);
            system("@cls||clear");
            menu();

            }else if(resposta == 2){
            codigo = 0;
            printf("\nCódigo do produto a ser removido:\n");
            scanf("%i", &codigo);
            getchar();

            for(int i = 0; i < contador_produto; i++){
                if(codigo == produtos[i].codigo){
                    produtos[i].quantidade = 0;
                    produtos[i].selecionado = 0;
                }
            }

            system("@cls||clear");
            printf("\n\n==============================\n");
            printf("====== ALTERAR CARRINHO ======\n");
            printf("==============================\n");
            printf("\nProduto removido do carrinho com sucesso\n");
            Sleep(2000);
            system("@cls||clear");
            menu();

            }else{
            system("@cls||clear");
            printf("\n\n==============================\n");
            printf("====== ALTERAR CARRINHO ======\n");
            printf("==============================\n");
            printf("\nOpção inválida!\n");
            Sleep(2000);
            system("@cls||clear");
            menu();
            }
	}else{
		printf("\n\nNão temos ainda produtos no carrinho\n");
		Sleep(2000);
		system("@cls||clear");
		menu();
	}
}

void fecharPedido(Produto prod){
	if(contador_produto > 0 && prod.selecionado > 0){
		float valorTotal = 0.0;
		printf("\n\n==============================\n");
		printf("====== FINALIZAR COMPRA ======\n");
		printf("==============================\n\n");
		for(int i = 0; i < contador_produto; i++){
			Produto p = produtos[i];
			int quantidade = produtos[i].quantidade;
			valorTotal += p.preco * quantidade;
			infoProdutoCarrinho(p);
			if(p.quantidade > 0){
			printf("Quantidade: %d\n", quantidade);
			printf("\n==============================\n\n");
			}
			Sleep(1000);
		}
		printf("Sua fatura é R$ %.2f\n\n", valorTotal);

		//limpar carrinho
		contador_produto = 0;
		printf("\nObrigado pela preferência!\n\n");
		system("pause");
		system("@cls||clear");
		menu();
	}else{
        printf("\n\n==============================\n");
		printf("====== FINALIZAR COMPRA ======\n");
		printf("==============================\n");
		printf("\nVocê não tem nenhum produto no carrinho ainda\n");
		Sleep(3000);
		system("@cls||clear");
		menu();
	}
}


