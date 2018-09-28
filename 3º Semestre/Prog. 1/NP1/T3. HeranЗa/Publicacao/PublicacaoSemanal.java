public class PublicacaoSemanal extends Publicacao{
	private double taxaEntrega;
	
	public PublicacaoSemanal(String nome, double precoExemplar){
		super(nome, precoExemplar);
		calcularTaxaEntraga();
		calcularAnuidade();
	}
	//get
	public double getTaxaEntrega(){
		return this.taxaEntrega;
	}
	//set
	public void setTaxaEntrega(double valor){
		this.taxaEntrega = valor;
	}
	//método public da class
	public void calcularTaxaEntraga(){
		setTaxaEntrega(super.getPrecoExemplar()*0.05);
	}
	//métodos herdeiros da super classe
	@Override
	public void calcularAnuidade(){
		super.setValorAnuidade(52 * ( getTaxaEntrega()+super.getPrecoExemplar() ));
	}
	@Override
	public void imprimirDados(){
		super.imprimirDados();
		System.out.println("Taxa de Entrega: R$ " + getTaxaEntrega() );
	}
}