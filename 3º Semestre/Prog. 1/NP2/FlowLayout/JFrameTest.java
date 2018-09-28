import javax.swing.*;
import java.awt.*;

public class JFrameTest{
	public JFrame f;
	public JButton botao1, botao2, botao3, botao4, botao5;

	public JFrameTest(){
		f = new JFrame();
		f.setLayout(new FlowLayout());
		botao1 = new JButton("Sair");
		botao2 = new JButton("Copiar");
		botao3 = new JButton("Voltar");
		botao4 = new JButton("Entrar");
		botao5 = new JButton("Recortar");
		f.add(botao1);
		f.add(botao2);
		f.add(botao3);
		f.add(botao4);
		f.add(botao5);
		f.pack();
		f.setVisible(true);
	}		
}