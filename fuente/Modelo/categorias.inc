<?php
declare(strict_types=1);
include_once __DIR__ . '/../../app/config/sanitize.php';
class Categorias
{ 	private $idCategoria;//IdCategoria INTEGER IDENTITY PRIMARY KEY,
	private $nombreCategoria;//NombreCategoria VARCHAR(200) NOT NULL,
	private $descripcion;//Descripcion VARCHAR(200) NOT NULL,
	private $alias;//$alias VARCHAR(200) NOT NULL,


	public function __construct(array $categorias)
	{ 	$this->idCategoria = $categorias['IdCategoria'];
			$this->nombreCategoria = $categorias['NombreCategoria'];
			$this->descripcion = $categorias['Descripcion'];
			$this->alias = $categorias['Alias'];
	}

	public function setIdCategoria(int $idCategoria)
	{ $this->idCategoria = sanea($idCategoria);
	}

	public function setNombreCategoria(string $nombreCategoria)
	{ $this->nombreCategoria = sanea($nombreCategoria);
	}

	public function setDescripcion(string $descripcion)
	{ $this->descripcion = sanea($descripcion);
	}

	public function setAlias(string $alias)
	{ $this->alias = sanea($alias);
	}


	public function getIdCategoria() :int
	{ return (int)$this->idCategoria;
	}

	public function getNombreCategoria() :string
	{ return (string)$this->nombreCategoria;
	}

	public function getDescripcion() :string
	{ return (string)$this->descripcion;
	}

	public function getAlias() :string
	{ return (string)$this->alias;
	}


}//fin clase
?>
