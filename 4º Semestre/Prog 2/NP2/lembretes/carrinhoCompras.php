<?php
	class carrinhoCompras{
		public $produtos;
		public $total=0;


		function add(Produto $produto){
			$this->produtos[]=$produto;
		}
	}
	
?>