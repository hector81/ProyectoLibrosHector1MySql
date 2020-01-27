<?php
require_once __DIR__ . '/app/config/config.php';

class conexionBaseDatos {
    private $con;

    public function __construct(){
          $parametrosConfig = (new Configuracion())->getParametros();
		  $this->con = new PDO("mysql:host=localhost;dbname=". $parametrosConfig['database'] . "", $parametrosConfig['user'], $parametrosConfig['password']);
    }//fin constructor

    public function getConexion(){
        return $this->con;
    }
}




$sql = "SELECT TOP 5 IdLibro, Titulo,YearPublicacion ,nombre_autor,Idioma,Paginas,PVP,Descripcion,Portada,NombreCategoria,NombreSubCategoria
		,NOMBRE_EDITORIAL,IdEjemplar FROM librosPaginaPrincipal order by idlibro desc;";
		

/////////////////////////////////////////////
	$con = (new ConexionBaseDatos)->getConexion();
	try {
		
		foreach($con->query('SELECT  IdLibro, Titulo,YearPublicacion ,nombre_autor,Idioma,Paginas,PVP,Descripcion,Portada,NombreCategoria,NombreSubCategoria
		,NOMBRE_EDITORIAL,IdEjemplar FROM librosPaginaPrincipal ORDER BY idlibro desc LIMIT 5 ;') as $fila) {
			print_r($fila);
		}
		$con = null;
	} catch (PDOException $e) {
		print "¡Error!: " . $e->getMessage() . "<br/>";
		die();
	}


	
		
/*
class conexionBaseDatos {
    private $con;

    public function __construct(){
          $parametrosConfig = (new Configuracion())->getParametros();
		  $this->con = new mysqli($parametrosConfig['host'], $parametrosConfig['user'], $parametrosConfig['password'], $parametrosConfig['database'], $parametrosConfig['port'], $parametrosConfig['socket']) 
				or die ('Could not connect to the database server' . mysqli_connect_error());

    }//fin constructor

    public function getConexion(){
        return $this->con;
    }
}

$con = (new ConexionBaseDatos)->getConexion();
*/
/*
// Check connection
if ($con -> connect_errno) {
  echo "Failed to connect to MySQL: " . $con -> connect_error;
  exit();
}
*/


/*		
$sqlw = "select IdAutor, Nombre, Nacionalidad from autores";
// Perform query
if ($result = $con->query($sql)) {
*/	
	/*
	while($row = $result->fetch_assoc()) {
        echo "<br> id: ". $row["IdAutor"]. " - Name: ". $row["Nombre"]. " " . $row["Nacionalidad"] . "<br>";
    }
	*/
/*	
	
	while ($fila = $result->fetch_assoc()) {
			
				echo 'IdLibro' . $fila['IdAutor'];
				echo 'Titulo' . $fila['Nombre'];
				echo 'YearPublicacion' . $fila['YearPublicacion'];
				echo 'nombre_autor' . $fila['nombre_autor'];
				echo 'Idioma' . $fila['Idioma'];
				echo 'Paginas' . $fila['Paginas'];
				echo 'PVP' . $fila['PVP'];
				echo 'Descripcion' . $fila['Descripcion'];
				echo 'Portada' . $fila['Portada'];
				echo 'NombreCategoria' . $fila['NombreCategoria'];
				echo 'NombreSubCategoria' . $fila['NombreSubCategoria'];
				echo 'NOMBRE_EDITORIAL' . $fila['NOMBRE_EDITORIAL'];
				echo 'IdEjemplar'. $fila['IdEjemplar'];
				echo '<br>';
		}
		

  $result -> free_result();
}
else{
	echo $sql;
}
$con -> close();
*/

?> 
