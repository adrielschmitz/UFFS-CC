<?php
	require_once('usuario.php');
	require_once('assistente.php');

	$usuario = new usuario("Kadu", "040.552.320-39", "Rua Angelo Rech, 554. Centro - Sarandi");

	$usuario->imprimeUsuario();

	$assistente = new assistente("Artur", "123.456.789-10", "Rua Podrona - Lugar dos Escravos", 1);

	$assistente->imprimeUsuario();

	$usuario2 = new usuario("Adriel");
	$usuario3 = new usuario("Leo");

	echo usuario::$usuariosOnline;
?>