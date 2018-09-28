/*  TRABALHO 04 da NP2
	Aluno: ADRIEL SCHMITZ
	Disciplina: PROGRAMAÇÃO 1
	Professor: DOGLAS ANDRÉ FINCO
*/
import java.util.*;
public class Post extends Blog{
	private String title;
	private String content;
	private Date date;
	private int likes;
	private int deslikes;

	//geters
	public String getTitle(){
		return this.title;
	}
	public String getContent(){
		return this.content;
	}
	public int getLikes(){
		return this.likes;
	}
	public int getDeslikes(){
		return this.deslikes;
	}
	public Date getData(){
		return this.date;
	}
	//seters
	public void setData(){
		this.date = new Date();
	}
	public void setTitle(String t){
		this.title = t;
	}
	public void setContent(String c){
		this.content = c;
	}
	public void setLikes(int l){
		this.likes = l;
	}
	public void setDeslikes(int d){
		this.deslikes = d;
	}
	//métodos publicos
	public void show(){
		System.out.println( "\nTítulo: " + this.title+
							"\nData: " +this.date+
							"\nConteúdo: " +this.content+
							"\nLikes: " +this.likes+
							"\nDeslikes: " +this.deslikes );
	}
	public void like(){
		this.likes++;
	}
	public void deslike(){
		this.deslikes++;
	}
}