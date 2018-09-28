import javax.swing.JOptionPane;

public class Dialogo{
	public static void main(String[] args){
		String nome = JOptionPane.showInputDialog("What's your name? ");
		String cpf = JOptionPane.showInputDialog("Informe seu cpf: ");
		int x = Integer.parseInt(cpf);
		JOptionPane.showMessageDialog(null, "Olá " + nome + "!");
		JOptionPane.showMessageDialog(null, "CPF " + x + "!");
	}
}