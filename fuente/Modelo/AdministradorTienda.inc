<?php
declare(strict_types=1);
include_once __DIR__ . '/../../app/config/sanitize.php';
class AdministradorTienda
{
	private $usuario;//Usuario VARCHAR(20) PRIMARY KEY,
	private $contrasenia;//Contrasenia VARCHAR(500) NOT NULL,
	private $idGrupoUsuario;//INTEGER NOT NULL,
	private $nombre;//Nombre VARCHAR(30) NOT NULL,
	private $primerApellido;//PrimerApellido VARCHAR(30) NOT NULL,
	private $segundoApellido;//SegundoApellido VARCHAR(30) NOT NULL,
	private $idCiudad;//IdCiudad INTEGER NOT NULL,
	private $telefono;//Telefono CHAR(9) NOT NULL,
	private $direccion;//Direccion VARCHAR(200) NOT NULL,
	private $nif;//Nif CHAR(9) NOT NULL,
	private $fax;//Fax VARCHAR(100) ,--NO ES OBLIGATORIO
	private $email;//Email VARCHAR(100) NOT NULL,
	private $idTienda;//integer
	private $activo;//bool BIT DEFAULT 1,

	public function __construct(array $administradorTienda)
	{
		$this->usuario = $administradorTienda['Usuario'];
		$this->contrasenia = $administradorTienda['Contrasenia'];
		$this->idGrupoUsuario = $administradorTienda['IdGrupoUsuario'];
		$this->nombre = $administradorTienda['Nombre'];
		$this->primerApellido = $administradorTienda['PrimerApellido'];
		$this->segundoApellido = $administradorTienda['SegundoApellido'];
		$this->idCiudad = $administradorTienda['IdCiudad'];
		$this->telefono = $administradorTienda['Telefono'];
		$this->direccion = $administradorTienda['Direccion'];
		$this->nif = $administradorTienda['Nif'];
		$this->fax = $administradorTienda['Fax'];
		$this->email = $administradorTienda['Email'];
		$this->idTienda = $administradorTienda['IdTienda'];
		$this->activo = $administradorTienda['Activo'];
	}

	public function getUsuario() :string
	{ return (string)$this->usuario;
	}

	public function setUsuario(string $usuario)
	{ $this->usuario = sanea($usuario);
	}

	public function getContrasenia() :string
	{ return (string)$this->contrasenia;
	}

	public function setContrasenia(string $contrasenia)
	{ $this->contrasenia = sanea($contrasenia);
	}

	public function getIdGrupoUsuario() :string
	{ return (string)$this->idGrupoUsuario;
	}

	public function setIdGrupoUsuario(string $idGrupoUsuario)
	{ $this->idGrupoUsuario = sanea($idGrupoUsuario);
	}

	public function getNombre() :string
	{ return (string)$this->nombre;
	}

	public function setNombre(string $nombre)
	{ $this->nombre = sanea($nombre);
	}

	public function getPrimerApellido() :string
	{ return (string)$this->primerApellido;
	}

	public function setPrimerApellido(string $primerApellido)
	{ $this->primerApellido = sanea($primerApellido);
	}

	public function getSegundoApellido() :string
	{ return (string)$this->segundoApellido;
	}

	public function setSegundoApellido(string $segundoApellido)
	{ $this->segundoApellido = sanea($segundoApellido);
	}

	public function getIdCiudad() :int
	{ return (int)$this->idCiudad;
	}

	public function setIdCiudad(int $idCiudad)
	{ $this->idCiudad = sanea($idCiudad);
	}

	public function getTelefono() :string
	{ return (string)$this->telefono;
	}

	public function setTelefono(string $telefono)
	{ $this->telefono = sanea($telefono);
	}

	public function getDireccion() :string
	{ return (string)$this->direccion;
	}

	public function setDireccion(string $direccion)
	{ $this->direccion = sanea($direccion);
	}

	public function getNif() :string
	{ return (string)$this->nif;
	}

	public function setNif(string $nif)
	{ $this->nif = sanea($nif);
	}

	public function getFax() :string
	{ return (string)$this->fax;
	}

	public function setFax(string $fax)
	{ $this->fax = sanea($fax);
	}

	public function getEmail() :string
	{ return (string)$this->email;
	}

	public function setEmail(string $email)
	{ $this->email = sanea($email);
	}

	public function getIdTienda() :int
	{ return (int)$this->idTienda;
	}

	public function setIdTienda(int $idTienda)
	{ $this->idTienda = sanea($idTienda);
	}

	public function getActivo() :bool
	{ return (bool)$this->activo;
	}

	public function setActivo(bool $activo)
	{ $this->activo = sanea($activo);
	}

}//fin clase
?>
