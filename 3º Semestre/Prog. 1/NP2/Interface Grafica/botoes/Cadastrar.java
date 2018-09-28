import javax.swing.*;
import java.awt.event.*;

public class Cadastrar{
	JButton botaoCadastrar = new JButton("Cadastrar");
	JButton botaoSair = new JButton("Sair");
	JPanel painel = new JPanel();
	JFrame mostrar = new JFrame("Exemplo de botoes");

	public Cadastrar(){
		mostrar.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		mostrar.setSize(300, 300);
		painel.add(botaoCadastrar);
		
		painel.add(botaoSair);
		mostrar.add(painel);

		mostrar.setVisible(true);	
		mostrar.add(painel);	
	}
}