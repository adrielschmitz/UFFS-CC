<?php
	echo "<h2>Avaliação TOPERSON sobre as aulas de PROG II</h2>";
	$i = 0;
	while($i<5){
		switch ($i){
			case 0:
				if(isset($RESPOSTA["check0"])) 
					echo "Prog 2 é topizeira, vou tatuar PHP no braço!";
				break;	
			case 1:
				if(isset($RESPOSTA["check1"])) 
					echo "Acho que deveria tirar algoritmos do curso e colocar Prog 2 no começo já! (HTML >> C).";
				break;
			case 2:
				if(isset($RESPOSTA["check2"])) 
					echo "Uma vez programador em HTML, programador em HTML até morrer (8)";
				break;
			case 3:
				if(isset($RESPOSTA["check3"])) 
					echo "Mas é claro que a matéria só é toperson assim por causa da Professora <3";
				break;
			case 4:
				if(isset($RESPOSTA["check4"]))
					echo "A professora é tão Top que se ela fosse um animal seria uma Toupeira!";
				break;
			default:
				break;
		}
		$i++;
	}
	echo "<br/><br/>Voce gostou da live action de Death Note?<br/><br/>";
	if(isset($RESPOSTA["radio"])){
		switch($RESPOSTA["radio"]){
			case "Sim":
				echo "Sério que voce respondeu sim mano? Não é possível, voce está vivendo errado!";
				break;
			case "Nao":
				echo "Ficou bom, mas tomar um tiro é bem melhor!!";
				break;
			default:
				break;
		}
	}else{
		echo "Ficou tão ruim que o usuário nem quis responder, mas com toda certeza seria NAO!";
	}
?>