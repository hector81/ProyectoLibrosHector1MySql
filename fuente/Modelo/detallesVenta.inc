<?php
declare(strict_types=1);
include_once __DIR__ . '/../../app/config/sanitize.php';
	class DetallesVenta
	{ 	private $idVenta;//IdVenta  INTEGER NOT NULL,
			private $idEjemplar;//IdEjemplar  INTEGER NOT NULL,
			private $cantidad;//Cantidad INTEGER NOT NULL,
			private $pvp;//	PVP MONEY
			private $idTienda;//IdTienda INTEGER
			private $activo;//Activo BIT DEFAULT 1,
			private $nulo;//Nulo BIT DEFAULT 1,

		public function __construct(array $detallesVenta)
		{ 	$this->idVenta = $detallesVenta['IdVenta'];
				$this->idEjemplar = $detallesVenta['IdEjemplar'];
				$this->cantidad = $detallesVenta['Cantidad'];
				$this->pvp = $detallesVenta['PVP'];
				$this->idTienda = $detallesVenta['IdTienda'];
				$this->activo = $detallesVenta['Activo'];
				$this->nulo = $detallesVenta['Nulo'];
		}

		public function setIdVenta(int $idVenta)
		{ $this->idVenta = sanea($idVenta);
		}

		public function setIdEjemplar(int $idEjemplar)
		{ $this->idEjemplar = sanea($idEjemplar);
		}

		public function setCantidad(int $cantidad)
		{ $this->cantidad = sanea($cantidad);
		}

		public function setPvp(float $pvp)
		{ $this->pvp = sanea($pvp);
		}

		public function setIdTienda(int $idTienda)
		{ $this->idTienda = sanea($idTienda);
		}

		public function setActivo(bool $activo)
		{ $this->activo = sanea($activo);
		}

		public function setNulo(bool $nulo)
		{ $this->nulo = sanea($nulo);
		}


		public function getidVenta() :int
		{ return (int)$this->idVenta;
		}

		public function getIdEjemplar() :int
		{ return (int)$this->idEjemplar;
		}

		public function getCantidad() :int
		{ return (int)$this->cantidad;
		}

		public function getPvp() :float
		{ return (float)$this->pvp;
		}

		public function getIdTienda() :int
		{ return (int)$this->idTienda;
		}

		public function getActivo() :bool
		{ return (float)$this->activo;
		}

		public function getNulo() :bool
		{ return (int)$this->nulo;
		}

	}//fin clase
?>
