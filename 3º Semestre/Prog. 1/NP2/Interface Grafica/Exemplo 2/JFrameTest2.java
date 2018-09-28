import javax.swing.*;
public class JFrameTest2{
	public JFrame f;
	public JButton botao;

	public JFrameTest2(){
		f = new JFrame("Exemplo 2: Frame com botao");
		botao = new JButton("pressione");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300, 300); // tamanho do frame
		f.add(botao);
		f.setVisible(true);
	}
}