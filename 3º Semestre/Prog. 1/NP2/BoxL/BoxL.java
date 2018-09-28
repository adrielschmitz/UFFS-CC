import javax.swing.*;
import java.awt.*;

public class BoxL{
	public JFrame f = new JFrame();
	public JPanel p = new JPanel();
	public JButton botao1, botao2, botao3, botao4, botao5;

	public BoxL(){
		f.add(p);
		p.setLayout( new BoxLayout(p, BoxLayout.Y_AXIS) );
		botao1 = new JButton("Sair");
		botao2 = new JButton("Copiar");
		botao3 = new JButton("Voltar");
		botao4 = new JButton("Entrar");
		botao5 = new JButton("Recortar");
		p.add(botao1);
		p.add(botao2);
		p.add(botao3);
		p.add(botao4);
		p.add(botao5);
		f.pack();
		f.setVisible(true);
	}
}