<?php
declare(strict_types=1);
include_once __DIR__ . '/../../app/config/sanitize.php';
class SubCategorias
{ 	private $idSubCategoria;//IdSubCategoria INTEGER IDENTITY PRIMARY KEY,
	private $nombreSubCategoria;//NombreSubCategoria VARCHAR(200) NOT NULL,
	private $descripcion;//Descripcion VARCHAR(200) NOT NULL,
	private $idCategoria;//IdCategoria INTEGER NOT NULL,
	private $alias;//$alias VARCHAR(200) NOT NULL,

	public function __construct(array $subCategorias)
	{ 	$this->idSubCategoria = $subCategorias['IdSubCategoria'];
		$this->nombreSubCategoria = $subCategorias['NombreSubCategoria'];
		$this->descripcion = $subCategorias['Descripcion'];
		$this->idCategoria = $subCategorias['IdCategoria'];
		$this->alias = $subCategorias['Alias'];
	}

	public function setIdSubCategoria(int $idSubCategoria)
	{ $this->idSubCategoria = sanea($idSubCategoria);
	}

	public function setNombreSubCategoria(string $nombreSubCategoria)
	{ $this->nombreSubCategoria = sanea($nombreSubCategoria);
	}

	public function setDescripcion(string $descripcion)
	{ $this->descripcion = sanea($descripcion);
	}

	public function setIdCategoria(int $idCategoria)
	{ $this->idCategoria = sanea($idCategoria);
	}

	public function setAlias(string $alias)
	{ $this->alias = sanea($alias);
	}


	public function getIdSubCategoria() :int
	{ return (int)$this->idSubCategoria;
	}

	public function getNombreSubCategoria() :string
	{ return (string)$this->nombreSubCategoria;
	}

	public function getDescripcion() :string
	{ return (string)$this->descripcion;
	}

	public function getIdCategoria() :int
	{ return (int)$this->idCategoria;
	}

	public function getAlias() :string
	{ return (string)$this->alias;
	}


}//fin clase
?>
