/*  1º trabalho da NP1 da desciplina de Programação I;
	Aluno: ADRIEL SCHMITZ
	Professor: DOGLAS ANDRÉ FINCO */
import java.util.*;
import javax.swing.JOptionPane;
public class Principal{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);

		String aux_entrada_dados;
		String nome = "Cobavital";
		double precoVenda = 12.50;
		int qtdEstoque = 20;
		boolean receitaObrigatoria = false;
		Medicamento medicamento = new Medicamento(nome, precoVenda, receitaObrigatoria, qtdEstoque);
		
		boolean flag = true, flag_opcao_5, escolha_reajuste;
		double reajuste;
		int opcao_menu, quantidade = 0, menu_opcao_5;

		while(flag){
			aux_entrada_dados =  JOptionPane.showInputDialog("Informe a opção desejda\n\t1. Comprar\n\t2. Mostrar dados do Medicamento\n\t3. Comprar do Fornecedor\n\t4. Reajustar preço do Medicamento\n\t5. Sair\n");
			opcao_menu = Integer.parseInt(aux_entrada_dados);
			switch(opcao_menu){
				case 1:
					aux_entrada_dados = JOptionPane.showInputDialog("Quantos produtos deseja comprar?");
					quantidade = Integer.parseInt(aux_entrada_dados);
					medicamento.Vender(quantidade);
					break;
				case 2:
					medicamento.Mostrar();
					break;
				case 3:
					String aux_quantidade = JOptionPane.showInputDialog("\nInforme a quantidade que deseja comprar: ");
					quantidade = Integer.parseInt(aux_quantidade);
					medicamento.Comprar(quantidade);
					break;
				case 4:
					flag_opcao_5 = true;
					while(flag_opcao_5){
						JOptionPane.showMessageDialog(null, "Dar Desconto[1] ou Acrescentar[2] no valor do medicamento? ");
						menu_opcao_5 = ler.nextInt();
						switch(menu_opcao_5){
							case 1:
								escolha_reajuste = true;
								JOptionPane.showMessageDialog(null, "Informe a porcentagem do desconto: ");
								reajuste = ler.nextDouble();
								if(reajuste <= 100)
									medicamento.ReajustarPrecoVenda(reajuste, escolha_reajuste);	
								else
									JOptionPane.showMessageDialog(null, "Desconto nao suportado!");
								flag_opcao_5 = false;
								break;
							case 2:
								escolha_reajuste = false;
								JOptionPane.showInputDialog("Informe a porcentagem do acréscimo: ");
								reajuste = ler.nextDouble();
								medicamento.ReajustarPrecoVenda(reajuste, escolha_reajuste);
								flag_opcao_5 = false;
								break;
							default:
								JOptionPane.showMessageDialog(null, "Opção inválida!");
								break;
						}
					}
					break;
				case 5:
					flag = false;
					break;
				default:
					JOptionPane.showMessageDialog(null, "**ERROR** Opção inválida!");
					break;
			}
		}
	}
}
