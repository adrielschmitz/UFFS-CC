import javax.swing.JOptionPane;
import java.util.*;
class Medicamento{
	String nome;
	boolean receitaObrigatoria;
	String dataValidade;
	double precoVenda;
	int qtdEstoque;

	// Atributos para a classe "Data"
	int dia = 10, mes = 04, ano = 2017;
	Data dataDeEntrada = new Data(dia, mes, ano);

	// Atributos para a classe "Laboratório"
	String nomeLaboratorio = "Ultra Farma"; // todas as strings seriam lidas com o nextLine, fazendo com que todos os caracteres sejam pegados até pressionar enter.
	String cnpj = "11223300-X";
	String endereco = "Rua " + "General Osório " + "Nº 2382";
	String telefone = "(48)3521-5051";
	Laboratorio dadosLab = new Laboratorio(nomeLaboratorio, cnpj, endereco, telefone);

	public Medicamento(String nome, double precoVenda, boolean receita,	int qtdEstoque){
		this.nome = nome;
		this.precoVenda = precoVenda;
		this.receitaObrigatoria = receita;
		this.qtdEstoque = qtdEstoque;
	}

	void Vender(int quatidade){
		double totalVenda;
		if(receitaObrigatoria){
			JOptionPane.showInputDialog("**ERROR**\nMedicamento só pode ser vendido com receita!\n");
		}else{
			if(quatidade <= qtdEstoque){
				totalVenda = (double)quatidade*precoVenda;
				qtdEstoque -= quatidade;
				JOptionPane.showMessageDialog(null, "Valor total da venda: R$ %.2f\n" + totalVenda);
			}else{
				JOptionPane.showMessageDialog(null, "**ERROR**\nQuantidade nao disponível em estoque!\n");
			}
		}
	}

	void Mostrar(){
		JOptionPane.showMessageDialog(null, "\nNome do produto: " + nome);
		System.out.printf("Preço do produto: R$ %.2f\n", precoVenda);
		System.out.println("Data de Validade: " + this.dataDeEntrada.Formata());
		JOptionPane.showMessageDialog(null, "Quantidade em estoque: " + qtdEstoque);
		dadosLab.PrintarLab();
	}
	void Comprar(int quatidade){
		qtdEstoque += quatidade;
		System.out.println("Medicamento: " + nome);
		System.out.println("Quantidade em Estoque: " + qtdEstoque);
	}

	void ReajustarPrecoVenda(double percentual, boolean escolha){
		if(escolha){
			precoVenda -= (Double)(precoVenda*percentual)/100;
		}else{
			precoVenda += (Double)(precoVenda*percentual)/100;
		}
		System.out.printf("Novo valor do produto: R$ %.2f\n", precoVenda);
	}
}