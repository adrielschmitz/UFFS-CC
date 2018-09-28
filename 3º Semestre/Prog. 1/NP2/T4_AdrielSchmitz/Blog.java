/*  TRABALHO 04 da NP2
	Aluno: ADRIEL SCHMITZ
	Disciplina: PROGRAMAÇÃO 1
	Professor: DOGLAS ANDRÉ FINCO
*/
import java.util.*;

public class Blog{
	Scanner ler = new Scanner(System.in);
	private List<Post> posts_arrayList = new ArrayList<>();

	//métodos publicos da classe
	public void showAll(){
		int i=1;
		System.out.print("\n");
		for(Post p : posts_arrayList){
			System.out.print("\n" + i + "º Postagem");
			p.show();
			i++;
		}
	}

	public void readData(Post p){//Upcasting
		if(p instanceof ProductReview){
			System.out.println("\n------OUTROS ASSUNTOS-----");
			p.setData();
			System.out.println("\nQual é o título?");
			p.setTitle(ler.nextLine());
			System.out.println("Qual é o conteúdo?");
			p.setContent(ler.nextLine());
			System.out.println("Qual é a marca? ");
			((ProductReview)p).setBrand(ler.nextLine());//Downcast
			System.out.println("Qual é a nota?(1 até 10) ");
			((ProductReview)p).evaluate(ler.nextInt());//Downcast
			ler.nextLine();
			this.posts_arrayList.add(p);
		}else if(p instanceof News){
			System.out.println("\n----------NOTÍCIAS--------");
			p.setData();
			System.out.println("\nQual é o título?");
			p.setTitle(ler.nextLine());
			System.out.println("Qual é o conteúdo?");
			p.setContent(ler.nextLine());
			System.out.println("Qual é a fonte? ");
			((News)p).setSource(ler.nextLine());//Downcast
			this.posts_arrayList.add(p);
		}else if(p instanceof Post){// a classe pai deve sempre ficar por último, caso contrário sempre entrará no if da classe pai e nao vai pras filhas....
			System.out.println("\n----------POSTS-----------");
			p.setData();
			System.out.println("\nQual é o título?");
			p.setTitle(ler.nextLine());
			System.out.println("Qual é o conteúdo?");
			p.setContent(ler.nextLine());
			this.posts_arrayList.add(p);
		}else{
			System.out.println("**ERROR**");
		}
	}
	//geters e seters do array posts
	public Post getPostsArrayList(int a){
		return this.posts_arrayList.get(a);//acessa o array no indice recebido como parâmetro
	}
	public void setPostsArrayList(List<Post> post){
		this.posts_arrayList = post;
	}
}