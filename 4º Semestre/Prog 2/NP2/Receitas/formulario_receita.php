<div class="container" id="container-minhas-receitas">
	<form method="post" action="salva_receita.php" enctype="multipart/form-data">
		<div class="row">
			<div class="input-field col s12">
				<input name="nome" id="nome" type="text" class="validate">
				<label for="nome">Nome da Receita</label>
			</div>
		</div>
		<div class="area-texto">
			<div class="row">
				<div class="input-field col s12">
					<textarea name="descricao" id="descricao" class="materialize-textarea" data-length="200"></textarea>
					<label for="descricao">Descrição</label>
				</div>
			</div>
			<div class="row">
				<div class="input-field col s12">
					<textarea name="ingredientes" id="ingredientes" class="materialize-textarea" data-length="1000"></textarea>
					<label for="ingredientes">Ingredientes</label>
				</div>
			</div>
			<div class="row">
				<div class="input-field col s12">
					<textarea name="modo_preparo" id="modo_preparo" class="materialize-textarea" data-length="1500"></textarea>
					<label for="modo_preparo">Modo de Preparo</label>
				</div>
			</div>
		</div>
		<div class="file-field input-field">
			<div class="btn">
				<span>Imagem</span>
				<input name="imagem" type="file">
				</div>
			<div class="file-path-wrapper">
				<input class="file-path validate" placeholder="Selecione uma imagem" type="text">
			</div>
		</div>
		<button class="btn waves-effect waves-light blue-grey" type="submit" name="action">Salvar Receita
			<i class="material-icons right">send</i>
		</button>
	</form>
</div>