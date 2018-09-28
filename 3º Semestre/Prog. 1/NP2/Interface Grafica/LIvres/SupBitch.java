import javax.swing.*;

public class SupBitch{

	public SupBitch(){
		JFrame f = new JFrame("Titulo da janela");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300, 300);
		JLabel texto = new JLabel("Este texto é um JLabel...");
		JLabel texto2 = new JLabel("<html>ESTE TEXTO TBM É UM<u>JLABEL</u<>/html>");
		JPanel p = new JPanel();
		p.add(texto);
		p.add(texto2);
		f.add(p);
		f.setVisible(true);
	}
}