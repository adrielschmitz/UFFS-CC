/*  TRABALHO 04 da NP2
	Aluno: ADRIEL SCHMITZ
	Disciplina: PROGRAMAÇÃO 1
	Professor: DOGLAS ANDRÉ FINCO
*/
public class News extends Post{
	private String source;

	public String getSource(){
		return this.source;
	}
	public void setSource(String s){
		this.source = s;
	}
	
	@Override
	public void show(){
		super.show();
		System.out.println("Fonte: " +this.source);
	}
}