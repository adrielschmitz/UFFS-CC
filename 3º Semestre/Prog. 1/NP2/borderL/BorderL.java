import javax.swing.*;
import java.awt.*;

public class BorderL{
	public JFrame f = new JFrame();
	public JButton botao1, botao2, botao3, botao4, botao5;

	public BorderL(){
		f.setLayout( new BorderLayout() );
		botao1 = new JButton("Sair");
		botao2 = new JButton("Copiar");
		botao3 = new JButton("Voltar");
		botao4 = new JButton("Entrar");
		botao5 = new JButton("Recortar");
		f.add(BorderLayout.NORTH, botao1);
		f.add(BorderLayout.WEST, botao2);
		f.add(BorderLayout.CENTER, botao3);
		f.add(BorderLayout.EAST, botao4);
		f.add(BorderLayout.SOUTH, botao5);
		f.pack();
		f.setVisible(true);
	}
}