class Data{
	int dia, mes, ano;

	public Data(int dia, int mes, int ano){
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	String Formata(){
		String data = dia + ":" + mes + ":" + ano;
		return data;
	}
}