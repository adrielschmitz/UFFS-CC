<html> 
	<head> 
		<meta charset="utf-8" /> 
		<title>Lembrador</title>
		<link rel="stylesheet" href="./css/tarefas.css" type="text/css"/>
	</head>

	<body> 
		<h1>Lembrador</h1> 
		
		<?php 
		include "formulario.php";
		if($exibir_tabela == 1){
			include "tabela.php";
		}

		?>
	</body> 
</html>

