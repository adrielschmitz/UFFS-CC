import javax.swing.*;

public class JFrameTest3{
	public JFrame f;
	public JButton botao;
	public JPanel p;

	public JFrameTest3(){
		f = new JFrame("Exemplo 3: frame com painel: ");
		botao = new JButton("pressione...");
		p = new JPanel();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300, 300);
		p.add(botao);
		f.add(p);
		f.setVisible(true);		
	}		
}