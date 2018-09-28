import java.util.*;
import java.text.DecimalFormat;
public class BalancoTrimestral{
	public static void main(String[] args){
		DecimalFormat f = new DecimalFormat("0.00");
		int jan = 15000, fev = 23000, mar = 17000, gastosTrimestre;
		
		gastosTrimestre = jan+fev+mar;
		System.out.println("Os gastos trimestrais foram de: R$ " + f.format(gastosTrimestre));
		boolean gastoControlado;
		if(gastosTrimestre < 30000)
			gastoControlado = true;
		else
			gastoControlado = false;
		System.out.println("Verificação: O gasto está controlado? " + gastoControlado);
	}
}